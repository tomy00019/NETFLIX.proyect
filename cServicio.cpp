#include "cServicio.h"
int cServicio::cantContenido = 0;

cServicio::cServicio(int duracion, string nombre)
{ 
	this->duracion = duracion; 
	this->nombre = nombre; 
	cantContenido++;
}

void cServicio::descargar()
{
	cout << "Se ha descargado con exito" << endl;
}
 
void cServicio::iniciar()
{
	cout << "Se ha iniciado con exito" << endl;
	for (int i = 0;i < duracion;i++)//se realizaran tantos loop como su duracion
	{								//caso que simule la interaccion 
									//se preguntara en cada loop si se desea pausar 
									//o salir u alguna otra accion

	}
}

void cServicio::pausar()
{
	int i = 0;
	cout << "presione el numero '9' para reanudar" << endl;
	while (i != 9)
	{     //Hago un while infinito para realizar una simulacion mejor de que esta pausado
		cin >> i;
	}
	cout << "Se ha reanudado" << endl;
}

void cServicio::Imprimir(){
	cout << "Nombre: " << nombre << "    " <<"Tiempo de Uso"<<to_string(duracion) << endl;
}

void cServicio::apagar()
{
	cout << "Apagado" << endl;     //Apago 
}

