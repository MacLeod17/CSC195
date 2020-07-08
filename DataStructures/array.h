#pragma once

#include<initializer_list>

namespace gk
{
	template<typename T, size_t TSize>
	class array 
	{
	public:
		array() {}
		array(const std::initializer_list<T>& ilist) 
		{
			size_t i = 0;
			for (T item : ilist) {
				_elements[i] = item;
				i++;
			}
		}

		T& operator [] (size_t position) {
			return _elements[position];
		}

		T& at(size_t position) {
			return _elements[position];
		}

		T& operator = (T& s2)
		{
			return s2;
		}

		const T& operator [] (size_t position) const
		{
			return _elements[position];
		}

		const T& at(size_t position) const
		{
			return _elements[position];
		}

		T& front();
		T& back();
		T* data();//

		void fill(const T& value);
		void swap(array& other);

		bool empty() const;

		size_t size() const;
		size_t max_size() const;
	private:
		T _elements[TSize]{};
	};

	template<typename T, size_t TSize>
	T& array<T,TSize>::front() 
	{
		return _elements[0];
	}

	template<typename T, size_t TSize>
	T& array<T, TSize>::back() 
	{
		return _elements[TSize - 1];
	}

	template<typename T, size_t TSize>
	T* array<T, TSize>::data()
	{
		return &(this->front());
	}

	template<typename T, size_t TSize>
	void array<T, TSize>::fill(const T& value) 
	{
		for (size_t i = 0; i < TSize; i++)
		{
			_elements[i] = value;
		}
	}

	template<typename T, size_t TSize>
	void array<T, TSize>::swap(array& other) 
	{
		array<T, TSize> temp;
		
		temp = *this;
		*this = other;
		other = temp;
	}

	template<typename T, size_t TSize>
	bool array<T, TSize>::empty() const
	{
		if (TSize == 0)
		{
			return true;
		}
		return false;
	}

	template<typename T, size_t TSize>
	size_t array<T, TSize>::size() const
	{
		return TSize;
	}

	template<typename T, size_t TSize>
	size_t array<T, TSize>::max_size() const
	{
		return TSize;
	}
}