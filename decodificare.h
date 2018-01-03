//
// Created by Alexandru Chirea on 30.12.2017.
//

#ifndef HUFFMANCODING_DECODIFICARE_H
#define HUFFMANCODING_DECODIFICARE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitii.h"

void decodificare(char *fisier) {
    int i, k = 0;
    struct Pereche x;
    FILE *f = fopen(fisier, "r");
    if (!f) {
        printEroare(fisierInexistentDecodificare);
        return;
    }
        FILE *g = fopen("decodat.txt", "w");
    fscanf(f, "%d ", &k);
    struct Nod **listaNoduri = (struct Nod **) malloc(sizeof(struct Nod *) * k);
    for (i=0; i<k; i++) {
        fscanf(f,"%d %d",&x.car,&x.val);
        struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
        nodNou->caracter = x.car;
        nodNou->valoare = x.val;
        nodNou->st = NULL;
        nodNou->dr = NULL;
        listaNoduri[i] = nodNou;
    }
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
        sortare(listaNoduri, o - 1);
    }
    struct Nod *root;
    root = listaNoduri[0];
    fgetc(f); fgetc(f);
    while(1) {
        x.car = fgetc(f);
        if (root->caracter!=0) {
            fprintf(g, "%c", root->caracter);
            root = listaNoduri[0];
        }
        if (x.car == '0') {
            root = root->st;
        } else {
            root = root->dr;
        }
        if (x.car == EOF) {
            break;
        }
    }
    fclose(f);
    fclose(g);
    elibereaza(root);
    free(listaNoduri);
}

#endif //HUFFMANCODING_DECODIFICARE_H
