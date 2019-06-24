// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

const int N_COLORES = 3;
using vectorInt = std::vector<int>;

// función que resuelve el problema

int piezasColocadas(int const MAX_PIEZAS, int const PIEZAS_DISP)	//Legibilidad
{
	return MAX_PIEZAS - PIEZAS_DISP;
}

bool esValida(vectorInt & vContador, vectorInt const& vTorre, int actual, int color, vectorInt vMAX_PIEZAS)
{
	if (vTorre[actual] == 2							// Ultima pieza verde
		&& vTorre[actual] == vTorre[actual - 1])	// Y la anterior tambien
		return false;
	else if (piezasColocadas(vMAX_PIEZAS[2], vContador[2]) >= piezasColocadas(vMAX_PIEZAS[0], vContador[0])			//Si hay más piezas verdes colocadas
		&& vTorre[actual] == 2)																						//Y el color que hemos colocado es verde
		return false;
	else if (vContador[color] == 0		//Si el contador de piezas ha llegado a 0
		&& vTorre[actual] == color)		//Y se quiere colocar el mismo color
		return false;
	else
		return true;		
}

bool esSolucion(int tamAct, int tamTotal, vectorInt const& vContador, vectorInt const& vTorre, vectorInt const& vMAX_PIEZAS)
{
	return tamAct == (tamTotal - 1)
		&& piezasColocadas(vMAX_PIEZAS[0], vContador[0]) + piezasColocadas(vMAX_PIEZAS[2], vContador[2]) < piezasColocadas(vMAX_PIEZAS[1], vContador[1]);
				// Si la suma de piezas verdes y azules colocadas es menor que las rojas
}

void tratarSolucion(vectorInt const& vTorre, int const& altura)
{
	for (int i = 0; i < altura; i++)
	{
		if (vTorre[i] == 0)
			std::cout << "azul ";	
		else if (vTorre[i] == 1)
			std::cout << "rojo ";
		else
			std::cout << "verde ";
	}

	std::cout << std::endl;
}

void resolver(vectorInt vContador, vectorInt &vTorre, int actual, int const altura, vectorInt const& vMAX_PIEZAS, bool &existe) {
	for (int color = 0; color < N_COLORES; color++)
	{
		vTorre[actual] = color;	//"Coloca" la pieza
		if (esValida(vContador, vTorre, actual, color, vMAX_PIEZAS)) {
			vContador[color]--;		//Le restamos 1 al color
			if (esSolucion(actual, vTorre.size(), vContador, vTorre, vMAX_PIEZAS))
			{
				if (!existe)	//No existía ninguna solucion
					existe = true;	//Ahora sí

				tratarSolucion(vTorre, altura);	//Pintar solucion
			}
			else
				if (actual < altura - 1)	//Para evitar exceso de llamadas
					resolver(vContador, vTorre, actual + 1, altura, vMAX_PIEZAS, existe);	//Llamada recursiva, siguiente nivel
				vContador[color]++;		//Dejamos de utilizar la pieza, y la 'devolvemos'
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int altura;
	std::cin >> altura;

	if (altura == 0)
		return false;

	vectorInt vPiezas(N_COLORES);	//nº piezas
	for (int i = 0; i < N_COLORES; i++)
		std::cin >> vPiezas[i];

	// Azul = 0
	// Rojo = 1
	// Verde = 2

	vectorInt vMAX_PIEZAS = vPiezas;	//cte, maximo de piezas, evitamos recorrer la torre entera
	vectorInt vTorre(altura);			//piezas que tiene la torre

	vTorre[0] = 1;	//La primera pieza es roja
	vPiezas[1]--;	//Restamos la pieza

	

	// escribir sol
	bool existe = false;	//Para saber si ha encontrado una solucion
	if(vPiezas[1] > 0)	//Al menos habia una roja
		resolver(vPiezas, vTorre, 1, altura, vMAX_PIEZAS, existe);

	if(!existe)	//No ha encontrado ninguna solucion
		std::cout << "SIN SOLUCION" << std::endl;

	std::cout << std::endl;	//Pretty print

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