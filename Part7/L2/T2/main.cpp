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
#include <Windows.h>

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

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
		current_cursor_pos = copy.current_cursor_pos;
	}
	int thread_num;
	std::thread::id id;
	int calculated_dist;
	bool is_done;
	bool is_error;
	double calculation_time;
	int calculation_length;
	std::mutex* mutex;
	COORD current_cursor_pos;
};

void calculate(ThreadParams& params) {
	const auto start_time{ std::chrono::steady_clock::now() };
	{
		std::lock_guard<std::mutex>lg(*params.mutex);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), params.current_cursor_pos);
		params.id = std::this_thread::get_id();
		std::cout << params.id << "\t";
		params.current_cursor_pos = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	}
	
	auto gen = std::bind(std::uniform_real_distribution<>(0, 1.000001), std::default_random_engine());
	int progress = 0;
	int prev_progress = 0;
	
	while (params.calculated_dist != params.calculation_length) {
		params.calculated_dist = params.calculated_dist + 1;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		for (int i = 0; i < 100000; i++) {
			bool b_err = gen() >= 1;
			if (b_err)
				params.is_error = true;
		}

		int progress = (params.calculated_dist * 10 / params.calculation_length);
		if (prev_progress < progress) {
			std::lock_guard<std::mutex>lg(*params.mutex);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), params.current_cursor_pos);
			if (params.is_error)
				std::cout << dye::red("*");
			else
				std::cout << dye::aqua("*");
			params.current_cursor_pos = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
			
		}
			
		int prev_progress = progress;
	}

	const auto stop_time{ std::chrono::steady_clock::now() };
	params.calculation_time = std::chrono::duration<double>(stop_time - start_time).count();

	{
		std::lock_guard<std::mutex>lg(*params.mutex);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), params.current_cursor_pos);
		std::cout << "\t" << params.calculation_time;
	}

	params.is_done = true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int thread_count, calc_length, thread_num = 0;

	std::cout << "Enter thread count: ";
	std::cin >> thread_count;

	std::cout << "Enter calculation length: ";
	std::cin >> calc_length;

	std::mutex mutex;
	std::cout << "#\tid\tProgress Bar\tTime";
	std::vector<ThreadParams> thread_params_vec;
	for (int i = 0; i < thread_count; i++) {
		std::cout << "\n";
		ThreadParams temp;
		temp.thread_num = i;
		temp.calculation_length = calc_length;
		temp.mutex = &mutex;
		std::cout << i + 1 << "\t";
		temp.current_cursor_pos = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
		thread_params_vec.push_back(temp);
	}
	
	std::vector<std::thread> thread_vec;
	for (auto& th : thread_params_vec) {
		thread_vec.emplace_back(calculate, std::ref(th));
		thread_vec.back().detach();
	}
	
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

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

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), thread_params_vec.back().current_cursor_pos);
	
	return 0;
}