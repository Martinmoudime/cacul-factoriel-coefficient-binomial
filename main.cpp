//INCLUSION DES BIBLIOTHEQUES

#include <iostream>
#include "function.h"

int main()
{
    int* indice = new int[2]; //TABLEAU CONTENANT LES X POUR LA MEMORISATION
    int* tableau = new int[2];// TABLEAU CONTENANT LES F(X) POUR LA MEMORISATION
    int* tab = new int[10000];//TABLEAU CONTENANT LES RESULTATS POUR LA MULTIPLICATION DES BIG_INTEGER
    tab[0] = 1;//INITIALISATION DE LA PREMIERE CELLULE A 1 
    int taille_BigInt = 1;//TAILLE DU TABLEAU DES RESULTATS POUR LA MULTIPLICATION DES BIG_INTEGER
    int nombre_elts = 0;//NOMBRES D'ELEMENTS DONT LE FACTORIEL EST CONNU
    int taille = 2;//TAILLE DU TABLEAU CONTENANT LES ELEMENTS DONT LE FACTORIEL EST CONNU
    int choix, a, b;
    bool state = true;//VARIABLE SPECIFIANT L'ARRET OU LA SUITE DU PROGRAMME

    while (state)
    {
//  AFFICHAGE DE L'INTERFACE UTILISATEUR

        std::cout << "\n";
        std::cout << "----------------------------------------------------------|\n";
        std::cout << "Projet Normal :\n";
        std::cout << "1 : Calcul de la Factoriel\n";
        std::cout << "2 : Calcul du nombre de Combinaison\n";
        std::cout << "3 : Affichage du triangle de Pascal\n";
        std::cout << "4 : Sortir\n";

        std::cin >> choix;

        switch (choix)
        {
            case 1:// CALCUL DU FACTRIEL
                std::cout << "Entrer un nombre : ";
                std::cin >> a;

                if (a < 0)//CAS OU LE N < 0
                    std::cout << "Entrer un nombre positif\n";
                else if (a > 170)//CAS OU L'ESPACE NECESSAIRE AU CALCUL DEVIENT TROP IMPORTANT
                    std::cout << "Le factoriel de "<< a << " ne peut pas être caculé avec précision \n";
                else
                {   
                    if (a > 12)//CAS OU LE NOMBRE DE BIT DU TYPE NATIF INT DEVIENT INSUFFISANT 
                    {
                        facto_BigInt(tab, taille_BigInt, a);   
                    }
                    else if (check(tableau, indice, nombre_elts, a) != -1)//CAS OU LE FACTORIEL DE N A DEJA ETE CALCULE
                    {
                        std::cout << a << "! = " << check(tableau, indice, nombre_elts, a) << "\n";
                    }
                    else
                    {
                        std::cout << a << "! = " << factoriel(a) << "\n";//CAS OU LE FACTORIEL DE N N'A PAS ENCORE ETE CALCULE
                        add(tableau, indice, taille, nombre_elts, a);//AJOUT POUR MEMORISATION ET POSSIBLE UTILISATION ULTERIEURE
                    }
                }    
                    
                break;

            case 2://CALCUL DU NOMBRE DE COMBINAISON / COEFFICIENT BINOMIAL
                std::cout << "Entrer la valeur de n : ";
                std::cin >> a;
                std::cout << "Entrer la valeur de k : ";
                std::cin >> b;

                if (combinaison(a, b) == 0)//CAS OU N < K
                    std::cout << "La valeur de a doit etre superieur n celle de k\n";
                else{
                    std::cout << "C (" << a << ", " << b << ") =  "<< a << "! / ("<< b << "! (" << a << " - "<< b << ")! = " << combinaison(a, b) << "\n";
                }
            break;
            
            case 3://CALCUL DU TRIANGLE DE PASCAL
                std::cout << "Entrer la valeur de n : ";
                std::cin >> a;
                affichageTrianglePascal(a);
            break;

            case 4://CAS OU L'UTILISATEUR SOUHAITE SORTIR DE LA BOUCLE
                state = false;
                std::cout << "Fin Projet\n";
            break;

            default://CAS OU L'UTILISATEUR NE CHOISIT PAS D'OPTIONS
                std::cout << "Entrer un nombre entre 1 et 3\n";
                state = false;
            break;
        }
    }

    //LIBERATION DE LA MEMOIRE ALLOUEE

    delete[] indice;
    delete[] tableau;
    delete[] tab;

    return 0;
}