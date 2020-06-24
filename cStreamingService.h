#pragma once
#include "cListaServicios.h"
#include "cAudio.h"
#include "cPeliculas.h"
#include "cJuegos.h"
#include "vector"

class cAudio;
class cPeliculas;
class cJuegos;
template <class T>
class cListaServicios;

class cStreamingService
{
	cListaServicios <cServicio> listaServicios;   //UNA SOLA LISTA DE CLASE PADRE PARA IMPLEMENTAR POLISNIRFISMO
public:
	cStreamingService() {}
	bool AgregarServicio(cServicio* servicio) {
		return listaServicios.AgregarItem(servicio);
	}
	bool QuitarServicio(int pos) {
		return listaServicios.QuitarenPos(pos);
	}
	cServicio* QuitarServicio(cServicio* servicio) {
		return listaServicios.Quitar(servicio);
	}
	void EliminarServicio(unsigned int pos) {
		listaServicios.Eliminar(pos);
	}


	void ListarServicios() {
		listaServicios.listarLista();
	}
	void ListarServicioNombreOrdenado() {
		listaServicios.listarNombreOrdenado();
	}
	template<class T, class K, class U>
	void ListarCategoria(U clave) {
		listaServicios.listarCategoria<T, K>(clave);				
	}
	template<class T, class K>
	void ListarCategoria() {
		listaServicios.listarCategoria<T>();
	}


	void operator+(cServicio* p) { AgregarServicio(p); };
	void operator-(cServicio* p) { QuitarServicio(p); };

	~cStreamingService() {}
};

