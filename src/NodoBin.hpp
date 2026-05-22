#ifndef NODOBIN_HPP
#define NODOBIN_HPP
#include<iostream>

using namespace std;
template <typename element>

class NodoBin{
	// Atributos para modelar ramificaciones binarias (izquierda y derecha)
	private:
		element info; // Información del nodo binario
		NodoBin<element> * hijoIzq, * hijoDer; // Punteros a las subestructuras hijas
	public:
		// Constructores del nodo binario
		NodoBin();
		NodoBin(element info, NodoBin<element> * hijoIzq, NodoBin<element> * hijoDer);
		
		// Métodos de acceso (Getters)
		element getInfo();
		NodoBin<element> * getHijoIzq();
		NodoBin<element> * getHijoDer();
		
		// Métodos de asignación (Setters)
		void setInfo(element info);
		void setHijoIzq(NodoBin<element> * HijoIzq);
		void setHijoDer(NodoBin<element> * HijoDer); 
};

// Constructor por defecto: Inicializa los punteros de los hijos en NULL
template <typename element>
NodoBin<element>::NodoBin()
{
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}

// Constructor parametrizado con asignación directa de subárboles
template <typename element>
NodoBin<element>::NodoBin(element info, NodoBin<element> * hijoIzq, NodoBin<element> * hijoDer)
{
	this->info = info;
	this->hijoIzq = hijoIzq;
	this->hijoDer = hijoDer;
}

// Retorna el valor guardado en el nodo binario
template <typename element>
element NodoBin<element>::getInfo()
{
	return this->info;
}

// Retorna el puntero al hijo izquierdo
template <typename element>
NodoBin<element> * NodoBin<element>::getHijoIzq()
{
	return this->hijoIzq;
}

// Retorna el puntero al hijo derecho
template <typename element>
NodoBin<element> * NodoBin<element>::getHijoDer()
{
	return this->hijoDer;
}

// Actualiza el valor del nodo binario
template <typename element>
void NodoBin<element>::setInfo(element info)
{
	this->info = info;
}

// Asigna una nueva dirección de memoria al hijo izquierdo
template <typename element>
void NodoBin<element>::setHijoIzq(NodoBin<element> * HijoIzq)
{
	this->hijoIzq = HijoIzq;
}

// Asigna una nueva dirección de memoria al hijo derecho
template <typename element>
void NodoBin<element>::setHijoDer(NodoBin<element> * HijoDer)
{
	this->hijoDer = HijoDer;
}
#endif
