#include <iostream>
#include <vector>
#include "MyUniquePtr.hpp"

class Test {
public:
    Test(int val) : m_field{val} { std::cout << "Test constructor" << "\n"; };
    ~Test() { std::cout << "Test destructor" << "\n"; };
public:
    int m_field;
};

int main()
{
    MyUniquePtr<Test> ptr1{ new Test(1) };
    std::cout << "ptr1 m_field =" << (*ptr1).m_field << "\n";
    MyUniquePtr<Test> ptr2{ new Test(2) };
    std::cout << "ptr2 m_field =" << ptr2->m_field << "\n";
    auto released_ptr = ptr2.release();

    return 0;
}