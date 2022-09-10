#include "../incl/iter.hpp"

int main(){

	char	char_array[] = {'a', 'b', 'c', 'd'};
	iter(char_array, sizeof(char_array), &calc_len);

	std::string string_array[] = {
		"hello",
		"byebye",
	}
	iter(string_array, sizeof(string_array), &calc_len);

	return(0);
}