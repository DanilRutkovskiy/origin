#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>

int main() {
	std::atomic<int> max_clients = 10000;
	std::atomic<int> client_count = 0;
	std::atomic<int> total_client_count = 0;

	std::mutex gMutex;

	auto f_t1 = [&]() {
			while (max_clients.load() > 0) {
				gMutex.lock();
				std::cout << "New client arrived! Current client count: " << client_count.load() << std::endl;
				gMutex.unlock();
				--max_clients;
				++client_count;
				++total_client_count;
			}
		};

	std::thread t1{ std::ref(f_t1) };
	std::thread t3{ std::ref(f_t1) };
	std::thread t5{ std::ref(f_t1) };

	auto f_t2 = [&]() {
		while (max_clients.load() > 0 || client_count.load() > 0) {
			if (client_count.load() > 0) {
				gMutex.lock();
				std::cout << "Client got serviced! Current client count: " << client_count.load() << std::endl;
				gMutex.unlock();
				--client_count;
			}
		}
		};

	std::thread t2{ std::ref(f_t2) };
	std::thread t4{ std::ref(f_t2) };


	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	std::cout << "Total served client count: " << total_client_count;

	return 0;
}