//
// Created by Alexandru Chirea on 18.12.2017.
//

#ifndef HUFFMANCODING_DEFINITII_H
#define HUFFMANCODING_DEFINITII_H

int min(int a, int b) {
    return (a > b) ? b : a;
}

int max(int a, int b) {
    return (a < b) ? b : a;
}

struct Nod {
    int valoare;
    int caracter;
    struct Nod *st;
    struct Nod *dr;
};

struct Nod **listaNoduri;

void adaugare();

struct Nod **sortare(struct Nod **lista, int k) {
    int i, o = 0;
    struct Nod *aux;
    while (o == 0) {
        o = 1;
        for (i = 0; i < k; i++) {
            if (lista[i]->valoare > lista[i + 1]->valoare) {
                aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
            }
        }
    }
    return lista;
}

#endif //HUFFMANCODING_DEFINITII_H
