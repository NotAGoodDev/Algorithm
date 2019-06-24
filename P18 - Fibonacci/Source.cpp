// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;
// función que resuelve el problema

lli fib(lli n, lli n1, lli n2)
{
	if (n == 0)
		return n1;
	else
		return fib(n - 1, n1 + n2, n1);
}

lli resolver(lli n)
{
	if (n == 0)
		return 0;
	else
		return fib(n - 1, 1, 0);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada


	lli n;
	std::cin >> n;

	if (!std::cin)
		return false;

	std::cout << resolver(n) << std::endl;
	// escribir sol

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