
#include <iostream>

#include "stack_v_t.h"
#include "stack_l_t.h"
#include <unistd.h>

using namespace std;

int main(void)
{
  stack_v_t<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  cout << "LLenamos la pila " << endl;
  for (int i = 0; i < 10; i++)
  {
    pila_vector.push('a' + i);
    cout << pila_vector << endl;
  }

  cout << endl;

  cout << "Vaciamos la pila " << endl;
  while (!pila_vector.empty())
  {
    pila_vector.pop();
    cout << pila_vector << endl;
  }

  pila_vector.empty() ? (cout << "La pila vector está vacia" << endl) : (cout << "La pila vector no está vacia" << endl);

  stack_l_t<char> pila_lista;
  cout << "********** PILA LISTA ENLAZADA **********" << endl;
  cout << "LLenamos la pila " << endl;
  for (int i = 0; i < 10; i++)
    pila_lista.push('a' + i);
  cout << pila_lista << endl;

  cout << endl;

  cout << "Inetercambiamos los dos primeros elementos en el top de la pila " << endl;
  pila_lista.swap12();
  cout << pila_lista << endl;

  cout << "Elminamos los elementos impares de la pila" << endl;
  pila_lista.erase_odds();
  cout << pila_lista << endl;

  cout << "Vaciamos la pila original y rellenamos otra pila" << endl;
  stack_l_t<char> pilaAux = pila_lista.inverseStackAux();

  cout << "Pila original" << endl;
  cout << pila_lista << endl;
  pila_lista.empty() ? (cout << "La pila lista está vacia\n" << endl) : (cout << "La pila lista no está vacia\n" << endl);

  cout << "Pila auxiliar con orden inverso" << endl;
  cout << pilaAux << endl;

  
  
  cout << "Creamos una pila de valores enteros" << endl;
  stack_l_t<int> pila1;
  int dato = 5;
  
  srand(time(NULL));
  for (size_t i = 0; i < 6; i++)
    pila1.push(rand() % 15);
  
  cout << "Pila de enteros" << endl;
  cout << pila1 << endl;

  // pila1.minMax(dato);

  int value = pila1.maxValue();
  cout << "El valor máximo de la pila es: " << value << endl;
  
  
  return 0;
}
