#pragma once
typedef struct {
	char ime[100];
	int stanje;
	int ulog;
	int dobitak;
	int maxdobitak;
}IGRAC;

void provjeriStanje(IGRAC*);
void promijeniUlog(IGRAC*);
void vrtnja(IGRAC* player, char mreza[3][3]);
void pretraziIgraca(IGRAC* igraci, int broj_igraca);
void sortiranje(IGRAC*,int);

