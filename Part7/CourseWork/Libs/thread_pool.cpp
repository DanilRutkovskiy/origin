#include "thread_pool.h"

void thread_pool::work()
{
	while (true) {
		std::unique_lock<std::mutex> lk{ m_mutex };
		m_cv.wait(lk, [&]() {return !m_tasks.empty() || m_exit; });
		lk.unlock();
		if (m_exit)
			return;
		
		auto task = m_tasks.pop();
		task();
	}
	
}

void thread_pool::submit(std::packaged_task<void()>&& task)
{
	m_tasks.push(std::move(task));
	m_cv.notify_one();
}

thread_pool::thread_pool() : m_exit{false}
{
	int size = std::thread::hardware_concurrency();

	for (int i = 0; i < size; i++) {
		std::thread t{ &thread_pool::work, this};
		m_threads.push_back(std::move(t));
	}
}

thread_pool::~thread_pool()
{
	m_exit = true;

	for (auto& elem : m_threads) {
		m_cv.notify_all();
		elem.join();
	}
}
