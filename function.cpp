#include "function.h"

int factoriel(int n)
{
    if (n == 0)
        return 1;
    else
    return n * factoriel(n-1);
}

int combinaison(int n, int k)
{
    if (n < k)
        return 0;
    return factoriel(n)/(factoriel(k) * (factoriel(n - k)));
}