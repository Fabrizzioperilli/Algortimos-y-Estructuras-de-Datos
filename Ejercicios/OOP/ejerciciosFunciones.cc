#include <iostream>
#include <vector>
#include "cmath"

int strlen(const char *c);            // Cuenta la longitud de la cadena
char *strcpy(char *a, const char *b); // Copia el contenido de b en a y devuelve a
void ecuacion(float, float *, int);   // Funcion de transicion
float *ecuacion(float, int);          // funcion de transicion que retorna un vector dinámico
void funBernoulli(float, float);  //funcion que calcula una lemniscata de Bernoulli

int main()
{
    char x[10];
    float v[] = {1, 2, 3, 4};

    std::cout << strlen("Algoritmo") << std::endl;
    std::cout << strcpy(x, "Algoritmo") << std::endl;
    ecuacion(2.0, v, 4);
    ecuacion(2.0, 4);
    funBernoulli(2.0, 2.0);
}

int strlen(const char *c)
{
    int i = 0;
    while (c[i] != '\0')
        i++;
    return i;
}

char *strcpy(char *a, const char *b)
{

    int i;
    for (i = 0; b[i] != '\0'; i++)
        a[i] = b[i];
    return a;
}

void ecuacion(float a, float *v, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        float x = i / (n - 1.0);
        v[i] = a * x * x * (3 - 2 * x);
        std::cout << v[i] << " | ";
    }
    std::cout << std::endl;
}

float *ecuacion(float a, int n)
{

    float *v = new float[n];
    for (size_t i = 0; i < n; i++)
    {
        float x = i / (n - 1.0);
        v[i] = a * x * x * (3 - 2 * x);
        std::cout << v[i] << " | ";
    }
    std::cout << std::endl;
    return v;
}

void funBernoulli(float d, float t){
    float x, y;
    x = (d * sqrt(2) * cos(t)) / (sin(t)*sin(t) + 1.0);
    y = x * sin(t);

    std::cout << "x: " << x << "  y: " << y << std::endl;
}
