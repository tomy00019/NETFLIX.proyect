#include "cJuegos.h"
int cJuegos::cantJuegos = 0;
//
cJuegos::cJuegos(int duracion, string nombre,string empresa, eJuegos categoria, vector<string> PaisesProhibidos) 
		:codigo("J" + to_string(cantJuegos)),
			cServicio(duracion, nombre, PaisesProhibidos){
	bool existeJuego = (categoria >= autos && categoria <= deportes);
	if(!existeJuego)
	{
		throw new exception("NO ES UNA CATEGORIA CORRECTA");
	}
	this->empresa = empresa;
	this->categoria = categoria;
	cantJuegos++;
}

void cJuegos::guardar()
{
	cout << "Se ha guardado con exito" << endl;       //Guardo el juego
}

void cJuegos::Imprimir() //Imprimo datos del juego
{
	cServicio::Imprimir();
	cout << '\t' << codigo << '\t' << "Empresa: "<<empresa<<endl;
}

void cJuegos::Comandos()
{
	int opcion = 0;
	while (true)            //Son comandos para realizar en el juego
	{
		cout << "COMANDOS" << endl;
		cout << "1. AGACHAR" << endl;
		cout << "2. PARARSE" << endl;
		cout << "3. DISPARAR" << endl;
		cout << "4. SALTAR" << endl;
		cout << "5. ADELANTARSE" << endl;
		cout << "6. APUNTAR" << endl;
		cout << "7. SENIALAR" << endl;
		cout << "-1. SALIR" << endl;
		cin >> opcion;
		if (opcion == 1) {
			cout << "agachado" << endl;
			continue;
		}
		else if (opcion == 2) {
			cout << "pararse" << endl;
			continue;
		}
		else if (opcion == 3) {
			cout << "disparar" << endl;
			continue;
		}
		else if (opcion == 4) {
			cout << "saltar" << endl;
			continue;
		}
		else if (opcion == 5) {
			cout << "adelantarse" << endl;
			continue;
		}
		else if (opcion == 6) {
			cout << "apuntar" << endl;
			continue;
		}
		else if (opcion == 7) {
			cout << "senialar" << endl;
			continue;
		}
		else if (opcion == -1) { return; }
		else {
			cout << "EL COMANDO INGRESADO ES ICORRECTO" << endl;
			continue;
		}
	}
}