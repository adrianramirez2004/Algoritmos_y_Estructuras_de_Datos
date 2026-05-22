#ifndef ARBOLN_HPP
#define ARBOLN_HPP
#include<iostream>
#include "NodoN.hpp"
#include "Lista.hpp"
#include "Cola.hpp"
#include "Pila.hpp"

using namespace std;
template<typename element>

class ArbolN{
	//Atributos
	private:
		int peso;
		NodoN<element> * raiz;
	//Metodos
	public:
		//Constructores
		ArbolN();
		ArbolN(int peso, NodoN<element> * raiz);
		void crearArbol(int n);
		//Getters
		int getPeso();
		NodoN<element> * getRaiz();
		//Setters
		void setPeso(int peso);
		void setRaiz(NodoN<element> * raiz);
		//Metodos
		void insertarNodo(element padre,element hijo,NodoN<element> * raiz);
		void leerArbol(int i, int n);
		bool esNulo();
		Lista<element> inOrden();
		Lista<element> postOrden();
		Lista<element> preOrden();
		Lista<element> porNiveles();
		void inOrden(NodoN<element> * raiz, Lista<element> &list);
		void postOrden(NodoN<element> * raiz, Lista<element> &list);
		void preOrden(NodoN<element> * raiz, Lista<element> &list);
		void mostrarPostOrden();
		void mostrarInorden();
		void mostrarPreOrden();
		void mostrarPorNiveles();
		//Operaciones
		int Buscar(Lista<int> l, int e);
		int balance();
		bool esHoja(NodoN<element> * raiz);
		int max(int sumaIncluyendo,int sumaExcluyendo);
		void MSI(NodoN<int> * raiz, int * sumaIncluyendo, int * sumaExcluyendo, Lista<int> list);
		int MSI(Lista<int> list);
};
template<typename element>
ArbolN<element>::ArbolN()
{
	this->peso = 0;
	this->raiz = NULL;
}
template<typename element>
ArbolN<element>::ArbolN(int peso, NodoN<element> * raiz)
{
	this->peso = peso;
	this->raiz = raiz;
}
template<typename element>
int ArbolN<element>::getPeso()
{
	return this->peso;
}
template<typename element>
NodoN<element> * ArbolN<element>::getRaiz()
{
	return this->raiz;
}
template<typename element>
void ArbolN<element>::setPeso(int peso)
{
	this->peso = peso;
}
template<typename element>
void ArbolN<element>::setRaiz(NodoN<element> * raiz)
{
	this->raiz = raiz;
}
template<typename element>
bool ArbolN<element>::esNulo()
{
	return this->raiz == NULL;
}
template<typename element>
Lista<element> ArbolN<element>::inOrden()
{
	Lista<element> list = Lista<element>();
	NodoN<element> * p;
	p = this->raiz;
	this->inOrden(p,list);
	return list;
}
template<typename element>
Lista<element> ArbolN<element>::postOrden()
{
	Lista<element> list = Lista<element>();
	NodoN<element> * p;
	p = this->raiz;
	this->postOrden(p,list);
	return list;
}
template<typename element>
Lista<element> ArbolN<element>::preOrden()
{
	Lista<element> list = Lista<element>();
	NodoN<element> * p;
	p = this->raiz;
	this->preOrden(p,list);
	return list;
}
template<typename element>
Lista<element> ArbolN<element>::porNiveles()
{
	Cola<NodoN<element> * > ColaAux= Cola<NodoN<element> * >();
	Lista<element> list = Lista<element>();
	NodoN<element> * hijo, * p;
	p = this->raiz;
	ColaAux.encolar(p);
	while(!ColaAux.esVacia())
	{
		hijo = ColaAux.getFrente()->getHijoIzq();
		while(hijo != NULL)
		{
			ColaAux.encolar(hijo);
			hijo = hijo->getHermanoDer();
		}
		list.insertar(ColaAux.getFrente()->getInfo(),list.getLongitud()+1);
		ColaAux.desencolar();
	}
	return list;
}
template<typename element>
void ArbolN<element>::inOrden(NodoN<element> * raiz, Lista<element> &list)
{
	NodoN<element> * hijo;
	if(raiz != nullptr)
	{
		this->inOrden(raiz->getHijoIzq(),list);
		list.insertar(raiz->getInfo(),list.getLongitud()+1);
		hijo = raiz->getHijoIzq();
		while(hijo != NULL)
		{
			hijo = hijo->getHermanoDer();
			this->inOrden(hijo,list);
		}
	}
}
template<typename element>
void ArbolN<element>::postOrden(NodoN<element> * raiz, Lista<element> &list)
{
	NodoN<element> * hijo;
	if(raiz != NULL)
	{
		hijo = raiz->getHijoIzq();
		while(hijo != NULL)
		{
			this->postOrden(hijo,list);
			hijo = hijo->getHermanoDer();
		}
		list.insertar(raiz->getInfo(),list.getLongitud()+1);
	}
}
template<typename element>
void ArbolN<element>::preOrden(NodoN<element> * raiz, Lista<element> &list)
{
	NodoN<element> * hijo;
	if(raiz != NULL)
	{
		list.insertar(raiz->getInfo(),list.getLongitud()+1);
		hijo = raiz->getHijoIzq();
		while(hijo != NULL)
		{
			this->preOrden(hijo,list);
			hijo = hijo->getHermanoDer();
		}
	}
}
template<typename element>
void ArbolN<element>::mostrarPostOrden()
{
	Lista<element> l = Lista<element>();
	l = this->postOrden();
	l.mostrar();
}
template<typename element>
void ArbolN<element>::mostrarInorden()
{
	Lista<element> l = Lista<element>();
	l = this->inOrden();
	l.mostrar();
}
template<typename element>
void ArbolN<element>::mostrarPreOrden()
{
	Lista<element> l = Lista<element>();
	l = this->preOrden();
	l.mostrar();
}
template<typename element>
void ArbolN<element>::mostrarPorNiveles()
{
	Lista<element> l = Lista<element>();
	l = this->porNiveles();
	l.mostrar();
}
template<typename element>
void ArbolN<element>::insertarNodo(element padre,element hijo,NodoN<element> * raiz)
{
	NodoN<element> * nuevoNodo, * hermanos;
	if(raiz != nullptr)
	{
		nuevoNodo = new (NodoN<element>);
        nuevoNodo->setInfo(hijo);
        nuevoNodo->setHijoIzq(nullptr);
        nuevoNodo->setHermanoDer(nullptr);
        if(raiz->getInfo() == padre)
        {
        	if(raiz->getHijoIzq() == nullptr)
        	{
        		raiz->setHijoIzq(nuevoNodo);
			}else
			{
				hermanos = raiz->getHijoIzq();
				while(hermanos->getHermanoDer() != nullptr)
				{
					hermanos = hermanos->getHermanoDer();
				}
				hermanos->setHermanoDer(nuevoNodo);
			}
			this->peso = this->peso + 1;
		}else
		{
			this->insertarNodo(padre,hijo,raiz->getHijoIzq());
            this->insertarNodo(padre,hijo,raiz->getHermanoDer());
		}
	}
}
template<typename element>
void ArbolN<element>::leerArbol(int i, int n)
{
	NodoN<element> * raiz;
	int u, v;
	raiz = new NodoN<element>;
	cin>>u>>v;
	raiz->setInfo(u);
	raiz->setHijoIzq(nullptr);
	raiz->setHermanoDer(nullptr);
	this->insertarNodo(u,v,raiz);
	while(i < n)
	{
		cin>>u>>v;
		this->insertarNodo(u,v,raiz);
		i++;
	}
	this->raiz = raiz;
}
template<typename element>
void ArbolN<element>::crearArbol(int n)
{
	int i = 1;
	this->leerArbol(i,n-1);
}
template<typename element>
int ArbolN<element>::balance()
{
	int par, impar, fin, i;
	NodoN<element> * hijo, * aux;
	Cola<NodoN<element> *> ColaAux = Cola<NodoN<element> *>();
	par = impar = 0;
	ColaAux.encolar(this->raiz);
	fin = ColaAux.getFrente()->getInfo();
	i = 0;
	while(!ColaAux.esVacia())
	{
		hijo = ColaAux.getFrente()->getHijoIzq();
		while(hijo != nullptr)
		{
			ColaAux.encolar(hijo);
			if(hijo->getHermanoDer() == nullptr)
			{
				aux = hijo;
			}
			hijo = hijo->getHermanoDer();
		}
		if(this->esHoja(ColaAux.getFrente()))
		{
			if(i%2 == 0)
			{
				par++;
			}else
			{
				impar++;
			}
		}
		if(fin == ColaAux.getFrente()->getInfo())
		{
			fin = aux->getInfo();
			i++;
		}
		ColaAux.desencolar();
	}
	return par - impar;
}
template<typename element>
bool ArbolN<element>::esHoja(NodoN<element> * raiz)
{
	return (raiz->getHijoIzq() == nullptr);
}
template<typename element>
int ArbolN<element>::max(int sumaIncluyendo,int sumaExcluyendo)
{
	if(sumaIncluyendo > sumaExcluyendo)
	{
		return sumaIncluyendo;
	}else
	{
		return sumaExcluyendo;
	}
}
template<typename element>
int ArbolN<element>::Buscar(Lista<int> l, int e)
{
	int pos;
	Lista<element> list = Lista<element>();
	list = this->porNiveles();
	pos = list.buscar(e);
	return l.consultar(pos);
}

template<typename element>
void ArbolN<element>::MSI(NodoN<int> * raiz, int * sumaIncluyendo, int * sumaExcluyendo, Lista<int> list)
{
    NodoN<int> * hijo;
    int inclHijo, exclHijo;

    if (raiz == nullptr)
    {
        *sumaIncluyendo = 0;
        *sumaExcluyendo = 0;
        return;
    }

    int valorNodo = this->Buscar(list, raiz->getInfo());

    // Caso hoja: incluirlo vale su valor, excluirlo vale 0
    if (raiz->getHijoIzq() == nullptr)
    {
        *sumaIncluyendo = valorNodo;
        *sumaExcluyendo = 0;
        return;
    }

    // Si incluimos este nodo: NO podemos incluir ningun hijo directo
    // aportamos excluyendo de cada hijo
    *sumaIncluyendo = valorNodo;

    // Si excluimos este nodo: tomamos el maximo (incl vs excl) de cada hijo
    *sumaExcluyendo = 0;

    hijo = raiz->getHijoIzq();
    while (hijo != nullptr)
    {
        this->MSI(hijo, &inclHijo, &exclHijo, list);
        *sumaIncluyendo += exclHijo;
        *sumaExcluyendo += this->max(inclHijo, exclHijo);
        hijo = hijo->getHermanoDer();
    }
}

// ---------------------------------------------------------------
// Funcion publica: devuelve el MSI del arbol completo
// ---------------------------------------------------------------
template<typename element>
int ArbolN<element>::MSI(Lista<int> list)
{
    int sumaIncluyendo = 0;
    int sumaExcluyendo = 0;
    NodoN<int> * raiz = this->raiz;
    this->MSI(raiz, &sumaIncluyendo, &sumaExcluyendo, list);
    return this->max(sumaIncluyendo, sumaExcluyendo);
}
#endif
