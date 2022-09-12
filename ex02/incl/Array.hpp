#include <iostream>
#include <iomanip>

template< typename T = float >
//if i don't tell what type it is, compiler assumes that it's this type
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
		Array( Array const & src): _array(0){
			
			*this = src;
		}
		~Array(){
			delete [] _array;
		}

		Array & operator=(Array const & rhs){
			
			if ( this != &rhs){

				_len = rhs._len;
				//ode rhier rhs._size() - weil man nicht an das Attribut von rhs kann?
				//Einschub, kann es auch sein, dass man hier zwei verschieden Array Klassen miteinader gleichsetzen will???
				// std::cout << *_array << '\n';
				if (_array)
					delete [] _array;
				_array = new T [rhs._len];
				for (int i = 0; i < _len; i++){

					_array[i] = rhs._array[i];
				}
			}
			return *this;
		}



		T& operator[](unsigned int index) const{
		//mit unsigned sollte der Fall < 0 auch gar nicht gehen...
		//vertstehe die Schreibweise hier nicht... weil, das unisgned int doch in den [sein muss]
			if (index >= _len || index < 0)
				throw std::out_of_range("index out of range");
			else
				return (_array[index]);
		}
		//hier gibt  man ein Element und nicht die ganze Klasse zurück!
		size_t size() const{

			return _len;
		}
	
	private:

		unsigned int	_len;
		T*				_array;

	//if you put the default constructor in private it means it's not possible to instantiate the class without passing it parameters
	//very practical to know!
};

template<typename T>
std::ostream& operator<<(std::ostream& o, Array<T> const & v){
	o << v.size() << "\t" << v[0];
	return o;
}

//wo würde man jetzt immer die eckigen Klammern hinschreiben?