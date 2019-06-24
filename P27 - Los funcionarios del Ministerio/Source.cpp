// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using vector = std::vector <int>;
using vectorBool = std::vector <bool>;
using matriz = std::vector<vector>;

// función que resuelve el problema

bool esValida(vectorBool const& vTrabajosAsign, int const& i)
{
	return !vTrabajosAsign[i];	//Si está asignado, devuelve false
}

bool esSolucion(int const& ACTUAL, int const& N_FUNCIONARIOS)
{
	return ACTUAL == N_FUNCIONARIOS - 1;	//Si se ha llegado al final
}

void compararSolucion(vector const& vSol, int &valorMejorSolucion, int const& N_FUNCIONARIOS)
{
	int solActual = 0;
	for (int i = 0; i < N_FUNCIONARIOS; i++)
		solActual += vSol[i];

	if (solActual < valorMejorSolucion)
		valorMejorSolucion = solActual;
}

void resolver(vector vSol, int funcActual, int &valorMejorSolucion, vectorBool vTrabajosAsign, matriz const& mFT, int const N_FUNCIONARIOS, int const N_TRABAJOS)
{
	for (int i = 0; i < N_TRABAJOS; i++)
	{
		vSol[funcActual] = mFT[funcActual][i];	//Suponemos que, al funcionario actual, se le asigna el trabajo i
		if (esValida(vTrabajosAsign, i))
		{
			vTrabajosAsign[i] = true;		//Ya se ha asignado el trabajo al funcionario, no se pueden repetir

			if (esSolucion(funcActual, N_FUNCIONARIOS))
				compararSolucion(vSol, valorMejorSolucion, N_FUNCIONARIOS);
			else
				resolver(vSol, funcActual + 1, valorMejorSolucion, vTrabajosAsign, mFT, N_FUNCIONARIOS, N_TRABAJOS);

			vTrabajosAsign[i] = false;		//Ya se ha asignado el trabajo al funcionario, no se pueden repetir
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nFuncionarios, nTrabajos;
	std::cin >> nFuncionarios;

	nTrabajos = nFuncionarios;	//Todos los funcionarios tienen un trabajo

	if (nFuncionarios == 0)
		return false;

	vectorBool vTrabajosAsign(nTrabajos, false);	//Que trabajos hecho asignado
	matriz mFT(nFuncionarios, vector(nTrabajos));	//Matriz de Funcionarios y Trabajos

	for (int i = 0; i < nFuncionarios; i++)
		for (int j = 0; j < nTrabajos; j++)
			std::cin >> mFT[i][j];

	vector vSol(nFuncionarios);
	int valorMejorSolucion = 10000 * nFuncionarios;	//Peor solucion, todos los trabajos de los funcionarios son de 10000
	int funcActual = 0;
	resolver(vSol, funcActual, valorMejorSolucion, vTrabajosAsign, mFT, nFuncionarios, nTrabajos);

	std::cout << valorMejorSolucion << std::endl;
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