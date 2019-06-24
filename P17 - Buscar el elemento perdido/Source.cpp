// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector <int>;
// función que resuelve el problema
// Tiene un coste nlog(n), 2T(n/2) + c
// (Dos llamadas, el vector se divide por la mitad)

int resolver(vector v1, vector v2, int ini, int fin) {
	int piv = (ini + fin) / 2;

	if (v1.size() == 1
		&& v2.size() == 0)
		return v1[fin];
	else if (ini >= fin)
		return v1[fin];
	else if (ini + 1 == fin)
		if (v1[fin] == v2[ini])
			return v1[ini];
		else
			return v1[fin];
	else if (v1[piv] == v2[piv - 1])	//Esta a la izq
		return resolver(v1, v2, ini, piv - 1);
	else	//Esta a la der
		return resolver(v1, v2, piv, fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	vector v1(tam);
	vector v2(tam - 1);

	for (int i = 0; i < tam; i++)
	{
		std::cin >> v1[i];
	}

	for (int i = 0; i < tam - 1; i++)
	{
		std::cin >> v2[i];
	}


	// escribir sol
	std::cout << resolver(v1, v2, 0, tam - 1) << std::endl;

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