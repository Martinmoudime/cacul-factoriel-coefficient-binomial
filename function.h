//MISE  EN PLACE DU GARDE D'INCLUSION

#ifndef FUNCTION_H
#define FUNCTION_H

//PROTOTYPES DES FONCTIONS

int factoriel(int n);
int combinaison(int n, int k);
void affichageTrianglePascal(int n);
void add(int*& tableau, int*& indice, int& taille, int& nbr, int val);//AJOUT D'ELEMETS DANS LE TABLEAU DE MEMORISATION
int check(int*& tableau, int*& indice, int& nbr, int val);//VERIFICATION DE LA PRESENCE DE N DANS LE TABLEAU DE MEMORISATION
void multiplication(int*& tab, int& taille, int val);//MULTIPLICATION POUR LES BIG_INTEGER
void facto_BigInt(int*& tab, int& taille, int val);//FACTORIEL POUR LES BIG_INTEGER

#endif