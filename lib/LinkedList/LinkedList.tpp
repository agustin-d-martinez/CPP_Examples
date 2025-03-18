#pragma once

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _First_Node(nullptr) , _Last_Node(nullptr)
{ }

template <typename T>
LinkedList<T>::LinkedList(T a)
{
	_First_Node = new Node<T>(a);
	_Last_Node = _First_Node;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &a) : _First_Node(a._First_Node) , _Last_Node(a._Last_Node)
{ }

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* tmp = _First_Node->_next_node;
	delete _First_Node;
	while(tmp != nullptr)
	{
		tmp = tmp->_next_node;
		delete tmp;
	}
}

template <typename T>
T LinkedList<T>::at(int idx)
{
	Node<T>* tmp = _First_Node;
	for (auto i=0; ((i < idx) && (tmp != _Last_Node)) ; i++)
		tmp = tmp->_next_node;
	
	if (tmp == nullptr)
		return 0;
	return tmp->_value;
}

template <typename T>
void LinkedList<T>::append(T a)
{
	Node<T>* tmp = new Node<T>(a);
	if (_Last_Node == nullptr)
		_First_Node = _Last_Node = tmp;
	else{
		_Last_Node->_next_node = tmp;				
		tmp->_prev_node = _Last_Node;	
		_Last_Node = tmp;				
	}
}

template <typename T>
void LinkedList<T>::insertAtBeggining(T value)
{
	Node<T>* tmp = new Node<T>(value);
	if ( _First_Node == nullptr )
		_First_Node = _Last_Node = tmp;
	else{
		tmp->_next_node = _First_Node;
		_First_Node->_prev_node = tmp;
		_First_Node = tmp;
	}
}

template <typename T>
void LinkedList<T>::insertAt(T value, int idx)
{
	Node<T>* newData = new Node<T>(value);
	if (_First_Node == nullptr)
		_First_Node = _Last_Node = newData;
	else if (idx == 0){
		newData->_next_node = _First_Node;
		_First_Node->_prev_node = newData;
		_First_Node = newData;
	}
	else{
		Node<T>* tmp = getNodeAt(idx);
		
		if (tmp == _Last_Node){
			tmp->_next_node = newData;
			newData->_prev_node = tmp;
			_Last_Node = newData;
		}
		else{
			newData->_prev_node = tmp->_prev_node;
			newData->_next_node = tmp;
			tmp->_prev_node->_next_node = newData;
			tmp->_prev_node = newData;
		}
	}
}

template <typename T>
void LinkedList<T>::remove(int idx)
{
	Node<T>* tmp = getNodeAt(idx);
	tmp->_prev_node->_next_node = tmp->_next_node;
	tmp->_next_node->_prev_node = tmp->_prev_node;
	delete tmp;
}

template <typename T>
void LinkedList<T>::removeFirst(void)
{
	Node<T>* newfirst = _First_Node->_next_node;
	newfirst->_prev_node = nullptr;
	delete _First_Node;
	_First_Node = newfirst;
}

template <typename T>
void LinkedList<T>::removeLast(void)
{
	Node<T>* newlast = _Last_Node->_prev_node;
	newlast->_next_node = nullptr;
	delete _Last_Node;
	_Last_Node = newlast;
}

template <typename T>
void LinkedList<T>::clear(void)
{
	Node<T>* tmp = _First_Node->_next_node;
	delete _First_Node;
	while(tmp != nullptr){
		tmp = tmp->_next_node;
		delete tmp;
	}
	_First_Node = _Last_Node = nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty(void)
{
	return (_First_Node == nullptr) ? true : false;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator+(T value)
{
	this->append(value);
	return *this;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator<<(T value)
{
	append(value);
	return *this;
}

template <typename T>
bool LinkedList<T>::has(T value)
{
	Node<T>* tmp = _First_Node;
	while (tmp != nullptr)
	{
		if (tmp->_value == value)
			return true;
		tmp = tmp->_next_node;
	}
	return false;
}

template <typename U>
std::ostream &operator<<(std::ostream &out, const LinkedList<U> &a)
{
	Node<U>* tmp = a._First_Node;
	while( tmp != nullptr){
		out << tmp->_value << " ";
		tmp = tmp->_next_node;
	}
	return out;
}

template <typename T>
Node<T> *LinkedList<T>::getNodeAt(int idx)
{
	Node<T>* tmp = _First_Node;
	for (auto i=0; i<idx && tmp->_next_node != nullptr; i++)
		tmp = tmp->_next_node;
	
	return tmp;
}
