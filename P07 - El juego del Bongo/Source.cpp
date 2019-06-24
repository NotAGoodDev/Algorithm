// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector <int> const& v, int nCantado, int ini, int fin) {
	int piv = (ini + fin) / 2;
	int nTotal = nCantado + piv;	//Posición + numero cantado

	if (nTotal == v[piv])	//Lo ha encontrado
		return nTotal;
	else if (fin - ini <= 0)	//Último elemento
		if (nTotal == v[piv])	//Existe
			return nTotal;
		else
			return -1;			//No lo ha encontrado
	else if (nTotal > v[piv])	//El nCantado es superior
		return resolver(v, nCantado, piv + 1, fin);
	else
		return resolver(v, nCantado, ini, piv - 1);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos 5de la entrada
	int tamVector, nCantado, nDevuelto;

	std::cin >> tamVector >> nCantado;
	std::vector <int> v (tamVector);

	for (int i = 0; i < v.size(); i++)
		std::cin >> v[i];

	// escribir sol
	nDevuelto = resolver(v, nCantado, 0, tamVector - 1);
	if (nDevuelto > -1)
		std::cout << nDevuelto << std::endl;
	else
		std::cout << "NO" << std::endl;

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