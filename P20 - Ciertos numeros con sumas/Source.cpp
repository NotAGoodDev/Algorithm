// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
using vector = std::vector <int>;
using matriz = std::vector <std::vector <int>>;

int resolver(matriz &m, vector const& v, int const N, int fin) {		// N = Numero que se busca
	if (N == 0)
		return m[0][fin] = 1;
	else if (fin == 0 && N > 0)
		return m[N][0] = 0;
	else if (N > 0 && fin > 0)
	{
		if (m[N][fin - 1] == -1)	m[N][fin - 1] = resolver(m, v, N, fin - 1);

		if (N - v[fin] >= 0)
		{
			if (m[N - v[fin]][fin - 1] == -1)
				m[N - v[fin]][fin - 1] = resolver(m, v, N - v[fin], fin - 1);

			return m[N][fin - 1] + m[N - v[fin]][fin - 1];
		}
		else
			return m[N][fin - 1];
	}
	else return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, nBuscado;
	std::cin >> tam >> nBuscado;

	if (!std::cin)
		return false;

	vector v(tam + 1, 0);

	for (int i = 0; i < tam; i++)
		std::cin >> v[i + 1];

	matriz m(nBuscado + 1, std::vector <int>(tam + 1, -1));
	// escribir sol
	std::cout << resolver(m, v, nBuscado, tam) << std::endl;

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