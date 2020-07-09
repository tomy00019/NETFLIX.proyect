#pragma once
#include <iostream>
#include <string>
#include "cPersona.h"
#include "cBaseDatos.h"
using namespace std;

class cPersona;
class cBaseDatos;
class cLog
{
	string usuario; //ID DEL USUARIO
	string servicio; //CODIGO DEL SERVICIO 
	long long timestamp; //esta en segundos
	string logCode;
	static int cantidad;
public:
	cLog(string usuario, string servicio, long long timestamp) {
		this->usuario = usuario;
		this->servicio = servicio;
		this->timestamp = timestamp;
		logCode = usuario + servicio[0] + to_string(cantidad);
		cantidad++;
	};
	string getServicio() {
		return servicio;
	}
	string getNombre() {
		return logCode;
	}
	string getNombreUsuario();
	int getTimestap() {
		return timestamp;
	}
	void Imprimir() { cout << "  "<<logCode <<"       "<<usuario << "	    " << servicio << "	    " << timestamp << endl; }

	~cLog() {};

};
