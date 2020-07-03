#pragma once
#include <string>
#include <iostream>
#include "cPersona.h";
using namespace std;

enum eCliente { gratis, basico, premium };

class cUsuario: public cPersona
{
	eCliente tipo;

public:
	cUsuario(eCliente tipo, string nombre, string apellido, string pais, string contrasenia);
	virtual string to_String() { return to_String() + '\t' + to_string(tipo); }
	eCliente getTipo() { return tipo; }
	virtual void Imprimir() { std::cout << to_String()<<endl; }
	~cUsuario() {};
};

