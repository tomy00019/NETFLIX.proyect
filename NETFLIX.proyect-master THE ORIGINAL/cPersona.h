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
	const string id;
	static int cantPersonas;
	bool online;
public:
	cPersona(string nombre, string apellido,  string pais, string contrasenia);
	string getNombre() { return username; }
	bool getOnline() { return online;  }
	void setOnline() { online = !online; }
	bool compararContrasenia(string contrasenia) {
		if (this->contrasenia==contrasenia){
			return true;
		}
		return false;
	}
	string getPais() { return pais; }
	virtual string to_String(){
		return nombre+ '\t' +apellido+ '\t' +username+ '\t' +pais+ '\t' +contrasenia+ '\t';
	}
	virtual void Imprimir() {};
	string getID() { return id; }
	virtual ~cPersona() {  }//no deleteo un cant de personas por que el proposito
					//no es contar las cantidad de personas sino utilizarlo para 
					//el ID; (se deberia hacer otro contador)
};

