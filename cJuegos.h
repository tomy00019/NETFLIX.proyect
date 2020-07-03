#pragma once 
#include <iostream>
#include <string>
#include "cServicio.h";
using namespace std; 

enum eJuegos { autos, armas, multijugador, ropa, deportes };

class cJuegos: public cServicio
{
private:
	eJuegos categoria;
	static int cantJuegos;
	string codigo;
public://duracion en juegos es una aproximacion de la media en que se tarda en completar el Modo aventura
	cJuegos(int duracion, string nombre,eJuegos categoria=autos);
	void guardar();
	void Comandos();
	

	eJuegos getTipo() { return categoria; }
	string getCodigo() { return codigo; }
	void Imprimir();
	virtual string to_String() { return cServicio::to_String() + '\t' + to_string(categoria); }

	~cJuegos() { cantJuegos--; }
};

