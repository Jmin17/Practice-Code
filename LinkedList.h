#pragma once
#include "Node.h"


template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();


	void add(T newValue);
	void insert(T newValue, int position);
	void remove(int position);
	T &operator[](int position);


	int getSize() { return size; }
private:
	Node<T> * head;
	Node<T>  * end;
	int size;



};

template<class T>
LinkedList<T>::~LinkedList()
{
	if (size == 0)
		return;

	Node<T> * holder = head;

	while (holder != end)
	{
		holder = holder->next;
		delete holder->prev;
	}

	delete end;
}
template <class T>
LinkedList<T>::LinkedList()
	:head(nullptr),end(nullptr), size(0)
{}

template <class T>
void LinkedList<T>::insert(T newValue,int position)
{
	Node<T> * holder = head;
	Node<T> * holder2 = nullptr;

	if (position < 0 || position >= size)
	{//bad value
		return;
	}
	else if (position == (size-1))
	{//appending a node to the end of the list, or giving a no node list an initial node
		this->add(newValue);
		return;// returning here to avoid duplicate size incrementation
	}
	else if (position == 0)
	{// inserting a node into the beginning of a list with multiple nodes
		holder = new Node<T>;
		holder->value = newValue;
		holder->next = head;
		head->prev = holder;
		head = holder;
	}
	else
	{// inserting a node inbetween two nodes

		//moving from node to node using the 'next' pointers
		for (int i = 0; i < position; i++)
			holder = holder->next;

		//creating the new node
		holder2 = new Node<T>;
		holder2->value = newValue;

		// connecting the pointers
		holder->prev->next = holder2;
		holder2->next = holder;
		holder2->prev = holder->prev;
		holder->prev = holder2;

	}//endif

	size++;
}

template <class T>
void LinkedList<T>::add(T newValue)
{
	Node<T> * holder = nullptr;

	if (size == 0)
	{// adding a node to an empty list
		head = new Node<T>;
		head->value = newValue;
		end = head;
	}
	else if ( size == 1 )
	{// appending a node to a one node list
		end = new Node<T>;
		end->value = newValue;
		head->next = end;
		end->prev = head;
	}
	else
	{// appending a node to a multiple node list;
		holder = end;
		end = new Node<T>;
		end->value = newValue;
		holder->next = end;
		end->prev = holder;
	}

	size++;
}

template <class T>
void LinkedList<T>::remove(int position)
{
	// these are temporary pointers to hold values to move the list nodes' pointers around
	Node<T> * holder = head;
	Node<T> * holder2 = nullptr;
	Node<T> * holder3 = nullptr;


	if (position >= size || position < 0)
	{// this is if you were given a bad position value
		
		//here's an opportunity to throw exception
		return;
	}

	for (int i = 0; i < position;i++)
	{
		holder = holder->next;
	}

	if (holder->next != nullptr && holder->prev != nullptr)
	{// this is removing a node that is not at one of the ends of the list
		holder2 = holder->prev;
		holder3 = holder->next;
		holder2->next = holder3;
		holder3->prev = holder2;
		delete holder;
	}
	else if (holder-> next != nullptr)
	{// this is if you're at the head of the linked list and there is more than one node
		head = head->next;
		delete holder;
		head->prev = nullptr;
	}
	else if (holder->prev != nullptr)
	{// this is if you're at the end of the linked list and there is more than one node
		end = end->prev;
		delete holder;
		end->next = nullptr;
	}
	else
	{// this is for removing the node from a single node list
		head = nullptr;
		end = nullptr;
		delete holder;
	}


	size--;
}//endfunc

template <class T>
T &LinkedList<T>::operator[](int position)
{

	Node<T> * holder = this->head;

	//catching bad position values
	if (position >= size || position < 0)
	{
		Node<T> x;
		//opportunity to throw exception
		return x.value;
	} 
	else if (position == (size - 1))
	{
		return this->end->value;
	}
	else
	{
		for (int i = 0;i < position;i++)
			holder = holder->next;

		return holder->value;
	}
}

