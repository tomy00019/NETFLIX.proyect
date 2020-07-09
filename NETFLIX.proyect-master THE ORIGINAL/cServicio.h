#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
class cServicio
{
protected:
	int duracion;
	string nombre;
	static int cantContenido;
	vector<string> PaisesProhibidos;
public:
	cServicio(int duracion = 0, string nombre = "", vector<string> PaisesProhibidos = {});
	void descargar();
	void iniciar();
	void pausar();
	void apagar();
	vector<string> getPaisesProhibidos() { return PaisesProhibidos; }
	string getNombre() { return nombre; }
	static int getCantContenido(){ return cantContenido; }
	virtual string to_String()const{ return nombre + '\t' + to_string(duracion); }
	virtual void Imprimir();
	virtual string getCodigo() { return ""; }
	~cServicio() { cantContenido--; }

};

