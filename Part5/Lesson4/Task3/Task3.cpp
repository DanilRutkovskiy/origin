#include <iostream>
#include <vector>

class Counter {
public:
    int get_sum();
    int get_count();
public:
    Counter();
public:
    void operator() (std::vector<int> vec);
private:
    int m_sum;
    int m_count;
};

int main()
{
    Counter a;
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    a(vec);
    std::cout << "get_sum: " << a.get_sum() << std::endl
        << "get_count: " << a.get_count();
}

int Counter::get_sum()
{
    return m_sum;
}

int Counter::get_count()
{
    return m_count;
}

Counter::Counter()
{
    m_sum = 0;
    m_count = 0;
}

void Counter::operator() (std::vector<int> vec)
{
    m_sum = 0;
    m_count = 0;
    for (auto elem : vec) {
        if (elem % 3 == 0) {
            m_sum += elem;
            m_count++;
        }
    }
}