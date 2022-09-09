#ifndef WHATEVER_HPP
#define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T& a, T& b){

	T	tmp;
	tmp = a;
	a = b;
	b = tmp;

}
//this T is called generic data type
//this swap function i now a generic function
//can we also use class keyword instead of typename?
template<typename random>
random const& min( random const& x, random const& y){
	return (x>=y ? y : x);
}

template<typename T>
T const& max( T const& x, T const& y){
	return (x<=y ? y : x);
}

#endif