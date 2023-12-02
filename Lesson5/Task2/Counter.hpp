class Counter {
public:
	Counter();
	Counter(int count);
	Counter& operator++(int);
	Counter& operator--(int);
	int get_count();

private:
	int m_count;
};