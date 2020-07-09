#include "cUsuario.h"
cUsuario::cUsuario(eCliente tipo, string nombre, string apellido,  string pais, string contrasenia) :cPersona( nombre,  apellido,  pais,  contrasenia) {
	this->tipo = tipo;
}