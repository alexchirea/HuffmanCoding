//
// Created by Alexandru Chirea on 25.11.2017.
//

#ifndef HUFFMANCODING_DEFINITII_H
#define HUFFMANCODING_DEFINITII_H

#endif //HUFFMANCODING_DEFINITII_H

#include <stdlib.h>

typedef struct {
    int caracter;
    struct Nod *stanga, *dreapta;
} Nod;

void inserare(int caracter, struct node **x) {
    if(*x== 0)
    {
        *x = (struct node*) malloc(sizeof(struct node));
        (*x)->key_value = caracter;
        (*x)->stanga = 0;
        (*x)->dreapta = 0;
    }
    else if(caracter<(*x)->caracter)
    {
        inserare( caracter, &(*x)->stanga);
    }
    else if(caracter>(*x)->caracter)
    {
        inserare(caracter, &(*x)->dreapta);
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
