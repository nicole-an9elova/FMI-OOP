#pragma once

//Impl + 10.7,10.8,10.9
template<class T>
class Vector
{
public:
	Vector();
	Vector(size_t nCapacity);
	template<class Type>
	Vector(size_t nCapacity, const Type& defaultVal);
	Vector(const Vector<T>& other);
	Vector<T>& operator= (const Vector<T>& other);
	~Vector();

	Vector<T> operator+ (const Vector<T>& other) const;
	Vector<T>& operator+= (const Vector<T>& other);
	T& operator[] (size_t i);
	T operator[] (size_t i) const;
	void push(const T& x);
	void push_back(const T& x);
	void print();
	size_t size() const;

	void resizeDecrease();
	void resizeIncrease();
	Vector<T>& resize(size_t n);

	Vector<Vector<T>> slice(size_t n);

	void copy(const Vector<T>& other);
private:
	T* elements;
	size_t nCapacity;
};


