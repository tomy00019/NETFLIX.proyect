#pragma once
#include "cLog.h"
#include "cListaT.h"
#include <string>
#include <map>

using namespace std;

class cLogger
{
	static cListaT<cLog> Logs;
public:
	cLogger() {};

	static bool Registrar(int timestamp, int usuario, string servicio);
	static bool Registrar(cLog* log);
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
