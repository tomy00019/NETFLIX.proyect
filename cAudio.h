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
	cAudio(int tiempoDeUso, string nombre, eAudio categoria=cancion, int duracion=0);
	void record();
	void fastFoward();
	void backFoward();
	eAudio getTipo() { return categoria; }
	

	void Imprimir();
	virtual string to_String() { return cServicio::to_String()+'\t' + to_string(categoria); }
	~cAudio() { cantAudios--; };


};

