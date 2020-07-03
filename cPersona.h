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
	int id;
	static int cantPersonas;
	bool online;
public:
	cPersona(string nombre, string apellido,  string pais, string contrasenia);
	string getNombre() { return username; }
	bool getOnline() { return online;  }

	bool compararContrasenia(string contrasenia) {
		if (this->contrasenia==contrasenia){
			return true;
		}
		return false;
	}
	virtual string to_String(){
		return nombre+ '\t' +apellido+ '\t' +username+ '\t' +pais+ '\t' +contrasenia+ '\t';
	}
	virtual void Imprimir() {};
	int getID() { return id; }
	~cPersona() { cantPersonas--; }
};

