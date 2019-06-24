// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>

//Añadida
#include <string>

// n (0 ≤ N ≤ 2^31 − 1).
using uli = unsigned long int;

// función que resuelve el problema
std::string recBin(int const& n)
{
	std::string binario;
	int numero = n % 2;

	if (n == 0) return binario += "0";
	else if (n == 1) return binario += "1";
	else return binario = recBin(n / 2) + char('0' + numero);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	uli n;

	std::cin >> n;
	std::cout << recBin(n) << std::endl;

	recBin(n);


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