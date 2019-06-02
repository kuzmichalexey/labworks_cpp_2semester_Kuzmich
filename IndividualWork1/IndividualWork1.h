#pragma once

#include<iostream>
 
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
