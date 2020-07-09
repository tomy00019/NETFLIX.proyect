#include "cAudio.h"
int cAudio::cantAudios = 0;

cAudio::cAudio(int duracion, string nombre, string artista, eAudio categoria, vector<string> PaisesProhibidos) 
		: codigo("A" + to_string(cantAudios)),
			cServicio(duracion, nombre, PaisesProhibidos){
	bool existe = (categoria >= podcast && categoria <= audioLibro);
	if (!existe) {
		throw new exception("NO ES UNA CATEGORIA CORRECTA");
	}
	this->artista = artista;
	this->categoria = categoria;
	this->duracion = duracion;
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
	cServicio::Imprimir();
	cout << '\t' << codigo << '\t'<<"Artista: "<< artista<< endl;
}