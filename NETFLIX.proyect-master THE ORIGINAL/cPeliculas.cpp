#include "cPeliculas.h"
int cPeliculas::cantPeliculas = 0;

cPeliculas::cPeliculas(int duracion, string nombre, ePeliculas categoria, string estudio, vector<string> PaisesProhibidos) 
		:codigo("P" + to_string(cantPeliculas)),
			cServicio(duracion, nombre, PaisesProhibidos){
	bool existePelicula = (categoria >= accion && categoria <= amor);
	if(!existePelicula)
	{
		throw new exception("NO ES UNA CATEGORIA CORRECTA");
	}
	this->categoria = categoria;
	this->estudio = estudio;
	cantPeliculas++;
}

void cPeliculas::record()
{
	cout << "La pelicula se ha grabado correctamente" <<endl;       //Grabo la pelicula
}
void cPeliculas::fastFoward()
{
	int i = 0;
	cout << "Adelantando pelicula presione la el numero '9' cuando desees parar" << endl;       //Hago un while infito para hacer una mejor simulacion de que se esta adelantando la pelicula
	while(i!=9)
	{
		cin >> i;
	}
}

void cPeliculas::backFoward()
{
	int i = 0;
	cout << "Retrocediendo pelicula presione el numero '9' cuando desees parar" << endl;       //Hago un while infito para hacer una mejor simulacion de que se esta retrocediendo la pelicula
	while (i != 9)
	{
		cin >> i;
	}
}

void cPeliculas::Imprimir() //Imprimo datos de la pelicula
{
	cServicio::Imprimir();
	cout << '\t' << codigo << '\t' << "Estudio: " << estudio << endl;
}