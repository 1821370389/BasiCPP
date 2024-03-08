// MyArray.hpp

#ifndef MYARRAY_HPP
#define MYARRAY_HPP


template<typename T>
class MyArray {
private:
    T* data;
    int size;
public:
    MyArray(int size);
    ~MyArray();
    T& operator[](int index);
    int getSize() const;
};


#endif
