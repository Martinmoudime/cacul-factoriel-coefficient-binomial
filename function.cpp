//INCLUSION DES BIBLIOTHEQUES

#include <iostream> 
#include "function.h"

int factoriel(int n)
{
    if (n == 0 || n == 1)//GESTION DES CAS DE BASE
        return 1;
    else
    return n * factoriel(n - 1);//APPLICATION DU PRINCIPE DE RECURSIVITE
}

int combinaison(int n, int k)
{
    if (n < k)//GESRION DU CAS OU N < K
        return 0;
    return factoriel(n) / (factoriel(k) * (factoriel(n - k)));//CALCULE DU CORFFICIENT BINOMIAL
}

void affichageTrianglePascal(int n)
{
    for (int i = 0; i < n; i++)//MISE EN PLACE DU COMPTEUR DE LA PREMIERE A LA N-IEME LIGNE
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << combinaison(i, j) << "      ";//AFFICHAGE DES ESPACES ENTRE LES VALEURS
        }
        std::cout << std::endl;//MECANISME POUR LE RETOUR A LA LIGNE
    }
}

void add(int*& tableau, int*& indice, int& taille, int& nbr, int val)
{
    if (taille == nbr)//CAS OU TOUTE LES CELLULES DU TABLEAUX SONT OCCUPEES
    {
        //CREATION DE TABLEAU PLUS GRAND

        int nouvelle_taille = taille + 1;
        int* nouveau_tableau = new int[nouvelle_taille];
        int* nouveau_indice = new int[nouvelle_taille];
        
        for (int i = 0; i < nbr; i++)
        {
            nouveau_tableau[i] = tableau[i];
            nouveau_indice[i] = indice[i];
        }

        //LIBERATION DE LA MEMOIRE ALLOUEE

        delete[] tableau;
        delete[] indice;

        //REDIRECTION DES POINTERS DE BASE VERS LES NOUVELLES ZONES MEMOIRES

        tableau = nouveau_tableau;
        indice = nouveau_indice;
        taille = nouvelle_taille;
    }

    //AJOUT DES DONNEES DANS LES NOUVEAUX TABLEAUX 

    indice[taille - nbr] = val;
    tableau[taille - nbr] = factoriel(val);
    nbr++;// AUGMENTATION DU NOMBRE D'ELEMENTS DONT LA TAILLE EST CONNU
}

int check(int*& tableau, int*& indice, int& nbr, int val)
{
    for (int i = 0; i < nbr; i++)//PARCOUR DU TABLEAU 
    {
        if (val == indice[i])//CAS OU LA VALEUR EXISTE DEJA
            return tableau[i];
    }
    return -1;//CAS OU LA VALEUR N'EXISTE PAS
}

int r = 0;//INITIALISATION DU RESTE

void multiplication(int*& tab, int& taille, int val)
{
    
    for (int i = 0; i < taille; i++)//INITIALISATION DU COMPTEUR
    {
        int produit = tab[i] * val + r;//PRINCIPE DE LA MULTIPLICATION MANUEL APPIRSE A L'ECOLE PRIMAIRE
        if (produit >= 10)//CAS OU L'ON OBTIENT DES RETENUES
        {
            tab[i] = produit % 10;//GESTION DES UNITES
            r = produit / 10;//GESTION DES DIZAINES
        }
        else//CAS OU L'ON OBTIENT PAS DE RETENUES
        {
            tab[i] = produit;//GESTION DU RESULTAT OBTENU DANS L'ORDRE INVERSE POUR FACILITER LES CALCULS EN COMMENCANT PAR LES UNITES
            r = 0;//PAS DE RESTE
        }
    }

    while (r > 0)//CAS OU TOUTE LES VALEURS ONT ETE MULTIPLIEES ET IL RESTE ENCORE UNE RETENUE
    {
        if (taille == 10000)//CAS OU LA TAILLE MAXIMALE DU TABLEAU EST ATTEINTE
        {
            //ALERTE ET ARRET DE L'EXECUTION

            std::cout << "La taille maximale est atteinte !\n";
            return;
        }
        else//CAS OU LA TAILLE DU TBLEAU PEUT ENCORE AUGMENTER
        {
            tab[taille] = r % 10;//AFFECTATION DE L RETENUE A LA DERNIERE CELLULE
            r /= 10;//INITIALISATION DE LA RETENUE A 0
            taille++;//AUGMNENTATION DE LA TAILLE DU TABLEAU
        }
    }
}

void facto_BigInt(int*& tab, int& taille, int val)
{
    //INITIALISATION DE LA TAILLE ET DU TABLEAU A 1
    tab[0] = 1;
    taille = 1;

    //CALCUL DU FACTORIEL

    for (int i = 2; i <= val; i++)
    {
        multiplication(tab, taille, i);
        if (taille == 10000)
            return;        
    }

    std::cout << val << "! = ";

    for (int i = taille - 1; i >= 0; i--)//AFFICHAGE DU RESULTAT DANS L'ORDRE INVERSE DES ELEMENTS 
    {
        std::cout << tab[i];
    }
}