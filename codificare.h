//
// Created by Alexandru Chirea on 25.11.2017.
//
#include <string.h>
#include <stdlib.h>
#include "definitii.h"

#ifndef HUFFMANCODING_CODIFICARE_H
#define HUFFMANCODING_CODIFICARE_H

void codificare(FILE *fisier) {
    int i, frecv[500] = {0}, nrcar = 0, start = 9999, stop = 0, k = 0;

    char intrare[1001];

    while (fgets(intrare, sizeof(intrare), fisier)) {
        for (i = 0; i < strlen(intrare); i++) {
            frecv[intrare[i]]++;
            start = min(start, intrare[i]);
            stop = max(stop, intrare[i]);
            nrcar++;
        }
    }

    fclose(fisier);

    for (i = start; i <= stop; i++) {
        if (frecv[i]) {
            k++;
        }
    }

    listaNoduri = (struct Nod **) malloc(sizeof(struct Nod *) * k);

    k = 0;

    for (i = start; i <= stop; i++) {
        if (frecv[i]) {
            struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
            nodNou->caracter = i;
            nodNou->valoare = frecv[i];
            listaNoduri[k] = nodNou;
            k++;
        }
    }

    //printf("%d", k);

    listaNoduri = sortare(listaNoduri, k - 1);
    //Afisare frecvente
    printf("\n");
    for (i = 0; i < k; i++) {
        printf("%c\t", listaNoduri[i]->caracter);
    }
    printf("\n");
    for (i = 0; i < k; i++) {
        printf("%d\t", listaNoduri[i]->valoare);
    }

}

#endif HUFFMANCODING_CODIFICARE_H
