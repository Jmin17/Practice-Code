#include "pch.h"
#include "BitConverter.h"



BitConverter::BitConverter(long inputDecimal)
	:decimalValue(inputDecimal)
{
	this->checkIsNegative();
}

BitConverter::BitConverter()
	: decimalValue(0)
{
	this->checkIsNegative();
}
const string & BitConverter::getBitString()
{
	bool isNegative = decimalValue > -1 ? false : true;

	long remainingValue = isNegative ? -1 * decimalValue : decimalValue;

	int bp = 0;//binary position, representing 2^n with bp being the greatest n
			   // such that 2^n is less than or equal to the decimal value

	while (pow(2, bp) <= remainingValue)
	{
		bp++;
	}

	int n = bp;// making n the current digit of the binary representation of the value

	long power2;
	bitString = "";
	bitString.resize(bp + 1, '0');
	int i = 0;
	for (; n >= 0 && remainingValue > 0; n--)
	{
		power2 = round(pow(2, n));

		if (remainingValue - power2 >= 0)
		{
			bitString[i] = '1';
			remainingValue -= power2;
		}
		else
		{
			bitString[i] = '0';
		}

		i++;
	}//end for

	if (isNegative)
	{
		this->performTwosComplement();
	}

	this->makeFancy();

	return bitString;
}

void BitConverter::performTwosComplement()
{

	int length = bitString.length();
	int i = 0;//index value

	for (;i < length; i++)
	{
		bitString[i] = (bitString[i] == '1') ? '0' : '1';
	}

	this->addOne();
}

void BitConverter::addOne()
{

	int length = bitString.length();
	int i = length - 1;
	if (bitString[i] == '0')
	{
		bitString[i] = '1';
		return;
	}

	bool finished = false;
	char prev = '0';
	while (i > -1 && !finished)
	{
		if (bitString[i] == '1')
		{
			bitString[i] = '0';
		}
		else//bitString[i] == '0'
		{
			bitString[i] = '1';
			finished = true;
		}
		i--;
	}

	if (!finished)
	{
		bitString.insert(size_t(0), "1");
	}


}

void BitConverter::makeFancy()
{
	int l = bitString.length();

	if (l < 32)
	{
		if(!this->isNegative)
			bitString.insert(0, 32 - l, '0');
		else
			bitString.insert(0, 32 - l, '1');
	}

	l = 32;

	int i = 0;// index values
	int n = 0;
	for (i = l; i > 0; i--)
	{
		if (n % 4 == 0)
		{
			bitString.insert(i, " ");
		}
		n++;
	}


}

bool BitConverter::checkIsNegative()
{
	return isNegative = ((decimalValue > -1) ? false : true);
}

const int &BitConverter::setDecimalValue(const long &inputDecimal)
{
	decimalValue = inputDecimal;
	this->checkIsNegative();
	return decimalValue;
}