#pragma once

#include <iostream>
using namespace std;

class LinkedList
{
	private:
	LinkedList*	_prev_node; 
	LinkedList*	_next_node;
	
	int	_value;

	public:
	LinkedList();
	LinkedList(int a);
	~LinkedList();

	void append( int a );
	int at( int a );
	friend ostream& operator<< ( ostream& out , LinkedList& a);
};