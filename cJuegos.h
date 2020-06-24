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
public:
	cJuegos(int tiempoDeUso, string nombre,eJuegos categoria=autos);
	void guardar();
	void Comandos();
	

	eJuegos getTipo() { return categoria; }
	
	void Imprimir();
	virtual string to_String() { return cServicio::to_String() + '\t' + to_string(categoria); }

	~cJuegos() { cantJuegos--; }
};

