#include <iostream>
#include <stdexcept>

class Array {
public:
    Array(size_t size);
    ~Array();

public:
    void push_back(int elem);
    int get_elem(size_t ind);

private:
    size_t m_valid_size;
    size_t m_real_size;
    int* m_arr;
};

Array::Array(size_t size) : m_valid_size(0), m_real_size(size)
{
    m_arr = new int[size];
}

Array::~Array()
{
    delete[] m_arr;
}

void Array::push_back(int elem)
{
    if (m_valid_size == m_real_size) {
        m_real_size *= 2;
        int* new_arr = new int[m_real_size];
        for (size_t i = 0; i < m_valid_size; i++)
            new_arr[i] = m_arr[i];

        delete[] m_arr;

        m_arr = new_arr;
    }

    m_arr[m_valid_size++] = elem;
}

int Array::get_elem(size_t ind)
{
    if (ind >= 0 && ind < m_valid_size) {
        return m_arr[ind];
    }

    throw std::range_error{ "Index out of range" };
}

int main()
{
    try {
        Array arr(10);
        arr.push_back(1);
        arr.push_back(2);
        arr.push_back(3);
        arr.push_back(4);
        arr.push_back(5);
        arr.push_back(6);
        arr.push_back(7);
        arr.push_back(8);
        arr.push_back(9);
        arr.push_back(10);
        std::cout << arr.get_elem(5) << std::endl;
        std::cout << arr.get_elem(11) << std::endl;
    }
    catch (const std::range_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}
