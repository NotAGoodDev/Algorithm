// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolverDer(std::vector <int> const& v, long ini, long fin, int altCulpable) {
	int piv = (ini + fin) / 2;

	if (ini >= fin)	//1 elemento
		if (altCulpable == v[fin])	//Elemento encontrado
			return fin;
		else return -1;	//Elemento no encontado
	else if (ini + 1 == fin)	//2 elementos
		if (v[fin] == altCulpable)	//Coincide con el primero
			return fin;
		else if (v[ini] == altCulpable)	//Coincide con el segundo
			return ini;
		else return -1;	//Elemento no coincide
	else if (altCulpable == v[piv]	//El elemento buscado es más grande
			&& altCulpable == v[piv + 1])	//Y además el elemento anterior es igual
		return resolverDer(v, piv + 1, fin, altCulpable);
	else
		return resolverDer(v, ini, piv, altCulpable);
}


int resolverIzq(std::vector <int> const& v, long ini, long fin, int altCulpable) {
	int piv = (ini + fin) / 2;

	if (ini >= fin)	//1 elemento
		if (altCulpable == v[fin])	//Elemento encontrado
			return fin;
		else return -1;	//Elemento no encontado
	else if (ini + 1 == fin)	//2 elementos
		if (v[ini] == altCulpable)	//Coincide con el primero
			return ini;
		else if (v[fin] == altCulpable)	//Coincide con el segundo
			return fin;
		else return -1;	//Elemento no coincide
	else if (altCulpable < v[piv]	//El elemento buscado es más pequeño
		|| (altCulpable == v[piv]	//El elemento buscado coincide
		&& altCulpable == v[piv - 1]))	//Y además el elemento anterior es igual
		return resolverIzq(v, ini, piv - 1, altCulpable);
	else
		return resolverIzq(v, piv, fin, altCulpable);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long nCasos;
	int altCulpable, izq;

	std::cin >> nCasos >> altCulpable;

	if (!std::cin)
		return false;

	std::vector <int> v(nCasos);		//using vector = std::vector <int>;
	for (int i = 0; i < nCasos; i++)
		std::cin >> v[i];

	izq = resolverIzq(v, 0, nCasos - 1, altCulpable);
	if (izq >= 0)
	{
		int der = resolverDer(v, izq + 1, nCasos - 1, altCulpable);

		if (izq + 1 < nCasos	//Existen más casos a la derecha
			&& der >= 0)
			std::cout << izq << " " << der << std::endl;
		else
			std::cout << izq << std::endl;
	}
	else
		std::cout << "NO EXISTE" << std::endl;
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