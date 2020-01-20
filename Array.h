#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <class T>
class Array
{
	int phySize, logSize;
	char delimeter;
	T* arr;
public:
	Array(int size=1,char delimeter =',');
	Array(const Array& other);
	~Array();
	
	const Array& operator=(const Array&other);
	const Array&operator+=(const T& newVal);
	int getSize() const { return logSize; };

	T& operator[](int i);
	const T& operator[](int i) const {return arr[i];}
	friend ostream& operator<<(ostream& os, const Array& arr) {
		for (int i = 0; i < arr.logSize; i++) {
			os << arr.arr[i] << arr.delimeter;
		}
		return os;
	}
};

template <class T>
T& Array<T>::operator[](int i) {
	return arr[i];
}
template <class T>
Array<T>::Array(int size, char delimeter) {
	this->delimeter = delimeter;
	phySize = size;
	logSize = 0;
	arr = new T[phySize];
}

template <class T>
Array <T>::Array(const Array& other):arr(NULL) {
	*this = other;

}

template <class T>
Array<T>::~Array() {
	delete[] arr;
}

template <class T>
const Array<T>& Array<T>::operator=(const Array<T>&other)
{
	if (this != &other) {
		delete[]arr;
		phySize = other.phySize;
		logSize = other.logSize;
		delimeter = other.delimeter;
		arr = new T[phySize];
		for (int i = 0; i < logSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <class T>
const Array<T>&Array<T>::operator+=(const T& newVal)
{
	if (logSize >= phySize) {
		phySize *= 2;
		T* newArr = new T[phySize];
		for (int i = 0; i < logSize; i++)
			newArr[i] = arr[i];
		delete[] arr;
		arr = newArr;
	}
	arr[logSize++] = newVal;
	return *this;
}
#endif