#include <iostream>
#include <iomanip>

int dig(unsigned int);
int sum(unsigned int);
int bin(unsigned int);
bool isPrime(unsigned int, int);
int mcm(const int, const int, const int);
int mcd(const int, const int, const int);
int collatz(int);

int main(void)
{
    int op;
    do
    {
        std::cout << "\n-----------------------------------------------------------" << std::endl;
        std::cout << "--------------Ejercicios de recursividad-[2]---------------" << std::endl;
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << "Calcular los digitos de un numero entero positivo" << std::setw(15) << "[1]" << std::endl;
        std::cout << "Calcular la suma de digitos de un numero entero positivo" << std::setw(8) << "[2]" << std::endl;
        std::cout << "Codificacion de un enteroa binario puro" << std::setw(25) << "[3]" << std::endl;
        std::cout << "Comprueba si un número es primo" << std::setw(33) << "[4]" << std::endl;
        std::cout << "Calcula el minimo comun multiplo de dos enteros" << std::setw(17) << "[5]" << std::endl;
        std::cout << "Calcula el maximo comun divisor de dos enteros" << std::setw(18) << "[6]" << std::endl;
        std::cout << "Logitud de la secuencia de Collatz" << std::setw(30) << "[7]" << std::endl;
        std::cout << "Salir" << std::setw(59) << "[0]" << std::endl;
        std::cout << "Introduzca una opción: ";
        std::cin >> op;
        std::cout << "----------------------------------------------------------" << std::endl;

        switch (op)
        {
        case 1:
            int n;
            std::cout << "Introduzca el valor de n: ";
            std::cin >> n;
            std::cout << "El numero de digitos de " << n << " es: " << dig(n) << std::endl;
            break;
        case 2:
            int number1;
            std::cout << "Introduzca el valor de n: ";
            std::cin >> number1;
            std::cout << "El la suma de digitos de " << number1 << " es: " << sum(number1) << std::endl;
            break;
        case 3:
            int number2;
            std::cout << "Introduzca el valor de n: ";
            std::cin >> number2;
            std::cout << "El resultado binario de" << number2 << " es: " << bin(number2) << std::endl;
            break;
        case 4:
            int number;
            std::cout << "Introduzca el valor de n: ";
            std::cin >> number;
            isPrime(number, 2) ? (std::cout << "EL número es primo" << std::endl) : (std::cout << "EL número no es primo" << std::endl);
            break;
        case 5:
            int n1, n2;
            std::cout << "Introduzca el valor de n1: ";
            std::cin >> n1;
            std::cout << "Introduzca el valor de n2: ";
            std::cin >> n2;
            std::cout << "Resultado: " << mcm(n1, n2, 2) << std::endl;
            break;
        case 6:
            int op1, op2;
            std::cout << "Introduzca el valor de n1: ";
            std::cin >> op1;
            std::cout << "Introduzca el valor de n2: ";
            std::cin >> op2;
            std::cout << "Resultado: " << mcd(n1, n2, 2) << std::endl;
            break;
        case 7:
            int seed;
            std::cout << "Introduzca el valor de n1: ";
            std::cin >> seed;
            std::cout << "Resultado: " << collatz(seed) << std::endl;
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
        n = (1 + dig(n / 10));
    return n;
    // return (n == 0) ? 0 : 1 + dig(n/10); Otra forma
}

int sum(unsigned int n)
{
    if (n == 0)
        return 0;
    else if (n > 0)
        n = (n % 10) + sum(n / 10);
    return n;
}

int bin(unsigned int n)
{
    if (n <= 1)
        return n;
    else if (n > 1)
        n = bin(n / 2) * 10 + (n % 2);
        return n;
}

bool isPrime(unsigned int number, int divisor = 2)
{

    if (number == divisor)
        return true;
    if (number % divisor == 0)
        return false;
    return isPrime(number, divisor + 1);
}

int mcm(const int n1, const int n2, const int divisor = 2)
{
    if (divisor > n1 || divisor > n2)
        return n1 * n2;
    if (n1 % divisor != 0 && n2 % divisor != 0)
        return mcm(n1, n2, divisor + 1);
    int x = n1 % divisor ? n1 : n1 / divisor;
    int y = n2 % divisor ? n2 : n2 / divisor;
    return divisor * mcm(x, y, divisor);
}

int mcd(const int n1, const int n2, const int divisor = 2)
{
    if (divisor > n1 || divisor > n2)
        return 1;
    else if (n1 % divisor == 0 && n2 % divisor == 0)
        return divisor * mcm(n1 / divisor, n2 / divisor, divisor);
    else
        return mcm(n1, n2, divisor + 1);
}

int collatz(int seed)
{
    if (seed == 1)
        return 1;
    int x = seed % 2 ? (3 * seed + 1) : (seed / 2);
    return 1 + collatz(x);
}

