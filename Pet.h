#pragma once
#include "Animal.h"



class Pet :	public Animal
{
public:
	Pet();
	~Pet();
	virtual void Move(double distance) override;
};

