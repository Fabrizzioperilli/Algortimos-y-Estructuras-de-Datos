#include <iostream>
#include <iomanip>

int dig(unsigned int);
int sum(unsigned int);
int bin(unsigned int);

int main(void)
{
    unsigned int op, n, n1, n2;
    do
    {
        std::cout << "\n---Ejercicios de recursividad---" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Calcular los digitos de un numero entero positivo" << std::setw(12) << "[1]" << std::endl;
        std::cout << "Calcular la suma de digitos de un numero entero positivo" << std::setw(12) << "[2]" << std::endl;
        std::cout << "Coficacion de un enteroa binario puro" << std::setw(12) << "[3]" << std::endl;
        std::cout << "Salir" << std::setw(26) << "[0]" << std::endl;
        ;
        std::cout << "Introduzca una opción: ";
        std::cin >> op;
        std::cout << "--------------------------------" << std::endl;

        switch (op)
        {
        case 1:
            std::cout << "Introduzca el valor de n: ";
            std::cin >> n;
            std::cout << "El numero de digitos de " << n << " es: " << dig(n) << std::endl;
            break;
        case 2:
            std::cout << "Introduzca el valor de n: ";
            std::cin >> n1;
            std::cout << "El la suma de digitos de " << n1 << " es: " << sum(n1) << std::endl;
            break;
        case 3:
            std::cout << "Introduzca el valor de n: ";
            std::cin >> n2;
            std::cout << "El resultado binario de" << n2 << " es: " << bin(n2) << std::endl;
            break;

        case 0:
            std::cout << "Fin del programa" << std::endl;
            break;
        default:
            std::cout << "Introduzca de nuevo una opción válida" << std::endl;
            break;
        }

    } while (op != 0);
}

int dig(unsigned int n)
{
    if (n == 0)
        return 0;
    else if (n > 0)
        return (1 + dig(n / 10));
    // return (n == 0) ? 0 : 1 + dig(n/10); Otra forma
}

int sum(unsigned int n)
{
    if (n == 0)
        return 0;
    else if (n > 0)
        return (n % 10) + sum(n / 10);
}

int bin(unsigned int n)
{
    if (n <= 1)
        return n;
    else if (n > 1)
        return bin(n/2) * 10 + (n % 2);
}