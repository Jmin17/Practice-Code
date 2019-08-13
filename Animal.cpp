#include "pch.h"
#include "Animal.h"


Animal::Animal()
{
	cout << "\tAnimal Created" << endl;
}


Animal::~Animal()
{
	cout << "\tAnimal Destroyed" << endl;
}

void Animal::Move(double distance)
{
	cout << "Animal moved " << distance << " meters." << endl;
}