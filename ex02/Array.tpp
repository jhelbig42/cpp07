#pragma once

#include "Array.hpp"
#include <iostream>

template<typename T>
Array<T>::Array( void ) : _size(0), _arr(NULL){

}

template<typename T>
Array<T>::Array( unsigned int size) : _size(size), _arr(NULL){
    if (size > 0)
        _arr = new T[this->_size](); // all values initialized with 0 - whatever that means
}

template<typename T>
Array<T>::Array( const Array &other ) : _size(other._size), _arr(new T[other._size]) {
    std::cout << "copy constructor called" << std::endl;
    for (unsigned int i = 0; i < _size; i++){
        _arr[i] = other._arr[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=( const Array &other ){
    if (this != &other){
        if (this != NULL)
            delete this->_arr;
        this->_size = other._size;
        this->_arr = new T[this->_size];
        for (unsigned int i = 0; i < _size; i++){
            this->_arr[i] = other._arr[i];
        }
    }
    return (*this);
}

template<typename T>
Array<T>::~Array( void ){
    delete[] (this->_arr);
}

template<typename T>
T& Array<T>::operator[]( unsigned int idx ) const {
    if (idx >= this->_size)
        throw Array<T>::InvalidIndexException();
    return (this->_arr[idx]);
}

template<typename T>
unsigned int Array<T>::size( void ) const{
    return(this->_size);
}

template<typename T>
const char *Array<T>::InvalidIndexException::what() const throw(){
    return ("Invalid Index Exception");
}