// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector <int> const& v, int ini, int fin) {

	int piv = (ini + fin) / 2; //Divide y vencerás, coste de orden logarítmico

	if (ini >= fin)				//No puede recorrer más
		return v[fin];
	else if (fin - ini == 1)	//2 elementos
		if (v[ini] < v[fin])
			return v[ini];
		else
			return v[fin];
	else if (v[piv] < v[piv + 1])	//Si el numero siguiente consecutivo es mayor
		return resolver(v, ini, piv);	
	else
		return resolver(v, piv, fin);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::vector <int> v;
	int nCasos;
	std::cin >> nCasos;

	if (!std::cin)
		return false;

	for (int i = 0; i < nCasos; i++)
	{
		v.push_back(1);
		std::cin >> v[i];
	}



	std::cout << resolver(v, 0, nCasos - 1) << std::endl;		//Vector, y tamaño (inicial y final)
																//Binaria recursiva para Curva cóncava

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