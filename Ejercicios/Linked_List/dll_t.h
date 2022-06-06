// AUTOR: FABRIZZIO DANIEELL PERILLI MARTIN
// FECHA: 10/05/2022
// EMAIL: alu0101138589@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"
#include "../Stack/stack_v_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T>
class dll_t
{
public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void);

  // getters
  dll_node_t<T> *get_tail(void) const { return tail_; }
  dll_node_t<T> *get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T> *);
  void push_front(dll_node_t<T> *);

  dll_node_t<T> *pop_back(void);
  dll_node_t<T> *pop_front(void);
  dll_node_t<T> *erase(dll_node_t<T> *);

  //////////Problemas
  void insert_after(dll_node_t<T> *prev, dll_node_t<T> *n); // Inserta un nodo despues de uno previo
  void swap_last(void);                                     // Cambia el ultimo elemento de la lista por el penultimo
  void duplicate(void);                                     // duplica los elemento de la lista y los coloca al lado
  void erase_odds(void);                                    // Eliminar y liberar todo los elementos en posiciones impares de la lista
  dll_t<T> erase_evens(void);                               // Eliminar los nodos de las posiciones pares de la lista y transladarlos en otra lista
  void shift_back(dll_node_t<T> *n);                        // Intercambia la posicion del nodo pasado por parametros con el nodo anterior
  dll_node_t<T> *search(const T &d) const;                  // Busca un nodo especifico en la lista
  void write_odds();                                        // Imprime los elementos con valores impares de la lista de forma inversa

  /////////////////

  // E/S
  std::ostream &write(std::ostream & = std::cout) const;

private:
  dll_node_t<T> *head_;
  dll_node_t<T> *tail_;
  int sz_;
};
template <class T>
std::ostream &operator<<(std::ostream &os, dll_t<T> &dll)
{
  return dll.write(os);
}

// destructor
template <class T>
dll_t<T>::~dll_t(void)
{
  while (head_ != NULL)
  {
    dll_node_t<T> *aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T>
bool dll_t<T>::empty(void) const
{
  if (head_ == NULL)
  {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  }
  else
    return false;
}

// operaciones
template <class T>
void dll_t<T>::push_front(dll_node_t<T> *nodo)
{
  assert(nodo != NULL);

  if (empty())
  {
    head_ = nodo;
    tail_ = head_;
  }
  else
  {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T>
void dll_t<T>::push_back(dll_node_t<T> *nodo)
{
  assert(nodo != NULL);

  if (empty())
  {
    head_ = nodo;
    tail_ = head_;
  }
  else
  {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T>
dll_node_t<T> *dll_t<T>::pop_back(void)
{
  assert(!empty());

  dll_node_t<T> *aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T>
dll_node_t<T> *dll_t<T>::pop_front(void)
{
  assert(!empty());

  dll_node_t<T> *aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T>
dll_node_t<T> *dll_t<T>::erase(dll_node_t<T> *nodo)
{
  assert(nodo != NULL);

  if (nodo->get_prev() != NULL)
    nodo->get_prev()->set_next(nodo->get_next());
  else
    head_ = nodo->get_next();
  if (nodo->get_next() != NULL)
    nodo->get_next()->set_prev(nodo->get_prev());
  else
    tail_ = nodo->get_prev();
  sz_--;
  nodo->set_prev(NULL);
  nodo->set_next(NULL);
  return nodo;
}

// E/S
template <class T>
std::ostream &dll_t<T>::write(std::ostream &os) const
{
  dll_node_t<T> *aux = head_;

  while (aux != NULL)
  {
    aux->write(os);
    std::cout << " | ";
    aux = aux->get_next();
  }
  return os;
}
////////////Problemas
template <class T>
void dll_t<T>::insert_after(dll_node_t<T> *prev, dll_node_t<T> *n)
{

  n->set_next(prev->get_next());
  prev->set_next(n);

  if (n->get_next() != NULL)
    n->get_next()->set_prev(n);
  else
    tail_ = n;
  sz_++;
}

template <class T>
void dll_t<T>::swap_last(void)
{
  push_back(erase(tail_->get_prev()));
}

template <class T>
void dll_t<T>::duplicate(void)
{
  dll_node_t<T> *aux = get_head();
  dll_node_t<T> *end = get_tail();
  while (aux->get_prev() != end)
  {
    push_back(new dll_node_t<T>(aux->get_data()));
    aux = aux->get_next();
  }
}

template <class T>
void dll_t<T>::erase_odds(void)
{
  dll_node_t<T> *aux = get_head();

  while (aux != NULL)
  {
    dll_node_t<T> *next = aux->get_next();
    delete erase(aux);
    aux = next != NULL ? next->get_next() : NULL;
  }
}

template <class T>
dll_t<T> dll_t<T>::erase_evens(void)
{
  dll_t<T> list_evens;
  dll_node_t<T> *aux = get_head();
 

  while ((aux != NULL) && (aux->get_next() != NULL))
  {
    list_evens.push_back(erase(aux->get_next()));
    aux = aux->get_next();
  }

  return list_evens;
}

template <class T>
void dll_t<T>::shift_back(dll_node_t<T> *n)
{

  n->get_prev()->set_next(n->get_next());
  if (n == tail_)
    tail_ = n->get_prev();
  else
    n->get_next()->set_prev(n->get_prev());

  n->set_next(n->get_prev());
  n->set_prev(n->get_prev()->get_prev());
  if (n->get_next() == head_)
    head_ = n;
  else
    n->get_prev()->set_next(n);
}

template <class T>
dll_node_t<T> *dll_t<T>::search(const T &d) const
{
  dll_node_t<T> *aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();

  return aux;
}

template <class T>
void dll_t<T>::write_odds()
{

  dll_node_t<T> *aux = get_head();
  dll_t<int> auxlist;
  while (aux != NULL)
  {
    if(aux->get_data() % 2 != 0)
    auxlist.push_front(new dll_node_t<int>(aux->get_data()));
    aux = aux->get_next();
  }
    auxlist.write();

  // Utilizamos una extructura auxiliar

  // dll_node_t<T> *aux = get_head();
  // stack_v_t<int> stack;

  // while (aux != NULL)
  // {
  //   if (aux->get_data() % 2 != 0)
  //     stack.push(aux->get_data());
  //   aux = aux->get_next();
  // }
  // while (!stack.empty())
  // {
  //   std::cout << stack.top() << " | ";
  //   stack.pop();
  // }
  // std::cout << std::endl;

}

#endif // DLLT_H_
