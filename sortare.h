//
// Created by Alexandru Chirea on 25.11.2017.
//

#ifndef HUFFMANCODING_SORTARE_H
#define HUFFMANCODING_SORTARE_H

void sortare(int* frecv, int valori[200][2], int k) {
    int i, o=0, aux, caract;
    while (o==0) {
        o=1;
        for (i=1; i<k; i++) {
            if (valori[i][1]>valori[i+1][1]) {
                o=0;
                aux = valori[i][1];
                caract = valori[i][0];
                valori[i][1] = valori[i+1][1];
                valori[i][0] = valori[i+1][0];
                valori[i+1][1] = aux;
                valori[i+1][0] = caract;
            }
        }
    }
}

#endif HUFFMANCODING_SORTARE_H
