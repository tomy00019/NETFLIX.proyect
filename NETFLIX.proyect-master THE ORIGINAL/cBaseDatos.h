#pragma once
#include "cListaT.h"
#include "cUsuario.h"
#include "cLogger.h"

class cUsuario;
class cLogger;
class cBaseDatos
{
	static cListaT <cPersona> listaPersonas;  //creamos una lista de PERSONAS que tiene 
										//a los usuarios y a los administradores
public:
	cBaseDatos() {};
	static bool AgregarPersonas(cPersona* Persona) {
		return listaPersonas.AgregarItem(Persona);
	}
	static double personasConectadas() { //porcentaje de personas conctadas
		unsigned int cont = 0;
		for (unsigned int i = 0; i < listaPersonas.getCA();i++) {
			if ((*listaPersonas.getItem(i)).getOnline()) cont++;     //Busco la cantidad de personas que hay conectadas
		}
		//si el 100% ------ getCA
		//       X % ------ cont son las online
		return ((cont * 100) / listaPersonas.getCA());
	}



	static cPersona* BuscarPersona(string usuario) {
		return listaPersonas.BuscarItem(usuario);
	}
	static bool QuitarPersonas(int pos) {
		return listaPersonas.QuitarenPos(pos);
	}
	static cPersona* QuitarPesonas(cPersona* persona) {
		return listaPersonas.Quitar(persona);
	}
	static bool EliminarPersonas(cPersona* persona) {
		return listaPersonas.Eliminar(persona);
	}
	static void ListarPersonas() {
		listaPersonas.listarLista();
	}

	static unsigned int getCA() { return listaPersonas.getCA(); }
	/*void ListarPersonasUsernameOrdenado() {
		listaPersonas.listarNombreOrdenado();
	}*/
	static cPersona* getItem(unsigned int i) {
		return listaPersonas.getItem(i);
	}
	~cBaseDatos() {};
};

