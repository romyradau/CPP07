#include "../incl/Array.hpp"


void	check_leaks(){
	system("leaks array");
}

int	main(){


	Array<std::string> strArray(3);
	strArray[0] = "I";
	strArray[1] = "AM";
	strArray[2] = "HUNGRY!";

    Array<std::string> NoStrArray(3);
	NoStrArray[0] = "NO";
	NoStrArray[1] = "YOU";
	NoStrArray[2] = "HANGRY!";

	std::cout << NoStrArray << '\n' << strArray << '\n';

    strArray = NoStrArray;

	std::cout << NoStrArray << '\n' << strArray << '\n';

	Array<int>	intArray(5);
	for (int i = 0; i < 5; i++){
		intArray[i] = arc4random();
	}
	std::cout << intArray << '\n';

	Array<int>	intArrayCopy(intArray);
	intArrayCopy[0] = 666;

	std::cout << intArray[0] << '\n';
	std::cout << intArrayCopy[0] << '\n';

	atexit(check_leaks);
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }