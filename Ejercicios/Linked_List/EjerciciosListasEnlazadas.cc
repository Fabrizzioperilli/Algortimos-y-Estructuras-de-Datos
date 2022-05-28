#include <iostream>
#include "sll_t.h"

#include <iostream>

#include "sll_t.h"

#define N_CHARS 26

using namespace std;

int main(void)
{
    sll_t<char> lista;
    int count = 1;

    // Inserción de N_CHARS elementos ('a', 'b, 'c' ...) a la lista por el frente
    for (int i = 0; i < N_CHARS; i++)
        lista.push_front(new sll_node_t<char>('a' + i));

    // Impresión de la lista elemento a elemento
    cout << count++ << "- Lista Original" << endl;
    cout << lista;
    cout << endl;

    cout << count++ << "- Elminando el último elemento de la lista: " << lista.remove_last() << endl;
    cout << lista;
    cout << endl;

    cout << count++ << "- Cambiamos el primer elemento con el segundo elemento de la lista: " << endl;
    lista.swap12();
    cout << lista << endl;

    cout << count++ << "- Eliminamos los elementos en las posciones pares de la lista" << endl;
    lista.erase_evens();
    cout << lista << endl;

    cout << count++ << "- Duplicamos el valor de cada nodo:  " << endl;
    lista.duplicate();
    cout << lista << endl;

    cout << count++ << "- Extracción de elemento 1 por el frente" << endl;
    sll_node_t<char> *nodo = lista.pop_front();
    char dato = nodo->get_data();
    delete nodo;

    cout << "Dato 1: " << dato << endl;
    cout << lista << endl;


    cout << count++ << "- Búsqueda e impresión del elemento con valor 'n'" << endl;
    nodo = lista.search('n');
    dato = nodo->get_data();
    cout << "Dato: " << dato << endl;

    cout << count++ << "- Extracción del elemento siguiente al de valor 'n' localizado anteriormente" << endl;
    nodo = lista.erase_after(nodo);
    dato = nodo->get_data();
    cout << lista << endl;
    cout << "Dato eliminado : " << dato << endl;

    delete nodo;

    cout << count++ << "- Invertimos el orden de la lista  " << endl;
    lista.invert();
    cout << lista << endl;

    cout << count++ << "- Eliminamos los nodos impares de la lista y lo almacenamos en otra lista:  " << endl;
    cout << lista.move_odds() << endl;

    cout << count++ << "- Insertamos un nodo nuevo al final de la lista:  " << endl;
    lista.insert_tail(new sll_node_t<char>('R'));

    cout << lista << endl;

    // Creamos dos listas de enteros
    sll_t<int> listA, listB, listC;

    for (size_t i = 0; i < 5; i++)
        listA.push_front(new sll_node_t<int>(i));

    for (size_t i = 6; i < 11; i++)
        listB.push_front(new sll_node_t<int>(i));
    
    cout << "\nLista A de enteros" << endl;
    cout << listA << endl;

    cout << "Lista B de enteros" << endl;
    cout << listB << endl;

    cout << "Fucionamos las dos listas en una tercera de forma descendiente" << endl;
    listC.fusion_desc(listA,listB);
    cout << listC << endl;
    


    return 0;
}
