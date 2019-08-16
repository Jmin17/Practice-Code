#include "Util.h"



void Util::initializeRandomIntArray(vector<int>& v, mt19937& generator, uniform_int_distribution<int>& distribution)
{
	int i = 0;
	int length = v.size();
	for (; i < length; i++) {
		v[i] = distribution(generator);
	}
}

void Util::testQuickSort()
{
	int i = 0, length = 10, minVal = 0, maxVal = 10;
	vector<int> v(length);
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> distribution(minVal, maxVal);

	initializeRandomIntArray(v, generator, distribution);

	cout << "Initial array: ";
	for (; i < length; i++) {

		cout << setw(3) << v[i];
	}
	cout << endl;

	Sorter<int>::qSort(v);

	cout << "Sorted array: ";
	for (i = 0; i < length; i++)
	{
		cout << setw(3) << v[i];
	}
	cout << endl << endl;
}

void Util::runRandomDevice()
{
	random_device rd;
	unsigned int iterations = 10999888;
	unsigned int i = 0;

	high_resolution_clock::time_point stop;
	high_resolution_clock::time_point start = high_resolution_clock::now();


	for (i = 0; i < iterations; i++)
	{
		rd();
	}

	stop = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(stop - start);

	double timeTaken = time_span.count() / iterations;
	//m.lock();
	cout << endl << "On average, random device took: " << timeTaken << " seconds" << endl;
	//m.unlock();
}

void Util::runMT()
{
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<int> intDistribution(0, 1000);
	unsigned int iterations = 10999888;
	unsigned int i = 0;

	high_resolution_clock::time_point stop;
	high_resolution_clock::time_point start = high_resolution_clock::now();


	for (i = 0; i < iterations; i++)
	{
		intDistribution(generator);
	}

	stop = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(stop - start);


	double timeTaken = time_span.count() / iterations;
	//m.lock();
	cout << endl << "On average, mersenne twister took: " << timeTaken << " seconds" << endl;
	//m.unlock();
}

void Util::threadingAndRng()
{
	mutex m;
	mutex& a = m;
	thread thread1(&Util::runMT, std::ref(*this));
	thread thread2(&Util::runRandomDevice,std::ref(*this));

	thread1.join();
	thread2.join();
}
