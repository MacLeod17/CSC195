#pragma once

#include <iostream>
#include<limits>

namespace gk
{
	template<typename T>
	class list
	{
		struct node_t
		{
			node_t(const T& value) : _value{value} {}
				
			T _value;
			node_t* _next{ nullptr };
			node_t* _prev{ nullptr };
		};
	public:
		list() {}
		list(const std::initializer_list<T>& ilist)
		{
			for (auto iter = ilist.begin(); iter != ilist.end(); iter++)
			{
				push_back(*iter);
			}
		}
		list(const list& other)
		{
			node_t* node = other._head;
			while (node)
			{
				push_back(node->_value);
				node = node->_next;
			}
		}

		list& operator = (const list& other)
		{
			clear();

			node_t* node = other._head;
			while (node)
			{
				push_back(node->_value);
				node = node->_next;
			}

			return *this;
		}

		~list()
		{
			clear();
		}

		T& front()
		{
			return _head->_value;
		}
		const T& front() const
		{
			return _head->_value;
		}

		T& back()
		{
			return tail()->_value;
		}
		const T& back() const
		{
			return tail()->_value;
		}

		void push_front(const T& value)
		{
			node_t* new_node = new node_t(value);
			if (_head)
			{
				_head->_prev = new_node;
			}
			new_node->_next = _head;
			_head = new_node;
		}

		void pop_front()
		{
			if (_head)
			{
				node_t* temp_node = _head;
				_head = _head->_next;
				_head->_prev = nullptr;
				delete temp_node;
			}
		}

		void push_back(const T& value)
		{
			node_t* new_node = new node_t(value);
			if (!_head)
			{
				_head = new_node;
			}
			else 
			{
				node_t* tail_node = tail();
				tail_node->_next = new_node;
				new_node->_prev = tail_node;
			}
		}

		void pop_back()
		{
			node_t* tail_node = tail();
			if (tail_node)
			{
				node_t* prev_node = tail_node->_prev;
				if (prev_node)
				{
					prev_node->_next = nullptr;
				}
				if (tail_node == _head)
				{
					_head = nullptr;
				}
				delete tail_node;
			}
		}

		void remove(const T& value)
		{
			node_t* node = _head;
			while (node)
			{
				if (node->_value == value)
				{
					node_t* prev_node = node->_prev;
					node_t* next_node = node->_next;

					if (prev_node) prev_node->_next = next_node;
					if (next_node) next_node->_prev = prev_node;

					if (node == _head)
					{
						_head = next_node;
					}
					delete node;
					node = next_node;
				}
				else {
					node = node->_next;
				}
			}
		}

		void reverse()
		{
			node_t* temp = nullptr;
			node_t* current = _head;

			while (current)
			{
				temp = current->_prev;
				current->_prev = current->_next;
				current->_next = temp;
				current = current->_prev;
			}

			if (temp)
			{
				_head = temp->_prev;
			}
		}

		void resize(size_t newSize, const T& value)
		{
			while (size() > newSize)
			{
				pop_back();
			}
			while (size() < newSize)
			{
				push_back(value);
			}
		}

		std::ostream& write(std::ostream& stream)
		{
			node_t* node = _head;
			while (node)
			{
				stream << node->_value << " ";
				node = node->_next;
			}
			stream << std::endl;

			return stream;
		}

		void clear()
		{
			node_t* node = _head;
			while (node)
			{
				node_t* next_node = node->_next;
				delete node;
				node = next_node;
			}
		}

		size_t size()
		{
			size_t size = 0;
			node_t* node = _head;
			while (node)
			{
				size++;
				node = node->_next;
			}
			return size;
		}

		size_t max_size() { return std::numeric_limits<size_t>::max(); }

		bool empty()
		{
			if (_head)
			{
				return false;
			}
			return true;
		}

	private:
		node_t* tail()
		{
			node_t* node = _head;
			while (node && node->_next)
			{
				node = node->_next;
			}
			return node;
		}

	private:
		node_t* _head{ nullptr };
	};
}