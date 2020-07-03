#pragma once  
#include <iostream>
#include <string>
#include "cServicio.h";
using namespace std;

enum ePeliculas { accion, aventura, comedia, terror, misterio, documental, amor };

class cPeliculas: public cServicio
{
	static int cantPeliculas;
	ePeliculas categoria;
	string codigo;
public:
	cPeliculas(int duracion=0, string nombre="", ePeliculas categoria=accion);
	void record();
	void fastFoward();
	void backFoward();
	string getCodigo() { return codigo; }

	ePeliculas getTipo() { return categoria; }

	void Imprimir();
	virtual string to_String() { return cServicio::to_String()+'\t'+to_string(categoria); }

	~cPeliculas() { cantPeliculas--; }
};

