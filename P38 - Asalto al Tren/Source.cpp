// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using vector = std::vector<int>;

//Devolver estructura
struct tSol
{
	int ini;
	int maxRobado;

	tSol(int i, int m) { ini = i; maxRobado = m; }
};

//Impresion rapida
std::ostream& operator<< (std::ostream &out, tSol &s)
{
	out << s.ini << " " << s.maxRobado << std::endl;
	return out;
}


// función que resuelve el problema
tSol resolver(vector const& v, int const N, int const MAX, int &ventana) {
	tSol sol(0, ventana);
	int i = MAX;	//Ya tenemos calculada la primera ventana, ponemos el puntero
	int robadoActual = ventana;
	while (i < N) {
		robadoActual += v[i] - v[i - MAX];
		if (robadoActual >= sol.maxRobado)
		{
			sol.ini = i - MAX + 1;
			sol.maxRobado = robadoActual;
		}

		i++;
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n, max, ventana;
	std::cin >> n >> max;

	vector v(n);
	ventana = 0;	//Parametro que pasaremos calculado
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];	//Dato vector

		if (i < max)	//Primera ventana, para evitar calcularla despues
			ventana += v[i];		
	}

	tSol sol = resolver(v, n, max, ventana);	//Ya que pasamos por referencia
											//la ventana, podriamos imprimirla
											//pero he preferido practicar sobrecarga y estructuras
	// escribir sol
	std::cout << sol;

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