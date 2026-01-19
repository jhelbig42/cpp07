
#include "iter.hpp"

void increment(int &i){
    i++;
}

void decrement2(int &i){
    i = i - 2;
}

void capitalize(std::string &str){
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
}

void print_int(int a){
    std::cout << a << " ";
}

void print_string(std::string a){
    std::cout << a << " ";
}

int main(void){
    int arr1[] = {7, 11, 13, 1001, 77};
    ::iter(arr1, 5, increment);
    ::iter(arr1, 5, print_int);
    std::cout << std::endl;
    ::iter(arr1, 5, decrement2);
    ::iter(arr1, 5, print_int);
    std::cout << std::endl;

    std::string arr2[] ={"hi", "there", "why", "?"};
    ::iter(arr2, 4, capitalize);
    ::iter(arr2, 4, print_string);
    std::cout << std::endl;
}