// Projekt 2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "header.h"






int main(int argc, char *argv[])
{
	int j = 1;
	std::string sciezkawejscia;
	std::string sciezkawyjscia;

	while (j < argc) {							//odczyt parametrow programu
		std::string text = std::string(argv[j]);
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
				std::cout << "Nieprawidlowe parametry wywolania!" << std::endl;
				return 0;
			}
		}
	}
	

	std::vector<char> dzialanie= wczytywanie(sciezkawejscia);			//wywolanie funkcji wczytujacej dzialanie z pliku

	std::vector<std::string> wynik2=normalizacja(dzialanie,sciezkawyjscia);	//wywolanie funkcji laczacej chary w stringi



	if (!wykrywaniebledow(wynik2)) {								//wywolanie sprawdzajacej poprawnosc dzialania
		std::cout << "Dzialanie zawiera bledy!";
		komunikatbledu(sciezkawyjscia);
		return 0;
	}

	std::vector<std::string> wynik=obsługa_liczb_ujemnych(wynik2);			//wywolanie funkcji umozliwajacej obsluge liczb ujemnych
	



	std::vector<std::string>dzialaniewonp=przeksztalcenienaonp(wynik,sciezkawyjscia);		//wywolanie funkcji wczytujacej dzialanie z pliku



	zapisdopliku(sciezkawyjscia, obliczanieonp(dzialaniewonp));		//wywolanie funkcji zapisujacej wynik do pliku




       return 0;
}

