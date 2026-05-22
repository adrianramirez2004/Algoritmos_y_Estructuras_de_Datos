#ifndef LISTA_HPP
#define LISTA_HPP
#include<iostream>
#include "Nodo.hpp"

using namespace std;
template <typename element>

class Lista{
	private:
		int longitud;
		Nodo<element> * primero, * ultimo;
	public:
		//constructores
		Lista();
		Lista(const Lista<element> &l);
		//getters
		int getLongitud();
		Nodo<element> * getprimero();
		Nodo<element> * getultimo();
		//setters
		void setLongitud(int longitud);
		void setPrimero(Nodo<element> * primero);
		void setUltimo(Nodo<element> * ultimo);
		//operaciones
		void invertir();
		void copiar(const Lista<element> &list);
		element consultar(int pos);
		int buscar(element e);
		void eliminar(int pos);
		void insertar(element e, int pos);
		void vaciar();
		bool esVacia();
		void destruir();
		void modificar(element e, int pos);
		void mostrar();
		void ordenarascendente();
		void ordenardescendente();
		//operadores
		bool operator!=(const Lista<element> &l);
		void operator=(const Lista<element> &l);
		bool operator==(const Lista<element> &l);
		element operator[](int pos);
		bool operator<(const Lista<element> &l);
		bool operator>(const Lista<element> &l);
		void operator+(const Lista<element> &l);
};

//Constructores
template <typename element>
Lista<element>::Lista()
{
	this->longitud = 0;
	this->primero = NULL;
	this->ultimo = NULL;
}
template <typename element>
Lista<element>::Lista(const Lista<element> &l)
{
	this->longitud = 0;
	this->primero = NULL;
	this->ultimo = NULL;
	this->copiar(l);
}

//Getters
template <typename element>
int Lista<element>::getLongitud()
{
	return this->longitud;
}
template <typename element>
Nodo<element> * Lista<element>::getprimero()
{
	return this->primero;
}
template <typename element>
Nodo<element> * Lista<element>::getultimo()
{
	return this->ultimo;
}

//Setters
template <typename element>
void Lista<element>::setLongitud(int longitud)
{
	this->longitud = longitud;
}
template <typename element>
void Lista<element>::setPrimero(Nodo<element> * primero)
{
	this->primero = primero;
}
template <typename element>
void Lista<element>::setUltimo(Nodo<element> * ultimo)
{
	this->ultimo = ultimo;
}

//operaciones
template <typename element>
void Lista<element>::insertar(element e, int pos)
{
	Nodo<element> * aux, * aux2;
	int i;
	aux = new Nodo<element>;
	aux->setinfo(e);
	if(this->longitud == 0)
	{
		aux->setsiguiente(NULL);
		this->primero = aux;
		this->ultimo = aux;
	}else
	{
		if(pos == 1)
		{
			aux->setsiguiente(this->primero);
			this->primero = aux;
		}else
		{
			if(pos == this->longitud + 1)
			{
				this->ultimo->setsiguiente(aux);
				aux->setsiguiente(NULL);
				this->ultimo = aux;
			}else
			{
				aux2 = this->primero;
				for(i=1;i<pos-1;i++)
				{
					aux2 = aux2->getsiguiente();
				}
				aux->setsiguiente(aux2->getsiguiente());
				aux2->setsiguiente(aux);
			}
		}
	}
	this->longitud++;
}
template <typename element>
bool Lista<element>::esVacia()
{
	return this->longitud == 0;	
}
template <typename element>
int Lista<element>::buscar(element e)
{
	int result,i;
	bool band;
	Nodo<element> * aux;
	band = false;
	aux = this->primero;
	i = 1;
	result = -1;
	while(!band && aux != NULL)
	{
		band = aux->getinfo() == e;
		if(band)
		{
			result = i;
		}
		aux = aux->getsiguiente();
		i++;
	}
	return result;
}
template <typename element>
void Lista<element>::eliminar(int pos)
{
	Nodo<element> * aux, * aux2;
	int i;
	aux = this->primero;
	if(pos == 1)
	{
		this->primero = aux->getsiguiente();
		aux->setsiguiente(NULL);
		delete aux;
	}else
	{
		for(i=1;i<pos-1;i++)
		{
			aux = aux->getsiguiente();
		}
		if(pos == this->longitud)
		{
			this->ultimo = aux;	
		}
		aux2 = aux->getsiguiente();
		aux->setsiguiente(aux2->getsiguiente());
		aux2->setsiguiente(NULL);
		delete aux2;
	}
	this->longitud--;
}
template <typename element>
element Lista<element>::consultar(int pos)
{
	element result;
	int i;
	Nodo<element> * aux;
	if(pos == 1)
	{
		result = this->primero->getinfo();
	}else
	{
		if(pos == this->longitud)
		{
			result = this->ultimo->getinfo();
		}else
		{
			aux = this->primero;
			for(i=1;i<pos;i++)
			{
				aux = aux->getsiguiente();
			}
			result = aux->getinfo();
		}
	}
	return result;
}
template <typename element>
void Lista<element>::modificar(element e, int pos)
{
	int i;
	Nodo<element> * aux;
	if(pos == this->longitud)
	{
		aux = this->ultimo;
	}else
	{
		aux = this->primero;
		for(i=1;i<pos;i++)
		{
			aux = aux->getsiguiente();
		}
	}
	aux->setinfo(e);
}
template <typename element>
void Lista<element>::vaciar()
{
	while(this->longitud != 0)
	{
		this->eliminar(1);
	}
	this->primero = NULL;
	this->ultimo = NULL;
}
template <typename element>
void Lista<element>::copiar(const Lista<element> &list)
{
	Nodo<element> * aux;
	this->vaciar();
	aux = list.primero;
	while(aux != NULL)
	{
		this->insertar(aux->getinfo(),this->longitud + 1);
		aux = aux->getsiguiente();
	}
}
template <typename element>
void Lista<element>::destruir()
{
	this->vaciar();
	delete this;
}
template <typename element>
void Lista<element>::invertir()
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
void Lista<element>::mostrar()
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
void Lista<element>::ordenarascendente()
{
	 Nodo<element> * aux1, * aux2;
	 element aux;
	 aux1 = this->primero;
	 while(aux1 != NULL)
	 {
	 	aux2 = aux1->getsiguiente();
	 	while(aux2 != NULL)
	 	{
	 		if(aux1->getinfo() > aux2->getinfo())
	 		{
	 			aux = aux1->getinfo();
	 			aux1->setinfo(aux2->getinfo());
	 			aux2->setinfo(aux);
			}
			aux2 = aux2->getsiguiente();
		}
		aux1 = aux1->getsiguiente();
	}
}
template <typename element>
void Lista<element>::ordenardescendente()
{
	Nodo<element> * aux1, * aux2;
	 element aux;
	 aux1 = this->primero;
	 while(aux1 != NULL)
	 {
	 	aux2 = aux1->getsiguiente();
	 	while(aux2 != NULL)
	 	{
	 		if(aux1->getinfo() < aux2->getinfo())
	 		{
	 			aux = aux1->getinfo();
	 			aux1->setinfo(aux2->getinfo());
	 			aux2->setinfo(aux);
			}
			aux2 = aux2->getsiguiente();
		}
		aux1 = aux1->getsiguiente();
	}
}
template <typename element>
bool Lista<element>::operator!=(const Lista<element> &l)
{
	Nodo<element> * aux, * aux2;
	bool band;
	band = true;
	aux = this->primero;
	aux2 = l.primero;
	while(band)
	{
		band = aux->getinfo() == aux2->getinfo();
	}
	return band;
}
template <typename element>
void Lista<element>::operator=(const Lista<element> &l)
{
	if(this != &l)
	{
		this->copiar(l);
	}
}
template <typename element>
bool Lista<element>::operator==(const Lista<element> &l)
{
	return this->longitud == l.longitud;
}
template <typename element>
element Lista<element>::operator[](int pos)
{
	return this->consultar(pos);
}
template <typename element>
bool Lista<element>::operator<(const Lista<element> &l)
{
	return this->longitud<l.longitud;	
}
template <typename element>
bool Lista<element>::operator>(const Lista<element> &l)
{
	return this->longitud>l.longitud;
}
template <typename element>
void Lista<element>::operator+(const Lista<element> &l)
{
	Nodo<element> * aux;
	aux = l.primero;
	this->ultimo->setsiguiente(aux);
	this->ultimo = l.ultimo;
	this->longitud = this->longitud + l.longitud;
}
#endif
