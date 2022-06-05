#include <iostream>
#include <iomanip>
#include "../Vector/vector_t.h"
#include <assert.h>
#include <cstring>

bool palindrome(char[], int, int);

int main()
{
    char cadena[50];
    std::cout << "Comprueba si una cadena es palindroma o no " <<std::endl;
    std::cout << "Introduzca una cadena: ";
    std::cin.getline(cadena, 50);
    palindrome(cadena, 0, strlen(cadena) -1 ) ? (std::cout << "La palabra " << cadena << " es palindroma " << std::endl) : (std::cout << "La palabra " << cadena << " no es palindroma " << std::endl);
}

bool palindrome(char cadena[], int iz, int de)
{
    if (iz >= de)
        return true;
    if (cadena[iz] == cadena[de])
        palindrome(cadena, iz + 1, de - 1);
    else
        return false;
}