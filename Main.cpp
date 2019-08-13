

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include "BitConverter.h"
#include "SmartPointer.h"
#include "Vector.h"
#include "Random.h"
#include "Sorter.h"

using namespace std;

void testBitConverter();
void testSmartPointer();
void testVector();

void AddColumn(int ** matrix, int numRows, int numCols)
{
	/*
		matrix[row][column]

		example: rows = 4 cols = 5

		---------------------------------
		|	12	51	16	90	3	matrix[0][0-4]
		|	34	1	4	0	7	matrix[1][0-4]
		|	0	0	0	0	22	matrix[2][0-4]
		|	0	0	0	0	88	matrix[3][0-4]
		
		adding a column requires: reallocating every row array,
		copying the values over, and deleting the old arrays
	*/
	
	int i = 0, j = 0; //index values
	int *temp; // will hold a temporary copy of the old int array
	for (;i < numRows; i++)
	{
		// reallocating
		temp = matrix[i];
		matrix[i] = new int[numCols + 1];
		
		//copying old values
		for (j = 0;j < numCols;j++)
			matrix[i][j] = temp[j];

		// ensuring the new values are initialized
		// to a default value
		matrix[i][numCols] = 0;

		//deleting the old array
		delete[] temp;
	}//end for

	/*
	matrix should now be:
	---------------------------------
	|	12	51	16	90	3	0	matrix[0][0-5]
	|	34	1	4	0	7	0	matrix[1][0-5]
	|	0	0	0	0	22	0	matrix[2][0-5]
	|	0	0	0	0	88	0	matrix[3][0-5]

*/
}//endfunc

void testMatrix()
{
	int ** matrix;
	int rows = 4, cols = 5;
	matrix = new int*[rows];

	//creating matrix
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = (1+i) * 10 + j + 1;
		}
	}

	cout << "initial matrix: " << endl;
	//printing 
	for (int i = 0; i < rows; i++)
	{
		cout << "\t";
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}

	AddColumn(matrix, rows, cols++);

	cout << "new matrix: " << endl;
	//printing
	for (int i = 0; i < rows; i++)
	{
		cout << "\t";
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void qSortTest();

int main()
{
	//testMatrix();
	//testBitConverter();

	//testSmartPointer();

	//testVector();

	qSortTest();

	cout << "\n\n\n"; 
}


void qSortTest()
{
	using namespace jlm;

	int length = 20;
	Vector<int> v(length);

	Random rng(0, 99);

	for (int i = 0; i < length; i++)
	{
		v[i] = rng.nextInt();
	}

	cout << "\n\tUnsorted Array: " << endl << "\t";
	for (int i = 0; i < length; i++)
	{
		cout << setw(4) << v[i];
	}
	Sorter<int>::qSort(v);

	cout << "\n\n\tSorted Array: " << endl << "\t";
	for (int i = 0; i < length; i++)
	{
		cout << setw(4) << v[i];
	}

}


void testVector()
{
	using namespace jlm;

	Vector<double> x;

	x.resize(20);

	for (int i = 0; i < 20; i++)
		x[i] = i * 10;

	for (int i = 0; i < 20; i++)
	{
		cout << setw(4) << x[i];
	}

	cout << endl << endl;

	x.resize(10);

	for (int i = 0; i < 10; i++)
		x[i] -= i * 5;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(4) << x[i];
	}

	cout << endl << endl;

	x.resize(0);


}

void testSmartPointer()
{
	using namespace jlm;
	
	SmartPointer<int> x;
	
	x = SmartPointer<int>(32);

	cout << *x << endl << endl;

	SmartPointer<int> y(x);



	*x = 14;

	cout << *x << endl << endl;

	*x = 54;

	cout << *y << endl << endl;
}


void testBitConverter()
{
	//unique_ptr<stringstream> buffer;
	//buffer = make_unique<stringstream>();
	stringstream buffer;

	long y = 0;
	string decimalString = "";
	BitConverter bc;

	while (decimalString != "end")
	{
		cout << endl << "\t";
		cin >> decimalString;

		if (decimalString != "end")
		{
			buffer = stringstream();
			//buffer.str("");
			//buffer.clear();
			buffer << decimalString;
			buffer >> y;
			bc.setDecimalValue(y);
			cout << endl << "\t" << bc.getBitString() << endl << endl;

		}
	}
}