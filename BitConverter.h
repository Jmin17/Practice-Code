#pragma once

#include <string>
using namespace std;


class BitConverter
{
public:
	BitConverter();
	BitConverter(long inputDecimal);

	const string &getBitString();
	const string &getBitString(long newDecimalValue)
	{
		decimalValue = newDecimalValue; 
		return getBitString();
	}

	const int &setDecimalValue(const long &);

private:
	long decimalValue;
	string bitString;
	bool isNegative;

	void addOne();
	void performTwosComplement();
	void makeFancy();
	bool checkIsNegative();
};
