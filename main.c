#include "zadani.h"
#include <stdio.h>
#include <stdlib.h>

#define MINROK 1582
#define MAXROK 2999


int prestupnyRok(int r) {
    return (r % 4 == 0 && r % 100 != 0) || (r % 100 == 0 && r % 400 == 0);
}

int pocetDniMesic(int m, int r) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        return 31;
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    } else if (prestupnyRok(r)) {
        return 29;
    } else {
        return 28;
    }
}

int next() {
    printf("Stisknete enter pro pokracovani...");
    if (getchar() == '\n') {
        return 1;
    } else {
        return 0;
    }
}

/*Funkce vraci pocet dni od pocatku kalendare daneho smybolickou konstantou MINROK od data
 uvedenho jako parametry den, mesic, rok.*/
int pocetDni(int den, int mesic, int rok) {
    int dny = 0;
    /*Vypocteme pocet dni vsech let predchazejicich aktualnimu roku (parametr rok).*/
    for (int r = MINROK; r < rok; ++r) {
        dny += prestupnyRok(r) ? 366 : 365;
    }
    /*Pricitame pocet dni v mesicich predchazejicich aktualnimu mesici (parametr mesic).*/
    for (int m = 1; m < mesic; ++m) {
        dny += pocetDniMesic(m, rok);
    }
    dny += den;
    return --dny;
}

int rozdilDni(int d1, int m1, int r1, int d2, int m2, int r2) {
    return abs(pocetDni(d1, m1, r1) - pocetDni(d2, m2, r2));
}

int main() {
    int den, mesic, rok;
    int den2, mesic2, rok2;
    do {
        rok = zadani("rok", MINROK, MAXROK);
        mesic = zadani("mesic", 1, 12);
        den = zadani("den", 1, pocetDniMesic(mesic, rok));
        printf("Zadane datum: %d. %d. %d\n", den, mesic, rok);
        printf("Od 1. 1. %d uplynulo %d dni.\n", MINROK, pocetDni(den, mesic, rok));
        rok2 = zadani("rok", MINROK, MAXROK);
        mesic2 = zadani("mesic", 1, 12);
        den2 = zadani("den", 1, pocetDniMesic(mesic, rok));
        printf("Rozdil mezi daty ve dnech %d. %d. %d a %d. %d. %d je %d.\n", den, mesic, rok,
               den2, mesic2, rok2, rozdilDni(den, mesic, rok, den2, mesic2, rok2));
    } while (next());
    return 0;
}
