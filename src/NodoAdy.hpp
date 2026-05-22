#ifndef NODOADY_HPP
#define NODOADY_HPP
#include<iostream>
#include "NodoVertice.hpp"

using namespace std;
template <typename element>
class NodoVertice; // Declaración hacia adelante para interconectar estructuras
template <typename element>

class NodoAdy{
	// Modela una arista dirigida hacia un vértice objetivo con un costo asociado
	private:
		float costo; // Peso numérico del arco (costo, distancia, etc.)
		NodoVertice<element> * info; // Puntero directo al vértice destino en el grafo
		NodoAdy<element> * prox; // Siguiente arco en la lista de adyacencia del vértice origen
	public:
		// Constructores de la arista
		NodoAdy();
		NodoAdy(float costo, NodoVertice<element> * info, NodoAdy<element> * prox);
		
		// Métodos selectores
		float getCosto();
		NodoVertice<element> * getInfo();
		NodoAdy<element> * getProx();
		
		// Métodos modificadores
		void setCosto(float costo);
		void setInfo(NodoVertice<element> * info);
		void setProx(NodoAdy<element> * prox); 
};

// Constructor por defecto
template <typename element>
NodoAdy<element>::NodoAdy()
{
	this->prox = nullptr;
	this->info = nullptr;
}

// Constructor con especificación de costo, destino y encadenamiento
template <typename element>
NodoAdy<element>::NodoAdy(float costo, NodoVertice<element> * info, NodoAdy<element> * prox)
{
	this->costo = costo;
	this->prox = prox;
	this->info = info;
}

// Retorna el peso/costo de la arista
template <typename element>
float NodoAdy<element>::getCosto()
{
	return this->costo;
}

// Retorna el vértice al que apunta este arco
template <typename element>
NodoVertice<element> * NodoAdy<element>::getInfo()
{
	return this->info;
}

// Retorna el siguiente arco del vértice de origen
template <typename element>
NodoAdy<element> * NodoAdy<element>::getProx()
{
	return this->prox;
}

// Cambia el costo de la arista
template <typename element>
void NodoAdy<element>::setCosto(float costo)
{
	this->costo = costo;
}

// Redirecciona la arista hacia otro vértice de destino
template <typename element>
void NodoAdy<element>::setInfo(NodoVertice<element> * info)
{
	this->info = info;
}

// Vincula el siguiente arco de la sublista de adyacencia
template <typename element>
void NodoAdy<element>::setProx(NodoAdy<element> * prox)
{
	this->prox = prox;
}
#endif
