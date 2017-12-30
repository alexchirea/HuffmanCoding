//
// Created by Alexandru Chirea on 25.11.2017.
//
#include <string.h>
#include <stdlib.h>
#include "definitii.h"

#ifndef HUFFMANCODING_CODIFICARE_H
#define HUFFMANCODING_CODIFICARE_H

void codificare(char *fisier) {
    FILE *f = fopen(fisier, "r");
    FILE *g = fopen("output.txt", "w");
    int i, frecv[500] = {0}, nrcar = 0, start = 9999, stop = 0, k = 0, height;
    char intrare[1001];
    while (fgets(intrare, sizeof(intrare), f)) {
        for (i = 0; i < strlen(intrare); i++) {
            frecv[intrare[i]]++;
            start = min(start, intrare[i]);
            stop = max(stop, intrare[i]);
            nrcar++;
        }
    }
    fclose(f);
    for (i = start; i <= stop; i++) {
        if (frecv[i]) {
            k++;
        }
    }
    fprintf(g, "%d ", k);
    struct Nod **listaNoduri = (struct Nod **) malloc(sizeof(struct Nod *) * k);
    k = 0;
    for (i = start; i <= stop; i++) {
        if (frecv[i]) {
            fprintf(g, "%c %d ", i, frecv[i]);
            struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
            nodNou->caracter = i;
            nodNou->valoare = frecv[i];
            nodNou->st = NULL;
            nodNou->dr = NULL;
            listaNoduri[k] = nodNou;
            k++;
        }
    }
    fprintf(g, "\n");
    sortare(listaNoduri, k - 1);
    int o = k;
    while (o) {
        struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
        nodNou->valoare = listaNoduri[0]->valoare + listaNoduri[1]->valoare;
        nodNou->caracter = 0;
        nodNou->st = listaNoduri[0];
        nodNou->dr = listaNoduri[1];
        listaNoduri[0] = nodNou;
        o--;
        if (o == 1) {
            break;
        }
        for (i = 1; i < o; i++) {
            listaNoduri[i] = listaNoduri[i + 1];
        }
        sortare(listaNoduri, o - 1); // ??????
        height++;
    }
    //parcurgere(listaNoduri[0]);
    struct Nod *root = (struct Nod *) malloc(sizeof(struct Nod));
    root = listaNoduri[0];
    int pos;
    int *arr = (int *) malloc(sizeof(int) * height);
    f = fopen(fisier, "r");
    while (fgets(intrare, sizeof(intrare), f)) {
        for (i = 0; i < strlen(intrare); i++) {
            pos = 0;
            cauta(intrare[i], root, pos, arr, g);
        }
    }
    fclose(f);
    fclose(g);

    /*for (i = start; i <= stop; i++) {
        if (frecv[i]) {
            pos = 0;
            printf("%c ", i);
            cauta(i, root, pos, arr,g);
        }
    }*/
    elibereaza(listaNoduri[0]);
    free(listaNoduri);
}

#endif HUFFMANCODING_CODIFICARE_H
