// AUTOR: FABRIZZIO PERILLI MARTIN
// FECHA: 26/04/2022
// EMAIL: alu0101138589@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
//

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h> // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;          // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode; // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t>
{
public:
  // constructores
  SllPolynomial(void) : sll_t(){};
  SllPolynomial(const vector_t<double> &, const double = EPS);

  // destructor
  ~SllPolynomial(){};

  // E/S
  void Write(std::ostream & = std::cout) const;

  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial &, const double = EPS) const;
  void Sum(const SllPolynomial &, SllPolynomial &, const double = EPS);
  void SumSec(void);


};

bool IsNotZero(const double val, const double eps = EPS)
{
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double> &v, const double eps)
{

  for (int i = v.get_size() - 1; i >= 0; i--)
    if (IsNotZero(v.at(i), eps))
    {
      pair_double_t pair(v.get_val(i), i);
      SllPolyNode *aux = new SllPolyNode(pair);
      push_front(aux);
    }
}

// E/S
void SllPolynomial::Write(std::ostream &os) const
{
  os << "[ ";
  bool first{true};
  SllPolyNode *aux{get_head()};
  while (aux != NULL)
  {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x"
                                        : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const SllPolynomial &p)
{
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const
{
  double result{0.0};
  SllPolyNode *aux = get_head();

  while (aux != NULL)
  {
    double value = aux->get_data().get_val();
    int index = aux->get_data().get_inx();
    result += value * pow(x, index);
    aux = aux->get_next();
  }

  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial &sllpol,
                            const double eps) const
{
  bool differents = false;

  SllPolyNode *aux = get_head();
  SllPolyNode *aux2 = sllpol.get_head();

  while ((aux != NULL) && (aux2 != NULL))
  {
    if ((aux->get_data().get_val() - aux2->get_data().get_val()) >= eps)
      differents = true;

    aux = aux->get_next();
    aux2 = aux2->get_next();
  }

  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial &sllpol,
                        SllPolynomial &sllpolsum,
                        const double eps)
{
  SllPolynomial auxSllPolSum;
  SllPolyNode *aux = get_head();
  SllPolyNode *aux2 = sllpol.get_head();
  pair_double_t pair;
  double sum = 0.0;

  while (aux != NULL || aux2 != NULL) {
    if (aux != NULL && aux2 != NULL) {
      if (aux->get_data().get_inx() == aux2->get_data().get_inx()) {
        sum = aux->get_data().get_val() + aux2->get_data().get_val();
        if (IsNotZero(sum, eps)) {
          pair.set(sum, aux->get_data().get_inx());
          auxSllPolSum.push_front(new SllPolyNode (pair));
        }
        if (aux != NULL)
          aux = aux->get_next();
        if (aux2 != NULL)
          aux2 = aux2->get_next();

      } else if (aux->get_data().get_inx() > aux2->get_data().get_inx()) {
        sum = aux2->get_data().get_val();
        if (IsNotZero(sum, eps)) {
          pair.set(sum, aux2->get_data().get_inx());
          auxSllPolSum.push_front(new SllPolyNode (pair));
        }
        if (aux2 != NULL)
          aux2 = aux2->get_next();
      } else {
        sum = aux->get_data().get_val();
        if (IsNotZero(sum, eps)) {
          pair.set(sum, aux->get_data().get_inx());
          auxSllPolSum.push_front(new SllPolyNode (pair));
        }

        if (aux != NULL)
          aux = aux->get_next();
      }

    } else if (aux == NULL) {
      sum = aux2->get_data().get_val();
      if (IsNotZero(sum, eps)) {
        pair.set(sum, aux2->get_data().get_inx());
        auxSllPolSum.push_front(new SllPolyNode (pair));
      }
      if (aux2 != NULL)
        aux2 = aux2->get_next();

    } else if (aux2 == NULL) {
      sum = aux->get_data().get_val();
      if (IsNotZero(sum, eps)) {
        pair.set(sum, aux2->get_data().get_inx());
        auxSllPolSum.push_front(new SllPolyNode (pair));
      }

      if (aux != NULL)
        aux = aux->get_next();
    }
  }

  while (!auxSllPolSum.empty()) {
    sllpolsum.push_front(auxSllPolSum.pop_front());
  }
}

void SllPolynomial::SumSec(void){
  SllPolyNode *aux = get_head();
  SllPolyNode *aux2 = get_head()->get_next();
  double sum = 0.0;

    while (aux != NULL && aux2 != NULL)
    {
      if ((aux->get_data().get_inx() + 1) == (aux2->get_data().get_inx())) { 
       sum = aux->get_data().get_val() + aux2->get_data().get_val();  
      std::cout << sum << ", ";
      }
      aux = aux->get_next();
      aux2 = aux2->get_next();
    }
}

#endif // SLLPOLYNOMIAL_H_
