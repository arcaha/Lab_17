#include <iostream>
#include "Point.hpp"
#ifndef sorted_array_hpp
#define sorted_array_hpp

template <class T>
class Sorted_Array {
private: 
	T* array;
	size_t capacity;
	size_t size;
public:
	Sorted_Array();
	Sorted_Array(size_t capacity);
	Sorted_Array(const Sorted_Array& a);
	~Sorted_Array();
	T& operator=(const T& a);
	void push(T value);
	T at(int index);
	T erase(size_t index);
	void watch();
	T& operator[](size_t index);
};

template <class T>
Sorted_Array<T>::Sorted_Array() {
	size = 0;
	capacity = 1;
	array = new T[capacity];
}

template <class T>
Sorted_Array<T>::Sorted_Array(const Sorted_Array&a) {
	size = a.size;
	capacity = a.capacity;
	array = new T[capacity];
	for (size_t i = 0; i < capacity; i++) {
		array[i] = a.array[i];
	}
}

template <class T>
Sorted_Array<T>::Sorted_Array(size_t capacity) {
	this->capacity = capacity;
	array = new T[capacity];
}

template <class T>
Sorted_Array<T>::~Sorted_Array() { delete[] array; }

template <class T>
T& Sorted_Array<T>::operator=(const T& a) {
	if (this == &a) {
		return *this;
	}
	size = a.size;
	capacity = a.capacity;
	array = new T[capacity];
	for (size_t i = 0; i < capacity; i++) {
		array[i] = a.array[i];
	}
	return *this;
}


template <class T>
void Sorted_Array<T>::push(T value) {

	if (size == capacity) {
		throw 12;
	}
	array[size] = value;
	size++;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j + 1] < array[j]) {
				T temp;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

template <class T>
T Sorted_Array<T>::at(int index) {
	if (index >= capacity || index < 0) {
		throw 14;
	}
	return array[index];
}

template <class T>
T Sorted_Array<T>::erase(size_t index) {
	if (index < 0 || index > capacity) {
		throw 15;
	}
	for (int k = index; k < size - 1; k++) {
		array[k] = array[k + 1];
	}
	size--;
}

template <class T>
void Sorted_Array<T>::watch() {
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

template <class T>
T& Sorted_Array<T>::operator[](size_t index) {
	if (index < 0 || index > capacity) {
		throw 18;
	}
	return array[index];
}

#endif