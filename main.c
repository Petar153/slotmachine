#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "data_type.h"
#include "funkcije.h"
#include "izbornik.h"
#include "slot.h"

int brojac=0;

int main(void) {

	srand((unsigned)time(NULL));
	brojac = 0;

	//stvaranje rezultati.txt datoteke 
	FILE* fp = fopen("rezultati.txt", "w");
	fclose(fp);

	int uvijet = 1;

	//kreiranje igraca
	IGRAC* player = (IGRAC*)calloc(1, sizeof(IGRAC));
	if (player == NULL) {
		perror("Zauzimanje memorije za studente");
		return NULL;
	}
	
	player->stanje = 500;
	player->ulog = 50;
	player->dobitak = 0;

	//zapisivanje pocetnog stanja
	fp = fopen("rezultati.txt", "a");
	if (fp == NULL) {
		printf("Nije moguce otvoriti datoteku za pisanje.\n");
		return;
	}
	fprintf(fp, "ID\tSTANJE\tULOG\tDOBITAK\n");
	fprintf(fp, "%d\t%d\t%d\t%d\n", brojac, player->stanje, player->ulog, player->dobitak);
	fclose(fp);


	//izbornik
	while (uvijet) {
		uvijet = izbornik(player);
	}


	free(player);

	printf("Zavrsetak programa!\n");
	return 0;
}