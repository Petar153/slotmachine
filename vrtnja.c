#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_type.h"
#include "funkcije.h"
#include "izbornik.h"
#include "slot.h"

void vrtnja(IGRAC* player, char mreza[3][3]) {

	if (player->stanje<player->ulog) {
		printf("Nedovoljno kredita, smanjite ulog!\n");
		return;
	}

// Punjenje mreze simbolima
for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		mreza[i][j] = generirajSimbol();
	}
}

ispisiMrezu(mreza); // Ispis mreze

static int dobitak = 0;


// Provjera dobitnih linija
if (provjeriDobitneLinije(mreza)) {
	printf("Cestitamo, osvojili ste:");
	int provjera = 0;

	// Provjera za simbol K u bilo kojoj dobitnoj liniji
	for (int i = 0; i < 3; i++) {
		if (mreza[i][0] == 'K' && mreza[i][1] == 'K' && mreza[i][2] == 'K') {
			dobitak = player->ulog * 13;
			printf(" %d kredita\n", dobitak);
			provjera = 1;
			break;
		}
	}
	
	// Provjera za simbol 7 u bilo kojoj dobitnoj liniji
	for (int i = 0; i < 3; i++) {
		if (mreza[i][0] == '7' && mreza[i][1] == '7' && mreza[i][2] == '7') {
			dobitak = player->ulog * 100;
			printf(" %d kredita\n", dobitak);
			provjera = 1;
			break;
		}
	}

	// Provjera za ostale simbole u bilo kojoj dobitnoj liniji
	if (!provjera) {
		dobitak = player->ulog * 5;
		printf(" %d kredita\n", dobitak);
	}
}
else {
	printf("Niste osvojili, pokusajte ponovno.\n");
}

//promjena stanja
player->stanje = player->stanje - player->ulog;
player->stanje = player->stanje + dobitak;
player->dobitak = dobitak;
dobitak = 0;

}