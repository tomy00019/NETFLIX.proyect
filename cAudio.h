#pragma once  
#include <iostream>
#include <string>
#include <iomanip>
#include "cServicio.h";
using namespace std;

enum eAudio { podcast, cancion, audioLibro };
class cAudio: public cServicio
{
	eAudio categoria;
	int duracion;
	static int cantAudios;
	string codigo;
public:
	cAudio(int duracion, string nombre, eAudio categoria=cancion);
	void record();
	void fastFoward();
	void backFoward();
	eAudio getTipo() { return categoria; }
	string getCodigo() { return codigo; }
	

	void Imprimir();
	virtual string to_String() { return cServicio::to_String()+'\t' + to_string(categoria); }
	~cAudio() { cantAudios--; };


};

