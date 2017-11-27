//
// Created by Alexandru Chirea on 25.11.2017.
//

#ifndef HUFFMANCODING_DEFINITII_H
#define HUFFMANCODING_DEFINITII_H

#endif //HUFFMANCODING_DEFINITII_H

#include <stdlib.h>

typedef struct {
    int frecventa;
    int caracter;
    struct Nod *stanga, *dreapta;
} Nod;

void inserare(int frecventa, int caracter, struct node **x) {
    if(*x==0)
    {
        *x=(struct node*) malloc(sizeof(struct node));
        (*x)->frecventa = frecventa;
        (*x)->caracter = caracter;
        (*x)->stanga = 0;
        (*x)->dreapta = 0;
    }
    else if(frecventa<(*x)->frecventa)
    {
        inserare(frecventa, caracter, &(*x)->stanga);
    }
    else if(frecventa>(*x)->frecventa)
    {
        inserare(frecventa, caracter, &(*x)->dreapta);
    }
}

Nod *cauta(int caracter, struct node *x) {
    if(x!= 0)
    {
        if(caracter==x->caracter)
        {
            return x;
        }
        else if(caracter<x->caracter)
        {
            return cauta(caracter, x->stanga);
        }
        else
        {
            return cauta(caracter, x->dreapta);
        }
    }
    else return 0;
}

void stergere_arbore(struct Nod *x) {
    if(x!=0)
    {
        stergere_arbore(x->stanga);
        stergere_arbore(x->dreapta);
        free(x);
    }
}
