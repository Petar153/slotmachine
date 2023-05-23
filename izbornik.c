#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



#include "data_type.h"
#include "slot.h"
#include "funkcije.h"
#include "vrtnja.h"



int izbornik(IGRAC* player) {

	static char mreza[3][3]; // Mreza za slot masinu

	printf("====================");
	printf("Odaberite jednu od ponudenih opcija:");
	printf("====================\n");
	printf("\t\t\tOpcija 1: provjera stanja!\n");
	printf("\t\t\tOpcija 2: promjena uloga!\n");
	printf("\t\t\tOpcija 3: zavrti!\n");
	printf("\t\t\tOpcija 4: info!\n");
	printf("\t\t\tOpcija 5: zavrsetak programa!\n");
	printf("Ulog: %d kredita\n",player->ulog);
	printf("======================================\
======================================\n");



	int uvijet = 1;
	
	

	scanf("%d", &uvijet);
	switch (uvijet) {
	case 1:
		provjeraStanja(player); //Provjera stanja igraca
		break;
	case 2:
		promjenaUloga(player);//promjena uloga
		break;
	case 3:
		vrtnja(player,mreza);//jedna vrtnja
		upis(player);
		break;
	case 4:
		info(); //Info o isplati
		break;
	case 5:
		uvijet = izlazIzPrograma(); //Exit
		break;
	default:
		uvijet = 0;
	}
	return uvijet;
}
