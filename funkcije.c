#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "data_type.h"



extern int brojac;

//funkcija za provjeru stanja
void provjeraStanja(IGRAC* player) {

	printf("Stanje: %d kredita\n\n",player->stanje);

}


//funkcija za promjenu uloga
void promjenaUloga(IGRAC* player) {
	int NoviUlog;
	int val;
	char input[100] = "";
	int length, i;
	int provjera = 0;


	while (1) {

	provjera = 0;
	printf("Unesite novi zeljeni ulog: ");
	scanf("%s", input);
	length = strlen(input);

	//provjera da li je broj
	for (i = 0; i < length; i++){  //for
		if (!isdigit(input[i]))
		{
			//nije broj
			printf("Krivi unos, unesi broj!\n");
			provjera = 0;
			break;
		}
		else {
			//broj je
			provjera = 1;
		}
	}//for

	if (provjera == 1) {  //if3

		val = atoi(input);
		NoviUlog = val;
		if (NoviUlog > player->stanje) {
			printf("Nedovoljno kredita na racunu.\n");
			
		}
		else {
			player->ulog = NoviUlog;
			break;
		}
	}//if3
	}//while
	
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