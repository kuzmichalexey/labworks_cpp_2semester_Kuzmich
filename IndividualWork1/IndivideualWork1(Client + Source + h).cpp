
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
using namespace std;

void inputArray(int*, int size);
void displayArray(int*, int size);
void swap(int*, int, int);
int findMinPositiveIndex(int*, int size);
int findMaxNegativeIndex(int*, int size);
int numberOfEvenDigits(int);
void getKeys(int*, int size, int* keys);
void cutOffArray(int*, int*, int leftBorder, int rightBorder);
void getCroppedPart(int*, int*, int size, int, int);
void getCroppedPart(int*, int*, int size, int);
void mergeSort(int* keys, int* array, int, int);
void merge(int* keys, int* array, int, int);
void changeAccordingToKeys(int*, int size, int*);
void example1(int* array, int size);
void example2(int* array, int size);
void example3(int* array, int size);
void randomInit(int* array, int size);
void(*initArray) (int* array, int size);

template <class T>
void findMinMax(T number1, T number2, T &min, T &max)
{
	if (number1 > number2)
	{
		min = number2;
		max = number1;
	}
	else
	{
		min = number1;
		max = number2;
	}
}

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

	system("pause");
	return 0;
}




void inputArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> *(array + i);
	}
}

void displayArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(array + i) << " ";
	}
}

int findMinPositiveIndex(int* array, int size)
{
	int i = 1, index = -1;

	for (; index == -1 && i < size; i+=2)
	{
		if (*(array + i) > 0)
		{
			index = i;
		}
	}

	for (int j = i; j < size; j+=2)
	{
		if (*(array + j) < *(array + index) && *(array + j) > 0)
		{
			index = j;
		}
	}

	return index;
}

int findMaxNegativeIndex(int* array, int size)
{
	int i = 1, index = -1;

	for (; index == -1 && i < size; i+=2)
	{
		if (*(array + i) < 0)
		{
			index = i;
		}
	}

	for (int j = i; j < size; j+=2)
	{
		if (*(array + j) > *(array + index) && *(array + j) < 0)
		{
			index = j;
		}
	}

	return index;
}

void getKeys(int* array, int size, int* keys)
{
	for (int i = 0; i < size; i++)
	{
		*(keys + i) = numberOfEvenDigits(*(array + i));
	}
}

int numberOfEvenDigits(int number)
{
	int counter = 0;
	number = abs(number);
	for (; number > 0; number /= 10)
	{
		if ((number % 10) % 2 == 0)
		{
			counter++;
		}
	}

	return counter;
}

void getCroppedPart(int* array, int *croppedPart, int size, int leftBorder, int rightBorder)
{
	for (int i = 0; i <= leftBorder; i++)
	{
		*(croppedPart + i) = *(array + i);
	}

	for (int i = rightBorder, j = leftBorder + 1; i < size; i++, j++)
	{
		*(croppedPart + j) = *(array + i);
	}
}

void getCroppedPart(int* array, int* croppedPart, int size, int border)
{
	for (int i = 0; i <= border; i++)
	{
		*(croppedPart + i) = *(array + i);
	}
}

void copyArray(int* array, int* arrayCopy, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arrayCopy + i) = *(array + i);
	}
}

void cutOffArray(int* array, int* arrayCopy, int leftBorder, int rightBorder)
{
	for (int i = leftBorder + 1, j = 0; i < rightBorder; i++, j++)
	{
		*(arrayCopy + j) = *(array + i);
	}
}

void swap(int* array, int a, int b)
{
	int temp = *(array + a);

	*(array + a) = *(array + b);
	*(array + b) = temp;
}

void mergeSort(int* keys, int* array, int left, int right)
{
	if (left < right)
	{
		if (right - left == 1)
		{
			if (*(keys + left) > *(keys + right))
			{
				swap(array, left, right);
				swap(keys, left, right);
			}
		}

		else
		{
			mergeSort(keys, array, left, left + (right - left) / 2);
			mergeSort(keys, array, left + (right - left) / 2 + 1, right);
			merge(keys, array, left, right);
		}
	}


}

void merge(int* keys, int* array, int begin, int end)
{
	int i = begin, mid = begin + (end - begin) / 2, j = mid + 1, counter = 0;
	int* keysContainer = new int[end - begin + 1];
	int* container = new int[end - begin + 1];

	while (i <= mid && j <= end)
	{
		if (*(keys + i) <= *(keys + j))
		{
			*(keysContainer + counter) = *(keys + i);
			*(container + counter++) = *(array + i++);
		}
		else
		{
			*(keysContainer + counter) = *(keys + j);
			*(container + counter++) = *(array + j++);
		}
	}

	while (i <= mid)
	{
		*(keysContainer + counter) = *(keys + i);
		*(container + counter++) = *(array + i++);
	}

	while (j <= end)
	{
		*(keysContainer + counter) = *(keys + j);
		*(container + counter++) = *(array + j++);
	}

	for (int l = 0; l <= end - begin; l++)
	{
		*(keys + l + begin) = *(keysContainer + l);
		*(array + l + begin) = *(container + l);
	}

}

void example1(int* array, int size)
{
	array[0] = 1;
	array[11] = 1;
	array[12] = 12;
	array[29] = -1;
	array[30] = 29;

	for (int i = 1; i < 11; i++)
	{
		array[i] = -(abs(array[i - 1]) + 1);
	}

	for (int i = 13; i < 29; i++)
	{
		array[i] = array[i - 1] + 1;
	}

	for (int i = 31; i < size; i++)
	{
		array[i] = -array[i - 1] + i;
	}
}

void example2(int* array, int size)
{
	for (int i = 0; i < 25; i++)
	{
		array[i] = i + 1;
	}

	for (int i = 26; i < size; i++)
	{
		array[i] = i;
	}

	array[25] = 1;
}

void example3(int* array, int size)
{
	for (int i = 1; i < size; i += 2)
	{
		array[i] = 0;
	}

	for (int i = 2; i < size; i += 2)
	{
		array[i] = i;
	}
	array[0] = 0;
}

void randomInit(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = 1 + rand() % 100;
	}
}