#pragma once
#include <mutex>
#include <condition_variable>
#include <queue>

template <class T>
class safe_queue {
public:
	void push(T&&);
	T pop();

public:
	safe_queue();
	~safe_queue();
	bool empty();

private:
	std::mutex m_mutex;
	std::queue<T> m_queue;
	std::condition_variable m_cv;
};

template<class T>
inline void safe_queue<T>::push(T&& elem)
{
	std::unique_lock<std::mutex> lk{ m_mutex };

	m_queue.push(std::move(elem));

	lk.unlock();

	m_cv.notify_one();
}

template<class T>
inline T safe_queue<T>::pop()
{
	std::unique_lock<std::mutex> lk{ m_mutex };

	m_cv.wait(lk, [&](){return m_queue.size() > 0; });

	T ret = std::move(m_queue.front()); m_queue.pop();

	return ret;
}

template<class T>
inline bool safe_queue<T>::empty()
{
	std::lock_guard<std::mutex> lk(m_mutex);
	return m_queue.empty();
}

template<class T>
inline safe_queue<T>::safe_queue()
{
}

template<class T>
inline safe_queue<T>::~safe_queue()
{

}