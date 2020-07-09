#pragma once
#include <string>
#include <iostream>
#include "cPersona.h";
using namespace std;
class cAdministrador: public cPersona
{
public:
	cAdministrador(string nombre, string apellido, string pais, string contrasenia):cPersona(nombre, apellido, pais, contrasenia) {};
	virtual string to_String() { return to_String(); }
	virtual void Imprimir() { std::cout << to_String() << endl; }
	~cAdministrador() {};
};

