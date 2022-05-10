#include <iostream>
#include <iomanip>

unsigned int factorial(unsigned);
float potencia(const float, const unsigned);
int producto(int, int);

int main()
{

    unsigned op, n = 4, expo = 2;
    float base = 2.0;
    int a = 3, b = 3;

    do
    {
        std::cout << "\n---Ejercicios de recursividad---" << std::endl;
        std::cout << "Factorial de número" << std::setw(10) << "[1]" << std::endl;
        std::cout << "Potencia de número" << std::setw(11) << "[2]" << std::endl;
        std::cout << "Producto de dos números" << std::setw(6) << "[3]" << std::endl;
        std::cout << "Salir" << std::setw(24) << "[0]" << std::endl;
        ;
        std::cout << "Introduzca una opción: ";
        std::cin >> op;
        std::cout << "-----------------------" << std::endl;

        switch (op)
        {
        case 1:
            std::cout << "Introduzca el valor de n: ";
            std::cin >> n;
            std::cout << "Factorial de " << n << " = " << factorial(n) << std::endl;
            break;
        case 2:
            std::cout << "Introduzca el valor de la base: ";
            std::cin >> base;

            std::cout << "Introduzca el valor del exponente: ";
            std::cin >> expo;

            std::cout << "Potencia de " << base << " = " << potencia(base, expo) << std::endl;
            break;
        case 3:
            std::cout << "Introduzca el valor de a: ";
            std::cin >> a;

            std::cout << "Introduzca el valor de b: ";
            std::cin >> b;

            std::cout << "Producto de " << a << " y " << b << " = " << producto(a, b) << std::endl;
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

unsigned int factorial(unsigned n)
{
    return (n == 0) ? 1 : n * factorial(n - 1);
}

float potencia(const float base, const unsigned expo)
{
    return (expo == 0) ? 1 : base * potencia(base, expo - 1);
}

int producto(int a, int b)
{
    return (b == 0) ? 0 : a + producto(a, b - 1);
}