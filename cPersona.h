#pragma once
#include <string>
using namespace std;
class cPersona
{
protected:
	string nombre;
	string apellido;
	string username;
	string pais;
	string contrasenia;
	long long id;
	static int cantPersonas;
	bool online;
public:
	cPersona(string nombre, string apellido, string username, string pais, string contrasenia);
	string getNombre() { return nombre; }
	bool getOnline() { return online;  }

	bool compararContrasenia(string contrasenia) {
		if (this->contrasenia==contrasenia){
			return true;
		}
		return false;
	}
	string to_StringPadre(){
		return nombre+ '\t' +apellido+ '\t' +username+ '\t' +pais+ '\t' +contrasenia+ '\t';
	}
	~cPersona() { cantPersonas--; }
};

