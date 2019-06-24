// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


/*
	method problema3 ( a : array <int > , p : int) returns ( b : bool )
	requires a != null && a . Length > 0
	requires 0 <= p < a . Length
	ensures b == forall u , w :: 0 <= u <= p < w < a . Length == > a [ u ] < a [ w ]
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector<int>;
// función que resuelve el problema
//Coste lineal, ya que recorre el array una unica vez -> O(N)
bool resolver(vector const& v, int const& p) {
	int izq = -1, der = -1;

	for (int i = 0; i <= p; i++)
		if (v[i] > izq
			|| izq == -1)		//Guarda el mayor elemento de la izquierda
			izq = v[i];
	
	for (int i = p + 1; i < v.size(); i++)
		if (v[i] < der
			|| der == -1)	//Guarda el menor elemento de la derecha
			der = v[i];

	return izq < der	//Si el elemento mas grande de la izquierda es menor al elemento mas pequeno de la derecha
		|| izq != -1	//Si ha guardado un elemento a la izq
		&& der == -1;	//y no ha guardado ningun elemento a la derecha -> p == v.size() -> No hay mas elementos
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nElem, p;
	std::cin >> nElem >> p;

	vector v(nElem);
	for (int i = 0; i < nElem; i++)
		std::cin >> v[i];

	if (p >= 0 && nElem > 0
		&& resolver(v, p))
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;

	// escribir sol


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}