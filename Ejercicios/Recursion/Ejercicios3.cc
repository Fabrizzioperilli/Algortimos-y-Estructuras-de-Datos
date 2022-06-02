#include <iostream>
#include <iomanip>
#include <vector>
// #include "../Vector/vector_t.h"
#include "../Vector/matrix_t.hpp"
#include <assert.h>

// std::vector<int> productoEscalar(std::vector<int>, std::vector<int>, int = 0);
double determinante(matrix_t<int>); // Calcula el determinante de la matriz invocante

int main()
{
    int op;
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {2, 2, 2, 2, 2};

    matrix_t<int> M(3, 3);

    for (size_t i = 1; i <= 3; i++)
        for (size_t j = 1; j <= 3; j++)
        {
            M.at(i, j) = i + j;
        }

    do
    {
        std::cout << "\n-----------------------------------------------------------" << std::endl;
        std::cout << "--------------Ejercicios de recursividad-[3]---------------" << std::endl;
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << "Productor Escalar" << std::setw(12) << "[1]" << std::endl;
        std::cout << "Introduzca una opción: ";
        std::cin >> op;
        std::cout << "--------------------------------" << std::endl;

        switch (op)
        {
        case 1:
            std::cout << "Producto escalar entre: " << std::endl;
            std::cout << "v1: [ ";
            for (size_t i = 0; i < v1.size(); i++)
                std::cout << v1[i] << ",";
            std::cout << "]" << std::endl;

            std::cout << "v2: [ ";
            for (size_t i = 0; i < v1.size(); i++)
                std::cout << v2[i] << ",";
            std::cout << "]" << std::endl;

            // v1 = productoEscalar(v1, v2);
            std::cout << "Resultado: " << std::endl;
            for (size_t i = 0; i < v1.size(); i++)
                std::cout << v1[i] << ",";
            std::cout << "]" << std::endl;

            break;
        case 2:
            std::cout << "Matriz A: " << std::endl;
            for (size_t i = 1; i <= 3; i++){
                for (size_t j = 1; j <= 3; j++)
                    std::cout << M(i, j);
                std::cout << std::endl;
            }
            std::cout << "Determinante de Matriz A: " << determinante(M)<< std::endl;

            break;
        default:
            std::cout << "introduzca una opción válida " << std::endl;
            break;
        }
    } while (op != 0);
    return 0;
}

// std::vector<int> productoEscalar(std::vector<int> v1, std::vector<int> v2, int i)
// {
//     assert(v1.size() == v2.size());
//     if (i ==  v1.size())
//         return 0;
//     return v1[i] * v2[i] + productoEscalar(v2, i +1);
// }

double determinante (matrix_t<int> M){
    assert(M.get_m() == M.get_n());

    if (M.get_m() == 1)
        return M.at(1,1);
    double suma = 0;
    for (size_t i = 1; i <= M.get_m(); i++)
        matrix_t<int> aux;    
}   