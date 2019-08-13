#include "pch.h"
#include "Dog.h"


Dog::Dog()
{
	cout << "\t\t\tDog Created" << endl;
}


Dog::~Dog()
{
	cout << "\t\t\tDog Destroyed" << endl;
}

void Dog::Move(double distance)
{
	cout << "Dog moved " << distance << " meters" << endl;
}
