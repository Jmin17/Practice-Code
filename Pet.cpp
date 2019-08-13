#include "pch.h"
#include "Pet.h"


Pet::Pet()
{
	cout << "\t\tPet Created" << endl;
}


Pet::~Pet()
{
	cout << "\t\tPet Destroyed" << endl;
}

void Pet::Move(double distance)
{
	cout << "Pet moved " << distance << " meters" << endl;
}