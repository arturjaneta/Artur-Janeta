// Projekt 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
using namespace std;

vector<string> wczytywanie(string nazwapliku)				//funkcja wczytujaca dane z pliku
{
	vector<string> wynik;
	fstream wejscie;
	wejscie.open(nazwapliku, ios::in);
	string linia;
	while (getline(wejscie, linia)) {
		stringstream liniastream = stringstream(linia);
		while (!liniastream.eof()) {
			string znak;
			liniastream >> znak;
			wynik.push_back(znak);
		}

	}

	wejscie.close();
	return wynik;
}





int main()
{
	
	vector<string> dzialanie= wczytywanie("wejscie.txt");
	for (int i = 0; i < dzialanie.size(); i++) {
		cout << dzialanie[i] << " ";
	}


       return 0;
}

