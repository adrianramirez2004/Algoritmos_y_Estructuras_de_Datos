#ifndef NODOVERTICE_HPP
#define NODOVERTICE_HPP
#include<iostream>
#include "NodoAdy.hpp"

using namespace std;
template <typename element>
class NodoAdy; // Declaración hacia adelante de la adyacencia
template <typename element>

class NodoVertice{
	// Representa la cabecera de la estructura de un vértice en un grafo 
	private:
		element info; // Identificador del vértice (ej. string, int)
		NodoVertice<element> * prox; // Siguiente vértice en la lista global de vértices del grafo
		NodoAdy<element> * ListaAdy; // Puntero al inicio de la lista de arcos (aristas salientes)
	public:
		// Constructores del vértice
		NodoVertice();
		NodoVertice(element v, NodoVertice<element> * prox, NodoAdy<element> * ListaAdy);
		
		// Getters 
		element getInfo();
		NodoVertice<element> * getProx();
		NodoAdy<element> * getListaAdy();
		
		// Setters 
		void setInfo(element info);
		void setProx(NodoVertice<element> * prox);
		void setListaAdy(NodoAdy<element> * ListaAdy); 
};

// Constructor inicializador: Limpia los punteros estructurales
template <typename element>
NodoVertice<element>::NodoVertice()
{
	this->prox = nullptr;
	this->ListaAdy = nullptr;
}

// Constructor con vinculación explícita de caminos y aristas
template <typename element>
NodoVertice<element>::NodoVertice(element v, NodoVertice<element> * prox, NodoAdy<element> * ListaAdy)
{
	this->info = v;
	this->prox = prox;
	this->ListaAdy = ListaAdy;
}

// Retorna el identificador del vértice
template <typename element>
element NodoVertice<element>::getInfo()
{
	return this->info;
}

// Retorna el siguiente vértice en la lista del grafo
template <typename element>
NodoVertice<element> * NodoVertice<element>::getProx()
{
	return this->prox;
}

// Retorna el inicio de la lista de adyacencia asociada a este nodo
template <typename element>
NodoAdy<element> * NodoVertice<element>::getListaAdy()
{
	return this->ListaAdy;
}

// Cambia el identificador/valor del vértice
template <typename element>
void NodoVertice<element>::setInfo(element info)
{
	this->info = info;
}

// Enlaza el siguiente vértice de la lista maestra del grafo
template <typename element>
void NodoVertice<element>::setProx(NodoVertice<element> * prox)
{
	this->prox = prox;
}

// Asigna una nueva lista de aristas incidentes/salientes a este vértice
template <typename element>
void NodoVertice<element>::setListaAdy(NodoAdy<element> * ListaAdy)
{
	this->ListaAdy = ListaAdy;
}
#endif
