#include "../incl/iter.hpp"

int main(){



	{
		int		int_array[] = {12, 34, 56, 78};
		float	float_array[] = {1.2f, 3.4f, 5.6f, 7.8f};
		double	double_array[] = {19.2, 28.3, 37.4, 46.5};

		for (int i = 0; i < sizeof(int_array) / sizeof(int); i++){
			std::cout << "startValue:" << int_array[i] << '\n';
		}
		::iter(int_array, sizeof(int_array)/ sizeof(int), cast_stuff);
		//wird zu
		//void iter<int>(const int *arr_address, int len, void (*funcPtr)(int &))
		for (int i = 0; i < sizeof(float_array)/ sizeof(float); i++){
			std::cout << "startValue:" << float_array[i] << '\n';
		}
		::iter(float_array, sizeof(float_array)/ sizeof(float), cast_stuff);
		
		for (int i = 0; i < sizeof(double_array)/ sizeof(double); i++){
			std::cout << "startValue:" << double_array[i] << '\n';
		}
		::iter(double_array, sizeof(double_array)/ sizeof(double), cast_stuff);
	}
	{
		char	char_array[] = {'a', 'b', 'c', 'd'};
		iter(char_array, sizeof(char_array), calc_len);
		std::string string_array[] = {
			"hello",
			"byebye",
		};
		iter(string_array, sizeof(string_array)/ sizeof(std::string), calc_len);
	}
	return(0);
}
//multiple ways for the 3rd param - can always be the same function or also changeable