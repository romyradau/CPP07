#include <iostream>
#include <iomanip>

template< typename T>
class Array{

	public:

		Array(): _len(0), _array(0){};

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
			if (index >= _len || index < 0)
				throw std::out_of_range("index out of range");
			else
				return (_array[index]);
		}
		size_t size() const{

			return _len;
		}
	
	private:

		unsigned int	_len;
		T*				_array;

};

template<typename T>
std::ostream& operator<<(std::ostream& o, Array<T> const & v){
	o << v.size() << "\t" << v[0];
	return o;
}
