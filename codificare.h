//
// Created by Alexandru Chirea on 25.11.2017.
//
#include <string.h>
#include "definitii.h"

#ifndef HUFFMANCODING_CODIFICARE_H
#define HUFFMANCODING_CODIFICARE_H

#endif //HUFFMANCODING_CODIFICARE_H

int min(int a, int b) {
    return (a>b)?b:a;
}

int max(int a, int b) {
    return (a<b)?b:a;
}

void codificare (FILE *fisier, char* intrare, int* frecv, int *nrcar, int *start, int *stop) {
    int i;
    while (fgets(intrare, sizeof(intrare), fisier)) {
        for (i=0; i<strlen(intrare); i++) {
            frecv[intrare[i]]++;
            *start = min(*start,intrare[i]);
            *stop = max(*stop,intrare[i]);
            (*nrcar)++;
        }
    }
    fclose(fisier);

    struct Nod *root = 0;
}
