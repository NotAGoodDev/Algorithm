// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector <int> const& v, int ini, int fin) {
	int piv = (ini + fin) / 2;

	if (ini >= fin)
		return v[fin];
	else if (ini + 1 == fin)
		if (v[ini] < v[fin])
			return v[ini] + v[fin];
		else
			return -1;
	else
	{
		int izq = resolver(v, ini, piv);
		int der = resolver(v, piv + 1, fin);

		if (izq != -1 && der != -1)
			if (izq < der)
				return izq + der;
			else
				return -1;
		else
			return -1;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int maxFilas, maxCols;

	std::cin >> maxFilas >> maxCols;


	if (!std::cin)
		return false;

	std::vector <std::vector <int>> matriz(maxFilas, std::vector <int>(maxCols)); //Matriz
	for (int i = 0; i < maxFilas; i++)		//Rellenar matriz con valores
		for (int j = 0; j < maxCols; j++)
			std::cin >> matriz[i][j];

	int filaCorrecta;		//Presuponemos que la fila tiene el degradado correcto
	int i = 0;				//Hacemos un esquema de búsqueda (Fila erronea, si existe)
	do
	{
		filaCorrecta = resolver(matriz[i], 0, maxCols - 1);
		i++;
	} while (i < maxFilas
		&& filaCorrecta != -1);


	if (filaCorrecta != -1)
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