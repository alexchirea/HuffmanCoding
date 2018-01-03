#include <stdio.h>
#include "codificare.h"
#include "decodificare.h"


//Creat de Alexandru-Cornel Chirea
//Univ. Bucuresti, Facultatea de Matematica si Informatica
//CTI - Gr. 154

int main() {

    char optiune; //1 codificare sau 2 decodificare

    printf("Introduceti 1 pentru codificare sau 2 pentru decodificare, dupa care apasati tasta Enter.\nOptiune = ");
    scanf("%c", &optiune);
    switch (optiune) {
        case '1':
            codificare("huffman.txt");
            break;
        case '2':
            decodificare("output.txt");
            break;
        default:
            printf("\nEROARE: Optiunea introdusa nu exista!\n");
    }
    return 0;
}