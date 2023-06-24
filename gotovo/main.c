#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "header.h"
#include "slot.h"



int main() {
    int izbor;
    int broj_igraca = 0;
    IGRAC* igraci = NULL;
    char mreza[3][3]; // Mreza za slot masinu

    srand((unsigned)time(NULL));

    //stvaranje rezultati.txt datoteke 
    FILE* fp = fopen("rezultati.txt", "w");
    fclose(fp);

    do {
        printf("====================");
        printf("Odaberite jednu od ponudenih opcija:");
        printf("====================\n");
        printf("\t\t\tOpcija 1: kreiranje novog korisnika!\n");
        printf("\t\t\tOpcija 2: provjera stanja!\n");
        printf("\t\t\tOpcija 3: promjena uloga!\n");
        printf("\t\t\tOpcija 4: zavrti!\n");
        printf("\t\t\tOpcija 5: info!\n");
        printf("\t\t\tOpcija 6: pretrazivanje korisnika po imenu!\n");
        printf("\t\t\tOpcija 7: zavrsetak programa!\n");
       
        printf("======================================\
======================================\n");
        scanf("%d", &izbor);

        switch (izbor) {
        case 1: {
            // Kreiranje novog igraca
            IGRAC novi_igrac;
            printf("Unesite ime igraca: ");
            scanf("%s", novi_igrac.ime);
            printf("Unesite pocetno stanje: ");
            scanf("%d", &novi_igrac.stanje);
            novi_igrac.ulog = 0;
            novi_igrac.dobitak = 0;
            novi_igrac.maxdobitak = 0;

            igraci = realloc(igraci, (broj_igraca + 1) * sizeof(IGRAC));
            igraci[broj_igraca++] = novi_igrac;

            printf("Igrac je uspjesno kreiran.\n");
            break;
        }
        case 2: {
            // Provjera stanja igraca
            int i = broj_igraca - 1;
                
                provjeriStanje(&igraci[i]);
                printf("\n");
            
            break;
        }
        case 3: {
            // Promjena uloga igraca
            
            promijeniUlog(&igraci[broj_igraca - 1]);
            
            break;
        }
        case 4: {
            // Zavrti slot masinu
            int indeks=broj_igraca-1;
              
                vrtnja(&igraci[indeks], mreza);
            
            break;
        }
        case 5:
            printf("Za K simbol dobitak je 13x\n");
            printf("Za Q simbol dobitak je 5x\n");
            printf("Za J simbol dobitak je 5x\n");
            printf("Za 7 simbol dobitak je 100x\n");
            break;
        case 6:
            
            pretraziIgraca(igraci, broj_igraca);
            break;
        case 7:
            sortiranje(igraci, broj_igraca);
            izbor = 0;
            break;
        default:
            printf("Neispravan odabir. Molimo odaberite ponovno.\n");
        }

        printf("\n");

    } while (izbor != 0);

    free(igraci);

    return 0;
}