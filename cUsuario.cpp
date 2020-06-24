#include "cUsuario.h"
cUsuario::cUsuario(eCliente tipo, string nombre, string apellido, string username, string pais, string contrasenia) :cPersona( nombre,  apellido,  username,  pais,  contrasenia) {
	this->tipo = tipo;
}