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



void komunikatbledu(std::string nazwapliku);
std::vector<char> wczytywanie(std::string nazwapliku);
std::vector<std::string> normalizacja(std::vector<char> dzialanie, std::string nazwaplikuwyjsciowego);
std::vector<std::string> obs³uga_liczb_ujemnych(std::vector<std::string> dzialanie);
bool czystringjestliczba(std::string string);
bool sprawdzanieargumentowfunkcji(std::vector<std::string> dzialanie);
bool wykrywaniebledow(std::vector<std::string> dzialanie);
std::vector<std::string> przeksztalcenienaonp(std::vector<std::string> dzialanie,std::string sciezkawyjscia);
double obliczanieonp(std::vector<std::string> dzialanie);
void zapisdopliku(std::string nazwapliku, double wynik);
