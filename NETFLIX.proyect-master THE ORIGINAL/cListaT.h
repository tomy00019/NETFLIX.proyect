﻿#pragma once
#define NMAX 1000

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
template<class T>
class cListaT
{
protected:
	T** vector;
	unsigned int CA, TAM;
public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool AgregarItem(T* item);

	T* Quitar(string clave);
	T* Quitar(T* item);
	T* QuitarenPos(unsigned int pos);

	bool Eliminar(string clave);
	bool Eliminar(T* item);
	bool Eliminar(unsigned int pos);

	void listarLista();
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);
	
	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();

};

template<class T>
unsigned int cListaT<T>::getTAM()
{
	return TAM;
}
template<class T>
unsigned int cListaT<T>::getCA()
{
	return CA;
}


template<class T>
cListaT<T>::cListaT(unsigned int TAM)
{
	vector = new T * [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;


}

template<class T>
cListaT<T>::~cListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}


}

template<class T>
void cListaT<T>::listarLista()
{
	for (unsigned int i = 0; i < CA; i++)
	{
		vector[i]->Imprimir();
	}
}

template<class T>
bool cListaT<T>::AgregarItem(T* item)
{

	T* i_f = BuscarItem(item->getNombre());
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else throw new exception("No hay tamaño suficiente para agregar el item");
	return true;
}

template<class T>
T* cListaT<T>::Quitar(string clave) {

	unsigned int pos = getItemPos(clave);
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);

}

template<class T>
T* cListaT<T>::Quitar(T* item) {
	unsigned int pos = getItemPos(item->getNombre());
	if (pos >= CA)return NULL;
	return QuitarenPos(pos);
}

template<class T>
T* cListaT<T>::QuitarenPos(unsigned int pos) {

	if (pos >= CA)throw new exception("Posicion invalida");

	T* aux = vector[pos];

	for (unsigned int i = pos; i < CA - 1; i++)
	{
		vector[i] = vector[i + 1];
	}

	vector[CA - 1] = NULL;
	CA--;
	return aux;
}


template<class T>
bool cListaT<T>::Eliminar(string clave) {

	unsigned int pos = getItemPos(clave);

	if (pos < CA) {
		return Eliminar(pos);
	}

}

template<class T>
bool cListaT<T>::Eliminar(T* item) {
	return Eliminar(item->getNombre());
}

template<class T>
bool cListaT<T>::Eliminar(unsigned int pos) {
	if (pos >= CA)return false;// o Throw no pude eliminar

	T* dato = QuitarenPos(pos);

	if (dato != NULL)
		delete dato;
	else
	{
		throw new exception("no encontrado");
	}
	return true;
}

template<class T>
T* cListaT<T>::BuscarItem(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (!((vector[i]->getNombre()).compare(clave))) {
			return vector[i];
		}
	}
	return NULL;
}

template<class T>
T* cListaT<T>::getItem(unsigned int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}

template<class T>
unsigned int cListaT<T>::getItemPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getNombre() == clave)
			return i;
	}

	return INT_MAX;
}




