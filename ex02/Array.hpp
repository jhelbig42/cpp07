#pragma once
#include <string>

// array of T can just be initialized as a pointer, not as T[]

template<typename T>
class Array{
    private:
        unsigned int    _size;
        T               *_arr;
    public:
        Array( void );
        Array( unsigned int size);
        Array( const Array &other);
        Array& operator=( const Array &other );
        ~Array( void );
        
        T& operator[]( size_t idx ) const ;
        
        unsigned int size( void ) const;

        class InvalidIndexException : public std::exception{
            public:
                virtual const char *what() const throw();
        };
};

#include "Array.tpp"