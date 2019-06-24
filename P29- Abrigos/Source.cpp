// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector<int>;

//Coste de orden N
bool esValida(vector const& vSol, int const& diaActual, vector const& vUsos,
	vector const& vAbrigos, vector const& vPrecip)
{
	if (diaActual > 0)
		if(vSol[diaActual] == vSol[diaActual - 1])				//Si no se repiten
			return false;
	if (vUsos[vSol[diaActual]] > ((diaActual) / 3) + 2)			//Condicion impuesta
		return false;
	if (vAbrigos[vSol[diaActual]] < vPrecip[diaActual])			//Si aguanta la lluvia
		return false;

	return true;
}


bool esSolucion(int const& ABRIGO_ACTUAL, int const& DIAS, vector const& vSol)
{
	if (ABRIGO_ACTUAL == DIAS - 1)
		if (vSol[0] != vSol[ABRIGO_ACTUAL])		//Si el primer y ultimo dia son distintos
			return true;

	return false;
}
/*
void tratarSolucion(int const& ABRIGO_ACTUAL, int const& DIAS, vector const& vSol, int & nSol)
{
	
	for (int i = 0; i < DIAS; i++)
		std::cout << vSol[i] << " ";

	std::cout << std::endl;
	
	nSol++;
}
*/

// función que resuelve el problema
void resolver(vector &vSol, int diaActual, int & nSoluc, vector &vUsos,
	vector const& vAbrigos, vector const& vPrecip, int const& DIAS, int const& ABRIGOS) {
	for (int i = 0; i < ABRIGOS; i++) {
		vSol[diaActual] = i;		//Se asigna el abrigo actual
		vUsos[i]++;				//Se suma 1 al abrigo usado

		if (esValida(vSol, diaActual, vUsos, vAbrigos, vPrecip)) {
			if (esSolucion(diaActual, DIAS, vSol))
				nSoluc++;
			else
				if (diaActual + 1 < DIAS) {
					resolver(vSol, diaActual + 1, nSoluc, vUsos,
						vAbrigos, vPrecip, DIAS, ABRIGOS);
				}
		}
				
		vUsos[i]--;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int nDias, nAbrigos;
	std::cin >> nDias >> nAbrigos;
	if (nDias == 0)
		return false;

	vector vPrecipitaciones(nDias);
	for (int i = 0; i < nDias; i++)
		std::cin >> vPrecipitaciones[i];

	vector vAbrigos(nAbrigos);
	for (int i = 0; i < nAbrigos; i++)
		std::cin >> vAbrigos[i];

	vector vSol(nDias);
	int nSoluciones = 0;

	vector vUsos(nAbrigos, 0);

	// escribir sol

	resolver(vSol, 0, nSoluciones, vUsos,
		vAbrigos, vPrecipitaciones, nDias, nAbrigos);	//0 == nActual

	if(nSoluciones > 0)
		std::cout << nSoluciones << std::endl;
	else
		std::cout << "Lo puedes comprar" << std::endl;


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