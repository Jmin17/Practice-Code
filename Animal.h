#pragma once
#include "Object.h"



class Animal : public Object
{
public:
	Animal();
	~Animal();

	virtual void Move(double distance);
};

