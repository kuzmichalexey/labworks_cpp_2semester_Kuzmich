#include <iostream>
#include <math.h>
#include <iomanip>
#include "LB2.h"

using namespace std;

int main()
{
	int rows, columns;
	double precision, error;
	double** basicMatrix;
	double** taylorMatrix;
	char end = 'y';

	while (end == 'y' || end == 'Y')
	{
		while (true)
		{
			cout << "Enter the number of rows: ";
			cin >> rows;
			system("cls");

			if (rows > 0)
			{
				break;
			}

			cout << "INVALID VALUES!!! Number rows should be positive.\n\nTry again" << endl;
		}

		while (true)
		{
			cout << "Enter the number of columns: ";
			cin >> columns;
			system("cls");

			if (columns > 0)
			{
				break;
			}

			cout << "INVALID VALUES!!! Number of columns should be positive.\n\nTry again" << endl;
		}

		while (true)
		{
			cout << "Enter the precision: ";
			cin >> precision;
			system("cls");

			if (precision > 0)
			{
				break;
			}

			cout << "INVALID VALUES!!! Precision should be positive.\n\nTry again" << endl;
		}

		cout << "TAYLOR VALUES: \n\n";

		taylorMatrix = matrixCreate(rows, columns);
		matrixTaylorInit(taylorMatrix, rows, columns, precision);
		matrixDisplay(taylorMatrix, rows, columns);

		divisionLine(columns);
		cout << endl << "\nBASIC VALUES: \n\n";

		basicMatrix = matrixCreate(rows, columns);
		matrixBasicInit(basicMatrix, rows, columns);
		matrixDisplay(basicMatrix, rows, columns);
		divisionLine(columns);

		error = abs(matrixNorm(basicMatrix, rows, columns) - matrixNorm(taylorMatrix, rows, columns));

		cout << endl << "The ERROR of colculations is: " << error << endl<<endl;

		cout << "Press Y or y to continue: ";
		cin >> end;

		system("cls");
	}
	
	return 0;
}