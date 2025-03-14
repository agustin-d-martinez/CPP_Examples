#pragma once

#include <iostream>
#include "../Node/Node.h"

template <typename T>
class LinkedList
{
	private:
	Node<T>*	_First_Node; 
	Node<T>*	_Last_Node;
	
	public:
	LinkedList();
	LinkedList(T value);
	LinkedList(const LinkedList &a);
	~LinkedList();

	T at( int idx );

	void append( T value );
	void insertAtBeggining ( T value );
	void insertAt( T value , int idx );

	void remove( int idx );
	void removeFirst( void );
	void removeLast( void );
	void clear( void );

	bool has( T value );
	bool isEmpty( void );

	LinkedList<T>& operator+( T value );
	LinkedList<T>& operator<<( T value );
	
	template <typename U>
	friend std::ostream& operator<< ( std::ostream& out , const LinkedList<U>& a);

	private:
	Node<T>* getNodeAt( int idx );
};

#include "LinkedList.tpp"