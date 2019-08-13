#pragma once

#ifndef LIST_H
#define LIST_H

#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>

template< class T>
struct ListNode
{
public:
	T val;
	std::shared_ptr<ListNode<T>> next;
};

template< class T>
class List
{
public:
	List();
	T &at(int index);
	void add(T newVal);
	void remove(int index);
	void insert(T newVal, int index);
	const int &getLength();
	std::string toString();
private:
	std::shared_ptr<ListNode<T>> head;
	std::shared_ptr<ListNode<T>> tail;
	int length;

};

template< class T >
List<T>::List()
{
	length = 0;
}

template< class T >
T &List<T>::at(int index)
{
	using namespace std;

	if (length == 0)
	{
		throw out_of_range("at function called on empty list");
	}

	int currIndex = 0;
	shared_ptr<Node<T>> returned = head;

	for (; currIndex < index; currIndex++)
	{
		if (returned.next)
		{
			returned = returned.next;
		}
		else
		{
			throw out_of_range("invalid index given to at");
		}
	}

	return returned.val;
}

template <class T>
void List<T>::add(T newVal)
{
	using namespace std;

	if (length == 0)
	{
		length += 1;
		head = make_shared<ListNode<T>>();
		head->val = newVal;
		tail = head;
	}
	else
	{
		length++;
		tail->next = make_shared<ListNode<T>>();
		tail->next->val = newVal;
		tail = tail->next;
	}

}

template < class T>
void List<T>::remove(int index)
{
	using namespace std;

	if (length == 0)
	{
		throw exception("can't remove from empty list");
	}

	if (index >= length)
		throw out_of_range("attempted to remove item from list from invalid index");

	int currIndex = 0;
	shared_ptr<ListNode<T>> holder = head, holder2;
	for (; currIndex < index - 1; currIndex++)
	{
		holder = holder->next;
	}

	holder2 = holder->next;
	if (holder2 != tail)
	{
		holder2 = holder2->next;
		holder->next = holder2;
	}
	else
	{
		tail = holder;
		tail->next = nullptr;
	}

	length--;
}

template < class T >
void List<T>::insert(T newVal, int index)
{
	using namespace std;

	if ((length == 0 && index != 0) || index > length)
		throw out_of_range("invalid insert, out of range");

	int currIndex = 0;
	shared_ptr<ListNode<T>> holder = head, holder2;

	if (index == 0)
	{
		holder2 = make_shared<ListNode<T>>();
		holder2->val = newVal;
		holder2->next = head;
		head = holder2;
	}
	else
	{
		for (; currIndex < index - 1; currIndex++)
		{
			holder = holder->next;
		}

		holder2 = holder->next;
		holder->next = make_shared<ListNode<T>>();
		holder = holder->next;
		holder->val = newVal;
		holder->next = holder2;

		if (tail->next)
			tail = tail->next;
	}

	length++;
}

template < class T >
const int &List<T>::getLength()
{
	return length;
}

template < class T >
std::string List<T>::toString()
{
	if (length == 0)
		return "";

	using namespace std;

	stringstream textHolder;
	string output = "", outputBuffer;

	shared_ptr<ListNode <T>> currNode = head;

	while (currNode != nullptr)
	{
		textHolder << currNode->val;
		textHolder >> outputBuffer;
		output += outputBuffer + " ";
		currNode = currNode->next;
		textHolder.clear();
	}

	return output;
}



#endif

