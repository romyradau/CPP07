#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
// void	iter(T const* arr_address, sizeof(T const*) len,  void *funcPtr(T))
void	iter(T const* arr_address, int len,  void *funcPtr(T))

//		iter(char const* arr_addrass, sizeof(char const*), generic_f(char))
//		iter(std::string* arr_address, sizeof(std::string *), geberic_f(std::string))
{
	for (int i = 0; i < len; i++){
		funcPtr(arr_address[i]);
	}
}

template<typename T>
void	calc_len(T){
	std::cout << sizeof(T) << std::endl;
}
#endif