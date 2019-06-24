// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector <int> const& v, int ini, int fin) {
	int piv = (ini + fin) / 2;
	
	if (v[piv] % 2 == 1)
		return v[piv];
	else if (fin - ini == 1)	//2 elementos y piv = ini, e ini no es impar
		return v[fin];
	else
		if (v[0] + (piv * 2) == v[piv]
			&& v[piv] %2 == 0)		//El numero inicial + la posicion * 2,
			return resolver(v, piv + 1, fin);	// debería coincidir con el valor del pivote
		else									//si este no se ha movido
			return resolver(v, ini, piv - 1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos;
	std::cin >> nCasos;

	
	if (nCasos == 0)
		return false;

	std::vector <int> v(nCasos);

	for (int i = 0; i < nCasos; i++)
		std::cin >> v[i];


	// escribir sol
	std::cout << resolver(v, 0, nCasos - 1) << std::endl;

	
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