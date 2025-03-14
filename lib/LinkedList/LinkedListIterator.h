#pragma once

#include "../Node/Node.h"

template <typename T>
class LinkedListIterator{
	private:
	Node<T>* _current;

	public:
	LinkedListIterator(Node<T>* node) : _current(node) {}
	T& operator*( void ) const {
		return _current->_value;
	}

	LinkedListIterator& operator++( void ){
		if (_current)
			_current = _current->_next_node;
		return *this;
	}

	bool operator!=( const LinkedListIterator& other ){
		return _current != other._current;
	}
};