#pragma once
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <set>

using namespace std;

void komunikatbledu(string nazwapliku);
vector<char> wczytywanie(string nazwapliku);
vector<string> normalizacja(vector<char> dzialanie, string nazwaplikuwyjsciowego);
vector<string> obs³uga_liczb_ujemnych(vector<string> dzialanie);
bool czystringjestliczba(string string);
bool sprawdzanieargumentowfunkcji(vector<string> dzialanie);
bool wykrywaniebledow(vector<string> dzialanie);
vector<string> przeksztalcenienaonp(vector<string> dzialanie);
double obliczanieonp(vector<string> dzialanie);
void zapisdopliku(string nazwapliku, double wynik);
