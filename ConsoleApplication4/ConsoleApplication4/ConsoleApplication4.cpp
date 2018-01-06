// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct element {
	int liczba;
	element *next;
};

void addfront(element *&start) {
	element *temp;
	temp = new element;
	int a;
	cout << "Podaj liczbe:";
	cin >> a;
	temp->liczba = a;
	temp->next = start;
	start = temp;

}
void addback(element *&start) {
	element *p,*e;
	e = new element;
	int a;
	cout << "Podaj liczbe:";
	cin >> a;
	e->liczba = a;
	e->next = NULL;
	p = start;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = e;
}

void addinside(element *&start) {

	int a,b;
	cout << "Podaj pozycje:";
	cin >> a;
	if (a == 1) {
		addfront(start);
	}else {
		element *p, *e;
		p = start;
		int numer = 1;
		while (p) {
			p = p->next;
			numer++;
		}
		p = start;
		if (a < numer + 1 && a>1) {
			e = new element;
			cout << "Podaj wartosc:";
			cin >> b;
			e->liczba = b;
			for (int i = 1; i < a - 1; i++) {
				p = p->next;
			}
			e->next = p->next;
			p->next = e;
		}
		else cout << "Nieprawidlowa pozycja!";
	}
	
	}


void printlist(element *&start) {
	element *p;
	p = start;
	while (p) {
		cout << p->liczba << " ";
		p = p->next;
	}

	cout << endl;
}
void search(element *&start) {
	element *p;
	int numer = 1;
	p = start;
	while (p) {
		if (p->liczba == 4) cout << "numer elementu z wyszukiwana wartoscia: " << numer << endl;
		p = p->next;
		numer++;
	}
}
void deletelist(element *&start) {
	element *p;
	while (start) {
		p = start;
		start = start->next;
		delete p;
	}
}


int main()
{
	element *start;
	start = NULL;
	for (int i = 0; i < 5; i++) {
		addfront(start);
	}
	printlist(start);
	for (int i = 0; i < 5; i++) {
		addback(start);
	}
	printlist(start);

	addinside(start);

	printlist(start);
	search(start);
	deletelist(start);
	return 0;
}

