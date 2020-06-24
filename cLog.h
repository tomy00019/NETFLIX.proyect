#pragma once
#include <iostream>
#include <string>
using namespace std;

class cLog
{
	int usuario; //ID DEL USUARIO
	string servicio; //CODIGO DEL SERVICIO
	int timestamp;
public:
	cLog(int usuario, string servicio, int timestamp) {
		this->usuario = usuario;
		this->servicio = servicio;
		this->timestamp = timestamp;
	};
	string getServicio() {
		return servicio;
	}
	int getUsuario() {
		return usuario;
	}
	int getTimestap() {
		return timestamp;
	}

	~cLog() {};

};

