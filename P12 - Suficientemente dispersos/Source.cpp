// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector <int>;

// función que resuelve el problema

//!! Me he fijado en el ejercicio resuelto del Campus
bool resolver(vector const& v, int ini, int fin, int K) {
	if (ini == fin)
		return true;

	else if (ini + 1 == fin)
		return K <= std::abs(v[fin] - v[ini]);

	else {
		int piv = (ini + fin) / 2;
		bool izq = resolver(v, ini, piv - 1, K);
		bool der = resolver(v, piv + 1, fin, K);
		return izq && der && K <= std::abs(v[ini] - v[fin]);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos, K;
	std::cin >> nCasos >> K;

	if (!std::cin)
		return false;

	vector v(nCasos);		//Using vector = ...

	for (int i = 0; i < nCasos; i++)
		std::cin >> v[i];

	// escribir sol
	if (resolver(v, 0, nCasos - 1, K))
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}