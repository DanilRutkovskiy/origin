#pragma once
#include "safe_queue.h"
#include <future>
#include <thread>
#include <vector>
#include <condition_variable>

class thread_pool {
public:
	void work();
	void submit(std::packaged_task<void()>&&);
public:
	thread_pool();
	~thread_pool();
private:
	std::condition_variable m_cv;
	safe_queue<std::packaged_task<void()>> m_tasks;
	std::vector<std::thread> m_threads;
	std::mutex m_mutex;
	std::atomic_bool m_exit;
};