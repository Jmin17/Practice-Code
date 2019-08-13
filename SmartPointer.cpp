
#include "pch.h"
#include "SmartPointer.h"

namespace jlm
{
	//template <class T>
	//SmartPointer<T>::SmartPointer()
	//{
	//	memoryAllocated = false;
	//	pointer = nullptr;
	//}

	//template <class T>
	//SmartPointer<T>::SmartPointer(T copied)
	//{
	//	memoryAllocated = false;
	//	pointer = new T(copied);
	//}
	
	//template <class T>
	//SmartPointer<T>::SmartPointer(const SmartPointer<T> &copied)
	//{
	//	memoryAllocated = copied.memoryAllocated;
	//	if (memoryAllocated)
	//		this->pointer = new T(*copied.pointer);


	//}


	//template <class T>
	//SmartPointer<T>::~SmartPointer()
	//{
	//	if (memoryAllocated)
	//		delete pointer;
	//}


	//template <class T>
	//T &SmartPointer<T>::operator*()
	//{
	//	if (memoryAllocated)
	//		return *pointer;
	//	else
	//		return nullptr;
	//}


}