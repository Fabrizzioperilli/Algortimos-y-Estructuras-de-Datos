#include <iostream>
#include <iomanip>
int main()
{

    typedef unsigned short conjunto_t;

    conjunto_t A = 0;
    conjunto_t B = 0;
    conjunto_t C = 0;
    conjunto_t uno = 1;
    unsigned i = 5, j = 2, count = 1;

    std::cout << count++ << "- Conjunto A vacio " << A << std::endl;
    A |= (uno << i);
    std::cout << count++ << "- Añadimos 1 bit al Conjunto A en la posicion [" << i << "]: " << A << std::endl;
    A |= (uno << j);
    std::cout << count++ << "- Añadimos 1 bit al Conjunto A en la posicion [" << j << "]: " << A << std::endl;
    uno <<= i;
    A &= ~uno;
    std::cout << count++ << "- Eliminamos 1 bit del conjunto A en la posicion [" << i << "]: " << A << std::endl;
    std::cout << count++ << "- Comprobamos si el bit de la posicion [" << i << "] pertenece al conjunto A" << std::endl;
    if ((A & uno) != 0)
        std::cout << std::setw(5) << i << "∈A" << " (Pertenece)" << std::endl;
    else
        std::cout << std::setw(5) << i << "∉A" << " (No pertenece)" << std::endl;
    conjunto_t Ac = ~A;
    std::cout << count++ << "- Complento del conjunto A  [" << A << "]: " << Ac << std::endl;
    
    B |= (uno << j);
    C = A | B ;
    std::cout << count++ << "- Union del conjunto A  [" << A << "]: " << " y  B [" << B << "]: " << C << std::endl;
    C = A & B ;
    std::cout << count++ << "- Interseccion del conjunto A  [" << A << "]: " << " y  B [" << B << "]: " << C << std::endl;
}
