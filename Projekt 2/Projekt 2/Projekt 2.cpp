// Projekt 2.cpp : Defines the entry point for the console application.
//



#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include "header.h"

using namespace std;




int main(int argc, char *argv[])
{
	int j = 1;
	string sciezkawejscia;
	string sciezkawyjscia;

	while (j < argc) {							//odczyt parametrow programu
		string text = string(argv[j]);
		if (text == "-i") {
			sciezkawejscia = argv[j + 1];
			j = j + 2;
		}
		else {
			if (text == "-o") {
				sciezkawyjscia = argv[j + 1];
				j = j + 2;
			}
			else {
				cout << "Nieprawidlowe parametry wywolania!" << endl;
				system("PAUSE");
				return 0;
			}
		}
	}
	

	vector<char> dzialanie= wczytywanie(sciezkawejscia);

	for (int i = 0; i < dzialanie.size(); i++) {
		cout << dzialanie[i] << " ";
	}
	cout << endl;

	vector<string> wynik2=normalizacja(dzialanie,sciezkawyjscia);

	for (int i = 0; i < wynik2.size(); i++) {
		cout << wynik2[i] << " ";
	}
	cout << endl;

	if (!wykrywaniebledow(wynik2)) {
		cout << "Dzialanie zawiera bledy!";
		komunikatbledu(sciezkawyjscia);
		return 0;
	}

	vector<string> wynik=obsługa_liczb_ujemnych(wynik2);
	
	for (int i = 0; i < wynik.size(); i++) {
		cout << wynik[i] << " ";
	}
	cout << endl;



	vector<string>dzialaniewonp=przeksztalcenienaonp(wynik);

	for (int i = 0; i < dzialaniewonp.size(); i++) {
		cout << dzialaniewonp[i] << " ";
	}

	cout << endl;

	zapisdopliku(sciezkawyjscia, obliczanieonp(dzialaniewonp));




	cout << obliczanieonp(dzialaniewonp);


       return 0;
}

