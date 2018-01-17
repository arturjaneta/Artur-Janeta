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
#include <stack>
using namespace std;

vector<char> wczytywanie(string nazwapliku)				//funkcja wczytujaca dane z pliku
{
	vector<char> wynik;
	fstream wejscie;
	wejscie.open(nazwapliku, ios::in);
	string linia;
	while (getline(wejscie, linia)) {
		stringstream liniastream = stringstream(linia);
		while (!liniastream.eof()) {
			char znak;
			liniastream >> znak;
			wynik.push_back(znak);
		}

	}
	wynik.pop_back();
	wejscie.close();
	return wynik;
}

vector<string> normalizacja(vector<char> dzialanie) {
	vector<string> wynik;
	char temp;
	int iterator;
	int przelacznik = 3;
	for (int i = 0; i < dzialanie.size(); i++) {
		temp = dzialanie[i];
		string liczba, znak;
		switch (temp) {
		case '0':;
		case '1':;
		case '2':;
		case '3':;
		case '4':;
		case '5':;
		case '6':;
		case '7':;
		case '8':;
		case '9':;
		case '.':if (przelacznik == 1) {
			liczba.push_back(temp);
			wynik.back() += liczba;
		}
				 else {
					 liczba.push_back(temp);
					 wynik.push_back(liczba);
		}
				 przelacznik = 1;	break;

		case '-':;
		case '+':;
		case '*':;
		case '/':;
		case ')':;
		case ',':;
		case '(': znak.push_back(temp); wynik.push_back(znak); przelacznik = 3; break;
		case 's':;
		case 'i':;
		case 'n':;
		case 'c':;
		case 'o':;
		case 't':;
		case 'g':;
		case 'e':;
		case 'x':;
		case 'p':;
		case 'l':;
		case 'q':;
		case 'r':;
		case 'a':;
		case 'b':;
		case 'w':if (przelacznik == 2) {
			znak.push_back(temp);
			wynik.back() += znak;
		}
				 else {
					 znak.push_back(temp); wynik.push_back(znak);
				 };

		przelacznik = 2; break;
		default: cout << "Dzialanie zawiera bledy!";
			exit(0);
			break;

		}
	}


	return wynik;
}

vector<string> obsługa_liczb_ujemnych(vector<string> dzialanie) {
	vector<string> wynik;
	for (int i = 0; i < dzialanie.size(); i++) {
		if (dzialanie[i] == "-") {
			if (i - 1 < 0) {
				wynik.push_back("0");
				wynik.push_back("-");
				wynik.push_back(dzialanie[i+1]);
				i++;
			}
			else if (dzialanie[i - 1] == "(") {
				wynik.push_back("0");
				wynik.push_back("-");
				wynik.push_back(dzialanie[i + 1]);
				i++;
			}
			else if (dzialanie[i - 1] == ",") {
				wynik.push_back("0");
				wynik.push_back("-");
				wynik.push_back(dzialanie[i + 1]);
				i++;
			}
			else {
				wynik.push_back(dzialanie[i]);
			}
		}else {
			wynik.push_back(dzialanie[i]);
		}
	}
	
	
	
	return wynik;
}

bool czystringjestliczba(string string) {
	bool wynik;
	int kropki = 0;
	/*if (string[0] >= '0' && string[0] <= '9') {
		wynik = true;
	}
	else {
		return false;
	}
	if (string[string.size() - 2] >= '0' && string[string.size() - 2] <= '9') {
		wynik = true;
	}
	else {
		return false;
	}*/


	for (int i = 0; i < string.size() - 1; i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			wynik == true;
		}
		else if(string[i]=='.'){
			wynik == true;
				kropki++;
		}
		else {
			if (i == 0) {
				if (string[i] == '-') { wynik == true; }
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	if (kropki > 1) return false;
	return wynik;
}


bool wykrywaniebledow(vector<string> dzialanie) {
	int lnawiasy=0;
	int pnawiasy=0;
	for (int i = 0; i < dzialanie.size(); i++) {        //sprawdzanie ilosci lewych i prawych nawiasow
		if (dzialanie[i] == "(") lnawiasy++;
		if (dzialanie[i] == ")") pnawiasy++;
	}
	if (lnawiasy != pnawiasy) {
		return false;
	}

	


	for (int i = 0; i < dzialanie.size(); i++) {
		if (czystringjestliczba(dzialanie[i])) {
			
			if (i==dzialanie.size()) {
				;
			}
			else if (dzialanie[i + 1] == "+") {
				;
			}else if(dzialanie[i + 1] == "-") {
				;
			}
			else if (dzialanie[i + 1] == "*") {
				;
			}
			else if (dzialanie[i + 1] == "/") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else {
				return false;
			}
			if (i==0) {
			;
			}else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;}
		}else if (dzialanie[i] == "e") {

			if (i==dzialanie.size()) {
				;
			}
			else if (dzialanie[i + 1] == "+") {
				;
			}else if(dzialanie[i + 1] == "-") {
				;
			}
			else if (dzialanie[i + 1] == "*") {
				;
			}
			else if (dzialanie[i + 1] == "/") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else {
				return false;
			}
			if (i==0) {
			;
			}else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;}
		}else if (dzialanie[i] == "pi") {
			if (i == dzialanie.size()) {
				;
			}
			else if (dzialanie[i + 1] == "+") {
				;
			}
			else if (dzialanie[i + 1] == "-") {
				;
			}
			else if (dzialanie[i + 1] == "*") {
				;
			}
			else if (dzialanie[i + 1] == "/") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "(") {
			if (czystringjestliczba(dzialanie[i+1])) {
				;
			}
			else if (dzialanie[i + 1] == "e") {
				;
			}
			else if (dzialanie[i + 1] == "pi") {
				;
			}
			else if (dzialanie[i + 1] == "(") {
				;
			}
			else if (dzialanie[i + 1] == "-") {
				;
			}
			else if (dzialanie[i + 1] == "sin") {
				;
			}
			else if (dzialanie[i + 1] == "cos") {
				;
			}
			else if (dzialanie[i + 1] == "tg") {
				;
			}
			else if (dzialanie[i + 1] == "ctg") {
				;
			}
			else if (dzialanie[i + 1] == "exp") {
				;
			}
			else if (dzialanie[i + 1] == "log") {
				;
			}
			else if (dzialanie[i + 1] == "sqrt") {
				;
			}
			else if (dzialanie[i + 1] == "abs") {
				;
			}
			else if (dzialanie[i + 1] == "ln") {
				;
			}
			else if (dzialanie[i + 1] == "pow") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "sin") {
				;
			}
			else if (dzialanie[i - 1] == "cos") {
				;
			}
			else if (dzialanie[i - 1] == "tg") {
				;
			}
			else if (dzialanie[i - 1] == "ctg") {
				;
			}
			else if (dzialanie[i - 1] == "exp") {
				;
			}
			else if (dzialanie[i - 1] == "log") {
				;
			}
			else if (dzialanie[i - 1] == "sqrt") {
				;
			}
			else if (dzialanie[i - 1] == "abs") {
				;
			}
			else if (dzialanie[i - 1] == "ln") {
				;
			}
			else if (dzialanie[i - 1] == "pow") {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == ")") {
			if (i=dzialanie.size()) {
				;
			}
			else if (dzialanie[i + 1] == "+") {
				;
			}
			else if (dzialanie[i + 1] == "-") {
				;
			}
			else if (dzialanie[i + 1] == "*") {
				;
			}
			else if (dzialanie[i + 1] == "/") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}
			else if (dzialanie[i - 1] == "e") {
				;
			}
			else if (dzialanie[i - 1] == "pi") {
				;
			}
			else if (dzialanie[i - 1] == ")") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "+") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}
			else if (dzialanie[i + 1] == "e") {
				;
			}
			else if (dzialanie[i + 1] == "pi") {
				;
			}
			else if (dzialanie[i + 1] == "(") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == "sin") {
				;
			}
			else if (dzialanie[i + 1] == "cos") {
				;
			}
			else if (dzialanie[i + 1] == "tg") {
				;
			}
			else if (dzialanie[i + 1] == "ctg") {
				;
			}
			else if (dzialanie[i + 1] == "exp") {
				;
			}
			else if (dzialanie[i + 1] == "log") {
				;
			}
			else if (dzialanie[i + 1] == "sqrt") {
				;
			}
			else if (dzialanie[i + 1] == "abs") {
				;
			}
			else if (dzialanie[i + 1] == "ln") {
				;
			}
			else if (dzialanie[i + 1] == "pow") {
				;
			}
			else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}
			else if (dzialanie[i - 1] == "e") {
				;
			}
			else if (dzialanie[i - 1] == "pi") {
				;
			}
			else if (dzialanie[i - 1] == ")") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "-") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}
			else if (dzialanie[i + 1] == "e") {
				;
			}
			else if (dzialanie[i + 1] == "pi") {
				;
			}
			else if (dzialanie[i + 1] == "(") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == "sin") {
				;
			}
			else if (dzialanie[i + 1] == "cos") {
				;
			}
			else if (dzialanie[i + 1] == "tg") {
				;
			}
			else if (dzialanie[i + 1] == "ctg") {
				;
			}
			else if (dzialanie[i + 1] == "exp") {
				;
			}
			else if (dzialanie[i + 1] == "log") {
				;
			}
			else if (dzialanie[i + 1] == "sqrt") {
				;
			}
			else if (dzialanie[i + 1] == "abs") {
				;
			}
			else if (dzialanie[i + 1] == "ln") {
				;
			}
			else if (dzialanie[i + 1] == "pow") {
				;
			}
			else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}
			else if (dzialanie[i - 1] == "e") {
				;
			}
			else if (dzialanie[i - 1] == "pi") {
				;
			}
			else if (dzialanie[i - 1] == ")") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "*") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}
			else if (dzialanie[i + 1] == "e") {
				;
			}
			else if (dzialanie[i + 1] == "pi") {
				;
			}
			else if (dzialanie[i + 1] == "(") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == "sin") {
				;
			}
			else if (dzialanie[i + 1] == "cos") {
				;
			}
			else if (dzialanie[i + 1] == "tg") {
				;
			}
			else if (dzialanie[i + 1] == "ctg") {
				;
			}
			else if (dzialanie[i + 1] == "exp") {
				;
			}
			else if (dzialanie[i + 1] == "log") {
				;
			}
			else if (dzialanie[i + 1] == "sqrt") {
				;
			}
			else if (dzialanie[i + 1] == "abs") {
				;
			}
			else if (dzialanie[i + 1] == "ln") {
				;
			}
			else if (dzialanie[i + 1] == "pow") {
				;
			}
			else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}
			else if (dzialanie[i - 1] == "e") {
				;
			}
			else if (dzialanie[i - 1] == "pi") {
				;
			}
			else if (dzialanie[i - 1] == ")") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "/") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}
			else if (dzialanie[i + 1] == "e") {
				;
			}
			else if (dzialanie[i + 1] == "pi") {
				;
			}
			else if (dzialanie[i + 1] == "(") {
				;
			}
			else if (dzialanie[i + 1] == ",") {
				;
			}
			else if (dzialanie[i + 1] == ")") {
				;
			}
			else if (dzialanie[i + 1] == "sin") {
				;
			}
			else if (dzialanie[i + 1] == "cos") {
				;
			}
			else if (dzialanie[i + 1] == "tg") {
				;
			}
			else if (dzialanie[i + 1] == "ctg") {
				;
			}
			else if (dzialanie[i + 1] == "exp") {
				;
			}
			else if (dzialanie[i + 1] == "log") {
				;
			}
			else if (dzialanie[i + 1] == "sqrt") {
				;
			}
			else if (dzialanie[i + 1] == "abs") {
				;
			}
			else if (dzialanie[i + 1] == "ln") {
				;
			}
			else if (dzialanie[i + 1] == "pow") {
				;
			}
			else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}
			else if (dzialanie[i - 1] == "e") {
				;
			}
			else if (dzialanie[i - 1] == "pi") {
				;
			}
			else if (dzialanie[i - 1] == ")") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == ",") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}
			else if (dzialanie[i + 1] == "e") {
				;
			}
			else if (dzialanie[i + 1] == "pi") {
				;
			}
			else if (dzialanie[i + 1] == "(") {
				;
			}
			else if (dzialanie[i + 1] == "sin") {
				;
			}
			else if (dzialanie[i + 1] == "cos") {
				;
			}
			else if (dzialanie[i + 1] == "tg") {
				;
			}
			else if (dzialanie[i + 1] == "ctg") {
				;
			}
			else if (dzialanie[i + 1] == "exp") {
				;
			}
			else if (dzialanie[i + 1] == "log") {
				;
			}
			else if (dzialanie[i + 1] == "sqrt") {
				;
			}
			else if (dzialanie[i + 1] == "abs") {
				;
			}
			else if (dzialanie[i + 1] == "ln") {
				;
			}
			else if (dzialanie[i + 1] == "pow") {
				;
			}
			else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}
			else if (dzialanie[i - 1] == "e") {
				;
			}
			else if (dzialanie[i - 1] == "pi") {
				;
			}
			else if (dzialanie[i - 1] == ")") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "sin") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i==0) {
				continue;
			}
			else if (dzialanie[i - 1] == "-") {
				continue;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "cos") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "tg") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "ctg") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "exp") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "log") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "sqrt") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "abs") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "ln") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else if (dzialanie[i] == "pow") {
			if (dzialanie[i + 1] == "(") {
				;
			}
			else {
				return false;
			}
			if (i == 0) {
				;
			}
			else if (dzialanie[i - 1] == "-") {
				;
			}
			else if (dzialanie[i - 1] == "+") {
				;
			}
			else if (dzialanie[i - 1] == "*") {
				;
			}
			else if (dzialanie[i - 1] == "/") {
				;
			}
			else if (dzialanie[i - 1] == "(") {
				;
			}
			else if (dzialanie[i - 1] == ",") {
				;
			}
			else {
				return false;
			}
		}
		else {
		
		}
	}


}


vector<string> przeksztalcenienaonp(vector<string> dzialanie) {
	stack <string> stos;
	vector<string> wyjscie;
	string temp;

	for (int i = 0; i < dzialanie.size(); i++) {
		if (dzialanie[i] == "e") {
			wyjscie.push_back(dzialanie[i]);
		}
		else if (dzialanie[i] == "pi") {
			wyjscie.push_back(dzialanie[i]);
		}
		else if (dzialanie[i] == "(") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == ")") {
			while (stos.top() != "(") {
				if(stos.empty()){
					cout << "Dzialanie zawiera bledy!";
					exit(0);
				}
				else {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
			}
			stos.pop();
			if (stos.empty() == false) {
				if (stos.top() == "sin") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "cos") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "tg") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "ctg") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "exp") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "log") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "sqrt") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "abs") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "ln") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
				else if (stos.top() == "pow") {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
			}
		}
		else if (dzialanie[i] == "+") {
			for (int i = 0; i < 2; i++) {
				while (true) {
					if (stos.empty() == true) {
						break;
					}else if(stos.top() == "-"){
						wyjscie.push_back(stos.top());
						stos.pop();
						}
					else if (stos.top() == "+") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() =="*") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() =="/") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else{
						break;
						}
				}
			}
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "-") {
			for (int i = 0; i < 2; i++) {
				while (true) {
					if (stos.empty() == true) {
						break;
					}
					else if (stos.top() == "-" ) {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() ==  "+") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() == "*") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() =="/") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else {
						break;
					}
				}
			}
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "*") {
			for (int i = 0; i < 2; i++) {
				while (true) {
					if (stos.empty() == true) {
						break;
					}
					else if (stos.top() == "*") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() == "/") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else {
						break;
					}
				}
			}
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "/") {
			for (int i = 0; i < 2; i++) {
				while (true) {
					if (stos.empty() == true) {
						break;
					}
					else if (stos.top() == "*") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() =="/") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else {
						break;
					}
				}
			}
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == ",") {
			while (dzialanie[i] == "(") {
				if (stos.empty()) {
					cout << "Dzialanie zawiera bledy!";
					exit(0);
				}
				else {
					wyjscie.push_back(stos.top());
					stos.pop();
				}
			}
		}
		else if (dzialanie[i] == "sin") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "cos") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "tg") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "ctg") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "exp") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "log") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "sqrt") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "abs") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "ln") {
			stos.push(dzialanie[i]);
		}
		else if (dzialanie[i] == "pow") {
			stos.push(dzialanie[i]);
		}
		else {
			wyjscie.push_back(dzialanie[i]);
		}

	}
	while (!stos.empty()) {
		if (stos.top() == "(") {
			cout << "Dzialanie zawiera bledy!";
			exit(0);
		}
		else if (stos.top() == ")") {
			cout << "Dzialanie zawiera bledy!";
			exit(0);
		}
		else {
			wyjscie.push_back(stos.top());
			stos.pop();
		}
	}
	return wyjscie;
}

double obliczanieonp(vector<string> dzialanie) {
	double wynik;
	stack <string> stos;
	for (int i = 0; i < dzialanie.size(); i++) {
		if (dzialanie[i] == "e") {
			stos.push("2.71828182845904523536028747135266249775724709369995");
		}
		else if (dzialanie[i] == "pi") {
			stos.push("3.141592653589793238462643383279502884197169399375105");
		}
		else if (dzialanie[i] == "+") {
			double liczba1,liczba2,wynik;
			string liczba,wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = liczba1 + liczba2;
			wynikstring = to_string(wynik);
			stos.push(wynikstring);

		}
		else if (dzialanie[i] == "-") {
			double liczba1, liczba2, wynik;
			string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = liczba2 - liczba1;
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "*") {
			double liczba1, liczba2, wynik;
			string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = liczba1 * liczba2;
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "/") {
			double liczba1, liczba2, wynik;
			string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = (liczba2 / liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "sin") {
			string liczba,wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 *0.0174533;
			stos.pop();
			wynik = sin(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "cos") {
			string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.0174533;
			stos.pop();
			wynik = cos(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "tg") {
			string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.0174533;
			stos.pop();
			wynik = tan(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "ctg") {
			string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.01745329;
			stos.pop();
			wynik = 1/tan(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "exp") {
			string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			wynik = exp(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "log") {
			double liczba1, liczba2, wynik;
			string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = log(liczba2)/log(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "sqrt") {
			double liczba1, liczba2, wynik;
			string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = pow(liczba2, 1/liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "abs") {
			string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			wynik = abs(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "ln") {
			string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			wynik = log(liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "pow") {
			double liczba1, liczba2, wynik;
			string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = pow(liczba2,liczba1);
			wynikstring = to_string(wynik);
			stos.push(wynikstring);
		}
		else {
			stos.push(dzialanie[i]);
		}


	}
	string liczba;
	liczba = stos.top();
	wynik=atof(liczba.c_str());
	return wynik;
}

void zapisdopliku(string nazwapliku,double wynik) {
	fstream wyjscie;
	wyjscie.open(nazwapliku, ios::out);
	string linia;
	wyjscie << wynik;
	wyjscie.close();
}


int main()
{
	
	vector<char> dzialanie= wczytywanie("wejscie.txt");

	for (int i = 0; i < dzialanie.size(); i++) {
		cout << dzialanie[i] << " ";
	}
	cout << endl;

	vector<string> wynik2=normalizacja(dzialanie);

	for (int i = 0; i < wynik2.size(); i++) {
		cout << wynik2[i] << " ";
	}
	cout << endl;

	if (!wykrywaniebledow(wynik2)) {
		cout << "Dzialanie zawiera bledy!";
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

	zapisdopliku("wyjscie.txt", obliczanieonp(dzialaniewonp));




	cout << obliczanieonp(dzialaniewonp);


       return 0;
}

