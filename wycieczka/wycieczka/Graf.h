#pragma once

class Rower {
public:
	int index;
	int skojarzona_osoba;
	Rower(int index) : skojarzona_osoba(-1), index(index) {};
};

class Osoba {
public:
	int index;
	int odleglosc;
	bool odwiedzony;
	Rower *znane_rowery[45];
	int liczba_rowerow;
	int skojarzony_rower;
	Osoba(int index) : odwiedzony(false), odleglosc(-1), skojarzony_rower(-1), index(index) {};
	~Osoba() {
		delete[] znane_rowery;
		delete this;
	}
};

class Graf {
public:
	int liczba_osob;
	Osoba **osoby;
	queue<Osoba*> kolejka;
	int wynik;

	Graf(int o, int r) : liczba_osob(o), wynik(0) {
		osoby = new Osoba*[liczba_osob];
	}

	~Graf() {
		delete[] osoby;
	}

	void ETAP_BFS() {

		for (int i = 0; i < liczba_osob; i++) {
			osoby[i]->odleglosc = -1;
		}

		for (int i = 0; i < liczba_osob; i++) {
			if (osoby[i]->skojarzony_rower == -1) {
				osoby[i]->odleglosc = 0;
				kolejka.push(osoby[i]);
			}
		}

		while (!kolejka.empty()) {
			Osoba *tmp = kolejka.front();
			kolejka.pop();
			for (int i = 0; i < tmp->liczba_rowerow; i++) {
				int index_z = tmp->znane_rowery[i]->skojarzona_osoba;
				if (index_z != -1 && osoby[index_z]->odleglosc == -1) {
					osoby[index_z]->odleglosc = tmp->odleglosc + 1;
					kolejka.push(osoby[index_z]);
				}
			}
		}
	}

	bool ETAP_DFS() {
		for (int i = 0; i < liczba_osob; i++) {
			osoby[i]->odwiedzony = false;
		}
		bool returnTrue = false;
		for (int i = 0; i < liczba_osob; i++) {
			if (osoby[i]->skojarzony_rower == -1) {
				if (szukanie_wglab(osoby[i]) == true) {
					wynik++;
					returnTrue = true;
				}
			}
		}

		if (returnTrue)
			return true;
		else
			return false;
	}

	bool szukanie_wglab(Osoba *osoba) {
		osoba->odwiedzony = true;
		for (int i = 0; i < osoba->liczba_rowerow; i++) {
			if (osoba->znane_rowery[i]->skojarzona_osoba == -1) {
				osoba->znane_rowery[i]->skojarzona_osoba = osoba->index;
				osoba->skojarzony_rower = osoba->znane_rowery[i]->index;
				return true;
			}
			int index_z = osoba->znane_rowery[i]->skojarzona_osoba;
			if (osoby[index_z]->odwiedzony == false
				&& osoby[index_z]->odleglosc - osoba->odleglosc == 1)
			if (szukanie_wglab(osoby[index_z]) == true) {
				osoba->skojarzony_rower = osoba->znane_rowery[i]->index;
				osoba->znane_rowery[i]->skojarzona_osoba = osoba->index;
				return true;
			}
		}
		return false;
	}

	int maxDopasowanie() {
		bool continueMatch;
		do {
			ETAP_BFS();
			continueMatch = ETAP_DFS();
		} while (continueMatch);
	
		return wynik;
	}

};