#ifndef COLA_HPP
#define COLA_HPP
#include<iostream>
#include "Nodo.hpp"

using namespace std;
template <typename element>

class Cola{
	private:
		int longitud;
		Nodo<element> * primero, * ultimo;
	public:
		//Constructores
		Cola();
		Cola(const Cola<element> & c);
		//Setters
		void setLongitud(int longitud);
		void setPrimero(Nodo<element> * primero);
		void setUltimo(Nodo<element> * ultimo);
		//Getters
		int getLongitud();
		Nodo<element> * getPrimero();
		Nodo<element> * getUltimo();
		//Operaciones
		void encolar(element e);
		void desencolar();
		bool esVacia();
		void vaciar();
		void destruir();
		element getFrente();
		void mostrar();
		void invertir();
		void copiar(const Cola<element> & c);
		//operadores
		bool operator!=(const Cola<element> & c);
		void operator=(const Cola<element> & c);
		bool operator==(const Cola<element> & c);
		bool operator<(const Cola<element> & c);
		bool operator>(const Cola<element> & c);
		void operator+(const Cola<element> & c);
};
template <typename element>
Cola<element>::Cola()
{
	this->longitud = 0;
	this->primero = NULL;
	this->ultimo = NULL;
}
template <typename element>
Cola<element>::Cola(const Cola<element> & c)
{
	this->longitud = 0;
	this->primero = NULL;
	this->ultimo = NULL;
	this->copiar(c);
}
template <typename element>
void Cola<element>::setLongitud(int longitud)
{
	this->longitud = longitud;
}
template <typename element>
void Cola<element>::setPrimero(Nodo<element> * primero)
{
	this->primero = primero;
}
template <typename element>
void Cola<element>::setUltimo(Nodo<element> * ultimo)
{
	this->ultimo = ultimo;
}
template <typename element>
int Cola<element>::getLongitud()
{
	return this->longitud;
}
template <typename element>
Nodo<element> * Cola<element>::getPrimero()
{
	return this->primero;
}
template <typename element>
Nodo<element> * Cola<element>::getUltimo()
{
	return this->ultimo;
}
template <typename element>
void Cola<element>::encolar(element e)
{
	Nodo<element> * aux;
	aux = new Nodo<element>;
	aux->setinfo(e);
	if(this->longitud == 0)
	{
		this->primero = aux;
		this->ultimo = aux;
	}else
	{
		this->ultimo->setsiguiente(aux);
		this->ultimo = aux;
	}
	aux->setsiguiente(NULL);
	this->longitud = this->longitud + 1; 
}
template <typename element>
void Cola<element>::desencolar()
{
	Nodo<element> * aux;
	aux = this->primero;
	this->primero = aux->getsiguiente();
	aux->setsiguiente(NULL);
	delete aux;
	this->longitud = this->longitud - 1;
	
}
template <typename element>
bool Cola<element>::esVacia()
{
	return this->longitud == 0;
}
template <typename element>
void Cola<element>::vaciar()
{
	while(this->longitud != 0)
	{
		this->desencolar();
	}
}
template <typename element>
void Cola<element>::destruir()
{
	this->vaciar();
	delete this;
}
template <typename element>
element Cola<element>::getFrente()
{
	return this->primero->getinfo();
}
template <typename element>
void Cola<element>::mostrar()
{
	Nodo<element> * aux;
	aux = this->primero;
	while(aux != NULL)
	{
		cout<<aux->getinfo()<<" ";
		aux = aux->getsiguiente();
	}
	cout<<endl;
}
template <typename element>
void Cola<element>::invertir()
{
	Nodo<element> * aux1, * aux2, * aux3;
	aux1 = NULL;
	aux2 = this->primero;
	aux3 = aux2->getsiguiente();
	this->ultimo = aux2;
	while(aux3 != NULL)
	{
		aux2->setsiguiente(aux1);
		aux1 = aux2;
		aux2 = aux3;
		aux3 = aux3->getsiguiente();
	}
	aux2->setsiguiente(aux1);
	this->primero = aux2;
}
template <typename element>
void Cola<element>::copiar(const Cola<element> & c)
{
	Nodo<element> * aux;
	this->vaciar();
	aux = c.primero;
	while(aux != NULL)
	{
		this->encolar(aux->getinfo());
		aux = aux->getsiguiente();
	}
}
template <typename element>
bool Cola<element>::operator!=(const Cola<element> & c)
{
	Nodo<element> * aux, * aux2;
	bool band;
	band = true;
	aux = this->primero;
	aux2 = c.primero;
	while(band)
	{
		band = aux->getinfo() == aux2->getinfo();
	}
	return band;
}
template <typename element>
void Cola<element>::operator=(const Cola<element> & c)
{
	if(this != &c)
	{
		this->copiar(c);
	}
}
template <typename element>
bool Cola<element>::operator==(const Cola<element> & c)
{
	return this->longitud == c.longitud;
}
template <typename element>
bool Cola<element>::operator<(const Cola<element> & c)
{
	return this->longitud<c.longitud;	
}
template <typename element>
bool Cola<element>::operator>(const Cola<element> & c)
{
	return this->longitud>c.longitud;
}
template <typename element>
void Cola<element>::operator+(const Cola<element> & c)
{
	Nodo<element> * aux;
	aux = c.primero;
	this->ultimo->setsiguiente(aux);
	this->ultimo = c.ultimo;
	this->longitud = this->longitud + c.longitud;
}
#endif
