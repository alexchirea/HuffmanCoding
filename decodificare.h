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
    int i, k = 0, y, cifre = 0, nr, c, a;
    char intrare[1001];
    FILE *f = fopen(fisier, "r");
    FILE *g = fopen("decodat.txt", "w");
    fscanf(f, "%d", &k);
    printf("%d", k);
    fgets(intrare, sizeof(intrare), f);
    i = k;
    while (i) {
        cifre++;
        i /= 10;
    }
    struct Nod **listaNoduri = (struct Nod **) malloc(sizeof(struct Nod *) * k);
    a = k;
    k = 0;
    for (i = cifre + 1; i < strlen(intrare); i++) {
        y = intrare[i];
        i+=2;
        c = intrare[i];
        nr = 0;
        while (c != ' ') {
            nr = nr * 10 + c;
            i++;
            c = intrare[i];
        }
        printf("%c %d", y, nr);
        struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
        nodNou->caracter = y;
        nodNou->valoare = nr;
        nodNou->st = NULL;
        nodNou->dr = NULL;
        listaNoduri[k] = nodNou;
        k++;
        if (a == k) {
            break;
        }
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
    struct Nod *root = (struct Nod *) malloc(sizeof(struct Nod));
    root = listaNoduri[0];
    while (1) {
        y = fgetc(f);
        if (y == '\n') {
            break;
        }
    }
    while (1) {
        y = fgetc(f);
        if (feof(f)) {
            break;
        }
        printf("%c ", y);
        if (root->st != NULL) {
            if (y == '0') {
                root = root->st;
            } else {
                root = root->dr;
            }
        } else {
            fprintf(g, "%c", root->caracter);
            //printf("%c", root->caracter);
            root = listaNoduri[0];
        }
    }
    fclose(f);
    fclose(g);
}

#endif HUFFMANCODING_DECODIFICARE_H
