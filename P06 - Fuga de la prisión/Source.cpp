// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
char resolver(std::vector <char> const& v, char letraInicial, char letraFinal, int posIni, int posFin) {

	int piv = (posIni + posFin) / 2;
	char letraCorrecta = letraInicial + piv;	//Comparar con v[i]
	
	if (posIni >= posFin)
		if (v[posIni] == letraInicial)
			return char(letraInicial + 1);
		else if (letraInicial - v[piv] == -1)	//Valor antes que el array
			return letraInicial;
		else if (v[piv] + 1 == letraFinal)
			return letraFinal;
		else return letraCorrecta;
	else if (letraCorrecta == v[piv])	//El pivote no está desplazado
		if (v[piv] + 1 != v[piv + 1])
			return v[piv] + 1;
		else
			return resolver(v, letraInicial, letraFinal, piv + 1, posFin);
	else //El pivote está desplazado
		return resolver(v, letraInicial, letraFinal, posIni, piv);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::vector <char> v;
	char ini, fin;
	int nCasos;

	std::cin >> ini >> fin;
	nCasos = int(fin - ini);
	for (int i = 0; i < nCasos; i++)
	{
		v.push_back(1);
		std::cin >> v[i];
	}
		
	// escribir sol
	std::cout << resolver(v, ini, fin, 0, nCasos - 1) << std::endl;


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