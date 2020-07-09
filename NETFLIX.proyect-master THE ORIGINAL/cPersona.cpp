#include "cPersona.h"
int cPersona::cantPersonas = 0;
cPersona::cPersona(string nombre, string apellido, string pais, string contrasenia): id(to_string(cantPersonas)) {
	this->nombre = nombre;
	this->apellido = apellido;
	this->username = nombre+'_'+apellido;
	this->pais = pais;
	this->contrasenia = contrasenia;
	online = false; //inicialmente el constructor los settea a falso, al iniciar sesion se transforma en true
	cantPersonas++;
}