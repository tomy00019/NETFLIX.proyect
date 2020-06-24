#pragma once
#include "cListaT.h"
#include "cUsuario.h"

class cUsuario;

class cBaseDatos
{
	cListaT <cPersona> listaPersonas;  //creamos una lista de PERSONAS que tiene 
										//a los usuarios y a los administradores
public:
	cBaseDatos() {};
	bool AgregarPersonas(cPersona* Persona) {
		return listaPersonas.AgregarItem(Persona);
	}
	float personasConectadas() {
		unsigned int cont = 0;
		for (unsigned int i = 0; i < listaPersonas.getCA();i++) {
			if ((*listaPersonas.getItem(i)).getOnline()) cont++;     //Busco la cantidad de personas que hay conectadas
		}//si el 100% ------ cantPersonas
		 //       X % ------ cont son las online
		return ((cont * 100) / listaPersonas.getCA());
	}

	// METODOS 
	/*bool QuitarPersonas(int Audio) {
		return listaPersonas.QuitarenPos(Audio);
	}*/
	/*cAudio* QuitarPesonas(cAudio* Audio) {
		return listaPersonas.Quitar(Audio);
	}
	void EliminarPersonas(unsigned int pos) {
		listaPersonas.Eliminar(pos);
	}
	void ListarPersonas() {
		listaPersonas.listarLista();
	}
	void ListarPersonasUsernameOrdenado() {
		listaPersonas.listarNombreOrdenado();
	}*/
	~cBaseDatos() {};
};

