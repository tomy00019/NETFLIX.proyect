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
	static int cantAudios;
	const string codigo;
	string artista;
public:
	cAudio(int duracion, string nombre, string artista, eAudio categoria = cancion, vector<string> PaisesProhibidos = {});
	void record();
	void fastFoward();
	void backFoward();
	eAudio getTipo() { return categoria; }
	virtual string getCodigo() { return codigo; }
	

	void Imprimir();
	virtual string to_String() { return cServicio::to_String()+'\t' + to_string(categoria); }
	~cAudio() { };


};

