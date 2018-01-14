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

struct Pereche {
  int val;
  int car;
};

enum Erori {
  fisierInexistentCodificare,
  fisierInexistentDecodificare
};

struct Nod *adaugare(int car, int frecv, struct Nod *st, struct Nod *dr) {
  struct Nod *nodNou = (struct Nod *) malloc(sizeof(struct Nod));
  nodNou->caracter = car;
  nodNou->valoare = frecv;
  nodNou->st = st;
  nodNou->dr = dr;
  return nodNou;
}

void sortare(struct Nod **lista, int k) {
  int i, o = 0;
  struct Nod *aux;
  while (o == 0) {
	o = 1;
	for (i = 0; i < k; i++) {
	  if (lista[i]->valoare > lista[i + 1]->valoare) {
		o = 0;
		aux = lista[i];
		lista[i] = lista[i + 1];
		lista[i + 1] = aux;
	  } else if (lista[i]->valoare == lista[i + 1]->valoare) {
		if (lista[i]->caracter > lista[i + 1]->caracter) {
		  o = 0;
		  aux = lista[i];
		  lista[i] = lista[i + 1];
		  lista[i + 1] = aux;
		}
	  }
	}
  }
}

void parcurgere(struct Nod *nod) {
  if (nod->st != NULL) {
	printf("%d %c\n", nod->valoare, nod->caracter);
	parcurgere(nod->st);
	parcurgere(nod->dr);
	printf("\n");
  } else {
	printf("%d %c\t", nod->valoare, nod->caracter);
  }
}

void printArbore(struct Nod *nod, FILE *g) {
  if (nod->st != NULL) {
	fprintf(g, "#");
	printArbore(nod->st, g);
	printArbore(nod->dr, g);
  } else {
	fprintf(g, "%c", nod->caracter);
  }
}

int cauta(int caracter, struct Nod *nod, int pos, int *arr, FILE *g) {
  if (nod->st != NULL) {
	arr[pos] = 0;
	cauta(caracter, nod->st, pos + 1, arr, g);

	arr[pos] = 1;
	cauta(caracter, nod->dr, pos + 1, arr, g);
  } else {
	if (nod->caracter == caracter) {
	  for (int i = 0; i < pos; i++)
		fprintf(g, "%d", arr[i]);
	}
  }
}

void elibereaza(struct Nod *nod) {
  if (nod->st != NULL) {
	elibereaza(nod->st);
	elibereaza(nod->dr);
	free(nod);
  } else {
	free(nod);
  }
}

void printEroare(enum Erori eroare) {
  if (eroare == 0) {
	printf("Fisierul 'huffman.txt' nu exista!");
  } else if (eroare == 1) {
	printf("Fisierul 'output.txt' nu exista!");
  }
}

#endif //HUFFMANCODING_DEFINITII_H
