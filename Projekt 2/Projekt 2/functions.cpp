#include "stdafx.h"
#include "header.h"


void komunikatbledu(std::string nazwapliku) {
	std::fstream wyjscie;
	wyjscie.open(nazwapliku, std::ios::out);
	std::string linia;
	wyjscie << "Dzialanie zawiera bledy!";
	wyjscie.close();
}


std::vector<char> wczytywanie(std::string nazwapliku)				//funkcja wczytujaca dane z pliku
{
	std::vector<char> wynik;
	std::fstream wejscie;
	wejscie.open(nazwapliku, std::ios::in);
	if (wejscie.good() == false)
	{
		std::cout << "Blad pliku wejsciowego!";
		exit(0);

	}
	std::string linia;
	while (std::getline(wejscie, linia)) {
		std::stringstream liniastream = std::stringstream(linia);
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

std::vector<std::string> normalizacja(std::vector<char> dzialanie, std::string nazwaplikuwyjsciowego) {
	std::vector<std::string> wynik;
	char temp;
	int iterator;
	int przelacznik = 3;
	for (int i = 0; i < dzialanie.size(); i++) {
		temp = dzialanie[i];
		std::string liczba, znak;
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
		default: komunikatbledu(nazwaplikuwyjsciowego);
			exit(0);
			break;

		}
	}


	return wynik;
}

std::vector<std::string> obs³uga_liczb_ujemnych(std::vector<std::string> dzialanie) {
	std::vector<std::string> wynik;
	for (int i = 0; i < dzialanie.size(); i++) {
		if (dzialanie[i] == "-") {
			if (i - 1 < 0) {
				wynik.push_back("0");
				wynik.push_back("-");
				wynik.push_back(dzialanie[i + 1]);
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
		}
		else {
			wynik.push_back(dzialanie[i]);
		}
	}



	return wynik;
}

bool czystringjestliczba(std::string string) {
	bool wynik = false;
	int kropki = 0;


	for (int i = 0; i < string.size(); i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			wynik = true;
		}
		else if (string[i] == '.') {
			wynik = true;
			kropki++;
		}
		else {

			return false;
		}
	}
	if (kropki > 1) return false;
	return wynik;
}

bool sprawdzanieargumentowfunkcji(std::vector<std::string> dzialanie) {
	bool wynik1 = true;
	bool wynik2 = true;
	int warstwa1 = 0;
	int warstwa2 = 0;
	for (int i = 0; i < dzialanie.size(); i++) {
		if (dzialanie[i] == ",") {
			wynik1 = false;
			for (int j = i - 1; j >= 0; j--) {

				if (dzialanie[j] == ")") {
					warstwa1++;
				}
				else if (dzialanie[j] == ","&&warstwa1 == 0) {
					wynik1 = false;
					break;
				}
				else if (dzialanie[j] == "(") {
					if (warstwa1 != 0) {
						warstwa1--;
					}
					else {
						if (dzialanie[j - 1] == "log" || dzialanie[j - 1] == "sqrt" || dzialanie[j - 1] == "pow") {
							wynik1 = true;
							break;
						}
						else { wynik1 = false; }
					}
				}
				else { wynik1 = false; }
			}
			wynik2 = false;
			for (int j = i + 1; j < dzialanie.size(); j++) {

				if (dzialanie[j] == "(") {
					warstwa2++;
				}
				else if (dzialanie[j] == ","&&warstwa2 == 0) {
					wynik2 = false;
					break;
				}
				else if (dzialanie[j] == ")") {
					if (warstwa2 != 0) {
						warstwa2--;
					}
					else {
						wynik2 = true;
						break;
					}
				}


			}

		}
	}

	bool wynik3 = true;
	int warstwa3 = 0;
	for (int i = 0; i < dzialanie.size(); i++) {

		if (dzialanie[i] == "log" || dzialanie[i] == "sqrt" || dzialanie[i] == "pow") {
			for (int j = i + 2; j < dzialanie.size(); j++) {
				if (dzialanie[j] == "(") {
					warstwa3++;
				}
				else if (dzialanie[j] == ","&&warstwa3 == 0) {
					wynik3 = true;
					break;
				}
				else if (dzialanie[j] == ")") {
					if (warstwa3 == 0) {
						wynik3 = false;
						break;
					}
					else {
						warstwa3--;
					}
				}
			}
		}

	}




	if (wynik1 == true && wynik2 == true && wynik3 == true) {
		return true;
	}
	else {
		return false;
	}

}

bool wykrywaniebledow(std::vector<std::string> dzialanie) {
	int lnawiasy = 0;
	int pnawiasy = 0;
	for (int i = 0; i < dzialanie.size(); i++) {        //sprawdzanie ilosci lewych i prawych nawiasow
		if (dzialanie[i] == "(") lnawiasy++;
		if (dzialanie[i] == ")") pnawiasy++;
	}
	if (lnawiasy != pnawiasy) {
		return false;
	}

	//zbiory wyrazen ktore moga wystapic po lub przed okreslonym wyrazeniu
	std::set<std::string> funkcje = { "sin" ,"cos","tg","ctg","exp","log","sqrt","abs","ln","pow" };	//wystepowanie:	po prawej od: "+" "-" "*" "/" "," po lewej od: "("
	std::set<std::string> operatory = { "+" ,"-","*","/" };												//wystepowanie:	po lewej od: "("
	std::set<std::string> zbior1 = { "+" ,"-","*","/",")","," };										//wystepowanie:	po prawej od: liczb "e" "pi" ")"
	std::set<std::string> zbior2 = { "+" ,"-","*","/","(","," };										//wystepowanie:	po lewej od: liczb "e" "pi"
	std::set<std::string> zbior3 = { "e","pi","(","-" };												//wystepowanie:	po prawej od: "("
	std::set<std::string> zbior4 = { "e" ,"pi",")" };													//wystepowanie:	po lewej od: ")" "+" "-" "*" "/" ","
	std::set<std::string> zbior5 = { "e" ,"pi","(" };													//wystepowanie:	po prawej od: "+" "*" "/" ","
	std::set<std::string> zbior6 = { "e" ,"pi",")",",","(" };											//wystepowanie:	po prawej od: "-"
	std::set<std::string> zbior7 = { "+" ,"-","*","/","(","," };										//wystepowanie:	po lewej od: funkcje


	//porownuje czy znaki po prawej i lewej stronie od kazdego znaku w dzialaniu sa poprawne, jesli sa niepoprawne funkcja zwraca false
	for (int i = 0; i < dzialanie.size(); i++) {
		if (czystringjestliczba(dzialanie[i])) {
			if (i == dzialanie.size() - 1) {
				;
			}else if (zbior1.find(dzialanie[i + 1]) != zbior1.end()) {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior2.find(dzialanie[i - 1]) != zbior2.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "e") {

			if (i == dzialanie.size() - 1) {
				;
			}else if (zbior1.find(dzialanie[i + 1]) != zbior1.end()) {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior2.find(dzialanie[i - 1]) != zbior2.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "pi") {
			if (i == dzialanie.size() - 1) {
				;
			}else if (zbior1.find(dzialanie[i + 1]) != zbior1.end()) {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior2.find(dzialanie[i - 1]) != zbior2.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "(") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}else if (zbior3.find(dzialanie[i + 1]) != zbior3.end()) {
					;
			}else if (funkcje.find(dzialanie[i + 1]) != funkcje.end()) {
					;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (operatory.find(dzialanie[i - 1]) != operatory.end()) {
				;
			}else if (funkcje.find(dzialanie[i - 1]) != funkcje.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == ")") {
			if (i == dzialanie.size() - 1) {
				;
			}else if (zbior1.find(dzialanie[i + 1]) != zbior1.end()) {
				;
			}else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}else if (zbior4.find(dzialanie[i - 1]) != zbior4.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "+") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}else if (zbior5.find(dzialanie[i + 1]) != zbior5.end()) {
				;
			}else if (funkcje.find(dzialanie[i + 1]) != funkcje.end()) {
				;
			}else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}else if (zbior4.find(dzialanie[i - 1]) != zbior4.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "-") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}else if (zbior6.find(dzialanie[i + 1]) != zbior6.end()) {
				;
			}else if (funkcje.find(dzialanie[i + 1]) != funkcje.end()) {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}else if (zbior4.find(dzialanie[i - 1]) != zbior4.end()) {
				;
			}else if (dzialanie[i - 1] == "(") {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "*") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}else if (zbior5.find(dzialanie[i + 1]) != zbior5.end()) {
				;
			}else if (funkcje.find(dzialanie[i + 1]) != funkcje.end()) {
				;
			}else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}else if (zbior4.find(dzialanie[i - 1]) != zbior4.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "/") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}else if (zbior5.find(dzialanie[i + 1]) != zbior5.end()) {
				;
			}else if (funkcje.find(dzialanie[i + 1]) != funkcje.end()) {
				;
			}else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}else if (zbior4.find(dzialanie[i - 1]) != zbior4.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == ",") {
			if (czystringjestliczba(dzialanie[i + 1])) {
				;
			}else if (zbior5.find(dzialanie[i + 1]) != zbior5.end()) {
				;
			}else if (funkcje.find(dzialanie[i + 1]) != funkcje.end()) {
				;
			}else {
				return false;
			}
			if (czystringjestliczba(dzialanie[i - 1])) {
				;
			}else if (zbior4.find(dzialanie[i - 1]) != zbior4.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "sin") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "cos") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "tg") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "ctg") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "exp") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "log") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "sqrt") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "abs") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "ln") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}
		else if (dzialanie[i] == "pow") {
			if (dzialanie[i + 1] == "(") {
				;
			}else {
				return false;
			}
			if (i == 0) {
				;
			}else if (zbior7.find(dzialanie[i - 1]) != zbior7.end()) {
				;
			}else {
				return false;
			}
		}else {
			return false;
		}
	}



	if (!sprawdzanieargumentowfunkcji(dzialanie)) {			//funkcja sprawdza czy funkcje posiadaja odpowiednie argumenty
		return false;
	}





}

std::vector<std::string> przeksztalcenienaonp(std::vector<std::string> dzialanie, std::string sciezkawyjscia) {
	std::stack <std::string> stos;				//utworzenie stosu wykorzystywanego przy przeksztalceniu na ONP
	std::vector<std::string> wyjscie;			//utworzenie wyjscia
	std::string temp;							//pomocniczy string


	//implementacja algorytmu na przeksztalcenie na ONP
	for (int i = 0; i < dzialanie.size(); i++) {			//petla przez cale dzialanie
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
				if (stos.empty()) {
					komunikatbledu(sciezkawyjscia);
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
					}
					else if (stos.top() == "-") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() == "+") {
						wyjscie.push_back(stos.top());
						stos.pop();
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
		else if (dzialanie[i] == "-") {
			for (int i = 0; i < 2; i++) {
				while (true) {
					if (stos.empty() == true) {
						break;
					}
					else if (stos.top() == "-") {
						wyjscie.push_back(stos.top());
						stos.pop();
					}
					else if (stos.top() == "+") {
						wyjscie.push_back(stos.top());
						stos.pop();
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
		else if (dzialanie[i] == ",") {
			while (dzialanie[i] == "(") {
				if (stos.empty()) {
					komunikatbledu(sciezkawyjscia);
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
			komunikatbledu(sciezkawyjscia);
			exit(0);
		}
		else if (stos.top() == ")") {
			komunikatbledu(sciezkawyjscia);
			exit(0);
		}
		else {
			wyjscie.push_back(stos.top());
			stos.pop();
		}
	}
	return wyjscie;
}

double obliczanieonp(std::vector<std::string> dzialanie) {
	double wynik; //ostateczny wynik dzialania
	std::stack <std::string> stos; //utworzenie stosu wykorzystywanego do obliczania wyrazenia ONP
	for (int i = 0; i < dzialanie.size(); i++) {
		if (dzialanie[i] == "e") {
			stos.push("2.71828182845904523536028747135266249775724709369995");  //zamiana e na przyblizona wartosc
		}
		else if (dzialanie[i] == "pi") {
			stos.push("3.141592653589793238462643383279502884197169399375105"); //zamiana pi na przyblizona wartosc
		}
		else if (dzialanie[i] == "+") {
			double liczba1, liczba2, wynik;		//pomocnicze zmienne
			std::string liczba, wynikstring;	//pomocnicze stringi	
			liczba = stos.top();		//pobranie stringa liczba ze stosu
			liczba1 = atof(liczba.c_str());		//zamiana string na double
			stos.pop();						//usuniecie elementu ze stosu
			liczba = stos.top();			//pobranie drugiego stringa ze stosu
			liczba2 = atof(liczba.c_str());		//zamiana string na double
			stos.pop();						//usuniecie elementu ze stosu
			wynik = liczba1 + liczba2;		//wykonanie dzialania
			wynikstring = std::to_string(wynik);	//zamiana wyniku typu double na string
			stos.push(wynikstring);		//wepchniecie wyniku na stos

		}
		else if (dzialanie[i] == "-") {
			double liczba1, liczba2, wynik;
			std::string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = liczba2 - liczba1;
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "*") {
			double liczba1, liczba2, wynik;
			std::string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = liczba1 * liczba2;
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "/") {
			double liczba1, liczba2, wynik;
			std::string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = (liczba2 / liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "sin") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.0174533; //zamiana stopni na radiany
			stos.pop();
			wynik = sin(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "cos") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.0174533;
			stos.pop();
			wynik = cos(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "tg") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.0174533;
			stos.pop();
			wynik = tan(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "ctg") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			liczba1 = liczba1 * 0.01745329;
			stos.pop();
			wynik = 1 / tan(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "exp") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			wynik = exp(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "log") {
			double liczba1, liczba2, wynik;
			std::string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = log(liczba2) / log(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "sqrt") {
			double liczba1, liczba2, wynik;
			std::string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = pow(liczba2, 1 / liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "abs") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			wynik = abs(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "ln") {
			std::string liczba, wynikstring;
			double liczba1, wynik;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			wynik = log(liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else if (dzialanie[i] == "pow") {
			double liczba1, liczba2, wynik;
			std::string liczba, wynikstring;
			liczba = stos.top();
			liczba1 = atof(liczba.c_str());
			stos.pop();
			liczba = stos.top();
			liczba2 = atof(liczba.c_str());
			stos.pop();
			wynik = pow(liczba2, liczba1);
			wynikstring = std::to_string(wynik);
			stos.push(wynikstring);
		}
		else {
			stos.push(dzialanie[i]);
		}


	}
	std::string liczba;
	liczba = stos.top();
	wynik = atof(liczba.c_str());
	return wynik;
}

void zapisdopliku(std::string nazwapliku, double wynik) {
	std::fstream wyjscie;
	wyjscie.open(nazwapliku, std::ios::out);
	std::string linia;
	wyjscie << wynik;
	wyjscie.close();
}