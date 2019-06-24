// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int invertido(int numero, int pot) {
	if (numero <= 9)
		return numero * pot;
	else
	{
		int i = invertido(numero / 10, pot / 10);
		int nActual = numero % 10;
		return nActual * pot + i;
	}

}


int complementario(int numero, int &pot) {
	if (numero <= 9)
		return 9 - numero;
	else
	{
		int c = complementario(numero / 10, pot);
		pot *= 10;
		int nActual = 9 - (numero % 10);
		return  c * 10 + nActual;
	}
		

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numero, pot = 1;
	std::cin >> numero;
	int c = complementario(numero, pot);
	int i = invertido(c, pot);

	// escribir sol
	std::cout << c << " "
		<< i << std::endl;

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