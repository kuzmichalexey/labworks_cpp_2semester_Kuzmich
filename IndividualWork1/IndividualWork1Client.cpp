/*
В массиве целых чисел среди чисел, стоящих на четных позициях,
найти минимальный положительный и максимальный отрицательный элементы.
Отсортировать часть массива между ними по возрастанию количества
четных цифр в десятичном представлении числа.Не отсортированные части массива записать 
в новый массив, удалив их из исходного массива.

Принятые соглашения:
 borders - границы(индексы) максимального отрицательного и минимального положительного эл-ов.
 Может быть 0, 1, 2 границы.
 Если 0 - сортируется весь массив.
 Если 1 - сортируется часть после соответствующего индекса, не включая его. Остольное обрезается.
 Если 2 - сортируется между индексами НЕ ВКЛЮЧАЯ сами эл-ты с этими индексами.

 По одному тестовому примеру на каждый случай представлено с помощью структуры switch.
 Возможность введения размерности массива и его самого пользователем предусмотрена и закоментирована.
*/

#include <iostream>
#include <IndividualWork1.h>

using namespace std;

int main()
{
	char end = 'y';
	int size, n;

	while (end == 'y' || end == 'Y')
	{
		cout << "Enter case: \n 1 - array with 2 borders;";
		cout << "\n 2 - array with 1 border;";
		cout << "\n 3 - array without borders;";
		cout << "\n other - random array \t";
		cin >> n;

		system("cls");

		switch (n)
		{
		case 1:
			size = 50;
			initArray = example1;
			break;
		case 2:
			size = 50;
			initArray = example2;
			break;
		case 3:
			size = 25;
			initArray = example3;
			break;
		default:
			size = 20;
			initArray = randomInit;
		}


		/*while (true)
		{
		cout << "Enter the size of the array: " << endl;
		cin >> size;

		system("cls");

		if (size >= 1)
		{
		break;
		}

		cout << "It is invalid size of the array!! The size should be natural number" << endl;
		}*/

		int* array = new int[size];
		initArray(array, size);
		/*cout << "Enter the array:";
		inputArray(array, size);
		cout << endl;*/

		cout << "Original array: ";
		displayArray(array, size);
		cout << endl;

		int leftBorder, rightBorder;
		findMinMax(findMaxNegativeIndex(array, size), findMinPositiveIndex(array, size), leftBorder, rightBorder);

		if (leftBorder == rightBorder)
		{
			int* keys = new int[size];
			getKeys(array, size, keys);

			mergeSort(keys, array, 0, size);

			cout << "There is no cropped part of this array." << endl;
			cout << "Resulting array: ";
			displayArray(array, size);
			cout << endl;
		}

		else
			if (leftBorder == -1)
			{
				int croppedSize = rightBorder + 1;
				int* croppedPart = new int[croppedSize];
				getCroppedPart(array, croppedPart, size, rightBorder);

				size = size - rightBorder - 1;
				int* result = new int[size];
				cutOffArray(array, result, rightBorder, size + croppedSize);

				int* keys = new int[size];
				getKeys(result, size, keys);

				mergeSort(keys, result, 0, size);

				cout << "Resulting array: ";
				displayArray(result, size);
				cout << endl;

				cout << "Cropped array: ";
				displayArray(croppedPart, croppedSize);
				cout << endl;
			}

			else
			{
				cout << "left = " << leftBorder << " right = " << rightBorder << endl;

				int croppedSize = size - (rightBorder - leftBorder - 1);
				int* croppedPart = new int[croppedSize];
				getCroppedPart(array, croppedPart, size, leftBorder, rightBorder);

				size = rightBorder - leftBorder - 1;
				int* result = new int[size];

				cutOffArray(array, result, leftBorder, rightBorder);

				int* keys = new int[size];
				getKeys(result, size, keys);

				mergeSort(keys, result, 0, size);

				cout << "Resulting array: ";
				displayArray(result, size);
				cout << endl;

				cout << "Cropped array: ";
				displayArray(croppedPart, croppedSize);
				cout << endl;
			}

		cout << "Press Y or y to continue" << endl;
		cin >> end;

		system("cls");
	}

	return 0;
}