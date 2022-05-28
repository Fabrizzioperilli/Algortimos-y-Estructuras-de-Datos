#include <iostream>
#include "cmath"
#include <vector>

void multiplo3(int *, int);
void reverse(int *, int);
int search(int *, int);
void maxMin(std::vector<int>);
int Sum(std::vector<int>); //Suma de los elementos del vector que sean multiplos de 3 o sean impares

int main(int argc, char const *argv[])
{

    int v[] = {10, 12, 3, 15, 5, 6, 10, 9, 18, 12};
    std::vector<int> v1 = {1, 2, 20, 0, 5, 9, 24};

    // multiplo3(v, 10);

    std::cout << "Vector original: ";
    for (size_t i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "Vector reverso: ";
    reverse(v, 10);

    int val = search(v, 3);
    if (val == -1)
        std::cout << "El valor a buscar no se encuenta en el vector " << std::endl;
    else
        std::cout << "El valor a buscar se encuenta en la posicion: " << val << std::endl;

    maxMin(v1);

    std::cout << "La suma de los elementos del vector v1 es: " << Sum(v1) << std::endl;

    return 0;
}



int Sum(std::vector<int> v)
{
    int sum = 0;
    for (size_t i = 0; i < v.size(); i++)
        if((v[i] % 3 == 0) || (v[i] % 2 != 0))
        sum += v[i];
    return sum;
}



void maxMin(std::vector<int> v)
{
    int mayor = 0;
    int min = v[0];
    int posi, posj;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > mayor)
        {
            mayor = v[i];
            posi = i;
        }
        else if (v[i] < min)
        {
            min = v[i];
            posj = i;
        }
    }
    std::cout << "El elemento mayor del vector es: " << mayor << " posicion [" << posi << "]" << std::endl;
    std::cout << "El elemento menor del vector es: " << min << " posicion [" << posj << "]" << std::endl;
}




int search(int *v, int x)
{

    for (size_t i = 0; i < 10; i++)
        if (v[i] == x)
            return i;

    return -1;
}



void reverse(int *v, int n)
{

    for (int i = n - 1; i >= 0; i--)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}



void multiplo3(int *v, int n = 10)
{
    int *T = new int[n];
    int *N = new int[n];
    int mult = 0, nomult = 0;
    int summary = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (v[i] % 3 == 0)
        {
            mult++;
            T[i] = v[i];
            std::cout << "Multiplo de 3: " << T[i] << " | posicion [" << i << "]" << std::endl;
        }
        else
        {
            nomult++;
            N[i] = v[i];
            std::cout << "No multiplo de 3: " << N[i] << " | posicion [" << i << "]" << std::endl;
        }

        summary += N[i] * N[i];
    }
    std::cout << "El modulo del vector de los elemtos no multiplos es:  " << sqrt(summary) << std::endl;

    delete[] T, N;
}