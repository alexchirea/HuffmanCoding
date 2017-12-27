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
    //struct Nod *root = (struct Nod *) malloc(sizeof(struct Nod));
    sortare(listaNoduri, k - 1);
    //for (i=0; i<k; i++) printf("%d:'%c' ",listaNoduri[i]->valoare,listaNoduri[i]->caracter);
    int o = k;
    while (o) {
        struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
        nodNou->valoare = listaNoduri[0]->valoare + listaNoduri[1]->valoare;
        nodNou->st = listaNoduri[0];
        //printf("%p\n",listaNoduri[0]);
        nodNou->dr = listaNoduri[1];
        //printf("%p\n",listaNoduri[1]);
        //root = nodNou;
        listaNoduri[0] = nodNou;
        o--;
        if (o == 1) {
            break;
        }
        for (i = 1; i < o; i++) {
            listaNoduri[i] = listaNoduri[i + 1];
        }
        sortare(listaNoduri, o - 1); // ??????
    }
    parcurgere(listaNoduri[0]);
    free(listaNoduri);
}

#endif HUFFMANCODING_CODIFICARE_H
