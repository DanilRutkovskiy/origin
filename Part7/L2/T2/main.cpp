#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <vector>
#include "color.hpp"
#include <ctime>
#include <random>
#include <functional>

struct ThreadParams {
	ThreadParams() :thread_num{ 0 }, calculated_dist{ 0 }, is_done{ 0 }, 
		calculation_time{ 0 }, calculation_length{ 0 }, mutex{ nullptr }, is_error{ 0 } {};
	ThreadParams(const ThreadParams& copy) {
		thread_num = copy.thread_num;
		id = copy.id;
		calculated_dist = copy.calculated_dist;
		is_done = copy.is_done;
		is_error = copy.is_error;
		calculation_time = copy.calculation_time;
		calculation_length = copy.calculation_length;
		mutex = copy.mutex;
	}
	int thread_num;
	std::thread::id id;
	int calculated_dist;
	bool is_done;
	bool is_error;
	double calculation_time;
	int calculation_length;
	std::mutex* mutex;
};

void calculate(ThreadParams& params) {
	const auto start_time{ std::chrono::steady_clock::now() };
	
	params.id = std::this_thread::get_id();
	auto gen = std::bind(std::uniform_real_distribution<>(0, 1.000001), std::default_random_engine());

	while (params.calculated_dist != params.calculation_length) {
		params.calculated_dist = params.calculated_dist + 1;
		for (int i = 0; i < 100000; i++) {
			int a = 5;

			bool b_err = gen() >= 1;
			if (b_err)
				params.is_error = true;
		}
	}
	
	const auto stop_time{ std::chrono::steady_clock::now() };
	params.calculation_time = std::chrono::duration<double>(stop_time - start_time).count();
	params.is_done = true;
}

int main() {
	int thread_count, calc_length, thread_num = 0;

	std::cout << "Enter thread count: ";
	std::cin >> thread_count;

	std::cout << "Enter calculation length: ";
	std::cin >> calc_length;

	std::mutex mutex;
	std::vector<ThreadParams> thread_params_vec;
	for (int i = 0; i < thread_count; i++) {
		ThreadParams temp;
		temp.thread_num = i + 1;
		temp.calculation_length = calc_length;
		temp.mutex = &mutex;
		thread_params_vec.push_back(temp);
	}
	
	std::vector<std::thread> thread_vec;
	for (auto& th : thread_params_vec) {
		thread_vec.emplace_back(calculate, std::ref(th));
		thread_vec.back().detach();
	}

	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		system("cls");
		std::cout << "#\tid\tProgress Bar\tTime\n";

		for (const auto& el : thread_params_vec) {
			std::cout << el.thread_num << "\t" << el.id << "\t";

			int progress = (el.calculated_dist * 10 / el.calculation_length);
			for (int i = 0; i < progress; i++)
				if(el.is_error)
					std::cout << dye::red("*");
				else
					std::cout << dye::aqua("*");
			
			if (el.is_done)
				std::cout << "\t" << el.calculation_time;

			std::cout << "\n";
		}

		bool exit = true;
		for (const auto& el : thread_params_vec) {
			if (!el.is_done) {
				exit = false;
				break;
			}
		}

		if (exit)
			break;
	}
	
	return 0;
}