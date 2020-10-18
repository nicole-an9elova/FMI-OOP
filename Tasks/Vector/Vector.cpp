#pragma once
#include "Vector.h"
#include <iostream>
#include <stdexcept>

//Impl + 10.7,10.8,10.9
template <class T>
Vector<T>::Vector()
{
    nCapacity = 0;
    elements = nullptr;
}

template<class T>
template<class Type>
Vector<T>::Vector(size_t defCapacity, const Type& defaultVal)
{
    elements = nullptr;
    nCapacity = 0;
    for (size_t i = 0; i < defCapacity; i++) {
        push_back(T(defaultVal));
    }
}

template<class T>
Vector<T>::Vector(size_t nCapacity)
{
    this->elements = new T[nCapacity];
    this->nCapacity = nCapacity;
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other) {
        delete[] elements;
        copy(other);
    }
    return *this;
}

template<class T>
Vector<T>::~Vector()
{
    delete[] elements;
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
    Vector<T> result; 
    result.elements = new T[this->nCapacity + other.nCapacity];
    for (size_t i = 0; i < this->nCapacity; i++) {
        result.elements[i] = this->elements[i];
    }
    for (size_t j = 0; j < other.nCapacity; j++) {
        result.elements[this->nCapacity + j] = other.elements[j];
    }
    result.nCapacity = this->nCapacity + other.nCapacity;
    return result;
}

template<class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
    T* biggerBuffer = new T[this->nCapacity + other.nCapacity];
    for (size_t i = 0; i < this->nCapacity; i++) {
        biggerBuffer[i] = this->elements[i];
    }
    for (size_t j = 0; j < other.nCapacity; j++) {
        biggerBuffer[this->nCapacity + j] = other.elements[j];
    }
    delete[] this->elements;
    this->elements = biggerBuffer;
    this->nCapacity = this->nCapacity + other.nCapacity;
    return *this;
}

template<class T>
T& Vector<T>::operator[](size_t i)
{
    if (i >= nCapacity)
        throw std::out_of_range("Index out of bounds!");
    return elements[i];
}

template<class T>
T Vector<T>::operator[](size_t i) const
{
    if (i >= nCapacity)
        throw std::out_of_range("Index out of bounds!");
    return elements[i];
}

template<class T>
void Vector<T>::push(const T& x)
{   
    T* biggerBuffer = new T[nCapacity + 1];
    for (size_t i = 0; i < nCapacity; i++) {
        biggerBuffer[i + 1] = this->elements[i];
    }
    biggerBuffer[0] = x;
    ++nCapacity;
    delete[] elements;
    elements = biggerBuffer;
}

template<class T>
void Vector<T>::push_back(const T& x)
{
    T* biggerBuffer = new T[nCapacity + 1];
    for (size_t i = 0; i < nCapacity; i++) {
        biggerBuffer[i] = elements[i];
    }
    biggerBuffer[nCapacity] = x;
    ++nCapacity;
    delete[] elements;
    elements = biggerBuffer;
}

template<class T>
void Vector<T>::print()
{
    std::cout << "--The Vector--" << std::endl;
    for (size_t i = 0; i < this->nCapacity; i++) {
        std::cout << this->elements[i] << "  ";
    }
    std::cout << std::endl;
}

template<class T>
size_t Vector<T>::size() const
{
    return nCapacity;
}

template<typename T>
void Vector<T>::resizeDecrease()
{
    size_t orig = this->nCapacity;
    this->nCapacity /= 2;
    T* smallerBuff = new T[nCapacity];
    if (orig % 2 == 1) {
        for (size_t i = 0; i < nCapacity; i++) {
            smallerBuff[i] = elements[nCapacity + 1 + i];
        }
    }
    else {
        for (size_t i = 0; i < nCapacity; i++) {
            smallerBuff[i] = elements[nCapacity + i];
        }
    }
    delete[] elements;
    elements = smallerBuff;
}

template<typename T>
void Vector<T>::resizeIncrease()
{
    this->nCapacity *= 2;
    T* biggerBuffer = new T[nCapacity];
    for (size_t i = 0; i < nCapacity; i++) {
        biggerBuffer[i] = elements[i];
    }
    delete[] elements;
    elements = biggerBuffer;
}

template<typename T>
Vector<T>& Vector<T>::resize(size_t n)
{
    T* buffer = new T[n];
    for (size_t i = 0; i < nCapacity; i++) {
        buffer[i] = elements[i];
    }
    delete[] elements;
    elements = buffer;
    nCapacity = n;
    return *this;
}

template<typename T>
Vector<Vector<T>> Vector<T>::slice(size_t n)
{
    size_t help = 0;
    size_t numOfEl;

    if (nCapacity % n == 0)
        numOfEl = nCapacity / n;
    else
        numOfEl = (nCapacity / n) + 1;

    Vector<Vector<T>> result(numOfEl);

    for (size_t i = 0; i < numOfEl; i++) {
        result[i].resize(n);
    }
    for (size_t i = 0; i < numOfEl ; i++) {
        for (size_t j = 0; j < n; j++) {
            result[i][j] = elements[i + j + help];
        }
        help += 2;
    }

    //for visualization purposes
    for (size_t k = 0; k < numOfEl; k++) {
        result[k].print();
    }
 
    return result;
}

template<class T>
void Vector<T>::copy(const Vector<T>& other)
{
    this->nCapacity = other.nCapacity;
    this->elements = new T[other.nCapacity];
    for (size_t i = 0; i < other.nCapacity; i++) {
        this->elements[i] = other.elements[i];
    }
}