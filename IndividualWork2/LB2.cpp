#include <iostream>
#include <math.h>
#include <iomanip>
#include "LB2.h"

using namespace std;

double** matrixCreate(int rows, int columns)
{
	double** matrix = new double*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[columns];
	}

	return matrix;
}

void matrixDisplay(double** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(12) << setprecision(7) << matrix[i][j] << "\t";
		}

		cout << endl;
	}
}

void matrixInit1(double** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = i + j + 2;
		}
	}
}

double columnAbsoluteSum(double** matrix, int rows, int columnNumber)
{
	double sum = 0;

	for (int i = 0; i < rows; i++)
	{
		sum += abs(matrix[i][columnNumber]);
	}

	return sum;
}

double matrixNorm(double** matrix, int rows, int columns)
{
	double max = columnAbsoluteSum(matrix, rows, 0);

	for (int i = 1; i < columns; i++)
	{
		if (columnAbsoluteSum(matrix, rows, i) > max)
		{
			max = columnAbsoluteSum(matrix, rows, i);
		}
	}

	return max;
}

void matrixBasicInit(double** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = matrixEntry(i+1, j+1);
		}
	}
}

void matrixTaylorInit(double** matrix, int rows, int columns, double precision)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = matrixEntry(i+1, j+1, precision);
		}
	}
}

double taylorCos(double radian, double precision)
{
	double addend = 1, cosin = 1;

	for (int i = 0; ; i++)
	{
		addend = -(addend*radian*radian) / ((2 * i + 2)*(2 * i + 1));
		cosin += addend;

		if (abs(addend) < precision)
		{
			return cosin;
		}
	}
}

void divisionLine(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "===============";
	}
}

double matrixEntry(int i, int j, double precision)
{
	return i == j ? (taylorCos(i + j, precision) + 2 * i - j) / (i + j + 1) / (i + j + 1) : i - j;
}

double matrixEntry(int i, int j)
{
	return i == j ? (cos(i + j) + 2 * i - j) / (i + j + 1) / (i + j + 1) : i - j;
}