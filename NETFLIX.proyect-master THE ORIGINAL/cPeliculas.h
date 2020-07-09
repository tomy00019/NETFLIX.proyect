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
	const string codigo;
	string estudio;
public:
	cPeliculas(int duracion = 0, string nombre = "", ePeliculas categoria = accion, string estudio = "", vector<string> PaisesProhibidos = {});
	void record();
	void fastFoward();
	void backFoward();
	virtual string getCodigo() { return codigo; }

	ePeliculas getTipo() { return categoria; }

	void Imprimir();
	virtual string to_String() { return cServicio::to_String()+'\t'+to_string(categoria); }

	~cPeliculas() { }
};

