#pragma once

#include <string> //for size_t
#include <iostream>

template<typename T_arr, typename T_func>
void iter(T_arr *addr, size_t const len, T_func fun){
    for(size_t i = 0; i < len; i++){
        fun(addr[i]);
    }
}
