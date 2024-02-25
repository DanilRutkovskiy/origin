#include <iostream>
#include <stdexcept>

class Array {
public:
    Array(size_t size);
    Array(size_t size, int start_value);
    Array(const Array& arr);
    ~Array();

public:
    void push_back(int elem);
    int get_elem(size_t ind);

public:
    void operator=(const Array& arr);

private:
    size_t m_valid_size;
    size_t m_real_size;
    int* m_arr;
};

Array::Array(size_t size) : m_valid_size(0), m_real_size(size)
{
    m_arr = new int[size];
}

Array::Array(size_t size, int start_value) : m_valid_size(0), m_real_size(size)
{
    m_arr = new int[size];

    for (int i = 0; i < size; i++) {
        m_arr[i] = start_value;
        ++m_valid_size;
    }
}

Array::Array(const Array& arr)
{
    m_valid_size = arr.m_valid_size;
    m_real_size = arr.m_real_size;

    m_arr = new int[m_real_size];

    for (int i = 0; i < m_valid_size; i++)
        m_arr[i] = arr.m_arr[i];
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

void Array::operator=(const Array& arr)
{
    if (m_arr != nullptr)
        delete[] m_arr;

    m_valid_size = arr.m_valid_size;
    m_real_size = arr.m_real_size;

    m_arr = new int[m_real_size];

    for (int i = 0; i < m_valid_size; i++)
        m_arr[i] = arr.m_arr[i];
}

int main()
{
    Array arr1{ 5, 1 };
    Array arr2{ 10, 2 };

    arr1 = arr2;

    return 0;
}
