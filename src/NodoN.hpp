#ifndef NODON_HPP
#define NODON_HPP
#include<iostream>

using namespace std;
template <typename element>

class NodoN{
	// Representación Hijo Izquierdo - Hermano Derecho 
	private:
		element info; // Contenido informático del nodo
		NodoN<element> * hijoIzq, * hermanoDer; // Punteros de estructura jerárquica
	public:
		// Constructores de la clase Enaria
		NodoN();
		NodoN(element info, NodoN<element> * hijoIzq, NodoN<element> * hermanoDer);
		
		// Selectores de los atributos del nodo
		element getInfo();
		NodoN<element> * getHijoIzq();
		NodoN<element> * getHermanoDer();
		
		// Modificadores de la estructura jerárquica
		void setInfo(element nuevo);
		void setHijoIzq(NodoN<element> * hijoIzq);
		void setHermanoDer(NodoN<element> * hermanoDer);
};

// Constructor por defecto para nodos genéricos
template <typename element>
NodoN<element>::NodoN()
{
	this->hijoIzq = NULL;
	this->hermanoDer = NULL;
}

// Constructor con especificación de descendencia y vecindad fraterna
template <typename element>
NodoN<element>::NodoN(element info, NodoN<element> * hijoIzq, NodoN<element> * hermanoDer)
{
	this->info = info;
	this->hijoIzq = hijoIzq;
	this->hermanoDer = hermanoDer;
}

// Obtiene la información del nodo general
template <typename element>
element NodoN<element>::getInfo()
{
	return this->info;
}

// Obtiene el puntero al primer hijo (hijo izquierdo)
template <typename element>
NodoN<element> * NodoN<element>::getHijoIzq()
{
	return this->hijoIzq;
}

// Obtiene el puntero al hermano inmediato derecho
template <typename element>
NodoN<element> * NodoN<element>::getHermanoDer()
{
	return this->hermanoDer;
}

// Modifica la información del nodo general
template <typename element>
void NodoN<element>::setInfo(element nuevo)
{
	this->info = nuevo;
}

// Define o cambia el primer hijo del nodo
template <typename element>
void NodoN<element>::setHijoIzq(NodoN<element> * hijoIzq)
{
	this->hijoIzq = hijoIzq;
}

// Enlaza el hermano inmediato derecho del nodo
template <typename element>
void NodoN<element>::setHermanoDer(NodoN<element> * hermanoDer)
{
	this->hermanoDer = hermanoDer;
}
#endif
