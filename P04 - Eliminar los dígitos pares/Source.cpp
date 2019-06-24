// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>

using ulli = unsigned long long int;

// función que resuelve el problema
ulli fRecursiva(ulli numero)
{
	ulli definitivo = 0;
	if (numero > 9)	//Más de 1 dígito
		if ((numero % 10) % 2 == 1) //impar
		{
			definitivo += numero % 10;	//El numero con todos los impares más el último digito (Que es impar)
			return definitivo += fRecursiva(numero / 10) * 10;	//El numero con todos los impares más la función recursiva
		}
		else	//Par
			return fRecursiva(numero / 10);	//No se suma nada al definitivo
	else if (numero % 2 == 1)	//último digito es impar
		return numero;
	else
		return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	ulli datos;
	std::cin >> datos;

	if (!std::cin)
		return false;

	// escribir sol
	std::cout << fRecursiva(datos) << std::endl;

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
