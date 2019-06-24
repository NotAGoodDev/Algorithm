// Nombre del alumno Álvaro David Ortiz Marchut
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vector = std::vector<int>;

bool coloresSeguidos(vector const& vTira, int luzActual)
{
	if (luzActual > 1)	//Si hay mas de dos luces ( [0] [1] ... )
		return vTira[luzActual] == vTira[luzActual - 1]	//Si la luz actual es igual a la anterior
			&& vTira[luzActual] == vTira[luzActual - 2];	// e igual a la anterior
	else
		return false;	//Hay 2 luces o menos
}

bool unColorEsLaMitad(vector const& vTira, int const LUZ_ACTUAL, vector const& vContadorColores, int const COLORES)
{
	int sumaColoresOpuestos = 0;
	for (int i = 0; i < COLORES; i++) {
		if (vTira[LUZ_ACTUAL] != i)	//Si es distinto a la luz actual, suma el total de bombillas
			sumaColoresOpuestos += vContadorColores[i];
	}


	return (vContadorColores[vTira[LUZ_ACTUAL]]) > sumaColoresOpuestos + 1;
}

bool superaLimiteConsumo(int const CONSUMO_ACTUAL, int const CONSUMO_MAX)
{
	return CONSUMO_ACTUAL > CONSUMO_MAX;
}

bool esValida(vector const& vTira, int const LUZ_ACTUAL, int const CONSUMO_ACTUAL, vector const& vContadorColores,
	int const COLORES, int const CONSUMO_MAX)
{
	return !coloresSeguidos(vTira, LUZ_ACTUAL)	//Legibilidad
		&& !unColorEsLaMitad(vTira, LUZ_ACTUAL, vContadorColores, COLORES)	//"
		&& !superaLimiteConsumo(CONSUMO_ACTUAL, CONSUMO_MAX);	//"
}

bool esSolucion(int const LUZ_ACTUAL, int const& LONG_TIRA)
{
	return LUZ_ACTUAL == LONG_TIRA;		//Si se ha llegado al limite
}

void tratarSolucion(vector & vTira, int &nSoluciones, int const& LONG_TIRA)
{
	/*
	for (int i = 0; i <= LONG_TIRA; i++)
		std::cout << vTira[i] << " ";
	std::cout << std::endl;
	*/
	nSoluciones++;
}
// función que resuelve el problema
void resolver(vector vTira, int luzActual, vector vConsumo, int consumoActual, vector vContadorColores, int const LONG_TIRA,
	int const COLORES, int const CONSUMO_MAX, int & nSoluciones)
{
	for (int color = 0; color < COLORES; color++)
	{
		vTira[luzActual] = color;		//Suponemos el color actual
		consumoActual += vConsumo[color];	//Suponemos el consumo
		vContadorColores[color]++;	//Sumamos 1 al contador del color actual
		if (esValida(vTira, luzActual, consumoActual, vContadorColores, COLORES, CONSUMO_MAX))
			if (esSolucion(luzActual, LONG_TIRA))
				tratarSolucion(vTira, nSoluciones, LONG_TIRA);
			else
				resolver(vTira, luzActual + 1, vConsumo, consumoActual, vContadorColores, LONG_TIRA, COLORES, CONSUMO_MAX, nSoluciones);
		
		consumoActual -= vConsumo[color];
		vContadorColores[color]--;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int longitud, colores, consumo;
	std::cin >> longitud >> colores >> consumo;

	if (!std::cin)
		return false;

	vector vConsumo(colores);
	for (int i = 0; i < colores; i++)
		std::cin >> vConsumo[i];

	vector vTira(longitud, -1);

	int nSoluciones = 0;

	for (int color = 0; color < colores; color++)	//Asigna la primera luz
	{
		vTira[0] = color;	//Primera luz de la tira
		int luzActual = 1;		//Tamaño de la tira
		int consumoTotal = vConsumo[color];	//Consumo de la tira
		vector vContadorColores(colores, 0);
		vContadorColores[color] = 1;
		resolver(vTira, luzActual, vConsumo, consumoTotal, vContadorColores, longitud - 1, colores, consumo, nSoluciones);
	}
	// vColor contiene el consumo de los colores
	// vTira es la tira
	// 1 es el tamaño actual

	std::cout << nSoluciones << std::endl;

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