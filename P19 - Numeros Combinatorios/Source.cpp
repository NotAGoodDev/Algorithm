// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using matriz = std::vector<std::vector<int>>;

// función que resuelve el problema
int resolver(int n, int m, matriz & matriz) {
	if (m == 0
		|| m == n)
		return matriz[n][m] = 1;
	else if (m == 1
		|| m == n - 1)
		return matriz[n][m] = n;
	else {
		if (matriz[n - 1][m - 1] == -1)
			matriz[n - 1][m - 1] = resolver(n - 1, m - 1, matriz);
		if (matriz[n - 1][m] == -1)
			matriz[n - 1][m] = resolver(n - 1, m, matriz);
		return matriz[n][m] = matriz[n - 1][m - 1] + matriz[n - 1][m];
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	std::cin >> a >> b;

	if (!std::cin)
		return false;

	matriz m(a + 1, std::vector<int>(b + 1));
	for (int i = 0; i < a + 1; i++)
	{
		for (int j = 0; j < b + 1; j++)
		{
			m[i][j] = -1;
		}
	}

	std::cout << resolver(a, b, m) << std::endl;

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