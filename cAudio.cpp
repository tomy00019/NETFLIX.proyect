#include "cAudio.h"
int cAudio::cantAudios = 0;

cAudio::cAudio(int tiempoDeUso, string nombre, eAudio categoria, int duracion) : cServicio(tiempoDeUso, nombre) {
	bool existe = (categoria >= podcast && categoria <= audioLibro);
	if (!existe) {
		throw new exception("NO ES UNA CATEGORIA CORRECTA");
	}

	this->categoria = categoria;
	this->duracion = duracion;
	codigo = 'A' + cantAudios;
	cantAudios++;
}

void cAudio::record()
{
	cout << "El audio se ha grabado correctamente" << endl;          //Grabo la pelicula
}
void cAudio::fastFoward()
{
	int i = 0;
	cout << "Adelantando audio presione el numero '9' cuando desees parar" << endl;     //Hago un while infito para hacer una mejor simulacion de que se esta adelantando el audio
	while (i != 9)
	{
		cin >> i;
	}
}

void cAudio::backFoward()
{
	int i = 0;
	cout << "Retrocediendo audio presione el numero '9' cuando desees parar" << endl;    //Hago un while infito para hacer una mejor simulacion de que se esta retrocediendo el audio
	while (i != 9)
	{
		cin >> i;
	}
}

void cAudio::Imprimir() //Imprimo datos del audio
{
	cout << "nombre: "<< nombre <<'\t' << "categoria:  " << categoria << '\t' << "duracion: " << duracion << endl;
}