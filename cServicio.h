#pragma once
#include <string>
#include <iostream>

using namespace std;
class cServicio
{
protected:
	int tiempoDeUso;
	string nombre;
	static int cantContenido;
	//string Pais;
public:
	cServicio(int tiempoDeUso=0, string nombre="");
	void descargar();
	void iniciar();
	void pausar();
	void apagar();
	string getNombre() { return nombre; }
	static int getCantContenido(){ return cantContenido; }
	virtual string to_String()const{ return nombre + '\t' + to_string(tiempoDeUso); }
	virtual void Imprimir();
	~cServicio() { cantContenido--; };

};

