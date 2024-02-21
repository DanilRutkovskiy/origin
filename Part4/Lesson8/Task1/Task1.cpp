#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int** make_empty_graph(int N) {
	int** ret = new int* [N];

	for (int i = 0; i < N; i++)
		ret[i] = new int[N];

	return ret;
}

void delete_graph(int** graph, int N) {
	for (int i = 0; i < N; i++)
		delete[] graph[i];

	delete[] graph;
}

void print_orgraph(int** og, int N) {
	std::cout << "Orgraph text interpretation:" << std::endl;
	for (int row = 0; row < N; row++) {
		bool printed = false;
		std::cout << row + 1 << ": ";
		for (int col = 0; col < N; col++) {
			if (og[row][col] == 1) {
				std::cout << col + 1 << " ";
				printed = true;
			}
		}

		if (!printed)
			std::cout << "No";
		
		std::cout<< std::endl;
	}
}

int main()
{
	std::ifstream inFile{ "input.txt" };

	if (inFile.is_open()) {
		std::string str{ "" };
		std::getline(inFile, str);
		int N = std::stoi(str);
		int** graph = make_empty_graph(N);

		int g_row = 0;
		while (!inFile.eof()) {
			int g_col = 0;
			std::getline(inFile, str);
			for (int i = 0; i < str.size(); i++) {
				if (str[i] >= '0' && str[i] <= '9') {
					graph[g_row][g_col] = str[i] - '0';
					++g_col;
				}
			}
			++g_row;
		}

		print_orgraph(graph, N);

		delete_graph(graph, N);
	}
	else {
		std::cout << "Can't open input file" << std::endl;
		return 1;
	}

	return 0;
}