#pragma once

#include "LinkedList.h"

LinkedList::LinkedList()
{
	_next_node = nullptr;
	_prev_node = nullptr;
	_value = 0;
}
LinkedList::LinkedList( int a )
{
	_next_node = nullptr;
	_prev_node = nullptr;
	_value = a;
}
LinkedList::~LinkedList()
{
	if (_next_node != nullptr)
	{
		_next_node->~LinkedList();
		delete _next_node;
	}
}
void LinkedList::append(int a)
{
	if(_next_node == nullptr)
	{
		_next_node = new LinkedList(a);
		_next_node->_prev_node = this;
	}
	else
		_next_node->append(a);
}

int LinkedList::at(int a)
{
	return 0;
}

ostream &operator<<(ostream &out, LinkedList &a)
{
	out << a._value;
	if (a._next_node != nullptr)
		out << *a._next_node;
	
	return out;
}
