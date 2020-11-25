#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
private:
	std::vector< std::thread > _pool;
	std::queue< std::function<void()> > _tasks;

	std::mutex _mtx;
	std::condition_variable _cv;
	bool _stop;
public:

	ThreadPool(size_t);
	~ThreadPool();
	template <typename T, typename...Args>
	auto enqueue(T&& f, Args&&... args) 
	-> std::future<typename std::result_of<T(Args...)>::type>;
};

inline ThreadPool::ThreadPool(size_t size):_stop(false) {
	for (int i=0; i<size; ++i) {
		_pool.emplace_back(
			[this] {
				for(;;) {
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> lock(this->_mtx);
						this->_cv.wait(lock, [this]{return this->_stop || !this->_tasks.empty();});
						if (this->_stop && this->_tasks.empty()) return;
						task = std::move(this->_tasks.front());
						this->_tasks.pop();
					}
					task();
				}
			}
		);
	}
}


template <typename T, typename...Args>
auto enqueue(T&& f, Args&&... args) -> std::future<typename std::result_of<T(Args...)>::type> {
	using return_type = typename std::result_of<T(Args...)>::type;
	auto task = std::make_shared< std::packaged_task<return_type()> >(
		std::bind(std::foward<T>(f), std::foward<Args>(args)...)
	);

	std::future<return_type> res = task->get_future();
	{
		std::unique_lock<std::mutex> lock(_mtx);
		if (_stop) {
			throw std::runtime_error("enqueue on stopped ThreadPool");
		}
		_tasks.emplace([task](){ (*task)(); });
	}
	_cv.notify_all();
	return res;
}



inline ThreadPool::~ThreadPool() {
	{
		std::unique_lock<std::mutex> lock(_mtx);
		_stop = true;
	}
	_cv.notify_all();
	for (auto & p: _pool) {
		p.join();
	}
}
