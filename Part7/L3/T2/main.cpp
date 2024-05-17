#include <iostream>
#include <vector>
#include <thread>
#include <future>

void parallel_for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end, const std::function<void(int& n)>& func, int lvl = 1) {
	if (lvl < std::thread::hardware_concurrency() / 2) {
		++lvl;
		parallel_for_each(begin, begin + (end - begin) / 2, func, lvl);
		parallel_for_each(begin + (end - begin) / 2, end, func, lvl);
	}
	else {
		std::async(std::launch::async, [&begin, &end, &func]() {
			while (begin != end) {
				func(*begin);
				begin++;
			}});
	}	
}

int main() {
	std::vector<int> vec{ 1,2,3,4,5,6,7,8 };
	std::cout << "Vector before: ";
	for (auto elem : vec)
		std::cout << elem << " ";
	const auto func = [](int& n) {n++; };
	parallel_for_each(vec.begin(), vec.end(), func);
	std::cout << "Vector after: ";
	for (auto elem : vec)
		std::cout << elem << " ";
	return 0;
}