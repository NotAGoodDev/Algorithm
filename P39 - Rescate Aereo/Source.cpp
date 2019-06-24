// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector<int>;
struct tSol
{
	int ini;
	int fin;

	tSol(int i, int f) { ini = i; fin = f; }
};

std::ostream& operator<< (std::ostream &out, tSol &s)
{
	out << s.ini << " " << s.fin << std::endl;
	return out;
}

// función que resuelve el problema
tSol resolver(vector const& v, int const& N, int const& T) {
	tSol sol(-1, -1);	//Sobrecarga
	int ini = 0;	//El fin lo llevamos con la i

	for (int i = 0; i < N; i++)
	{
		if(v[i] > T)	//Si el edificio > transporte
		{
			if (i - ini > sol.fin - sol.ini 	//Si la secuencia es mayor (Si son iguales se queda con la de la izquierda)
				|| sol.ini == -1 && sol.fin == -1)		//Si no esta inicializada						
			{
				sol.ini = ini;
				sol.fin = i;
			}
		}
		else
			ini = i + 1;	//Adelantamos a la siguiente posicion de la i
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, t;
	std::cin >> n >> t;

	vector v(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}


	tSol sol = resolver(v, n, t);
	// escribir sol
	std::cout << sol;	//Sobrecarga

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