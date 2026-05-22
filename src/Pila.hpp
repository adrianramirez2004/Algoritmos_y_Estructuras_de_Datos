#ifndef PILA_HPP
#define PILA_HPP
#include<iostream>
#include "Nodo.hpp"

using namespace std;

template <typename element>
class Pila{
	private:
		int longitud;
		Nodo<element> * primero, * ultimo;
	public:
		//Constructores
		Pila();
		Pila(const Pila<element> & p);
		//Setters
		void setLongitud(int longitud);
		void setPrimero(Nodo<element> * primero);
		void setUltimo(Nodo<element> * ultimo);
		//getters
		int getLongitud();
		Nodo<element> * getPrimero();
		Nodo<element> * getUltimo();
		//operaciones
		void invertir();
		void copiar(Pila<element> p);
		void vaciar();
		void apilar(element e);
		void destruir();
		element getTope();
		void desapilar();
		void mostrar();
		bool esVacia();
		//operadores
		bool operator!=(const Pila<element> & p);
		void operator=(const Pila<element> & p);
		bool operator==(const Pila<element> & p);
		bool operator<(const Pila<element> & p);
		bool operator>(const Pila<element> & p);
		void operator+(const Pila<element> & p);
};
template <typename element>
Pila<element>::Pila()
{
	this->longitud = 0;
	this->primero = NULL;
	this->ultimo = NULL;
}
template <typename element>
Pila<element>::Pila(const Pila<element> & p)
{
	this->longitud = 0;
	this->primero = NULL;
	this->ultimo = NULL;
	this->copiar(p);
}
template <typename element>
void Pila<element>::setLongitud(int longitud)
{
	this->longitud = longitud;
}
template <typename element>
void Pila<element>::setPrimero(Nodo<element> * primero)
{
	this->primero = primero;
}
template <typename element>
void Pila<element>::setUltimo(Nodo<element> * ultimo)
{
	this->ultimo = ultimo;
}
template <typename element>
int Pila<element>::getLongitud()
{
	return this->longitud;
}
template <typename element>
Nodo<element> * Pila<element>::getPrimero()
{
	return this->primero;
}
template <typename element>
Nodo<element> * Pila<element>::getUltimo()
{
	return this->ultimo;
}
template <typename element>
void Pila<element>::invertir()
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
void Pila<element>::copiar(Pila<element> p)
{
	Nodo<element> * aux;
	this->vaciar();
	aux = p.primero;
	while(aux != NULL)
	{
		this->apilar(aux->getinfo());
		aux = aux->getsiguiente();
	}
	this->invertir();
}
template <typename element>
void Pila<element>::vaciar()
{
	while(this->longitud != 0)
	{
		this->desapilar();
	}
}
template <typename element>
void Pila<element>::apilar(element e)
{
	Nodo<element> * aux;
	aux = new Nodo<element>;
	if(this->longitud==0)
	{
		this->ultimo = aux;
	}
	aux->setinfo(e);
	aux->setsiguiente(this->primero);
	this->primero = aux;
	this->longitud = this->longitud + 1;
}
template <typename element>
void Pila<element>::destruir()
{
	this->vaciar();
	delete this;
}
template <typename element>
element Pila<element>::getTope()
{
	return this->primero->getinfo();
}
template <typename element>
void Pila<element>::desapilar()
{
	Nodo<element> * aux;
	if(this->longitud == 1)
	{
		this->ultimo = NULL;
	}
	aux = this->primero;
	this->primero = aux->getsiguiente();
	aux->setsiguiente(NULL);
	delete aux;
	this->longitud = this->longitud - 1;
}
template <typename element>
void Pila<element>::mostrar()
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
bool Pila<element>::esVacia()
{
	return this->longitud == 0;
}
template <typename element>
bool Pila<element>::operator!=(const Pila<element> & p)
{
	Nodo<element> * aux, * aux2;
	bool band;
	band = true;
	aux = this->primero;
	aux2 = p.primero;
	while(band)
	{
		band = aux->getinfo() == aux2->getinfo();
	}
	return band;
}
template <typename element>
void Pila<element>::operator=(const Pila<element> & p)
{
	if(this != &p)
	{
		this->copiar(p);
	}
}
template <typename element>
bool Pila<element>::operator==(const Pila<element> & p)
{
	return this->longitud == p.longitud;
}
template <typename element>
bool Pila<element>::operator<(const Pila<element> & p)
{
	return this->longitud<p.longitud;	
}
template <typename element>
bool Pila<element>::operator>(const Pila<element> & p)
{
	return this->longitud>p.longitud;
}
template <typename element>
void Pila<element>::operator+(const Pila<element> & p)
{
	Nodo<element> * aux;
	aux = p.primero;
	this->ultimo->setsiguiente(aux);
	this->ultimo = p.ultimo;
	this->longitud = this->longitud + p.longitud;
}
#endif
