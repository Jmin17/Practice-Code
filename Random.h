#pragma once



#ifndef RANDOM_CLASS
#define RANDOM_CLASS
#include <random>
#include <memory>


class Random
{
public:
	Random();
	Random(int minIntVal, int maxIntVal);
	int nextInt();
	int nextInt(int minVal, int maxVal);
	void setIntRange(int minVal, int maxVal);
	double nextDouble();
	void setDoubleRange(double minVal, double maxVal);


private:
	static std::random_device seeder;
	static std::shared_ptr<std::mt19937> engine;
	std::shared_ptr<std::uniform_int_distribution <int>> disInt;
	std::shared_ptr<std::uniform_real_distribution <double>> disReal;

};


#endif




