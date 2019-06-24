// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector<int>;
// función que resuelve el problema
//2 llamadas, partimos el vector por la mitad,
//comparamos pares -> 2T(n/2) + c -> nlog n
int resolver(vector v, int ini, int fin) {
	int piv = (ini + fin) / 2;
	if (ini == fin)
		return 0;
	else if (ini + 1 == fin)
		if (v[ini] % 2 == 0	//Los dos son pares
			&& v[fin] % 2 == 0)
			return 2;
		else if (v[ini] % 2 == 0	//Uno es par
			|| v[fin] % 2 == 0)
			return 1;
		else
			return 0;
	else
	{
		int paresIzq = 0;
		int paresDer = 0;

		paresIzq += resolver(v, ini, piv);
		paresDer += resolver(v, piv + 1, fin);
		if (abs(paresIzq - paresDer) < 3
			&& paresDer != -1
			&& paresIzq != -1)
			return paresIzq + paresDer;
		else
			return -1;
	}
		
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos;
	std::cin >> nCasos;

	if (nCasos == 0)
		return false;

	vector v(nCasos);

	for (int i = 0; i < nCasos; i++)
		std::cin >> v[i];

	if (resolver(v, 0, nCasos - 1) != -1)
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;
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