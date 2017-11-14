// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void insertSort(float tab[], int size)
{
	int i, j, value;

	for (i = 1; i < size; ++i)
	{
		value = tab[i];
		for (j = i - 1; j >= 0 && tab[j] > value; --j)
		{
			tab[j + 1] = tab[j];
		}
		tab[j + 1] = value;
	}
}

int main()
{
	float tab[5] = { 1, 3, -55, -1, 2 };
	for (int i = 0; i < 5; i++) {
		std::cout << tab[i] << "  ";
	}
	std::cout << std::endl;
	insertSort(tab, 5);
	for (int i = 0; i < 5; i++) {
	std::cout << tab[i] << "  ";
	}
    return 0;
}

