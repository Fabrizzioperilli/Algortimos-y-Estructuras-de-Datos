
#include "bitset_t.hpp"
#include "../Stack/stack_l_t.h"

namespace AED {

// constructor
bitset_t::bitset_t(void):
block_(0)
{}



// constructor de copia
bitset_t::bitset_t(const bitset_t& bs)
{
  block_ = bs.block_;
}



// destructor
bitset_t::~bitset_t(void)
{}



// insertar elemento
void
bitset_t::insert(const int i)
{
  block_t uno = 0x1;
  block_ |= (uno << (i - 1));
}


// insertar un conjunto completo
void
bitset_t::insert(const bitset_t& bs)
{
  block_ |= bs.block_;
}



// eliminar un elemento
void
bitset_t::remove(const int i)
{
  block_t uno = 0x1;
  uno <<= (i - 1);
  block_ &= ~uno;
}



// eliminar un conjunto completo
void
bitset_t::remove(const bitset_t& bs)
{
  block_ &= ~bs.block_;
}



// pertenencia
bool
bitset_t::contains(const int i) const
{
  block_t uno = 0x1;
  uno <<= (i - 1);
  return (block_ & uno) != 0;  
}



// igualdad de conjuntos
bool
bitset_t::contains(const bitset_t& bs) const
{
  return (block_ & bs.block_) == bs.block_;
}



// eliminación del conjunto
void
bitset_t::clear(void)
{
  block_ = 0;
}



// intersección de conjuntos
void
bitset_t::set_intersec(const bitset_t& bs, bitset_t& result) const
{
  result.block_ = block_ & bs.block_;
}



// union de conjuntos
void
bitset_t::set_union(const bitset_t& bs, bitset_t& result) const
{
  result.block_ = block_ | bs.block_;
}



// diferencia de conjuntos
void
bitset_t::set_minus(const bitset_t& bs, bitset_t& result) const
{
  result.block_ = block_ & ~bs.block_;
}



// diferencia simétrica de conjuntos
void
bitset_t::set_dif(const bitset_t& bs, bitset_t& result) const
{
  result.block_ = (block_ | bs.block_) & ~(block_ & bs.block_);
}



// cardinalidad
inline int
bitset_t::cardinality(void) const
{
  return __builtin_popcount(block_);
}



// primer elemento del conjunto
int
bitset_t::first_item(void) const
{
  return __builtin_ffsl(block_);
}



// último elemento del conjunto
int
bitset_t::last_item(void) const
{
  return SIZE_U - __builtin_clzl(block_);
}



// muestra conjunto por pantalla
void
bitset_t::write(std::ostream& os) const
{
  stack_l_t<char> s;
  
  for (int i = 1; i <= SIZE_U; ++i)
  {
    if (contains(i)) s.push('1');
    else             s.push('0');
  }
  
  char aux[SIZE_U + 1];
  int i = 0;
  while (!s.empty())
  {
    aux[i++] = s.top();
    s.pop();
  }
  
  aux[SIZE_U] = '\0';
  os << aux;
}



ostream&
operator<<(ostream& os, const bitset_t& bs)
{
  bs.write(os);
  return os;
}


void
bitset_t::universal(void){
  block_ = ~0;
}

void
bitset_t::complement(void){
  block_ = ~block_;
}

void 
bitset_t::set_nand(bitset_t& bs, bitset_t& result){
  
  set_intersec(bs,result);
  result.complement();
  
  // result.block_ = ~(block_ & bs.block_); 
}

float
bitset_t::mean(void){
  
  int suma = 0, count = 0;
  for (size_t i = 0; i < SIZE_U; i++)
    if (contains(i)){
    suma += i;
    count++;
    }
  
  return (suma / count);
}

void
bitset_t::prod_cart(const bitset_t& bs) const {
  for (int i = 1; i <= SIZE_U; i++)
    if (contains(i))
      for (int j = 1; j <= SIZE_U; j++)
        if (bs.contains(j)) {
          cout << '(' << i << ',' << j << "),";
        }
  cout << "\b \b\n";  // Delete last comma
}




} // namespace
