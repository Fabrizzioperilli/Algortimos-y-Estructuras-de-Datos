#include <iostream>
#include <iomanip>

double factorial(double);
float potencia(const float, const unsigned);
int producto(int, int);
unsigned fibonacci(unsigned);
unsigned CoeBinomial(unsigned, unsigned);
int BBR(int*, int, int, int);

int main(void)
{

    unsigned op, expo = 2;
    double n;
    float base = 2.0;
    int a = 3, b = 3;
    unsigned fib, N, k;
    int v[] = {1, 2, 3, 4, 5, 6};
    int value = 2;

    do
    {
        std::cout << "\n---Ejercicios de recursividad---" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Factorial de número" << std::setw(12) << "[1]" << std::endl;
        std::cout << "Potencia de número" << std::setw(13) << "[2]" << std::endl;
        std::cout << "Producto de dos números" << std::setw(8) << "[3]" << std::endl;
        std::cout << "Serie Fibonacci" << std::setw(16) << "[4]" << std::endl;
        std::cout << "Coeficiente binomial" << std::setw(11) << "[5]" << std::endl;
        std::cout << "Busqueda binaria recursiva" << std::setw(5) << "[6]" << std::endl;
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
        case 4:
            std::cout << "Introduzca el valor del entero: ";
            std::cin >> fib;
            std::cout << "El resultado es: " << fibonacci(fib) << " " << std::endl;
            break;

        case 5:
            std::cout << "Introduzca el valor de n (n > k) : " << std::endl;
            std::cin >> N;
            std::cout << "Introduzca el valor de k: " << std::endl;
            std::cin >> k;
            std::cout << "El resultado es: " << CoeBinomial(N, k) << std::endl;
            break;
       
        case 6:
            int val;
            std::cout << "Vector: [";
            for (size_t i = 0; i < 6; i++)
                std::cout << v[i] << ", ";
            std::cout << "]" << std::endl;
            std::cout << "Valor a buscar: " << value;
            
            val = BBR(v, 1, 6, value); 
            if (val == 1)
                std::cout << "\nValor encontrado en el vector" << std::endl;
            else
                std::cout << "\nValor no encontrado en el vector" << std::endl;
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

 double factorial( double n)
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

unsigned fibonacci(unsigned n)
{
    if (n <= 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned CoeBinomial(unsigned N, unsigned k)
{
    if (k == 0 || k == N)
        return 1;
    else
        return CoeBinomial(N - 1, k - 1) + CoeBinomial(N - 1, k);
}

int BBR(int v[], int i, int d, int x)
{
    if (i > d)
        return -1;
    int c = (i + d) / 2;

    if (v[c] == x)
        return c;
    if (v[c] < x )
        return BBR(v, c + 1, d, x);
    if ( x < v[c] )
        return BBR(v, i, c - 1, x);
}