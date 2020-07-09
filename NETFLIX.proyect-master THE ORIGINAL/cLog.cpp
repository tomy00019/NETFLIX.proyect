#include "cLog.h"

int cLog::cantidad = 0;

string cLog::getNombreUsuario() {
	unsigned int ca = cBaseDatos::getCA();
	for (unsigned int i = 0;i < ca;i++) {
		string id = cBaseDatos::getItem(i)->getID();
		if (id == usuario) {
			return  cBaseDatos::getItem(i)->getNombre();
		}
	}
}