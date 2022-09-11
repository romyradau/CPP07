#include <iostream>
#include <iomanip>

template< typename T = float >
//if i don't tell you what type it is compiler, assume that it's this type
class Array{

	public:

		Array(): _len(0), _array(0){};
		//könnte ich den in private packen, sodass der user werte eingeben MUSS?
		//kann man das so schreiben, für NULLPTR?
		//oder lieber hier auch schon wie Manuel allocaten?

		Array(unsigned int n){
			_array = new T[n];
			_len = n;
		}
		Array( Array const & src){
			
			*this = src;
		}
		~Array();

		Array & operator=(Array const & rhs){
			
			if ( this != &rhs){

				_len = rhs._len;
				//ode rhier rhs._size() - weil man nicht an das Attribut der anderen kann?
				//Einschub, kann es auch sein, dass man hier zwei verschieden Array Klassen miteinader gleichsetzen will???
				if (_array)
					delete [] _array;
				_array = new T [rhs._len];
				for (int i = 0; i < _len; i++){

					_array[i] = rhs._array[i];
				}
			}
			return *this;
		}

		T const& operator[](T* arrPtr);
		//hier gibt  man ein Element und nicht die ganze Klasse zurück!
		size_t size() const;
	
	private:

		unsigned int	_len;
		T*				_array;

	//if you put the default constructor in private it means it's not possible to instantiate the class without passing it parameters
	//very practical to know!
};

template<typename T>
std::ostream& operator<<(std::ostream& o, Array<T>const & v){
	o << v.size() << std::cout;
}

//wo würde man jetzt immer die eckigen Klammern hinschreiben?