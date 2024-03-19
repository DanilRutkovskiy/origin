template<class T>
class MyUniquePtr {
public:
	MyUniquePtr(T* ptr);
	~MyUniquePtr();

public:
	T* release();

public:
	T& operator*();
	T* operator->();

public:
	MyUniquePtr(const MyUniquePtr&) = delete;
	void operator=(const MyUniquePtr&) = delete;

private:
	T* m_ptr;
};

template<class T>
inline MyUniquePtr<T>::MyUniquePtr(T* ptr)
{
	m_ptr = ptr;
}

template<class T>
inline MyUniquePtr<T>::~MyUniquePtr()
{
	if(m_ptr != nullptr)
		delete m_ptr;
}

template<class T>
inline T* MyUniquePtr<T>::release()
{
	m_ptr = nullptr;
	return m_ptr;
}

template<class T>
inline T& MyUniquePtr<T>::operator*()
{
	return *m_ptr;
}

template<class T>
inline T* MyUniquePtr<T>::operator->()
{
	return m_ptr;
}
