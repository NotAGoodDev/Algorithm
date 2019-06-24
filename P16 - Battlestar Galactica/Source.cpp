// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using vector = std::vector <int>;

// función que resuelve el problema
int resolver(vector &v, int ini, int fin) {		//Organiza en orden creciente las dos partes
	int piv = (ini + fin) / 2;

	if (ini >= fin)	//1 elemento
		return 0;
	else if(ini + 1 == fin)		//2 elementos
	{
		if (v[ini] < v[fin])	//Están ordenados
			return 0;
		else
		{
			std::swap(v[ini], v[fin]);
			return 1;
		}
	}

	int contador = 0;
	int iniIzq = ini;		//Por claridad
	int finIzq = piv;		// "
	int iniDer = piv + 1;	// "
	int finDer = fin;		// "

	contador += resolver(v, ini, piv);
	contador += resolver(v, piv + 1, fin);

	while (iniIzq <= finIzq
		&& iniDer <= finDer)
		if (v[iniIzq] < v[iniDer])
			iniIzq++;
		else
		{
			contador += (finIzq - iniIzq + 1);	//Se restan todas las posiciones que tiene que recorrer a la izquierda
			iniDer++;								//Y además se añade una, ya que se pone delante primer elemento de la izquierda
		}
	
		//NO FUNCIONA
	/*
	std::vector <int> &aux(v);
	std::merge(v.begin() + iniIzq, v.begin() + finIzq, v.begin() + finIzq, v.begin() + finDer, aux.begin());
	*/

	std::sort(v.begin() + ini, v.begin() + fin + 1);	//Desde el inicio hasta el final (El final es excluyente, por eso el +1)
	return contador;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos;
	std::cin >> nCasos;

	if (!std::cin)
		return false;

	vector v(nCasos);

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