#pragma once

#include <vector>
#include <random>
#include <chrono>
#include <mutex>
#include <iostream>
#include <iomanip>
#include "Sorter.h"
using namespace std;
using namespace std::chrono;

class Util
{
public:

	void initializeRandomIntArray(vector<int>& v, mt19937& generator, uniform_int_distribution<int>& distribution);
	void testQuickSort();
	void runRandomDevice();
	void runMT();
	void threadingAndRng();


private:
};

