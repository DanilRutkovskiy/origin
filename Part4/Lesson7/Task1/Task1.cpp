#include <iostream>
#include <fstream>
#include <string>

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

void deep_first_traversal_rec(int** graph, int N, int* checked_cells, int ind) {
	int work_ind = ind - 1;
	if (checked_cells[work_ind] == 0) {
		std::cout << ind << " ";
		checked_cells[work_ind] = 1;
	}

	for (int i = 0; i < N; i++) {
		if (graph[work_ind][i] == 1 && checked_cells[i] != 1)
			deep_first_traversal_rec(graph, N, checked_cells, i + 1);
	}
}

void deep_first_traversal(int** graph, int N) {
	int* checked_cells = new int[N];
	for (int i = 0; i < N; i++)
		checked_cells[i] = 0;

	std::cout << "Vectex traversal order: ";
	deep_first_traversal_rec(graph, N, checked_cells, 1);
	delete[] checked_cells;
}

int main()
{
	std::ifstream inFile{"input.txt"};

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
		deep_first_traversal(graph, N);

		delete_graph(graph, N);
	}
	else {
		std::cout << "Can't open input file" << std::endl;
		return 1;
	}

	return 0;
}