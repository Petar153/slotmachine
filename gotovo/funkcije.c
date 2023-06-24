#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "slot.h"

void provjeriStanje(IGRAC* igrac) {
    printf("Stanje: %d\n", igrac->stanje);
    printf("Ulog: %d\n", igrac->ulog);
    printf("Dobitak: %d\n", igrac->dobitak);
    printf("Maksimalni dobitak: %d\n", igrac->maxdobitak);
}

// Funkcija za promjenu uloga igraca
void promijeniUlog(IGRAC* igrac) {
    int novi_ulog;
    printf("Unesite novi ulog: ");
    scanf("%d", &novi_ulog);

    if (novi_ulog <= igrac->stanje) {
        igrac->ulog = novi_ulog;
        printf("Ulog je uspjesno promijenjen.\n");
    }
    else {
        printf("Nemate dovoljno sredstava za postavljeni ulog.\n");
    }
}



void vrtnja(IGRAC* player, char mreza[3][3]) {

	if (player->stanje < player->ulog) {
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

	if (player->dobitak > player->maxdobitak) {
		player->maxdobitak = player->dobitak;
	}

}


// Funkcija za pretrazivanje igraca po imenu
void pretraziIgraca(IGRAC* igraci, int broj_igraca) {
	char trazeno_ime[50];
	printf("Unesite ime igraca: ");
	scanf("%s", trazeno_ime);

	int pronaden = 0;
	int i;

	for (i = 0; i < broj_igraca; i++) {
		if (strcmp(igraci[i].ime, trazeno_ime) == 0) {
			printf("Igrac pronaden:\n");
			printf("Ime: %s\n", igraci[i].ime);
			printf("Stanje: %d\n", igraci[i].stanje);
			printf("Ulog: %d\n", igraci[i].ulog);
			printf("Dobitak: %d\n", igraci[i].dobitak);
			printf("Maksimalni dobitak: %d\n", igraci[i].maxdobitak);
			pronaden = 1;
			break;
		}
	}

	if (!pronaden) {
		printf("Igrac s tim imenom nije pronaden.\n");
	}
}



// Funkcija za sortirani ispis igraca po maksimalnom dobitku
void sortiranje(IGRAC* igraci, int broj_igraca) {
	int i, j;
	IGRAC temp;

	// Sortiranje igraca po maksimalnom dobitku
	for (i = 0; i < broj_igraca - 1; i++) {
		for (j = 0; j < broj_igraca - i - 1; j++) {
			if (igraci[j].maxdobitak < igraci[j + 1].maxdobitak) {
				temp = igraci[j];
				igraci[j] = igraci[j + 1];
				igraci[j + 1] = temp;
			}
		}
	}

	FILE* fp = fopen("rezultati.txt", "w");
	
	// Ispis sortiranih igraca
	for (i = 0; i < broj_igraca; i++) {
		fprintf(fp,"Igrac: %s, Maksimalni dobitak: %d\n", igraci[i].ime, igraci[i].maxdobitak);
	}

	fclose(fp);
}