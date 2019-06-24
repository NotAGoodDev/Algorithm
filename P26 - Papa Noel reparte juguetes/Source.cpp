// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using vector = std::vector <int>;
using vectorStr = std::vector <std::string>;
using matriz = std::vector <vector>;
// función que resuelve el problema

bool udsNegativas(int const& udsJuguete)
{
	return udsJuguete < 0;
}

bool cumpleGradoSatisfaccion(matriz const& mSatisf, vector& vJugDeNinios, int const& jActual, int const& SATISF_MIN)
{
	bool dosJuguetes = jActual % 2 == 1;	//Si estamos en el juguete impar, quiere decir que tenemos un juguete anterior
	int ninio = jActual / 2;				// Al ser 2 juguetes por ninio, dividimos entre 2, para saber que ninio es
											// 2/0 = 0		2/1 = 0		2/2 = 1...
	if(dosJuguetes)
		return (mSatisf[ninio][vJugDeNinios[jActual]] + mSatisf[ninio][vJugDeNinios[jActual - 1]]) >= SATISF_MIN;	//La suma de satisfaccion los dos juguetes es la minima deseada
	return true;		//Suponemos que con el otro juguete, la satisfacción será >= que la minima
}

bool juguetesDistintos(vectorStr const& vId, vector & vJugDeNinios, int const& jActual)
{
	bool dosJuguetes = jActual % 2 == 1;	//Si estamos en el juguete impar, quiere decir que tenemos un juguete anterior
	
	if (dosJuguetes)
	{
		bool distintoTipo = vId[vJugDeNinios[jActual]] != vId[vJugDeNinios[jActual - 1]];	//Comparamos los tipos
		if (distintoTipo)
			return vJugDeNinios[jActual] != vJugDeNinios[jActual - 1]		//Si se repite el juguete anterior
			&& vJugDeNinios[jActual - 1] < vJugDeNinios[jActual];	//Y que el juguete anterior sea menor en satisfaccion
		else
			return false;
	}

	return true; //Suponemos que solo hay 1 juguete y el siguiente será distinto
}

bool esValida(vectorStr const& vId, vector const& vUdsDisponibles, matriz const& mSatisf,
	int const& SATISF_MIN, vector& vJugDeNinios, int actual, int const& posJuguete)
{
	return !udsNegativas(vUdsDisponibles[posJuguete])
		&& cumpleGradoSatisfaccion(mSatisf, vJugDeNinios, actual, SATISF_MIN)
		&& juguetesDistintos(vId, vJugDeNinios, actual);
}

bool esSolucion(int const& ACTUAL, int const& N_NINIOS)
{
	return ACTUAL == (N_NINIOS * 2) - 1;
}

void tratarSolucion(vector& vJugDeNinios, int const& N_NINIOS)
{
	int i = 0;
	for (int i = 0; i < (N_NINIOS * 2); i++)
		std::cout << vJugDeNinios[i] << " ";
	std::cout << std::endl;
}

void resolver(vectorStr const& vId, vector vUdsDisponibles, matriz const& mSatisf, int const& N_JUGUETES,
	int const& N_NINIOS, int const& SATISF_MIN, vector& vJugDeNinios, int actual, bool &solucion) {
	for (int i = 0; i < N_JUGUETES; i++)
	{
		vJugDeNinios[actual] = i;	
		vUdsDisponibles[i]--;

		if (esValida(vId, vUdsDisponibles, mSatisf, SATISF_MIN, vJugDeNinios, actual, i))
		{
			if (esSolucion(actual, N_NINIOS))
			{
				tratarSolucion(vJugDeNinios, N_NINIOS);
				solucion = true;
			}
			else
				resolver(vId, vUdsDisponibles, mSatisf, N_JUGUETES, N_NINIOS, SATISF_MIN,
					vJugDeNinios, actual + 1, solucion);
		}
		vJugDeNinios[actual] = -1;
		vUdsDisponibles[i]++;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string foo;
	bool existeSolucion = false;
	int nJuguetes, nNinios, satisfMin, actual;

	std::cin >> nJuguetes >> nNinios >> satisfMin;
	if (!std::cin)
		return false;

	vector vUdsDisponibles(nJuguetes);
	vectorStr vId(nJuguetes);
	matriz m(nNinios, vector(nJuguetes));

	for (int i = 0; i < nJuguetes; i++)
		std::cin >> vUdsDisponibles[i];

	for (int i = 0; i < nJuguetes; i++)		//No necesario
		std::cin >> vId[i];

	for (int i = 0; i < nNinios; i++)
		for (int j = 0; j < nJuguetes; j++)
			std::cin >> m[i][j];

	vector vJugDeNinios(2 * nNinios, - 1);
	resolver(vId, vUdsDisponibles, m, nJuguetes, nNinios, satisfMin, vJugDeNinios, 0, existeSolucion); // 0 = actual

	if (!existeSolucion)
		std::cout << "SIN SOLUCION" << std::endl;

	std::cout << std::endl;

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