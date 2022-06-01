
#include <iostream>
#include "bitset_t.hpp"

using namespace std;
using namespace AED;

int main(void)
{
	cout << "|U|= " << SIZE_U << endl;

	bitset_t A;
	A.insert(1);
	A.insert(5);
	A.insert(9);
	A.insert(25);

	cout << "A: " << A << endl;
	cout << "A.first_item: " << A.first_item() << endl;
	cout << "A.last_item: " << A.last_item() << endl;

	bitset_t B;
	B.insert(A);
	B.insert(31);
	B.insert(21);
	B.remove(9);

	cout << "B: " << B << endl;
	cout << "B.first_item: " << B.first_item() << endl;
	cout << "B.last_item: " << B.last_item() << endl;

	bitset_t C;
	A.set_union(B, C);
	cout << "C = A U B" << endl
		 << "C: " << C << endl;

	A.set_intersec(B, C);
	cout << "C = A ∩ B" << endl
		 << "C: " << C << endl;

	A.set_minus(B, C);
	cout << "C = A \\ B" << endl
		 << "C: " << C << endl;

	A.set_dif(B, C);
	cout << "C = A △ B" << endl
		 << "C: " << C << endl;

	
	bitset_t D;
	cout << "\n--------------------------" << endl;
	cout << "D: " << D << endl;
	cout << "Conjunto Universal de D: " << endl;
	D.universal();
	cout << D << endl;
	cout << "Complemento de D: " << endl;
	D.complement();
	cout << D << endl;

	cout << "Calculamos NAND entre A y B, y lo almacenamos en D " << endl;
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	A.set_nand(B,D);
	cout << "Resultado: " << endl;
	cout << "D: " << D << endl;

	D.complement();
	cout << "Complemento D: " << D << endl;
	cout << "Calculamos el valor medio de los elementos del conjunto D:  " << D.mean() << endl;
	cout << "Calculamos el producto cartesiano entre A y B:  " << endl;
	A.prod_cart(B);
	return 0;
}
