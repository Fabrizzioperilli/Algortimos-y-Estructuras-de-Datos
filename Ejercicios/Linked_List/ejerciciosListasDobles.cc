#include <iostream>

#include "dll_t.h"

using namespace std;

int main(void)
{
    const int n_chars{26};
    dll_t<char> lista;

    // Inserción de n_chars elementos ('a', 'b, 'c' ...) a la lista por el frente
    for (int i = 0; i < n_chars; i++)
        lista.push_front(new dll_node_t<char>('a' + i));
    cout << "Lista Original" << endl;
    cout << lista << endl << endl;

    // Extracción del elemento 1 por el frente
    dll_node_t<char> *nodo = lista.pop_front();
    char dato = nodo->get_data();
    delete nodo;

    // Impresión del elemento 1 extraído
    cout << "Extrae desde cabecera: " << dato << endl;

    // Extracción de elemento 2 por el frente
    nodo = lista.pop_front();
    dato = nodo->get_data();
    delete nodo;

    // Impresión del elemento 2 extraído
    cout << "Extrae desde cabecera: " << dato << endl;
    cout << lista << endl;

    // Extracción de elemento por la cola
    nodo = lista.pop_back();
    dato = nodo->get_data();
    delete nodo;

    // Impresión del elemento extraído por la cola
    cout << "Extrae desde cola: " << dato << endl;
    cout << lista << endl;

    // Borrado de elemento tercero por el frente
    nodo = lista.erase(lista.get_head()->get_next()->get_next());
    dato = nodo->get_data();
    delete nodo;
    cout << "Borra tercer elemento desde frente: " << dato << endl;
    cout << lista << endl;


    // Extracción de elemento por la cola
    nodo = lista.pop_back();
    dato = nodo->get_data();
    delete nodo;


    cout << "Extrae desde cola: " << dato << endl;
    cout << lista << endl;

    // Obtención del nodo de la cola
    nodo = lista.get_tail();
    dato = nodo->get_data();

    cout << "Dato en la cola: " << dato << endl;

    // Impresión de la lista elemento a elemento
    lista.write();
    cout << endl;

    cout << "Inserción de un nodo después de otro" << endl;
    lista.insert_after(lista.get_head(), new dll_node_t<char>('V'));
    cout << lista << endl;

    cout << "Cambiamos el ultimo elemento de la lista por le penultimo" << endl;
    lista.swap_last();
    cout << lista << endl;

    cout << "Duplicamos los nodos de la lista y los ponemos al final" << endl;
    lista.duplicate();
    cout << lista << endl;

    cout << "Eliminamos y liberamos los elementos impares de la lista" << endl;
    lista.erase_odds();
    cout << lista << endl;
    
    cout << "Eliminamos los nodos de las posiciones pares de la lista y los almacenamos en otra lista" << endl;
    dll_t<char> list_aux = lista.erase_evens();
    cout << list_aux << endl;    

    return 0;
}
