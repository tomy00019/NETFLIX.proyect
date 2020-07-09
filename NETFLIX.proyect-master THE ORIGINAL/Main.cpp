#pragma once
#include "cPeliculas.h"
#include "cAdministrador.h"
#include "cUsuario.h"
#include "cServicio.h"
#include "cListaT.h"
#include "cAudio.h"
#include "cJuegos.h"
#include "cStreamingService.h"
#include "cBaseDatos.h"
#include "IMPUT_DATA.h"
#define N 50

using namespace std;

int main() {
	cStreamingService PLATAFORMA;  //SE CREA LA PLATAFORMA

	//Se cargan algunos que otros servicios:
	//AUDIOS
	vector <pair<string, string>> pepe = crearCancion(N);  //deber de ser UNICO al ser un parametro de busqueda de repeticion en la lista
	for (int i = 0;i < N;i++) {
		PLATAFORMA + new cAudio(generateNumber(0, 300), pepe[i].first, pepe[i].second, static_cast<eAudio>(generateNumber(0, 3)));
	}
	//PELICULAS (int duracion, string nombre, ePeliculas categoria, int duracion)
	string* nombrePeliculas = createPeliculaNombre(N);  //deber de ser UNICO al ser un parametro de busqueda de repeticion en la lista
	vector <string> arr = {  "Noruega", "Argentina"};
	for (int i = 0;i < N;i++) {
		PLATAFORMA + new cPeliculas(generateNumber(0, 300), nombrePeliculas[i], static_cast<ePeliculas>(generateNumber(0, 7)),estudio(),arr);
	}

	//JUEGOS (int tiempoDeUso, string nombre, eJuegos categoria)
	pepe = crearJuego(N);
	for (int i = 0;i < N;i++) {
		PLATAFORMA + new cJuegos(generateNumber(0, 300), pepe[i].first , pepe[i].second, static_cast<eJuegos>(generateNumber(0, 5)));
	}

	//Dado el exito del departamento de marketing a la hora de anunciar nuestra platforma
	//se SUBSCRIBEN LOS PRIMEROS Clientes y se emplean administradores que pueden 
	//administrar el cotenido(agregar pelis, audios, eliminar, etc) y subscriptores(dar de baja, etc)

	//Se decide la creacion de una base de datos que alacene los datos de todos los usuarios/administradores


	//USUARIO (eCliente tipo, string nombre, string apellido, string username, string pais, string contrasenia)

	cBaseDatos::AgregarPersonas(new cUsuario(premium, "Carlos", "Lopez", "Argentina", "alfonsito19")); //agrego un usuario
	cBaseDatos::AgregarPersonas(new cUsuario(eCliente::basico, "Ken", "Osaka", "Japon", "t"));
	cBaseDatos::AgregarPersonas(new cAdministrador( "adm", "pepe", "Argentina", "toto"));
	//Usuarios comianzan a interactuar con nuestra plataforma
	//interaccion es un metodo en el cual una determinda persona accede a nuestra plataforma
	//si la persona resulta ser una administrador se desplega un menu que es SOLO para administradores
	//lo mismo con usuario. A PARTTIR DEL MENU LA PERSONA COMIENZA LA INTERACCION CON LA PLATAFORMA
	PLATAFORMA.INTERACCION();//recordadr que el usuario ingresado es Nombreusuario: "Carlos_Lopez", Contraseña: "alfonsito19"
	//se probo el funcionaminto de los metodos individualmente y luego se las ensamblo
	cout << "LISTA de logs" << endl;
	cLogger::listarLogs();
	cout << "/////////" << endl;


	return 0;
}