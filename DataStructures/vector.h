#pragma once

#include<initializer_list>
#include <limits>

namespace gk 
{
	template<typename T>
	class vector {
	public:
		vector() {}
		vector(size_t capacity) 
		{
			_elements = new T[capacity];
			_capacity = capacity;
		}
		vector(size_t size, const T& value)
		{
			_elements = new T[size];
			_capacity = size;
			_size = size;
			for (size_t i = 0; i < _size; i++)
			{
				_elements[i] = value;
			}
		}
		vector(const std::initializer_list<T>& ilist)
		{
			size_t i = 0;
			for (T item : ilist) {
				push_back(item);
				i++;
			}
		}
		vector(const vector& other) 
		{
			_capacity = other._capacity;
			_size = other._size;
			_elements = new T[_capacity];

			for (size_t i = 0; i < _size; i++) 
			{
				_elements[i] = other._elements[i];
			}
		}
		
		~vector() 
		{
			if (_elements) {
				delete[] _elements;
			}
		}

		vector& operator = (const vector& other)
		{
			_capacity = other._capacity;
			_size = other._size;
			if (_elements)
			{
				delete[] _elements;
			}
			_elements = new T[_capacity];

			for (size_t i = 0; i < _size; i++)
			{
				_elements[i] = other._elements[i];
			}

			return *this;
		}

		T& operator [] (size_t position) {
			return _elements[position];
		}
		T& at(size_t position) 
		{
			return _elements[position];
		}

		const T& operator [] (size_t position) const
		{
			return _elements[position];
		}
		const T& at(size_t position) const
		{
			return _elements[position];
		}

		void push_back(const T& value) 
		{
			if (_size >= _capacity)
			{
				size_t capacity = _capacity * 2;
				if (capacity == 0) capacity = 4;
				reserve(capacity);
			}
			_elements[_size] = value;
			_size++;
		}
		void pop_back()
		{
			if (_size > 0) {
				_size--;
			}
		}

		T& front()
		{
			return _elements[0];
		}
		T& back()
		{
			return _elements[this->size() - 1];
		}

		void reserve(size_t capacity)
		{
			if (capacity < _capacity) return;

			T* newElements = new T[capacity];
			for (size_t i = 0; i < _size; i++)
			{
				newElements[i] = _elements[i]; 
			}
			if (_elements)
			{
				delete[] _elements;
			}
			_elements = newElements;
			_capacity = capacity;
		}

		void resize(size_t size, T value = T{})
		{
			if (size > _size)
			{
				while (size > _size)
				{
					push_back(value);
				}
			}
			else 
			{
				_size = size;
			}
		}
		void clear()
		{
			_size = 0;
		}
		void swap(vector& other)
		{
			vector<T> temp;

			temp = *this;
			*this = other;
			other = temp;
		}

		T* data()
		{
			return &(this->front());
		}

		bool empty() { return (_size == 0); }
		size_t size() const { return _size; }
		size_t max_size() const { return std::numeric_limits<size_t>::max(); }
		size_t capacity() const { return _capacity; }

	private:
		T* _elements{ nullptr };
		size_t _size{ 0 };
		size_t _capacity{ 0 };
	};
}