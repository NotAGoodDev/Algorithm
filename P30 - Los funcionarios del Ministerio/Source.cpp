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
void resolver(vector &vSol, int funcActual, int &valorSolActual, int &valorMejorSolucion,
	vectorBool &vTrabajosAsign, matriz const& mFT, int const& N_FUNCIONARIOS, int const& N_TRABAJOS) {

	for (int i = 0; i < N_TRABAJOS; i++)
	{
		vSol[funcActual] = mFT[funcActual][i];	//Suponemos que, al funcionario actual, se le asigna el trabajo i
		valorSolActual += vSol[funcActual];		//Llevamos la suma 

		if (!vTrabajosAsign[i]					//Es valida
			&& valorMejorSolucion > valorSolActual)
		{
			vTrabajosAsign[i] = true;		//Ya se ha asignado el trabajo al funcionario, no se pueden repetir
			if (funcActual == N_FUNCIONARIOS - 1)	//Es solucion	
				valorMejorSolucion = valorSolActual;

			else
				resolver(vSol, funcActual + 1, valorSolActual, valorMejorSolucion, vTrabajosAsign, mFT, N_FUNCIONARIOS, N_TRABAJOS);
		
			vTrabajosAsign[i] = false;
		}

		valorSolActual -= vSol[funcActual];
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
	int valorMejorSolucion = 0;


	for (int i = 0; i < nFuncionarios; i++)
		for (int j = 0; j < nTrabajos; j++) {
			std::cin >> mFT[i][j];

			if (i == j)
				valorMejorSolucion += mFT[i][j];	//Diagonal
		}


	vector vSol(nFuncionarios);
	int funcActual = 0, valorSolActual = 0;

	resolver(vSol, funcActual, valorSolActual, valorMejorSolucion, vTrabajosAsign, mFT, nFuncionarios, nTrabajos);

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