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

  //Lista cu noduri
  struct Nod **listaNoduri = (struct Nod **) malloc(sizeof(struct Nod *) * k);
  for (i = 0; i < k; i++) {
	fscanf(f, "%d %d", &x.car, &x.val);
	listaNoduri[i] = adaugare(x.car, x.val, NULL, NULL);
  }

  //Sortare crescator dupa frecvente (valoare)
  sortare(listaNoduri, k - 1);
  int o = k;
  while (o) {
	listaNoduri[0] = adaugare(0, listaNoduri[0]->valoare + listaNoduri[1]->valoare, listaNoduri[0], listaNoduri[1]);
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
  fgetc(f); //spatii albe
  fgetc(f); //spatii albe
  while (1) {
	x.car = fgetc(f);

	if (root->caracter != 0) {
	  //nodul este frunza
	  fprintf(g, "%c", root->caracter);
	  root = listaNoduri[0];
	}

	if (x.car == '0') {
	  //deplasare la nodul din stanga
	  root = root->st;
	} else {
	  //deplasare la nodul din dreapta
	  root = root->dr;
	}

	if (x.car == EOF) {
	  //sfarsit fisier
	  break;
	}
  }

  //Inchidere fisiere
  fclose(f);
  fclose(g);

  //Eliberare memorie
  elibereaza(root);
  free(listaNoduri);
}

#endif //HUFFMANCODING_DECODIFICARE_H
