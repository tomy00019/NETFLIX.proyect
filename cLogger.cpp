#include "cLogger.h"

cListaT<cLog> cLogger::Logs;

bool cLogger::Registrar(int timestamp, int usuario, string servicio) {
	return Logs.AgregarItem(new cLog(usuario, servicio, timestamp));
}

bool cLogger::Registrar(cLog* log) {
	return Logs.AgregarItem(log);
}

string cLogger::Masvistos()
{
	map<string, int> m; //el map almacenara la cantidad de veces que aparecio un elemento

	unsigned int size = getCA();
	for (int i = 0; i < size;i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'P')  //si es una pelicula su codigo inicia con 'P'
		{
			if (m.count((Logs.getItem(i))->getServicio())) {  //si count es cero no esta en el map
				m[(Logs.getItem(i))->getServicio()] = 1;  //ya esta en el map sumamos uno mas
			}
			else {
				m[(Logs.getItem(i))->getServicio()]++;    //creamos un map y lo igualamos a cero
			}
		}
	}
	//tenemos un map con lo siguiente EJ:
	// rapido y furioso - 9
	//cars - 5
	//barney - 80
	//donde el string es nombre de la pelicula y el int las repeticiones dentro del vector
	//proseguimos a sacar el maximo

	int max = -1;
	string nombre = " ";
	for (auto x : m) {
		if (x.second > max) {
			max = x.second;
			nombre = x.first;
		}
	}
	return nombre;
}


string cLogger::Masescuchados()  //aplicando la mmisma metodologia que Masvistos
{
	map<string, int> m;

	unsigned int size = getCA();
	for (unsigned int i = 0; i < size;i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'A')
		{
			if (m.count((Logs.getItem(i))->getServicio())) {
				m[(Logs.getItem(i))->getServicio()] = 1;
			}
			else {
				m[(Logs.getItem(i))->getServicio()]++;
			}
		}
	}
	int max = -1;
	string nombre = " ";
	for (auto x : m) {
		if (x.second > max) {
			max = x.second;
			nombre = x.first;
		}
	}
	return nombre;
}

string cLogger::Masjugados() //aplicando la mmisma metodologia que Masvistos
{
	map<string, int> m;
	unsigned int size = getCA();
	for (unsigned int i = 0; i < size;i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'J')
		{
			if (m.count((Logs.getItem(i))->getServicio())) {
				m[(Logs.getItem(i))->getServicio()] = 1;
			}
			else {
				m[(Logs.getItem(i))->getServicio()]++;
			}
		}
	}

	int max = -1;
	string nombre = " ";
	for (auto x : m) {
		if (x.second > max) {
			max = x.second;
			nombre = x.first;
		}
	}
	return nombre;
}

double* cLogger::cantTiempoUsuario(int usuario) { //retorno un array del usauario con el tiempo que estuvo en peliculas, audios, y juegos respectivamente

	double arr[] = { 0,0,0 };
	for (unsigned int i = 0;i < Logs.getCA();i++) {
		if ((Logs.getItem(i))->getNombre() == to_string(usuario)) {
			if (((Logs.getItem(i))->getServicio())[0] == 'P') {
				arr[0] += (Logs.getItem(i))->getTimestap();
			}
			if (((Logs.getItem(i))->getServicio())[0] == 'J') {
				arr[1] += (Logs.getItem(i))->getTimestap();
			}
			if (((Logs.getItem(i))->getServicio())[0] == 'A') {
				arr[2] += (Logs.getItem(i))->getTimestap();
			}
		}
	}
	return arr;
}



double cLogger::CantTiempoPeliculas()
{
	double acum = 0;
	for (unsigned int i = 0; i < Logs.getCA(); i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'P') {
			acum += (Logs.getItem(i))->getTimestap();
		}
	}
	return acum;     //Retorna la cantidad de tiempo total que se vieron las peliculas
}

double cLogger::CantTiempoAudios()
{
	double acum = 0;
	for (unsigned int i = 0; i < Logs.getCA(); i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'A') {
			acum += (Logs.getItem(i))->getTimestap();
		}
	}
	return acum;
}

double cLogger::CantTiempoJuegos()
{
	double acum = 0;
	for (unsigned int i = 0; i < Logs.getCA(); i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'J') {
			acum += (Logs.getItem(i))->getTimestap();
		}
	}
	return acum;
}