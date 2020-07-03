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
	int getNombre() {
		return usuario;
	}
	int getTimestap() {
		return timestamp;
	}
	/*bool operator == (int clave)    //DAMI, la sobrecargaa la que te referias era asi?
	{
		return ;
	}
	//sobrecargar el == , la lista es verdaderamente template 
	//y no requiere que tenga un método que se llame como pide la lista,
	//si sobrecargas el == con lo que sea el tipo de la clave(En este caso
	//debería ser int si la clave es el user o string si es servicio(O tal vez ambas ?
	//Podés darle doble parámetro al buscar si te gusta o si sabés / querés hacerlo)*/
	~cLog() {};

};
