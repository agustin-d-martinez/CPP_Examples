#pragma once

template <typename T>
class Node{
	public:
	Node*	_prev_node; 
	Node*	_next_node;
	T	_value;
	
	public:
	Node(T a)
	{
		_next_node = nullptr;
		_prev_node = nullptr;
		_value = a;	
	}
	~Node(){};
};
