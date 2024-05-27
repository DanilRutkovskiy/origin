#include <iostream>
#include "thread_pool.h"

void f1() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << __FUNCTION__ << std::endl;
}

void f2(int a, int b) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1900));
	std::cout << __FUNCTION__ << " res = " << a + b << std::endl;
}

int main() {
	thread_pool p;

	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::packaged_task<void()> task1(std::bind(f1));
		p.submit(std::move(task1));
		std::packaged_task<void()> task2(std::bind(f2, 3, 4));
		p.submit(std::move(task2));
	}

	return 0;
}