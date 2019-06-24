// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using vector = std::vector <int>;
// función que resuelve el problema
void resolver(vector const& v, int const MAX) {

	for (int i = 0; i < MAX; i++)
		if (v[i] < v[i + 1]		//Menor
			&& v[i + 1] % 2 == 0	//Par
			&& v[i + 1] > 0)		//Mayor que 0
			std::cout << v[i + 1] << " ";

	std::cout << std::endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int tamVect;
	std::cin >> tamVect;

	vector v(tamVect + 1, 0);

	for (int i = 1; i < tamVect + 1; i++)
		std::cin >> v[i];


	resolver(v, tamVect);
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