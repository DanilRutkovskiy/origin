#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void sum_range(int& ret, std::vector<int>& v1, std::vector<int>& v2, int l_ind, int el_count) {
	for (int i = 0; i < el_count; i++) {
		ret += v1[l_ind + i];
		ret += v2[l_ind + i];
	}
}

double sum(std::vector<int>& v1, std::vector<int>& v2, int thread_count, int sum_count) {
	int sum = 0;
	int range_step = sum_count / thread_count;
	const auto start_time{ std::chrono::steady_clock::now() };
	switch (thread_count)
	{
	case 1:
	{
		std::thread t1{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), 0, sum_count };
		t1.join();
		break;
	}
	case 2:
	{
		std::thread t1{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), 0, range_step };
		std::thread t2{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step, sum_count - range_step };
		t1.join();
		t2.join();
		break;
	}
	case 4:
	{
		std::thread t1{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), 0, range_step };
		std::thread t2{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step, range_step };
		std::thread t3{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 2, range_step };
		std::thread t4{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 3, sum_count - range_step * 3 };
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		break;
	}
	case 8:
	{
		std::thread t1{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), 0, range_step };
		std::thread t2{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step, range_step };
		std::thread t3{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 2, range_step };
		std::thread t4{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 3, range_step };
		std::thread t5{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 4, range_step };
		std::thread t6{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 5, range_step };
		std::thread t7{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 6, range_step };
		std::thread t8{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 7, sum_count - range_step * 7 };
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		break;
	}
	case 16:
	{
		std::thread t1{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), 0, range_step };
		std::thread t2{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step, range_step };
		std::thread t3{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 2, range_step };
		std::thread t4{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 3, range_step };
		std::thread t5{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 4, range_step };
		std::thread t6{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 5, range_step };
		std::thread t7{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 6, range_step };
		std::thread t8{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 7, range_step };
		std::thread t9{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 8, range_step };
		std::thread t10{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 9, range_step };
		std::thread t11{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 10, range_step };
		std::thread t12{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 11, range_step };
		std::thread t13{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 12, range_step };
		std::thread t14{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 13, range_step };
		std::thread t15{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 14, range_step };
		std::thread t16{ sum_range,std::ref(sum), std::ref(v1), std::ref(v2), range_step * 15, sum_count - range_step * 15 };
		t1.join(); t2.join(); t3.join(); t4.join(); t5.join(); t6.join(); t7.join(); t8.join();
		t9.join(); t10.join(); t11.join(); t12.join(); t13.join(); t14.join(); t15.join(); t16.join();
		break;
	}
	default:
		break;
	}

	const auto end_time{ std::chrono::steady_clock::now() };
	const auto elapsed_time = std::chrono::duration<double>(end_time - start_time).count();

	return elapsed_time;
}

int main() {
	int core_count = std::thread::hardware_concurrency();

	std::cout << "Hardware core count: " << core_count << std::endl;

	std::cout << "\t\t1000\t\t10000\t\t100000\t\t1000000\n";

	std::vector<int> v1;
	std::vector<int> v2;
	v1.resize(1000000);
	v2.resize(1000000);


	std::cout << "1 thread: \t";
	std::cout << sum(v1, v2, 1, 1000) <<"\t";
	std::cout << sum(v1, v2, 1, 10000) << "\t";
	std::cout << sum(v1, v2, 1, 100000) << "\t";
	std::cout << sum(v1, v2, 1, 1000000) << "\n";
	std::cout << "2 threads: \t";
	std::cout << sum(v1, v2, 2, 1000) << "\t";
	std::cout << sum(v1, v2, 2, 10000) << "\t";
	std::cout << sum(v1, v2, 2, 100000) << "\t";
	std::cout << sum(v1, v2, 2, 1000000) << "\n";
	std::cout << "4 threads: \t";
	std::cout << sum(v1, v2, 4, 1000) << "\t";
	std::cout << sum(v1, v2, 4, 10000) << "\t";
	std::cout << sum(v1, v2, 4, 100000) << "\t";
	std::cout << sum(v1, v2, 4, 1000000) << "\n";
	std::cout << "8 threads: \t";
	std::cout << sum(v1, v2, 8, 1000) << "\t";
	std::cout << sum(v1, v2, 8, 10000) << "\t";
	std::cout << sum(v1, v2, 8, 100000) << "\t";
	std::cout << sum(v1, v2, 8, 1000000) << "\n";
	std::cout << "16 threads: \t";
	std::cout << sum(v1, v2, 16, 1000) << "\t";
	std::cout << sum(v1, v2, 16, 10000) << "\t";
	std::cout << sum(v1, v2, 16, 100000) << "\t";
	std::cout << sum(v1, v2, 16, 1000000) << "\n";
	return 0;
}