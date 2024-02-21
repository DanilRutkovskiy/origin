#include <iostream>
#include <fstream>
#include <string>
#include <list>

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

void dfs(int** graph, int N, int vertex, int* visited, std::list<int>& order) {
	visited[vertex] = 1;

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0 && graph[vertex][i] == 1)
			dfs(graph, N, i, visited, order);
	}

	order.push_front(vertex);
}

std::list<int> top_sort(int** graph, int N) {
	std::list<int> order;
	int* visited = new int[N];

	for (int i = 0; i < N; i++)
		visited[i] = 0;

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0)
			dfs(graph, N, i, visited, order);
	}

	return order;
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

		auto ret = top_sort(graph, N);
		
		std::cout << "Sorted graph: ";
		for (auto elem : ret)
			std::cout << elem + 1 << " ";

		delete_graph(graph, N);
	}
	else {
		std::cout << "Can't open input file" << std::endl;
		return 1;
	}

	return 0;
}