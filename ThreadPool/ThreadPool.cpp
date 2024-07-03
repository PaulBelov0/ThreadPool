#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t num_threads = std::thread::hardware_concurrency())
{
	stop_ = false;

	for (std::size_t i = 0; i < num_threads; i++)
	{
		threads_.emplace_back([this]
			{
				while (true)
				{
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> lock(queueMutex_);

						cv_.wait(lock, [this]
							{
								return !tasks_.empty() || stop_;
							});
						if (stop_ && tasks_.empty())
						{
							return;
						}

						task = move(tasks_.front());
						tasks_.pop();
					}
					task();
				}
			});
	}
}

void ThreadPool::enqueue(std::function<void()> task)
{
	{
		std::unique_lock<std::mutex> lock(queueMutex_);
		tasks_.emplace(move(task));
	}
	cv_.notify_one();
}

ThreadPool::~ThreadPool()
{
	{
		std::unique_lock<std::mutex> lock(queueMutex_);
		stop_ = true;
	}
}