//
// Created by Alexandru Chirea on 25.11.2017.
//
#include <string.h>
#include <stdlib.h>
#include "definitii.h"

#ifndef HUFFMANCODING_CODIFICARE_H
#define HUFFMANCODING_CODIFICARE_H

void codificare(char *fisier) {
  int i, frecv[500] = {0}, nrcar = 0, start = 9999, stop = 0, k = 0, height;
  char intrare[1001];

  FILE *f = fopen(fisier, "r");
  if (!f) {
	printEroare(fisierInexistentCodificare);
	return;
  }
  FILE *g = fopen("output.txt", "w");

  //Numarul de aparitii pentru fiecare caracter prezent in fisier.
  //start = cel mai mic cod al caracterului (int)
  //stop = cel mai mare cod al caracterului (int)
  while (fgets(intrare, sizeof(intrare), f)) {
	for (i = 0; i < strlen(intrare); i++) {
	  frecv[intrare[i]]++;
	  start = min(start, intrare[i]);
	  stop = max(stop, intrare[i]);
	  nrcar++;
	}
  }
  fclose(f);

  //Numarul de caractere diferite care apar
  for (i = start; i <= stop; i++) {
	if (frecv[i]) {
	  k++;
	}
  }
  fprintf(g, "%d ", k);

  //Lista cu noduri
  struct Nod **listaNoduri = (struct Nod **) malloc(sizeof(struct Nod *) * k);
  k = 0;
  for (i = start; i <= stop; i++) {
	if (frecv[i]) {
	  fprintf(g, "%d %d ", i, frecv[i]);
	  //Creare nod nou, adaugarea lui in lista
	  listaNoduri[k] = adaugare(i, frecv[i], NULL, NULL);
	  k++;
	}
  }
  fprintf(g, "\n");

  //Sortare noduri crescator dupa 'valoare'
  sortare(listaNoduri, k - 1);
  int o = k;
  while (o) {
	//Creare nod din primele cele mai mici noduri din lista
	listaNoduri[0] = adaugare(0, listaNoduri[0]->valoare + listaNoduri[1]->valoare, listaNoduri[0], listaNoduri[1]);
	o--;
	if (o == 1) {
	  break;
	}
	for (i = 1; i < o; i++) {
	  listaNoduri[i] = listaNoduri[i + 1];
	}
	sortare(listaNoduri, o - 1);
	height++; //inaltime arbore
  }
  struct Nod *root;
  root = listaNoduri[0];
  int pos;
  int *arr = (int *) malloc(sizeof(int) * height);
  f = fopen(fisier, "r");
  while (fgets(intrare, sizeof(intrare), f)) {
	for (i = 0; i < strlen(intrare); i++) {
	  pos = 0;
	  cauta(intrare[i], root, pos, arr, g);
	}
  }

  //Inchidere fisiere
  fclose(f);
  fclose(g);

  //Eliberare memorie
  elibereaza(root);
  free(listaNoduri);
}

#endif //HUFFMANCODING_CODIFICARE_H
