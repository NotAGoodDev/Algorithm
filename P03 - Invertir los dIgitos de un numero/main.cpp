// Nombre del alumno Álvaro David, Ortiz Marchut [2ºE]
// Usuario del Juez E38


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

struct sol
{
	lli numero;
	int pot;

	sol() { lli numero; int pot;}
	sol(lli n, int p) { numero = n; pot = p; }	//Sobrecarga
};

sol invertir(lli const& datos)
{
	sol digitos;

	if (datos  <= 9)
	{
		return sol(datos, 10);
	}
	else
	{
		digitos = invertir(datos / 10);		//Llama a la funcion
		return sol(((datos % 10) * digitos.pot) + digitos.numero, digitos.pot * 10);	//Digito unico[[[%10]]] * potencia + numero anterior
	}


}



bool resuelveCaso() {
	// leer los datos de la entrada
	lli datos;
	std::cin >> datos;
	if (!std::cin)
		return false;

	sol solucion = invertir(datos);

	// escribir sol
	std::cout << solucion.numero << std::endl;

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