#include "cJuegos.h"
int cJuegos::cantJuegos = 0;
//
cJuegos::cJuegos(int tiempoDeUso, string nombre, eJuegos categoria) :cServicio(tiempoDeUso, nombre)
{
	bool existeJuego = (categoria >= autos && categoria <= deportes);
	if(!existeJuego)
	{
		throw new exception("NO ES UNA CATEGORIA CORRECTA");
	}
	this->categoria = categoria;
	codigo = 'J' + cantJuegos;
	cantJuegos++;
}

void cJuegos::guardar()
{
	cout << "Se ha guardado con exito" << endl;       //Guardo el juego
}

void cJuegos::Imprimir() //Imprimo datos del juego
{
	cout << "nombre: "<< nombre <<'\t' << "categoria: "<< categoria << endl;
}

void cJuegos::Comandos()
{
	int opcion = 0;
	while (opcion != -1)            //Son comandos para realizar en el juego
	{
		cin >> opcion;
		if (opcion == 1) {
			cout << "agachado" << endl;
			continue;
		}
		else if (opcion == 2) {
			cout << "pararse" << endl;
			continue;
		}
		else if (opcion == 3) {
			cout << "disparar" << endl;
			continue;
		}
		else if (opcion == 4) {
			cout << "saltar" << endl;
			continue;
		}
		else if (opcion == 5) {
			cout << "adelantarse" << endl;
			continue;
		}
		else if (opcion == 6) {
			cout << "apuntar" << endl;
			continue;
		}
		else if (opcion == 7) {
			cout << "senialar" << endl;
			continue;
		}
		else {
			cout << "EL COMANDO INGRESADO ES ICORRECTO" << endl;
			continue;
		}
	}
}