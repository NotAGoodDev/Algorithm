// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector <int>;
struct tDatos
{
	int tam;
	vector v;
	
};
// función que resuelve el problema
//Coste lineal -> O(n)
	//Recorre todos los elementos del array una sola vez
int resolver(tDatos const& d) {
	int pos = -1;
	int cont0 = 0, cont1 = 0;
	for (int i = 0; i < d.tam; i++)
	{
		if (d.v[i] == 0)
			cont0++;
		else if (d.v[i] == 1)
			cont1++;

		if (cont0 == cont1)
			pos = i;
	}

	return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	std::cin >> d.tam;

	d.v.resize(d.tam);
	
	for (int &i : d.v)
		std::cin >> i;



	int sol = resolver(d);
	// escribir sol
	std::cout << sol << std::endl;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}