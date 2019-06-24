// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
//La función es recursiva, su coste es logarítmico,
int resolver(std::vector <int> const& v, int ini, int fin) {
	int piv = (ini + fin) / 2;		

	if (ini == fin)		//1 Elemento
		return v[piv];
	else if (fin - ini == 1)	//2 Elementos
		if (v[ini] < v[fin])
 			return v[ini];
		else
			return v[fin];
	else
		if (v[ini] > v[piv])
			return resolver(v, piv, fin);
		else
			return resolver(v, ini, piv);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos;
	std::cin >> nCasos;
	
	if (!std::cin)
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