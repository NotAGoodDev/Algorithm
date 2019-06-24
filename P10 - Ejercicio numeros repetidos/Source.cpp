// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int buscarFinRepet(std::vector <int> const& v, int ini, int fin)
{
	int piv = (ini + fin) / 2;

	if (ini >= fin)
		return fin;
	else if (v[ini] != v[piv])
		return buscarFinRepet(v, ini, piv);
	else if (v[piv] != v[piv + 1])
		return piv + 1;
	else
		return buscarFinRepet(v, piv + 1, fin);



}

int resolver(std::vector <int> const& v, int ini, int fin) {
	int contador = 0;
	int piv = (ini + fin) / 2;

	if (ini >= fin || v[ini] == v[fin])		//Solo hay un numero o está repetido
		return contador += 1;
	else if (fin - ini == 1)	//Hay dos numeros
		if (v[ini] != v[fin])
			return contador += 2;	//Distintos
		else
			return contador += 1;	//Único número
	else if (v[ini] == v[piv])	//Los números terminan en el pivote
		if(v[piv] != v[piv + 1])
			return contador = 1 + resolver(v, piv + 1, fin);
		else
			return contador = 1 + resolver(v, buscarFinRepet(v, piv, fin), fin);
	else
		return contador = 1 + resolver(v, buscarFinRepet(v, ini, piv), fin);
		

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

	std::cout << resolver(v, 0, nCasos - 1) << std::endl;
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