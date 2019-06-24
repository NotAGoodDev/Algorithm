// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

// función que resuelve el problema
using vector = std::vector <bool>;

struct tJuego
{
	int partidos;
	vector v;
	vector sigV;
};

void resolver(tJuego &j, int ini, int fin) {

	int piv = (ini + fin) / 2;

	if (ini + 1 == fin)	//2 elementos (potencia de dos)
		if (j.v[ini]			//Ambos se han presentado
			&& j.v[fin])
		{
			j.sigV.push_back(true);
			j.partidos++;		//n partidos + 1
		}
		else if (j.v[ini]		//Solo se ha presentado un jugador
			|| j.v[fin])
			j.sigV.push_back(true);
		else					//No se ha presentado nadie
			j.sigV.push_back(false);

	else
	{
		resolver(j, ini, piv);	//Partidos izq
		resolver(j, piv + 1, fin); //Partidos der
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nCasos, partidos;
	std::cin >> nCasos >> partidos;
	if (!std::cin)
		return false;
	tJuego juego;
	juego.v = vector(nCasos);
	juego.sigV = vector(0);
	juego.partidos = 0;

	for (int i = 0; i < nCasos; i++)
	{
		std::string nombre;
		std::cin >> nombre;
		if (nombre != "NP")
			juego.v[i] = true;
	}
	for (int i = 0; i < partidos; i++)
	{
		resolver(juego, 0, nCasos - 1);
		juego.v = juego.sigV;
		juego.sigV = vector(0);
		nCasos /= 2;
	}

	std::cout << juego.partidos << std::endl;
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