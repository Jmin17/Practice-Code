#pragma once
#include "Pet.h"
#include <string>
using namespace std;


class Dog :	public Pet
{
public:
	Dog();
	~Dog();
	void virtual Move(double distance) override;

	string name;
};

