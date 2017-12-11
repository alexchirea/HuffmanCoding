//
// Created by Alexandru Chirea on 25.11.2017.
//
#include <string.h>
#include "sortare.h"

#ifndef HUFFMANCODING_CODIFICARE_H
#define HUFFMANCODING_CODIFICARE_H

int min(int a, int b) {
    return (a>b)?b:a;
}

int max(int a, int b) {
    return (a<b)?b:a;
}

void codificare (FILE *fisier) {
    int i, frecv[500]={0}, valori[200][2], nrcar=0, start=9999, stop=0, k=0;
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

    for (i=start; i<=stop; i++) {
        if (frecv[i]) {
            k++;
            valori[k][0]=i;
            valori[k][1]=frecv[i];
        }
    }

    sortare(frecv,valori,k);

    //Afisare frecvente
    /*printf("\n");
    for (i=1; i<=k; i++) {
        printf("%c\t",valori[i][0]);
    }
    printf("\n");
    for (i=1; i<=k; i++) {
        printf("%d\t",valori[i][1]);
    }*/

    //struct Nod *root = 0;
}

#endif HUFFMANCODING_CODIFICARE_H
