// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector <int>;

int buscarPequeno(vector const& v, int ini, int fin)
{
	int piv = (ini + fin) / 2;

	if (ini >= fin)
		return v[fin];
	else if (ini + 1 == fin)	//Potencia de 2, caso base
		if (v[ini] <= v[fin])	//Devolver el más grande
			return v[ini];
		else
			return -1;
	else
	{
		int izqPequeno = buscarPequeno(v, ini, piv);	//Recursividad más pequeno izq
		int derPequeno = buscarPequeno(v, piv + 1, fin);

		if (izqPequeno <= derPequeno)	//Comparar los más pequenos de cada lado
			return izqPequeno;
		else
			return -1;
	}
}

int buscarGrande(vector const& v, int ini, int fin)
{
	int piv = (ini + fin) / 2;

	if (ini >= fin)
		return v[fin];
	else if (ini + 1 == fin)
		if (v[ini] <= v[fin])
			return v[ini];
		else
			return -1;
	else
	{
		int izqGrande = buscarGrande(v, ini, piv);
		int derGrande = buscarGrande(v, piv + 1, fin);

		if (derGrande >= izqGrande)
			return derGrande;
		else
			return -1;
	}
}

// función que resuelve el problema
bool resolver(vector const& v, int ini, int fin) {
	int piv = (ini + fin) / 2;

	int izqPequeno = buscarPequeno(v, ini, piv);
	int izqGrande = buscarGrande(v, ini, piv);
	int derPequeno = buscarPequeno(v, piv + 1, fin);
	int derGrande = buscarGrande(v, piv + 1, fin);
	return izqPequeno != -1	//Ha cumplido la parcialidad
		&& izqGrande != -1	// "
		&& derPequeno != -1	// "
		&& derGrande != -1	// "
		&& derGrande >= izqGrande
		&& izqPequeno <= derPequeno;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int i = 0;
	int n;
	vector v;

	std::cin >> n;
	while (n != 0)
	{
		v.push_back(n);
		std::cin >> n;
		i++;
	}

	if (i == 0)
		return false;

	if (resolver(v, 0, v.size() - 1))	//Número de más, y 0
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