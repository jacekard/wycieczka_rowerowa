#include <iostream>
using namespace std;
#include "queue.h"
#include "Graf.h"

int main() {

	int osoby, rowery, index;
	cin >> osoby;
	cin >> rowery;

	Rower **Rowery = new Rower*[rowery];
	Graf *graf = new Graf(osoby, rowery);

	for (int i = 0; i < osoby; i++) 
		graf->osoby[i] = new Osoba(i);

	for (int i = 0; i < rowery; i++) 
		Rowery[i] = new Rower(i);

	for (int a = 0; a < osoby; a++) {
		cin >> rowery;
		graf->osoby[a]->liczba_rowerow = rowery;
		graf->osoby[a]->znane_rowery = new Rower*[rowery];
		for (int b = 0; b < rowery; b++) {
			cin >> index;
			graf->osoby[a]->znane_rowery[b] = Rowery[--index];
		}
	}

	cout << graf->maxDopasowanie() << endl;

	return 0;
}