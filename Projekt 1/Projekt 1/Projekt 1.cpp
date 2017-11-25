// Projekt 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void odczyt1(double W1[],int maxwsp1) {
	int i = 0;
	std::string temp;
	std::fstream wejscie;
	wejscie.open("wejscie.txt", std::ios::in);

	if (wejscie.good() == false) std::cout << "Nie mozna otworzyc pliku!";

	while (getline(wejscie, temp))
	{
		W1[i] = atoi(temp.c_str());
		i++;
		maxwsp1++;
	}

	wejscie.close();
}


void odczyt2(double W2[], int maxwsp2) {
	int i = 0;
	std::string temp;
	std::fstream wejscie2;
	wejscie2.open("wejscie2.txt", std::ios::in);

	if (wejscie2.good() == false) std::cout << "Nie mozna otworzyc pliku!";

	while (getline(wejscie2, temp))
	{
		W2[i] = atoi(temp.c_str());
		i++;
		maxwsp2++;
	}

	wejscie2.close();
}


void suma(double W1[], double W2[],double W3[],int maxwsp) {
	
	for (int i = 0; i < 100; i++) {
		W3[i] = W2[i] + W1[i];
	}
	std::fstream wyjscie;
	wyjscie.open("wyjscie.txt", std::ios::out);

	for (int j = 0; j < maxwsp; j++) {
		wyjscie << W3[j] << std::endl;
	}

}
void roznica(double W1[], double W2[], double W3[],int maxwsp) {

	for (int i = 0; i < 100; i++) {
		W3[i] = W1[i] - W2[i];

		std::fstream wyjscie;
		wyjscie.open("wyjscie.txt", std::ios::out);

		for (int j = 0; j < maxwsp; j++) {
			wyjscie << W3[j] << std::endl;
		}
	}
}
void iloczyn(double W1[], double W2[], double W3[],double W4[],int maxwsp1,int maxwsp2,int maxwsp) {
	int k = 0;
	for (int i = 0; i < maxwsp1; i++) {
		for (int j = 0; j < maxwsp2; j++) {
			W3[k] = W1[i] * W2[j];
			k++;
		}
	}
	for (int i = 0; i < maxwsp1; i++) {
		for (int j = 0; j < maxwsp2; j++) {

			W4[i+j] += W3[i*maxwsp+j];
		}
	}
	std::fstream wyjscie;
	wyjscie.open("wyjscie.txt", std::ios::out);

	for (int j = 0; j < maxwsp1*maxwsp2; j++) {
		wyjscie << W4[j] << std::endl;
	}

}


int main()
{
	double W1[100] = { 0 };
	double W2[100] = { 0 };
	double W3[10000] = { 0 };
	double W4[10000] = { 0 };
	int maxwsp;
	int maxwsp1 = 0;
	int maxwsp2 = 0;
	odczyt1(W1, maxwsp1);
	odczyt2(W2, maxwsp2);
	if (maxwsp1 > maxwsp2) {
		maxwsp = maxwsp1;
	}
	else {
		maxwsp = maxwsp2;
	}

	std::cout << "Witaj w programie sluzacym do wykonywania prostych dzialan na wielomianach." << std::endl;
	std::cout << "Wielomiany wejsciowe powynny zostac uieszczone w plikach 'wejscie.txt' oraz 'wejscie2.txt' w formie wspolczynnikow zaczynajac od najmniejszego i oddzielone od siebie kolejnymi liniami." << std::endl;
	std::cout << "Jakie dzialanie chcesz wykonac?" << std::endl;
	std::cout << "1.Dodawanie" << std::endl;
	std::cout << "2.Odejmowanie" << std::endl;
	std::cout << "3.Mnozenie" << std::endl;
	std::cout << "Proszę wprowadzic odpowiednia cyfre:" << std::endl;
	int a;
	std::cin >> a;
	if (a == 1) {
		suma(W1, W2, W3, maxwsp);
	}
	else {
		if (a == 2) {
			roznica(W1, W2, W3, maxwsp);
		}
		else {
			if (a == 3) {
				iloczyn(W1,W2,W3,W4, maxwsp1,maxwsp2,maxwsp);
			}
			else {
				std::cout << "Niepoprawny znak!";
			}

		}
	}


	return 0;
}

