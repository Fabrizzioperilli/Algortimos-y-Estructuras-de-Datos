#include <iostream>

int Sum(int **m);
void fill(int **m, int, int);
void write(int **m, int, int);
void diagonal(int **m, int, int);
void SecDiagonal(int **m, int, int);
void SubMatrixInfer(int **m, int, int);
void SubMatrixSuperior(int **m, int, int);
void SubMatrixInferSinDiagonal(int **m, int, int);
bool isSimmetric(int **m, int, int);

int main()
{
    int rows = 3;
    int col = 3;

    int **matriz = new int *[rows];
    for (size_t i = 0; i < rows; i++)
        matriz[i] = new int[col];

    fill(matriz, rows, col);
    write(matriz, rows, col);
    
    if (isSimmetric(matriz, rows, col))
        std::cout << "La matriz es simetrica" << std::endl;
    else
        std::cout << "La matriz no es simetrica" << std::endl;
    
    std::cout << "La suma de los elementos de la matriz es: " << Sum(matriz) << std::endl;

    diagonal(matriz, rows, col);
    SecDiagonal(matriz, rows, col);
    SubMatrixInfer(matriz, rows, col);
    SubMatrixInferSinDiagonal(matriz, rows, col);
    SubMatrixSuperior(matriz, rows, col);

    return 0;
}



void SubMatrixInfer(int **m, int rows, int col)
{
    std::cout << "Submatriz triangular inferior: " << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j <= i; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}



void SubMatrixInferSinDiagonal(int **m, int rows, int col)
{
    std::cout << "Submatriz triangular inferior sin diagonal principal: " << std::endl;
    for (size_t i = 1; i < rows; i++)
    {
        for (size_t j = 0; j <= i - 1; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}



void SubMatrixSuperior(int **m, int rows, int col)
{
    std::cout << "Submatriz triangular superior: " << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = i; j < col; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}



void diagonal(int **m, int rows, int col)
{

    std::cout << "Diagonal principal: ";
    for (size_t i = 0; i < rows; i++)
        std::cout << m[i][i] << " ";
    std::cout << std::endl;
}



void SecDiagonal(int **m, int rows, int col)
{

    std::cout << "Diagonal secundaria: ";
    for (size_t i = 0; i < rows; i++)
        std::cout << m[i][(rows - 1) - i] << " ";
    std::cout << std::endl;
}



void write(int **m, int rows, int col)
{

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < col; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}



void fill(int **m, int rows, int col)
{
    // for (size_t i = 0; i < rows; i++)
    //     for (size_t j = 0; j < col; j++)
    //         m[i][j] = i + 1;
    m[0][0] = 5;
    m[0][1] = 1;
    m[0][2] = 3;
    m[1][0] = 1;
    m[1][1] = 8;
    m[1][2] = 2;
    m[2][0] = 3;
    m[2][1] = 2;
    m[2][2] = 5;
}



int Sum(int **m)
{
    int sum = 0;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            sum += m[i][j];
    return sum;
}



bool isSimmetric(int **m, int rows, int col)
{

    bool is_sym = true;
    int i = 1;
    while ((is_sym == true) && (i < col))
    {
        int j = 0;
        while ((is_sym == true) && (j <= i - 1))
        {
            if (m[i][j] != m[j][i])
                is_sym = false;
            j++;
        }
        i++;
    }
    return is_sym;
}