#include "cLogger.h"

cListaT<cLog> cLogger::Logs;

bool cLogger::Registrar(long long timestamp, string usuario, string servicio) {
	return Logs.AgregarItem(new cLog(usuario, servicio, timestamp));
}

bool cLogger::Registrar(cLog* log) {
	return Logs.AgregarItem(log);
}

vector<pair<string, int>> cLogger::Masvistos()  //retorno el codigo del elemento y numero de repeticiones
{
	map<string, int> m; //el map almacenara la cantidad de veces que aparecio un elemento

	unsigned int size = getCA();
	for (int i = 0; i < size;i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'P')  //si es una pelicula su codigo inicia con 'P'
		{
			if (m.count((Logs.getItem(i))->getServicio())) {  //si count es cero no esta en el map
				m[(Logs.getItem(i))->getServicio()]++;  //ya esta en el map sumamos uno mas
			}
			else {
				m[(Logs.getItem(i))->getServicio()]=1;    //creamos un map y lo igualamos a uno
			}
		}
	}
	//tenemos un map con lo siguiente EJ:
	// rapido y furioso - 9
	//cars - 5
	//barney - 80
	//donde el string es codigo de la pelicula y el int las repeticiones dentro del vector
	//proseguimos a ordenar un retornar un array con los n elementos pedidos
	vector<pair<string, int>> vec;  //creamos un vector de pares
	copy(m.begin(), // copiamos las KEY-VALUES pares del map al vector
		m.end(),
		back_inserter<vector<pair<string, int>>>(vec));
	sort(vec.begin(), vec.end(),   //ordenamos el vector por orden decreciente
		[](const pair<string, int>& l, const pair<string, int>& r) { //hacemos una lambda-para "sortear"
		if (l.second != r.second)
			return l.second > r.second;

		return l.first > r.first;
	});
	return vec;
}


vector<pair<string, int>> cLogger::Masescuchados()  //aplicando la mmisma metodologia que Masvistos
{
	map<string, int> m; 

	unsigned int size = getCA();
	for (int i = 0; i < size;i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'A') 
		{
			if (m.count((Logs.getItem(i))->getServicio())) {  
				m[(Logs.getItem(i))->getServicio()]++;
			}
			else {
				m[(Logs.getItem(i))->getServicio()] = 1;   
			}
		}
	}
	vector<pair<string, int>> vec;  
	copy(m.begin(),
		m.end(),
		back_inserter<vector<pair<string, int>>>(vec));
	sort(vec.begin(), vec.end(),  
		[](const pair<string, int>& l, const pair<string, int>& r) {
		if (l.second != r.second)
			return l.second > r.second;

		return l.first > r.first;
	});
	return vec;
}

vector<pair<string, int>> cLogger::Masjugados() //aplicando la mmisma metodologia que Masvistos
{
	map<string, int> m; 

	unsigned int size = getCA();
	for (int i = 0; i < size;i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'J')  
		{
			if (m.count((Logs.getItem(i))->getServicio())) { 
				m[(Logs.getItem(i))->getServicio()]++; 
			}
			else {
				m[(Logs.getItem(i))->getServicio()] = 1;   
			}
		}
	}
	vector<pair<string, int>> vec; 
	copy(m.begin(),
		m.end(),
		back_inserter<vector<pair<string, int>>>(vec));
	sort(vec.begin(), vec.end(),  
		[](const pair<string, int>& l, const pair<string, int>& r) {
		if (l.second != r.second)
			return l.second > r.second;

		return l.first > r.first;
	});
	return vec;
}

int* cLogger::cantTiempoUsuario(string usuario) { //retorno un array del usauario con el tiempo que estuvo en peliculas, audios, y juegos respectivamente

	int arr[] = { 0,0,0 };
	for (unsigned int i = 0;i < Logs.getCA();i++) {
		if ((Logs.getItem(i))->getNombreUsuario() == usuario) {
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
	for (int i = 0;i < 3;i++) {
		cout << arr[i] << endl;
	}
	return arr;
}



long long cLogger::CantTiempoPeliculas()
{
	long long acum = 0;
	for (unsigned int i = 0; i < Logs.getCA(); i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'P') {
			acum += (Logs.getItem(i))->getTimestap();
		}
	}
	return acum;     //Retorna la cantidad de tiempo total que se vieron las peliculas
}

long long cLogger::CantTiempoAudios()
{
	long long acum = 0;
	for (unsigned int i = 0; i < Logs.getCA(); i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'A') {
			acum += (Logs.getItem(i))->getTimestap();
		}
	}
	return acum;
}

long long cLogger::CantTiempoJuegos()
{
	long long acum = 0;
	for (unsigned int i = 0; i < Logs.getCA(); i++)
	{
		if (((Logs.getItem(i))->getServicio())[0] == 'J') {
			acum += (Logs.getItem(i))->getTimestap();
		}
	}
	return acum;
}