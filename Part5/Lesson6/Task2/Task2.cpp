#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <list>

template<typename Iterator>
void print_container(Iterator begin, Iterator end) {
	while (begin != end) {
		std::cout << *begin << " ";
		std::advance(begin, 1);
	}
}

int main()
{
	std::vector<int> vec{1, 2, 3, 4, 5} ;
	std::cout << "Vector: ";
	print_container(vec.begin(), vec.end());

	std::set<int> set{ 5, 4, 3, 2, 1 };
	std::cout << std::endl << "Set: ";
	print_container(set.begin(), set.end());

	std::list<int> list{ 4, 7, 8, 9, 112 };
	std::cout << std::endl << "List: ";
	print_container(list.begin(), list.end());
	return 0;
}