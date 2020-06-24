#pragma once  
#include <iostream>
#include <string>
#include "cServicio.h";
using namespace std;

enum ePeliculas { accion, aventura, comedia, terror, misterio, documental, amor };

class cPeliculas: public cServicio
{
	int duracion;
	static int cantPeliculas;
	ePeliculas categoria;
	string codigo;
public:
	cPeliculas(int tiempoDeUso, string nombre, ePeliculas categoria=accion, int duracion=0);
	void record();
	void fastFoward();
	void backFoward();

	ePeliculas getTipo() { return categoria; }

	void Imprimir();
	virtual string to_String() { return cServicio::to_String()+'\t'+to_string(categoria); }

	~cPeliculas() { cantPeliculas--; }
};

