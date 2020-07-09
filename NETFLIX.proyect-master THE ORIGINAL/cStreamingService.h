#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include "cListaServicios.h"
#include "cAudio.h"
#include "cPeliculas.h"
#include "cJuegos.h"
#include "vector"
#include "cLog.h"
#include "cUsuario.h"
#include "cBaseDatos.h"
#include "cLogger.h"
#include "cAdministrador.h"
class cLog;
class cAudio;
class cPeliculas;
class cJuegos;
template <class T>
class cListaServicios;
class cUsuario;
class cBaseDatos;
class cLogger;
class cAdministrador;

class cStreamingService
{
	cListaServicios <cServicio> listaServicios;   //UNA SOLA LISTA DE CLASE PADRE PARA IMPLEMENTAR POLISNIRFISMO
public:
	cStreamingService() {}
	//SOLO USUARIOS
	cPersona* inicioSesion();
	void INTERACCION();
	pair<long long, string> SELECCION(string paisUsuario);

	cServicio* BuscarServicio(string clave) {
		return listaServicios.BuscarItem(clave);
	}

	//SOLO ADMINISTRADORES acceden
	bool AgregarServicio(cServicio* servicio) {
		return listaServicios.AgregarItem(servicio);
	} 
	bool QuitarServicio(int pos) {
		return listaServicios.QuitarenPos(pos);
	}
	cServicio* QuitarServicio(cServicio* servicio) {
		return listaServicios.Quitar(servicio);
	}
	bool EliminarServicio(string clave) {
		return listaServicios.Eliminar(clave);
	}


	void ListarServicios() {
		listaServicios.listarLista();
	}
	void ListarServicioNombreOrdenado() {
		listaServicios.listarNombreOrdenado();
	}
	template<class Categoria,class Subcategoria>
	void ListarCategoria(Subcategoria clave) {
		cout << '\t' << '\t' << "TITULO" << std::setw(22) << "DURACION" << "  " << "CODIGO" << endl;
		listaServicios.listarCategoria<Categoria>(clave);
	}
	template<class Categoria>
	void ListarCategoria() {
		cout << '\t' << '\t' << "TITULO" << std::setw(22) << "DURACION" << "  " << "CODIGO" << endl;
		listaServicios.listarCategoria<Categoria>();
	}
//los siguientes metodos imprime los n mas escuchados, jugados, vistos de cada categoria
	void AudioMasEscuchado(int n);
	void PeliculaMasVista(int n);
	void JuegoMasJugado(int n);

	void operator+(cServicio* p) { AgregarServicio(p); };
	void operator-(cServicio* p) { QuitarServicio(p); };
	cServicio* operator[](int pos) {
		return listaServicios.getItem(pos);
	}

	~cStreamingService() {}
};

