// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
using vector = std::vector<int>;
using matriz = std::vector<vector>;

bool esValida(vector const& vProdRest, int const& superMActual, int const& prodActual, int const& costeSolActual,
	int const& mejorSol, vector const& vProdMasBaratos, int const& N_PROD)
{
	int solOptima = 0;
	for (int i = prodActual; i < N_PROD; i++)
		solOptima += vProdMasBaratos[i];
	
	return vProdRest[superMActual] > 0
		&&(costeSolActual + solOptima < mejorSol
		|| mejorSol == -1);
}

bool esSolucion(int const& prodActual, int const& N_PROD)
{
	return prodActual == N_PROD - 1;
}

void tratarSolucion(vector const& sol, int & mejorSol, int const& N_PROD)
{
	int precioTotal = 0;
	for (int i = 0; i < N_PROD; i++)
		precioTotal += sol[i];

	if (precioTotal < mejorSol || mejorSol == -1)
	{
		mejorSol = precioTotal;
		//std::cout << mejorSol << std::endl;
	}
}

void resolver(vector sol, int prodActual, int costeSolActual, int &mejorSol, vector const& vProdMasBaratos, vector vProdRest,
	matriz const& m, int const& N_SUPERM, int const& N_PROD)
{
	for (int i = 0; i < N_SUPERM; i++)
	{
		if (esValida(vProdRest, i, prodActual, costeSolActual, mejorSol, vProdMasBaratos, N_PROD))
		{
			sol[prodActual] = m[i][prodActual];
			costeSolActual += sol[prodActual];
			vProdRest[i]--;

			if (esSolucion(prodActual, N_PROD))
				tratarSolucion(sol, mejorSol, N_PROD);
			else
				resolver(sol, prodActual + 1, costeSolActual, mejorSol, vProdMasBaratos, vProdRest, m, N_SUPERM, N_PROD);

			costeSolActual -= sol[prodActual];
			vProdRest[i]++;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nSuperm, nProd;
	std::cin >> nSuperm >> nProd;


	matriz m(nSuperm, vector(nProd));
	vector vProdMasBaratos(nProd, - 1);	//Nos servirá para estimar

	for (int i = 0; i < nSuperm; i++)
	{
		for (int j = 0; j < nProd; j++)
		{
			std::cin >> m[i][j];
		}
	}

	for (int i = 0; i < nProd; i++)
		for (int j = 0; j < nSuperm; j++)
			if (vProdMasBaratos[i] > m[j][i]
				|| vProdMasBaratos[i] == -1)
				vProdMasBaratos[i] = m[j][i];

	vector sol(nProd, - 1);
	vector vProdRest(nSuperm, 3);	//Máximo 3 productos en cada super
	int prodActual = 0;
	int mejorSol = -1;
	resolver(sol, prodActual, 0, mejorSol, vProdMasBaratos, vProdRest, m, nSuperm, nProd);	//0 = costeSolActual

	if (mejorSol == -1)
		std::cout << "Sin solucion factible" << std::endl;
	else
		std::cout << mejorSol << std::endl;

	// escribir sol


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