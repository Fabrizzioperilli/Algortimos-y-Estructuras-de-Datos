#pragma once
#include <iostream>

using namespace std;


// char  	  		1 byte		1 byte = 8 bits
// bool       		1 byte
// int 	      		4 bytes
// float      		4 bytes
// short int  		2 bytes
// double	  		8 bytes
// long double	  	8 bytes
// long int 		8 bytes

typedef long int block_t;

// |U|: cardinalidad del conjunto universal U
#define SIZE_U (8 * sizeof(block_t))

namespace AED
{

	class bitset_t
	{
	public:
		// constructor, constructor de copia y destructor
		bitset_t(void);
		bitset_t(const bitset_t &);
		~bitset_t(void);

		// insertar o eliminar un elemento
		void insert(const int);
		void remove(const int);

		// inserta o elimina al conjunto del objeto elementos de un conjunto
		// pasado por parámetro
		void insert(const bitset_t &);
		void remove(const bitset_t &);

		// permite saber si un elemento o un conjunto de elementos están contenidos
		// en el conjunto del objeto
		bool contains(const int) const;
		bool contains(const bitset_t &) const;

		// elimina todos los elementos del conjunto
		void clear(void);

		// operaciones sobre conjuntos
		void set_intersec(const bitset_t &, bitset_t &) const;
		void set_union(const bitset_t &, bitset_t &) const;
		void set_minus(const bitset_t &, bitset_t &) const;
		void set_dif(const bitset_t &, bitset_t &) const;
		int cardinality(void) const;

		// devuelve el primer y último elemento del conjunto
		int first_item(void) const;
		int last_item(void) const;

		// muestra el conjunto por pantalla
		void write(ostream & = cout) const;

		//////Problemas
		void universal(void); // El conjunto universal tiene todos los bits a 1
		void complement(void); // Complemento de un conjunto
		void set_nand(bitset_t& bs, bitset_t& result); // NAND
		float mean(void); // calcula el valor medio de los elementos de un conjunto
		void prod_cart(const bitset_t&) const; // producto cartesiano entre dos conjuntos
		//////

	private:
		block_t block_;
	};

	ostream &operator<<(ostream &, const bitset_t &);

}
