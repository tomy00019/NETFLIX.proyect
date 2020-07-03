#pragma once
#include "cListaT.h"

template <class T>
class cListaServicios : public cListaT<T>
{
public:
	cListaServicios() : cListaT<T>() {}
	
	void listarNombreOrdenado();

	template <class K, class U>
	void listarCategoria(U clave);
	template <class K>
	void listarCategoria();


	~cListaServicios() {};
};


template<class T>
template<class K, class U>
void cListaServicios<T>::listarCategoria(U clave)	//se lista el tipo de servicio  y la subcategoria
{													
	for (unsigned int i = 0; i < this->CA; i++)
	{
		K* aux = dynamic_cast<K*>(this->getItem(i));
		if (aux!= NULL){
			if (aux->getTipo() == clave)
			{
				aux->Imprimir();
			}
		}

	}
}

template<class T>
template<class K>
void cListaServicios<T>::listarCategoria()	//se lista el tipo de servicio
{
	for (unsigned int i = 0; i < this->CA; i++)
	{
		K* aux = dynamic_cast<K*>(this->getItem(i));
		if (aux != NULL) {
			aux->Imprimir();
		}

	}
}

template<class T>
void cListaServicios<T>::listarNombreOrdenado() 
{
	vector <T> buffer;
	for (unsigned int i = 0; i < this->CA; i++)   //creamos un vector auxiliar (no se quiere modificar el vector original)
	{
		buffer.push_back(*(this->vector[i]));
	}
	//vector.sort();
	for (unsigned int i = 0;i < this->CA - 1;i++) { //Bubble sort O(n^2)
		int cont = 0;
		for (unsigned int l = 0;l < this->CA - 1;l++) {
			if (((buffer[l].getNombre()).compare(buffer[l + 1].getNombre())) > 0) {
				swap(buffer[l], buffer[l + 1]);
				cont++;
			}
		}
		if (cont == 0) break;
	}
	for (unsigned int i = 0; i < this->CA; i++)   //creamos un vector auxiliar (no se quiere modificar el vector original)
	{
		buffer[i].Imprimir();
	}
	
	/*
	no funciona
	for (unsigned int i = 0; i < buffer.size(); i++)
	{
		cJuegos* aux1 = dynamic_cast<cJuegos*>(&buffer[i]);
		if (aux1 != NULL) {
			aux1->Imprimir();
			continue;
		}
		cPeliculas* aux2 = dynamic_cast<cPeliculas*>(&buffer[i]);
		if (aux2 != NULL) {
			aux2->Imprimir();
			continue;
		}
		cAudio* aux3 = dynamic_cast<cAudio*>(&buffer[i]);
		if (aux3 != NULL) {
			aux3->Imprimir();
			continue;
		}
		throw new exception("NO SE HA ENCONTRADO LA CATEGORIA");
	}
	
	for (unsigned int i = 0;i < this->CA - 1;i++) { //Bubble sort O(n^2)
		int cont = 0;
		for (unsigned int l = 0;l < this->CA - 1;l++) {
			if (((vector[l].getNombre()).compare(vector[l + 1].getNombre())) > 0) {
				swap(vector[l], vector[l + 1]);
				cont++;
			}
		}
		for (unsigned int i = 0;i < this->CA - 1;i++) {

		}
		if (cont == 0) break;
	}*/
}

