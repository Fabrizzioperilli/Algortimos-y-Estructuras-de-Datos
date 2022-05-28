#include "queue_v_t.h"
#include "queue_l_t.h"

int main(void)
{
	queue_v_t<char> cola_vector;
	cout << "Insertamos elementos en la cola de vector..." << endl;

	for (int i = 0; i < 10; i++)
	{
		cola_vector.push('a' + i);
		cout << cola_vector;
	}

	cout << endl;
	cout << "Vaciamos la cola..." << endl;

	while (!cola_vector.empty())
	{
		cola_vector.pop();
		cout << cola_vector;
	}

	queue_l_t<char> cola_lista;

	cout << "Insertamos elementos en la cola de lista..." << endl;
	for (int i = 0; i < 10; i++)
		cola_lista.push('a' + i);
	cout << cola_lista;

	cout << "back_: " << cola_lista.back() << endl;
	cout << "front_: " << cola_lista.front() << endl;
	cout << endl;

	cout << "Invertimos la cola..." << endl;
	cola_lista.reverse();
	cout << cola_lista;

	cout << "back_: " << cola_lista.back() << endl;
	cout << "front_: " << cola_lista.front() << endl;
	cout << endl;

	cout << "Separamos los elementos de la cola con las posiciones pares e impares" << endl;
	cola_lista.split();
	cola_lista.empty() ? (cout << "La cola principal está vacía" << endl) : (cout << "La cola principal no está vacía" << endl);

	queue_l_t<int> queueInt;
	
	cout << "\nCreamos una cola de valores enteros y la rellenamos..." << endl;
	for (size_t i = 0; i < 6; i++)
		queueInt.push(rand() % 5);
	cout << queueInt << endl;

	cout << "Eliminamos los elementos repetidos..." << endl;
	queueInt.remove_repeat();
	cout << queueInt << endl;
	return 0;
}
