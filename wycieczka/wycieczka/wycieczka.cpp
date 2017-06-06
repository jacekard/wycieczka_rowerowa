#include <iostream>
using namespace std;
#include "queue.h"
#include "Graf.h"

Rower *Rowery[17400];

int main() {

	int osoby, rowery, index, liczba_rowerow;
	scanf("%d", &osoby);
	scanf("%d", &liczba_rowerow);

	Graf *graf = new Graf(osoby, liczba_rowerow);

	for (int i = 0; i < osoby; i++) 
		graf->osoby[i] = new Osoba(i);

	for (int i = 0; i < liczba_rowerow; i++) 
		Rowery[i] = new Rower(i);

	for (int a = 0; a < osoby; a++) {
		scanf("%d", &rowery);
		graf->osoby[a]->liczba_rowerow = rowery;
		for (int b = 0; b < rowery; b++) {
			scanf("%d",&index);
			graf->osoby[a]->znane_rowery[b] = Rowery[--index];
		}
	}

	cout << graf->maxDopasowanie() << '\n';

	delete graf;

	for (int i = 0; i < liczba_rowerow; i++) {
		delete Rowery[i];
	}

	return 0;
}