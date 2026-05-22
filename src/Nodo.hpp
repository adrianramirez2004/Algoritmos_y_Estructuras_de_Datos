#ifndef NODO_HPP
#define NODO_HPP
#include<iostream>

using namespace std;
template <typename element>

class Nodo{
	// Atributos privados que encapsulan la información del nodo
	private:
		element info; // Información o dato almacenado en el nodo
		Nodo<element> * siguiente; // Puntero hacia el próximo nodo de la estructura
	public:
		// Constructores de la clase
		Nodo();
		Nodo(element newinfo, Nodo<element> * nuevo);
		
		// Métodos selectores (Getters)
		element getinfo();
		Nodo<element> * getsiguiente();
		
		// Métodos modificadores (Setters)
		void setinfo(element newinfo);
		void setsiguiente(Nodo<element> * newprimero);
};

// Constructor por defecto: Inicializa el enlace al siguiente nodo en NULL
template <typename element>
Nodo<element>::Nodo()
{
	this->siguiente = NULL;
}

// Constructor parametrizado: Inicializa el nodo con un dato y un enlace específico
template <typename element>
Nodo<element>::Nodo(element newinfo, Nodo<element> * nuevo)
{
 	this->info = newinfo;
 	this->siguiente = nuevo;
}

// Retorna el dato contenido en el nodo
template <typename element>
element Nodo<element>::getinfo()
{
	return this->info;
}

// Retorna la dirección de memoria del siguiente nodo
template <typename element>
Nodo<element> * Nodo<element>::getsiguiente()
{
	return this->siguiente;
}

// Modifica la información almacenada en el nodo
template <typename element>
void Nodo<element>::setinfo(element newinfo)
{
	this->info = newinfo;
}

// Establece el enlace hacia el siguiente nodo
template <typename element>
void Nodo<element>::setsiguiente(Nodo<element> * newsiguiente)
{
	this->siguiente = newsiguiente;	
}
#endif

