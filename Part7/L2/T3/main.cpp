#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <vector>

class Data {
public:
	Data(int data) :m_data{ data } {};
	int m_data;
	std::mutex m_mutex;
};

void swap1(Data& d1, Data& d2) {
	static std::mutex io_mutex;
	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "Swap 1 waiting to for locks" << "\n";
	}

	std::lock(d1.m_mutex, d2.m_mutex);
	std::lock_guard<std::mutex> lk1{ d1.m_mutex, std::adopt_lock };
	std::lock_guard<std::mutex> lk2{ d2.m_mutex, std::adopt_lock };

	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "Swap 1 ready to swap data" << "\n";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::swap(d1.m_data, d2.m_data);
}

void swap2(Data& d1, Data& d2) {
	static std::mutex io_mutex;
	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "Swap 2 waiting to for locks" << "\n";
	}
	std::scoped_lock lock(d1.m_mutex, d2.m_mutex);

	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "Swap 2 ready to swap data" << "\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::swap(d1.m_data, d2.m_data);
}

void swap3(Data& d1, Data& d2) {
	static std::mutex io_mutex;
	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "Swap 3 waiting to for locks" << "\n";
	}
	std::unique_lock<std::mutex> lk1(d1.m_mutex, std::defer_lock);
	std::unique_lock<std::mutex> lk2(d2.m_mutex, std::defer_lock);
	std::lock(lk1, lk2);

	{
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "Swap 3 ready to swap data" << "\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::swap(d1.m_data, d2.m_data);
}

int main() {
	Data d1{ 1 };
	Data d2{ 2 };

	std::vector<std::thread> thread_vec;

	thread_vec.emplace_back(swap1, std::ref(d1), std::ref(d2));
	thread_vec.emplace_back(swap2, std::ref(d1), std::ref(d2));
	thread_vec.emplace_back(swap3, std::ref(d1), std::ref(d2));

	for (auto& el : thread_vec)
		el.join();
}