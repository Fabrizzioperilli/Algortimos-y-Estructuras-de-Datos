
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cassert>
#include "../Stack/stack_l_t.h"
#include "dll_t.h"

// Clase TAD cola implementada con una lista
template <class T>
class queue_l_t
{
private:
  dll_t<T> l_;

public:
  // constructor
  queue_l_t(void) : l_() {}

  // destructor
  ~queue_l_t(void) {}

  // operaciones
  bool empty(void) const;
  int size(void) const;
  void push(const T &dato);
  void pop(void);
  const T &front(void) const;
  const T &back(void) const;

  /////////////Problemas
  void reverse(); // Invierte los elementos de una cola
  void split();  //Separamos los elementos de la cola invocante en dos diferentes donde alamacenamos los elementos de posciones pares e impares
  void remove_repeat(); //Elimina los elementos repetidos de una cola
  /////////////

  // E/S
  std::ostream &write(std::ostream &os = std::cout) const;
};

// operaciones
template <class T>
bool queue_l_t<T>::empty(void) const
{
  return l_.empty();
}

template <class T>
int queue_l_t<T>::size(void) const
{
  return l_.get_size();
}

template <class T>
void queue_l_t<T>::push(const T &dato)
{
  dll_node_t<T> *node = new dll_node_t<T>(dato);
  assert(node != NULL);
  l_.push_front(node);
}

template <class T>
void queue_l_t<T>::pop(void)
{
  assert(!empty());
  delete l_.pop_back();
}

template <class T>
const T &queue_l_t<T>::front(void) const
{
  assert(!empty());
  return (l_.get_tail()->get_data());
}

template <class T>
const T &queue_l_t<T>::back(void) const
{
  assert(!empty());
  return (l_.get_head()->get_data());
}

// E/S
template <class T>
std::ostream &queue_l_t<T>::write(std::ostream &os) const
{
  dll_node_t<T> *aux = l_.get_head();
  while (aux != NULL)
  {
    os << aux->get_data() << " | ";
    aux = aux->get_next();
  }
  os << std::endl;
  return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os,
                         const queue_l_t<T> &q)
{
  q.write(os);
  return os;
}

template <class T>
void queue_l_t<T>::reverse()
{
  stack_l_t<T> stack; // Utilizamos una pila auxiliar para invertir los elementos de la cola

  while (!empty())
  {
    stack.push(front());
    pop();
  }

  while (!stack.empty())
  {
    push(stack.top());
    stack.pop();
  }
}

template<class T>
void queue_l_t<T>::split(){
  queue_l_t<T> odds;
  queue_l_t<T> evens;
  
  while (!empty())
  {
    odds.push(front());
    pop();
    evens.push(front());
    pop();
  }
  
  std::cout << "Cola de posiciones impares" << std::endl;
  std::cout << odds << std::endl;
  std::cout << "Cola de posiciones pares" << std::endl;
  std::cout << evens << std::endl;

}

template<class T>
void queue_l_t<T>::remove_repeat(){

  int sz = size();  // Tamaño original de la cola
  int n = 0;  // Número de elementos no repetidos encontrados hasta el momento
  
  T *aux = new T[sz];  // Estructura auxiliar
  for (int i = 0; i < sz; i++)  // Para cada elemento de la cola
  {
    bool found = false;  // Comprobamos si ya aparece en la estructura auxiliar
    for (int j = 0; j < n && !found; j++)
      if (aux[j] == front())
        found = true;
    if (!found)  // Si no está repetido, lo añadimos tanto a la cola como a aux
    {
      aux[n++] = front();
      push(front());
    }
    pop();
  }
  delete [] aux;
}
#endif // QUEUE_H_
