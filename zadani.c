#include "zadani.h"
int zadani(const char *text, int min, int max) {
    int denMesicRok;
    int countOfChar;

    do {
        printf("Zadejte %s v intervalu %d az %d: ", text, min, max);
        scanf("%d", &denMesicRok);
        countOfChar = 0;
        while (getchar() != '\n') {
            countOfChar++;
        }
        if (countOfChar != 0) {
            printf("Nebylo zadano cele cislo. Zkuste znovu.\n");
        } else if (denMesicRok < min || denMesicRok > max) {
            printf("Cislo je mimo interval %d az %d.\n", min, max);
        }
    } while (countOfChar != 0 || denMesicRok < min || denMesicRok > max);
    return denMesicRok;
}
