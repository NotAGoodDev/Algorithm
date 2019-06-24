// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>

// función que resuelve el problema
bool estaBalanceado(int &peso) {
	int pIzq, dIzq, pDer, dDer;
	std::cin >> pIzq >> dIzq >> pDer >> dDer;

	bool bIzq = true, bDer = true;

	if (pIzq == 0)
		bIzq = estaBalanceado(pIzq);
	if (pDer == 0)
		bDer = estaBalanceado(pDer);


	if (bIzq && bDer
		&& ((pIzq * dIzq) == (pDer * dDer))) {
		peso = pDer + pIzq;
		return true;
	}
	else
		return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int peso;

	// escribir sol
	if (estaBalanceado(peso))
		std::cout << "SI" << std::endl;
	else 
		std::cout << "NO" << std::endl;
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