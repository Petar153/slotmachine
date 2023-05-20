#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Funkcija za generiranje nasumicnog broja 
int generirajNasumicanBroj(int min, int max) {
    return rand() % (max - min) + min;
}

// Funkcija za ispisivanje mreze
void ispisiMrezu(char mreza[3][3]) {
    printf("----------\n");
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++) {
            printf(" %c |", mreza[i][j]);
        }
        printf("\n----------\n");
    }
}

// Funkcija za provjeru dobitnih linija
int provjeriDobitneLinije(char mreza[3][3]) {

    // Provjera dobitnih linija
    for (int i = 0; i < 3; i++) {
        if (mreza[i][0] == mreza[i][1] && mreza[i][1] == mreza[i][2]) {
            return 1;
        }
    }

    // Provjera dobitnih dijagonalnih linija
    if ((mreza[0][0] == mreza[1][1] && mreza[1][1] == mreza[2][2]) || (mreza[0][2] == mreza[1][1] && mreza[1][1] == mreza[2][0])) {
        return 1;
    }

    return 0;
}

// Funkcija za generiranje simbola
char generirajSimbol() {
    int randomBroj = generirajNasumicanBroj(1, 100);

    // Pravila vjerojatnosti za simbole
    if (randomBroj <= 20) {
        return 'K';
    }
    else if (randomBroj <= 55) {
        return 'Q';
    }
    else if (randomBroj <= 90) {
        return 'J';
    }
    else {
        return '7';
    }
}


