#pragma once




template <class T>
class Node
{
public:
	Node()
		:prev(nullptr), next(nullptr)
	{}
	Node(T)
		:prev(nullptr), next(nullptr)
	{}

	T value;
	Node<T> * prev;
	Node<T> * next;



private:


};

