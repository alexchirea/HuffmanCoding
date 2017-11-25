#include <stdio.h>
#include "codificare.h"
#include "definitii.h"

//Creat de Alexandru-Cornel Chirea
//Univ. Bucuresti, Facultatea de Matematica si Informatica
//CTI - Gr. 154

char intrare[1001];
int frecv[300], nrcar, start=9999, stop;
int main() {

    //Fisierul din care se citeste textul de (de)codificat.
    FILE *f = fopen("huffman.txt","r");

    int optiune; //1 codificare sau 2 decodificare

    printf("Introduceti 1 pentru codificare sau 2 pentru decodificare, dupa care apasati tasta Enter.\nOptiune = ");
    //scanf("%d", &optiune);
    optiune=1;
    switch (optiune) {
        case 1:
            codificare(f, intrare, frecv, &nrcar, &start, &stop);
            break;
        case 2:
            //decodificare
            break;
        default:
            printf("\nEROARE: Optiunea introdusa nu exista!\n");
    }
    return 0;
}