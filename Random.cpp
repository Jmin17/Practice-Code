
#include "pch.h"
#include "Random.h"

Random::Random()
{
	disInt = std::make_shared < std::uniform_int_distribution<int>>(0, 10);
	disReal = std::make_shared< std::uniform_real_distribution<double> >(0.0, 1.0);
}

std::random_device Random::seeder;
std::shared_ptr<std::mt19937> Random::engine = std::make_shared<std::mt19937>(seeder());

Random::Random(int minIntVal, int maxIntVal)
{
	disInt = std::make_shared < std::uniform_int_distribution<int>>(minIntVal, maxIntVal);
	disReal = std::make_shared< std::uniform_real_distribution<double> >(0.0, 1.0);
}

int Random::nextInt()
{
	return (*disInt)(*engine);
}

int Random::nextInt(int minVal, int maxVal)
{
	if ( disInt->min() == minVal && disInt->max() == maxVal)
	{
		return (*disInt)(*engine);
	}
	else
	{
		disInt = std::make_shared< std::uniform_int_distribution<int>>(minVal, maxVal);
		return(*disInt)(*engine);
	}
}

void Random::setIntRange(int minVal, int maxVal)
{
	using namespace std;

	disInt = make_shared<uniform_int_distribution<int>>(minVal, maxVal);
}

double Random::nextDouble()
{
	return (*disReal)(*engine);
}

void Random::setDoubleRange(double minVal, double maxVal)
{
	using namespace std;

	disReal = make_shared<uniform_real_distribution<double>>(minVal, maxVal);
}