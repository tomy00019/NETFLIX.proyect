#include "cPersona.h"
int cPersona::cantPersonas = 0;
cPersona::cPersona(string nombre, string apellido, string username, string pais, string contrasenia) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->username = username;
	this->pais = pais;
	this->contrasenia = contrasenia;
	id = cantPersonas;
	cantPersonas++;
}