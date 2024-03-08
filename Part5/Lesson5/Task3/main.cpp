#include <iostream>
#include <exception>

template <class T>
class Vector {
public:
	Vector();
	~Vector();

public:
	T& at(size_t ind);
	void push_back(T val);
	size_t size();
	size_t capasity();
	T& operator[](size_t ind);

private:
	T* m_data;
	size_t m_used_size;
	size_t m_actual_size;
};

int main() {

	Vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);

	std::cout << "Current size: " << vec.size() << std::endl;
	std::cout << "Current capacity: " << vec.capasity() << std::endl;

	std::cout << "Current vector: ";
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";

	std::cout << std::endl;
	
	try {
		vec.at(25);
	}
	catch (std::out_of_range ex) {
		std::cout << ex.what();
	}

	return 0;
}

template<class T>
Vector<T>::Vector()
{
	m_used_size = 0;
	m_actual_size = 1;

	m_data = new T[1];
}

template<class T>
Vector<T>::~Vector()
{
	delete[] m_data;
}

template<class T>
T& Vector<T>::at(size_t ind)
{
	if (ind >= m_used_size || ind < 0)
		throw std::out_of_range{"Index out of bounds"};
		

	return m_data[ind];
}

template<class T>
void Vector<T>::push_back(T val)
{
	if (m_used_size == m_actual_size) {
		m_actual_size *= 2;
		T* temp = new T[m_actual_size];
		for (size_t i = 0; i < m_used_size; i++)
			temp[i] = m_data[i];

		delete[] m_data;
		m_data = temp;
	}

	m_data[m_used_size++] = val;
}

template<class T>
size_t Vector<T>::size()
{
	return m_used_size;
}

template<class T>
size_t Vector<T>::capasity()
{
	return m_actual_size;
}

template<class T>
T& Vector<T>::operator[](size_t ind)
{
	return m_data[ind];
}