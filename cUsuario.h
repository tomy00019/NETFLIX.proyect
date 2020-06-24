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
	cUsuario(eCliente tipo, string nombre, string apellido, string username, string pais, string contrasenia);
	string to_String() { return to_StringPadre() + '\t' + to_string(tipo); }
	eCliente getTipo() { return tipo; }
	void Imprimir() { std::cout << to_String()<<endl; }
	~cUsuario() {};
};

