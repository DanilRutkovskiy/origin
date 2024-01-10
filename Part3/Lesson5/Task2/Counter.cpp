#include "Counter.hpp"

int Counter::get_count() {return m_count;}
Counter& Counter::operator++(int) { m_count++; return *this; }
Counter& Counter::operator--(int) { m_count--; return *this; }
Counter::Counter(int count) : m_count{ count } {};
Counter::Counter() :m_count{ 1 } {};