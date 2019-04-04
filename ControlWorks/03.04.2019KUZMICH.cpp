#include <iostream>
using namespace std;

void createNumberEncryption(int* encryptionRule);
void(*createEncryptionRule)(int* encryptionRule) = &createNumberEncryption;
void encrypt(char*, int*, int*);
void display—ipher(int*);

int main()
{

	char array[21];
	int encryptionRule[26];
	int cipher[20];
	char end = 'y';
	createEncryptionRule(encryptionRule);

	while (end == 'y' || end == 'Y')
	{
		cout << "Enter the string you want to encrypt:" << endl;
		cin >> array;
		cout << endl << array << endl;

		encrypt(array, encryptionRule, cipher);
		display—ipher(cipher);

		cout << "Do you want to encrypt another string? If yes enter the y or Y:" << endl;
		cin >> end;

		system("cls");
	}

	return 0;
}



void encrypt(char* array, int* encryptionRule, int* cipher)
{
	for (int i = 0; array[i] != '\0'; i++)
	{
		if ((int)array[i] <= 122 && (int)array[i] >= 97)
		{
			cipher[i] = encryptionRule[(int)array[i] - 97];
		}

		if ((int)array[i] <= 90 && (int)array[i] >= 65)
		{
			cipher[i] = encryptionRule[(int)array[i] - 65];
		}
	}
}

void createNumberEncryption(int* encryptionRule)
{
	for (int i = 0; i < 26; i++)
	{
		encryptionRule[i] = 26 - i;
	}
}

void displayCipher(int* cipher)
{
	for (int i = 0; i < 20; i++)
	{
		cout << "|" << cipher;
	}
}
