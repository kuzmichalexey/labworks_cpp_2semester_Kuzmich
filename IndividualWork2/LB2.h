#pragma once

double** matrixCreate(int rows, int columns);
void matrixDisplay(double** matrix, int rows, int columns);
double columnAbsoluteSum(double** matrix, int rows, int);
double matrixNorm(double** matrix, int rows, int columns);
void matrixBasicInit(double** matrix, int rows, int columns);
void matrixTaylorInit(double** matrix, int rows, int columns, double precision);
double taylorCos(double radian, double precision);
void divisionLine(int);
double matrixEntry(int, int, double precision);
double matrixEntry(int, int);