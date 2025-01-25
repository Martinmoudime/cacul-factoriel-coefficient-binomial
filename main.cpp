#include <iostream>
#include "function.h"

int main()
{
    int choix, a, b;
    bool state = true;

    while (state)
    {
        std::cout << "Projet Normal :\n";
        std::cout << "1 : Calcul de la factorielle\n";
        std::cout << "2 : Calcul du nombre de Combinaison\n";
        std::cout << "3 : Sortir\n";

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                std::cout << "Entrer un nombre : ";
                std::cin >> a;

                if (a < 0)
                    std::cout << "Entrer un nombre positif\n";
                else
                    std::cout << a << "! = " << factoriel(a) << "\n";
                break;

            case 2:
                std::cout << "Entrer la valeur de n : ";
                std::cin >> a;
                std::cout << "Entrer la valeur de k : ";
                std::cin >> b;

                if (combinaison(a, b) == 0)
                    std::cout << "la valeur de a doit etre superieur n celle de k\n";
                else{
                    std::cout << "  ( " << a << " )\n";
                    std::cout << "C |   | =  "<< a << "!/("<< b << "!(" << a << "-"<< b << ")! = " << combinaison(a, b) << "\n";
                    std::cout << "  ( " << b << " )\n";
                }
            break;

            case 3:
                state = false;
            break;

            default:
                std::cout << "Entrer un nombre entre 1 et 3\n";
            break;
        }
    }
    
    return 0;
}