// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
void printarray(int**array, int depth) {
	int k = 1;
	for (int i = 0; i < depth; i++) {
		if (i < depth / 2) {
			for (int j = 0; j < pow(2, i); j++) {
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
		else {
			for (int j = 0; j < pow(2, depth - i - 1); j++) {
				std::cout << array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
}


void fillarray(int depth) {
	int ** tablica = new int *[depth];
	int m = 1;
	for (int i = 0; i < depth; i++) {
		if (i < depth / 2) {
			tablica[i] = new int[m];
			m = m * 2;
		}
		else {
			tablica[i] = new int[m];
			m = m / 2;
		}

	}
	int l = 1;
	for (int i = 0; i < depth; i++) {
		if (i < depth / 2) {
			for (int j = 0; j <pow(2,i); j++) {
				tablica[i][j] = l;
				l++;
			}
		}else{
				for (int j = 0; j <pow(2,depth-i-1); j++) {
					tablica[i][j] = l;
					l++;
			}
		}
	}

	printarray(tablica, depth);
	for (int i = 0; i < depth; i++) {
		delete []tablica[i];
	}
	delete []tablica;


}




int main()
{

	fillarray(6);


    return 0;
}

