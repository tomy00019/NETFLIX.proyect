#pragma once
#include "cLog.h"
#include "cListaT.h"
#include <string>
#include <map>
#include "cBaseDatos.h"
#include "cPersona.h"


using namespace std;
class cPersona;
class cBaseDatos;
class cLog;
class cLogger
{
	static cListaT<cLog> Logs;
public:
	cLogger() {};

	static bool Registrar(long long timestamp, string usuario, string servicio);
	static bool Registrar(cLog* log);
	static vector<pair<string, int>> Masvistos();
	static vector<pair<string, int>> Masjugados(); //retorna un vector con los servicios mas utilizados
	static vector<pair<string, int>> Masescuchados();
	static long long CantTiempoPeliculas();
	static long long CantTiempoAudios();  //Estos 3 metodos son para calcular la cantidad de tiempo total que se vieron cada servcio
	static long long CantTiempoJuegos();

	static int* cantTiempoUsuario(string usuario);

	static unsigned int getCA() {
		return Logs.getCA();
	}

	static void listarLogs() {
		cout <<"LOG-CODE"<<" USER-ID"<< " SERVICIO"<<" TIEMPO"<<endl;
		return Logs.listarLista();
	}

	~cLogger() {};
};
