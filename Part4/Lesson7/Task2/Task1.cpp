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

void width_first_traversal(int** graph, int N, int start_ind) {
	std::queue<int> q;
	q.push(start_ind - 1);
	int* checked_vertexes = new int[N];
	for (int i = 0; i < N; i++)
		checked_vertexes[i] = 0;

	std::cout << "Vertexes traversal order: ";

	while (!q.empty()) {
		int vertex = q.front(); q.pop();

		std::cout << vertex + 1 << " ";

		checked_vertexes[vertex] = 1;

		for (int i = 0; i < N; i++) {
			if (graph[vertex][i] == 1 && checked_vertexes[i] == 0) {
				q.push(i);
				checked_vertexes[i] = 1;
			}
				
		}
	}

	delete[] checked_vertexes;
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

		int start_ind;
		std::cout << "Enter start ind from 1 to " << N << ": ";
		std::cin >> start_ind;
		if (start_ind < 1 || start_ind > N) {
			std::cout << "Can't start at that index!";
		}
		else {
			width_first_traversal(graph, N, start_ind);
		}

		delete_graph(graph, N);
	}
	else {
		std::cout << "Can't open input file" << std::endl;
		return 1;
	}

	return 0;
}