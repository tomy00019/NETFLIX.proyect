#pragma once
#include "cLog.h"
#include "cListaT.h"
#include "cUsuario.h"
#include <map>

class cLog;

class cLogger
{
	static cListaT <cLog> Logs;
public:
	cLogger() {};
	
	static bool Registrar(double timestamp, int usuario, string servicio);
	static string Masvistos();
	static string Masjugados();
	static string Masescuchados();
	static double CantTiempoPeliculas();
	static double CantTiempoAudios();            //Estos 3 metodos son para calcular la cantidad de tiempo total que se vieron cada servcio
	static double CantTiempoJuegos();

	static double* cantTiempoUsuario(int usuario);
	
	static unsigned int getCA() {
		return Logs.getCA();
	}

	~cLogger() {};
};


//estoy inicializando bien las listas templates? 
//falta convertir la plataforma en dinamica (estaticos con dinamicos NO!!!!)
//TODOS LOS METODOS DEBENE SER STATICOS ACA?
//yo tenia al vector logs y el getCA no dinamicos y no em permitia operar (ERROR)
//cambiar los enums por enum class