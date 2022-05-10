// AUTOR: FABRIZZIO DANIEELL PERILLI MARTIN   
// FECHA: 10/05/2022  
// EMAIL: alu0101138589@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  const int result = stack_.top();
  stack_.pop();

  return result;
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c' );

  int aux[2], result;
  
    for (int i = 0; i <= 1; i++)
      if (!stack_.empty()){
        aux[i] = stack_.top();
        stack_.pop();
        std::cout << "   Sacamos de la pila un operando: " << aux[i] << std::endl;
      }
      
switch (c) {
    case '+':
            result = aux[1] + aux [0];
      break;
    case '-': 
	          result = aux[1] - aux[0];
			break;
	  case '*': 
	          result = aux[1] * aux[0];
			break;
	  case '/': 
	          result = aux[1] / aux[0];
			break;
	  case '^': 
	          result = pow(aux[1], aux[0]);
			break;
	  case 'c': 
	          result = pow(aux[0], 2);
			break;
	  case 'r': 
	          result = sqrt(aux[0]);
			break;
	  case 'l': 
	          result = log2(aux[0]);
			break;
	  
	  default: std::cout << std::endl << "Elemento (" << c << ") no identificado." << std::endl;
  }
  stack_.push(result);
  std::cout << "   Metemos en la pila el resultado: " << result <<  std::endl;
}
 
#endif  // RPNT_H_
