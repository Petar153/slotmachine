#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "data_type.h"



extern int brojac;

//funkcija za provjeru stanja
void provjeraStanja(IGRAC* player) {

	printf("Stanje: %d kredita\n\n",player->stanje);

}


//funkcija za promjenu uloga
void promjenaUloga(IGRAC* player) {
	int NoviUlog;

	printf("Unesite novi zeljeni ulog: ");
	scanf("%d",&NoviUlog);


	//provjera dali ne prekoracava stanje na racunu
	while (NoviUlog > player->stanje) {
		printf("Nedovoljno kredita na racunu.\n");
		printf("Unesite novi zeljeni ulog: ");
		scanf("%d", &NoviUlog);
	}

	player->ulog = NoviUlog;
	
}


//upis rezultata u datoteku
void upis(IGRAC* player) {
	

	FILE* fp = fopen("rezultati.txt", "a");
	if (fp == NULL) {
		printf("Nije moguce otvoriti datoteku za pisanje.\n");
		return;
	}
	brojac++;
	fprintf(fp, "%d\t%d\t%d\t%d\n", brojac, player->stanje, player->ulog, player->dobitak);


	fclose(fp);
	
}


//funkcija za informaciju o dobicima
void info() {
	printf("Za K simbol dobitak je 13x\n");
	printf("Za Q simbol dobitak je 5x\n");
	printf("Za J simbol dobitak je 5x\n");
	printf("Za 7 simbol dobitak je 100x\n");
}


//funkcija za izlaz iz programa
int izlazIzPrograma() {
	char c[10] = "";
	char s[] = "ne";
	
	printf("Da li ste sigurni kako zelite zavrsiti program?\nda/ne\n");
	scanf("%s", c);
	if (!strcmp(c, s)) {

		return 1;
	}
	else {

		return 0;
	}

}