#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "../Linked_List/dll_t.h"

// Clase para pilas mediante estructura dinámica
template <class T>
class stack_l_t
{
public:
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T &);
  void pop(void);
  const T &top(void) const;
  bool empty(void) const;
  /////////////Problemas
  void swap12(void);              // intercambia los dos primeros elementos del top de la pila
  stack_l_t<T> inverseStackAux(); // Vacia la pila invocante y rellena una auxiliar con estos valores ordenados al revés
  void erase_odds();              // Elimina los nodos en posiciones impares
  void minMax(T &dato);           // Traslada los elementos menores que el parametro en una pila auxiliar y los mayores o iguales en otra pila
  T maxValue();                   // Obtiene el maximo valor de una pila
  void cod2bin(int);              // Codifica en binario un numero decimal

  /////////////

  // E/S
  std::ostream &write(std::ostream &os = std::cout) const;

private:
  dll_t<T> l_;
};

template <class T>
std::ostream &operator<<(std::ostream &os, stack_l_t<T> &stack)
{
  return stack.write(os);
}

// operaciones
template <class T>
void stack_l_t<T>::push(const T &dato)
{
  dll_node_t<T> *nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

template <class T>
void stack_l_t<T>::pop(void)
{
  assert(!empty());
  delete l_.pop_front();
}

template <class T>
const T &stack_l_t<T>::top(void) const
{
  assert(!empty());
  return l_.get_head()->get_data();
}

template <class T>
bool stack_l_t<T>::empty(void) const
{
  return l_.empty();
}

// E/S
template <class T>
std::ostream &stack_l_t<T>::write(std::ostream &os) const
{
  dll_node_t<T> *aux = l_.get_head();
  while (aux != NULL)
  {
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

template <class T>
void stack_l_t<T>::swap12(void)
{
  T elem1 = top();
  pop();
  T elem2 = top();
  pop();
  push(elem1);
  push(elem2);
}

template <class T>
stack_l_t<T> stack_l_t<T>::inverseStackAux()
{

  stack_l_t<T> aux;
  while (!empty())
  {
    aux.push(top());
    pop();
  }
  return aux;
}

template <class T>
void stack_l_t<T>::erase_odds()
{
  stack_l_t<T> aux = inverseStackAux();

  while (!aux.empty())
  {
    aux.pop();
    if (!aux.empty())
      push(aux.top());
    aux.pop();
  }
}

template <class T>
void stack_l_t<T>::minMax(T &dato)
{
  stack_l_t<T> min;
  stack_l_t<T> max;

  while (!empty())
  {
    if (top() >= dato)
    {

      max.push(top());
    }
    else
    {
      min.push(top());
    }
    pop();
  }

  std::cout << "Pila con valores menores que: " << dato << std::endl;
  min.write();

  std::cout << "Pila con valores mayores o iguales que: " << dato << std::endl;
  max.write();
}

template <class T>
T stack_l_t<T>::maxValue()
{

  T value = top();
  pop();

  while (!empty())
  {
    if (top() > value)
      value = top();
    pop();
  }
  return value;
}

template <class T>
void stack_l_t<T>::cod2bin(int n)
{

  while (n >= 1)
  {
    if (n % 2 == 0)
      push(n % 2);
    else
      push(n % 2);
    n /= 2;
  }

  while (!empty())
  {
    std::cout << top();
    pop();
  }
}

#endif // STACKL_H_
