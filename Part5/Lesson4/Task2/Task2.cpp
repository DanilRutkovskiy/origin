#include <iostream>
#include <utility>

template <typename T>
class Table {
public:
    Table(size_t rows, size_t cols);
    ~Table();

public:
    std::pair<size_t, size_t> Size() const;

public:
    T* operator[] (size_t row);
    T* operator[] (size_t row) const;
private:
    size_t m_rows;
    size_t m_cols;

private:
    T** m_p_head;
};

template<typename T>
Table<T>::Table(size_t rows, size_t cols) : m_rows{rows}, m_cols{cols}
{
    m_p_head = new T*[rows];
    for (size_t i = 0; i < rows; i++)
        m_p_head[i] = new T[cols];

    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            m_p_head[row][col] = 0;
}

template<typename T>
Table<T>::~Table()
{
    for (int i = 0; i < m_rows; i++)
        delete[] m_p_head[i];

    delete[] m_p_head;
}

template<typename T>
std::pair<size_t, size_t> Table<T>::Size() const
{
    return std::make_pair(m_rows, m_cols);
}

template<typename T>
T* Table<T>::operator[](size_t row)
{
    return m_p_head[row];
}

template<typename T>
T* Table<T>::operator[](size_t row) const
{
    return m_p_head[row];
}

int main()
{
    Table<int> tbl{ 3, 5 };
    tbl[1][2] = 2;
    auto h = tbl[1][2];
    std::cout << tbl[1][2];
    return 0;
}