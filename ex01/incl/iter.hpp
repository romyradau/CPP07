#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T* arr_address, int len,  void (*funcPtr)(T&))
{
	if (!arr_address || !funcPtr)
		return ;
	for (int i = 0; i < len; i++){
		funcPtr(arr_address[i]);
	}
}

template<typename T>
void	calc_len(T& thing){
	std::cout << sizeof(thing) << std::endl;
}
#endif

template<typename T>
void	cast_stuff(T& thing){
	std::cout << "castValue:" << static_cast<char>(thing) << std::endl;

}