#include <iostream>
#include <vector>
#include <thread>
#include <future>

void findMinInd(std::promise<int> value ,const std::vector<int>& vec, int start_ind = 0) {
	int min = vec[start_ind];
	int ret = start_ind;

	for (int i = start_ind; i < vec.size(); i++) {
		if (min > vec[i]) {
			min = vec[i];
			ret = i;
		}	
	}

	value.set_value(ret);
}

int main() {
	std::vector<int> vec{ 4, 2, 5, 7, 4, 3, 2, 1, 5, 6 };
	std::cout << "Start vec: ";
	for (const auto& elem : vec)
		std::cout << elem << " ";

	for (int i = 0; i < vec.size(); i++) {
		std::promise<int> value;
		std::future<int> futureValue{ value.get_future() };
		std::thread asyncThread{findMinInd, std::move(value), std::ref(vec), i};
		asyncThread.detach();

		int minInd = futureValue.get();
		std::swap(vec[i], vec[minInd]);
	}

	std::cout << "After sort vec: ";
	for (const auto& elem : vec)
		std::cout << elem << " ";
	
	return 0;
}