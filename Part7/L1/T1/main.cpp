#include <iostream>
#include <thread>
#include <chrono>

int main() {
	int max_clients = 10;
	int client_count = 0;

	auto f_t1 = [&]() {
			while (max_clients > 0) {
				std::cout << "New client arrived! Current client count: " << client_count << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				--max_clients;
				++client_count;
			}
		};

	std::thread t1{std::ref(f_t1)};

	auto f_t2 = [&]() {
		while (max_clients > 0 || client_count > 0) {
			if (client_count > 0) {
				std::cout << "Client got serviced! Current client count: " << client_count << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				--client_count;

			}
		}
		};

	std::thread t2{ std::ref(f_t2) };

	t1.join();
	t2.join();

	return 0;
}