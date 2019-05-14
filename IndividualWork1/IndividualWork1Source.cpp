#include <ostream>
#include <iostream>
#include <IndividualWork1.h>

using namespace SortingExtension;
using namespace std;

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

	for (; index == -1 && i < size; i += 2)
	{
		if (*(array + i) > 0)
		{
			index = i;
		}
	}

	for (int j = i; j < size; j += 2)
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

	for (; index == -1 && i < size; i += 2)
	{
		if (*(array + i) < 0)
		{
			index = i;
		}
	}

	for (int j = i; j < size; j += 2)
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