// AUTOR: FABRIZZIO PERILLI MARTIN
// FECHA: 26/04/2022
// EMAIL: alu0101138589@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"
#include "../Stack/stack_l_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T>
class sll_t
{
public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T> *get_head(void) const { return head_; };
  void set_head(sll_node_t<T> *node) { head_ = node; }

  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T> *);
  sll_node_t<T> *pop_front(void);

  void insert_after(sll_node_t<T> *, sll_node_t<T> *);
  sll_node_t<T> *erase_after(sll_node_t<T> *);

  sll_node_t<T> *search(const T &) const;

  //////////Problemas de clase
  T remove_last(void);                          // Elemina el ultimo elemento de la lista
  void swap12(void);                            // Cambia el primer nodo con el segundo de la lista
  void duplicate(void);                         // Duplica el nodo y lo coloca como el siguiente de la lista
  void erase_evens(void);                       // Elimina y libera los nodos en las posiciones pares de la lista
  sll_t<T> move_odds(void);                     // Elimina los nodos de las posiciones impares y los translada en otra lista
  void invert(void);                            // Invierte todos los nodos de la lista
  void insert_tail(sll_node_t<T> *n);           // Inserta un nodo por el final de la lista
  void fusion_desc(sll_t<T> &A, sll_t<T> &B);   // Fuciona los valores de dos listas en una tercera de forma descedente
  void fusion_asc(sll_t<T> &A, sll_t<T> &B);    // Fuciona los valores de dos listas en una tercera de forma ascedente
  void sll_union(sll_t<T> &A, sll_t<T> &B);     // Realiza la union de dos listas enlazadas (elementos no repetidos)
  void sll_intersect(sll_t<T> &A, sll_t<T> &B); // Realiza la interseccion de dos listas enlazadas (elementos repetidos)

  //////////////////////

  // E/S
  std::ostream &write(std::ostream & = std::cout) const;

private:
  sll_node_t<T> *head_;
};

template <class T>
std::ostream &operator<<(std::ostream &, const sll_t<T> &);

// destructor
template <class T>
sll_t<T>::~sll_t(void)
{
  while (!empty())
  {
    sll_node_t<T> *aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// Comprobar si lista vacía
template <class T>
bool sll_t<T>::empty(void) const
{
  return head_ == NULL;
}

// operaciones
template <class T>
void sll_t<T>::push_front(sll_node_t<T> *n)
{
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T>
sll_node_t<T> *sll_t<T>::pop_front(void)
{
  assert(!empty());
  sll_node_t<T> *aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T>
void sll_t<T>::insert_after(sll_node_t<T> *prev,
                            sll_node_t<T> *n)
{
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T>
sll_node_t<T> *sll_t<T>::erase_after(sll_node_t<T> *prev)
{
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T> *aux = prev->get_next();

  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T>
sll_node_t<T> *sll_t<T>::search(const T &d) const
{
  sll_node_t<T> *aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();

  return aux;
}

// E/S
template <class T>
std::ostream &sll_t<T>::write(std::ostream &os) const
{
  sll_node_t<T> *aux = head_;

  while (aux != NULL)
  {
    aux->write(os);
    std::cout << " | ";
    aux = aux->get_next();
  }
  return os;
}
///////////////////Problemas de clase

template <class T>
T sll_t<T>::remove_last(void)
{
  sll_node_t<T> *aux = head_;
  sll_node_t<T> *prev = NULL;
  sll_node_t<T> *node;

  while (aux->get_next() != NULL)
  {
    prev = aux;
    aux = aux->get_next();
  }

  if (prev == NULL)
    node = pop_front();
  else
    node = erase_after(prev);
  T dato = node->get_data();

  delete node;
  return dato;
}

template <class T>
void sll_t<T>::swap12()
{

  assert(!empty());
  assert(get_head()->get_next() != NULL);
  push_front(erase_after(get_head()));
}

template <class T>
std::ostream &operator<<(std::ostream &os, const sll_t<T> &sll)
{
  return sll.write(os);
}

template <class T>
void sll_t<T>::duplicate()
{
  sll_node_t<T> *aux = get_head();

  while (aux != NULL)
  {
    sll_node_t<T> *aux2 = new sll_node_t<T>(aux->get_data());
    insert_after(aux, aux2);
    aux = aux->get_next()->get_next();
  }
}

template <class T>
void sll_t<T>::erase_evens(void)
{
  sll_node_t<T> *aux = get_head();

  while ((aux != NULL) && (aux->get_next() != NULL))
  {
    delete erase_after(aux);
    aux = aux->get_next();
  }
}

template <class T>
sll_t<T> sll_t<T>::move_odds(void)
{
  sll_t<T> odds_list;
  sll_node_t<T> *aux = get_head();

  if (!empty())
  {
    odds_list.push_front(pop_front());
    aux = get_head();
  }
  while (aux != NULL && aux->get_next() != NULL)
  {
    odds_list.push_front(erase_after(aux));
    aux = aux->get_next();
  }

  return odds_list;
}

template <class T>
void sll_t<T>::invert(void)
{
  sll_node_t<T> *aux;
  sll_node_t<T> *new_head = NULL;

  while (get_head() != NULL)
  {
    aux = get_head();
    set_head(aux->get_next());
    aux->set_next(new_head);
    new_head = aux;
  }
  set_head(new_head);
}

template <class T>
void sll_t<T>::insert_tail(sll_node_t<T> *n)
{
  if (empty())
    push_front(n);
  else
  {
    sll_node_t<T> *aux = get_head();
    while (aux->get_next() != NULL)
      aux = aux->get_next();
    insert_after(aux, n);
  }
}

template <class T>
void sll_t<T>::fusion_desc(sll_t<T> &A, sll_t<T> &B)
{
  sll_node_t<T> *auxA = A.get_head();
  sll_node_t<T> *auxB = B.get_head();
  T d;

  while (auxA != NULL && auxB != NULL)
  {
    if (auxA->get_data() < auxB->get_data())
    {
      d = auxA->get_data();
      auxA = auxA->get_next();
    }
    else
    {
      d = auxB->get_data();
      auxB = auxB->get_next();
    }
    push_front(new sll_node_t<T>(d));
  }
}

template <class T>
void sll_t<T>::fusion_asc(sll_t<T> &A, sll_t<T> &B)
{

  sll_node_t<T> *auxA = A.get_head();
  sll_node_t<T> *auxB = B.get_head();
  T d;
  stack_l_t<int> stack;

  while (auxA != NULL && auxB != NULL)
  {
    if (auxA->get_data() < auxB->get_data())
    {
      d = auxA->get_data();
      auxA = auxA->get_next();
    }
    else
    {
      d = auxB->get_data();
      auxB = auxB->get_next();
    }
    stack.push(d);
  }

  while (!stack.empty())
  {
    push_front(new sll_node_t<T>(stack.top()));
    stack.pop();
  }
}

template <class T>
void sll_t<T>::sll_union(sll_t<T> &A, sll_t<T> &B)
{
  sll_node_t<T> *aux = A.get_head();
  // Insertamos los elementos no repetidos
  while (aux != NULL)
  {
    if (B.search(aux->get_data()) == NULL)
      push_front(new sll_node_t<T>(aux->get_data()));
    aux = aux->get_next();
  }
  // Insertamos los elementos que quedan de B

  aux = B.get_head();
  while (aux != NULL)
  {
    push_front(new sll_node_t<T>(aux->get_data()));
    aux = aux->get_next();
  }
}

template <class T>
void sll_t<T>::sll_intersect(sll_t<T> &A, sll_t<T> &B)
{
  sll_node_t<T> *aux = A.get_head();

  while (aux != NULL)
  {
    if (B.search(aux->get_data()) != NULL)
      push_front(new sll_node_t<T>(aux->get_data()));
    aux = aux->get_next();
  }
}

#endif // SLLT_H_
