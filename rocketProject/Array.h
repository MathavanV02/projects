#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <typename T>
class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		Array& add(T);
		Array& remove(T);
		
		int getSize() const;
		bool isFull() const;

		Array& operator+=(const T&);
		Array& operator-=(const T&);
		T& operator[](int);
		const T& operator[](int) const;
	private:
		int numElements;
		T* elements;
	
};
template <typename T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

template <typename T>
Array<T>::~Array(){
	delete [] elements;
}

template <typename T>
Array<T>& Array<T>::add(T t){
	if (numElements >= MAX_ARR)   return *this;
  	elements[numElements++] = t;
	return *this;
}

template <typename T>
Array<T>& Array<T>::remove(T t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

template <typename T>
int Array<T>::getSize() const{
	return numElements;
}
template <typename T>
bool Array<T>::isFull() const {
	return numElements >= MAX_ARR;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
Array<T>& Array<T>::operator+=(const T& t) {
    if (numElements >= MAX_ARR) return *this;
    elements[numElements++] = t;
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(const T& t) {
    int index = 0;
    while (index < numElements) {
        if (t == elements[index]) {
            --numElements;
            break;
        }
        ++index;
    }
    while (index < numElements) {
        elements[index] = elements[index + 1];
        ++index;
    }
    return *this;
}

#endif