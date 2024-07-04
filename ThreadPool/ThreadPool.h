#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <condition_variable>
#include <functional>
#include <cstdint>
#include <mutex> 
#include <queue> 
#include <thread> 

class ThreadPool{
public:

    explicit ThreadPool(size_t& num_threads);

	~ThreadPool();

    bool enqueue(std::function<void()> task);

private:
	std::vector<std::thread> threads_;

	std::queue<std::function<void()>> tasks_;

	std::mutex queue_mutex_;
	std::condition_variable cv_;

	bool stop_;
};

#endif //THREADPOOL_H
