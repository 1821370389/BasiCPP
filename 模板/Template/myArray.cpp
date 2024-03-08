// MyArray.cpp
#include "myArray.hpp"

// template class MyArray<int>;
// template class MyArray<double>;

template<typename T>
MyArray<T>::MyArray(int size) : size(size) {
    data = new T[size];
}

template<typename T>
MyArray<T>::~MyArray() {
    delete[] data;
}

template<typename T>
T& MyArray<T>::operator[](int index) {
    return data[index];
}

template<typename T>
int MyArray<T>::getSize() const {
    return size;
}
