#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <condition_variable> 
#include <functional> 
#include <iostream> 
#include <mutex> 
#include <queue> 
#include <thread> 

class ThreadPool
{
public:

	ThreadPool(size_t num_threads = std::thread::hardware_concurrency());

	~ThreadPool();

	void enqueue(std::function<void()> task);

private:
	std::vector<std::thread> threads_;

	std::queue<std::function<void()>> tasks_;

	std::mutex queueMutex_;
	std::condition_variable cv_;

	bool stop_;
};

#endif //THREADPOOL_H