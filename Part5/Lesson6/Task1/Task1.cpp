#include <iostream>
#include <vector>
#include <map>

template <typename T>
void remove_dublicates(std::vector<T>& vec) {
	std::map<T, int> map;

	for (const auto& elem : vec)
		map[elem]++;

	vec.clear();

	vec.reserve(map.size());
	
	for (const auto& elem : map)
		vec.push_back(elem.first);
}


int main()
{
	std::vector<int> vec{ 1,1,2,3,4,5,6,4,6,7 };

	std::cout << "Initial vector: ";
	for (const auto& elem : vec)
		std::cout << elem << " ";

	remove_dublicates(vec);

	std::cout << std::endl;

	std::cout << "After removing dublicates: ";
	for (const auto& elem : vec)
		std::cout << elem << " ";
}