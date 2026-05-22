#ifndef ARBOLBIN_HPP
#define ARBOLBIN_HPP
#include<iostream>
#include "Nodobin.hpp"
#include "Lista.hpp"
#include "Cola.hpp"
#include "Pila.hpp"
#include<cstdlib>

using namespace std;
template<typename element>

class ArbolBin{
	//Atributos
	private:
		int peso;
		NodoBin<element> * raiz;
	//Metodos
	private:
		NodoBin<element> * copiarNodos(NodoBin<element> * ptrNodo);
	public:
		//Constructores
		ArbolBin();
		ArbolBin(int peso, NodoBin<element> * raiz);
		void crearArbol();
		//Getters
		int getPeso();
		NodoBin<element> * getRaiz();
		//Setters
		void setPeso(int peso);
		void setRaiz(NodoBin<element> * raiz);
		//Opeaciones
		void copiar(ArbolBin<element>& arbol);
		void getHojas(NodoBin<element> * raiz, Lista<element>& result);
		Lista<element> getHojas();
		element getPadre(element e);
		bool esNulo();
		element obtRaiz();
		ArbolBin<element> hijoIzquierdo();
		ArbolBin<element> hijoDerecho();
		Lista<element> camino(element e1, element e2);
		void esAVL(NodoBin<element> * raiz,int * peso,bool * result);
		bool esAVL();
		bool esBinarioBusqueda();
		void LCA(NodoBin<element> * raiz, Pila<element> &Camino,bool * encontrado,element e);
		element LCA(element e1, element e2);
		void destruir();
		int calcularPeso(NodoBin<element> * raiz);
		int Distancia(element e1, element e2);
		int DistanciaNiveles(element e1, element e2);
		//recorridos
		void preOrden(NodoBin<element> * raiz, Lista<element>& result);
		Lista<element> preOrden();
		void postOrden(NodoBin<element> * raiz, Lista<element>& result);
		Lista<element> postOrden();
		void inorden(NodoBin<element> * raiz, Lista<element> &result);
		Lista<element> inorden();
		Lista<element> porNiveles();
		void mostrarPreOrden();
		void mostrarPostOrden();
		void mostrarInOrden();
		void mostrarPorNiveles();
		//Insertar y eliminar
		void insertar(element padre, element hijo, NodoBin<element> * raiz);
		void insertarNodo(element padre, element hijo);
		void insertarSubArbol(ArbolBin<element> Arbol);
		void eliminarSubArbol(int pos);
		//Leer Arbol
		NodoBin<element> * leerPreOrden(Lista<element> preOrden, Lista<element> inorden);
		NodoBin<element> * leerPostOrden(Lista<element> postOrden, Lista<element> inorden);
};
template<typename element>
NodoBin<element> * ArbolBin<element>::copiarNodos(NodoBin<element> * ptrNodo)
{
	NodoBin<element> * aux;
	aux = new NodoBin<element>;
	if(ptrNodo == NULL)
	{
		aux = NULL;
	}else
	{
		aux->setInfo(ptrNodo->getInfo());
		aux->setHijoIzq(ptrNodo->getHijoIzq());
		aux->setHijoDer(ptrNodo->getHijoDer());
	}
	return aux;
}
//CONSTRUCTORES
template<typename element>
ArbolBin<element>::ArbolBin()
{
	this->peso = 0;
	this->raiz = NULL;
}
template<typename element>
ArbolBin<element>::ArbolBin(int peso, NodoBin<element> * raiz)
{
	this->peso = peso;
	this->raiz = raiz;
}
//GETTERS
template<typename element>
int ArbolBin<element>::getPeso()
{
	return this->peso;
}
template<typename element>
NodoBin<element> * ArbolBin<element>::getRaiz()
{
	return this->raiz;
}
//SETTERS
template<typename element>
void ArbolBin<element>::setPeso(int peso)
{
	this->peso = peso;
}
template<typename element>
void ArbolBin<element>::setRaiz(NodoBin<element> * raiz)
{
	this->raiz = raiz;
}
//Operaciones
template<typename element>
void ArbolBin<element>::copiar(ArbolBin<element>& arbol)
{
	this->raiz = copiarNodos(arbol.raiz);
	this->peso = arbol.getPeso();
}
template<typename element>
void ArbolBin<element>::getHojas(NodoBin<element> * raiz, Lista<element>& result)
{
	if(raiz != NULL)
	{
		if(raiz->getHijoDer() == NULL && raiz->getHijoIzq() == NULL)
		{
			result.insertar(raiz->getInfo(), result.getLongitud()+1);
		}else
		{
			getHojas(raiz->getHijoIzq(),result);
			getHojas(raiz->getHijoDer(),result);
		}
	}
}
template<typename element>
Lista<element> ArbolBin<element>::getHojas()
{
	Lista<element> result = Lista<element>();
	NodoBin<element> * raiz;
	raiz = new (NodoBin<element>);
	raiz = this->raiz;
	this->getHojas(raiz,result);
	return result;
}
template<typename element>
element ArbolBin<element>::getPadre(element e)
{
	element result;
	bool band;
	NodoBin<element> * aux;
	Cola<NodoBin<element> *> ColaAux = Cola<NodoBin<element> *>();
	aux = new (NodoBin<element>);
	aux = this->raiz;
	ColaAux.encolar(aux);
	band = false;
	while(!ColaAux.esVacia() && !band)
	{
		aux = ColaAux.getFrente();
		if(aux->getHijoIzq()->getInfo() == e || aux->getHijoDer()->getInfo() == e)
		{
			result = aux->getInfo();
			band = true;
		}else
		{
			if(aux->getHijoIzq() != NULL)
			{
				ColaAux.encolar(aux->getHijoIzq());
			}
			if(aux->getHijoDer() != NULL)
			{
				ColaAux.encolar(aux->getHijoDer());
			}
		}
		ColaAux.desencolar();
	}
	return result;
}
template<typename element>
bool ArbolBin<element>::esNulo()
{
	bool result;
	result = this->raiz == NULL;
	return result;
}
template<typename element>
element ArbolBin<element>::obtRaiz()
{
	return this->raiz->getInfo();
}
template<typename element>
ArbolBin<element> ArbolBin<element>::hijoIzquierdo()
{
	ArbolBin<element> hijoIzq = ArbolBin<element>();
	if(this->raiz->getHijoIzq() != NULL)
	{
		hijoIzq.raiz = copiarNodos(this->raiz->getHijoIzq());
	}else
	{
		hijoIzq.raiz = NULL;
	}
	return hijoIzq;
}
template<typename element>
ArbolBin<element> ArbolBin<element>::hijoDerecho()
{
	ArbolBin<element> hijoDer = ArbolBin<element>();
	if(this->raiz->getHijoDer() != NULL)
	{
		hijoDer.raiz = copiarNodos(this->raiz->getHijoDer());
	}else
	{
		hijoDer.raiz = NULL;
	}
	return hijoDer;
}
template<typename element>
Lista<element> ArbolBin<element>::camino(element e1, element e2)
{
	Pila<element> Pila1 = Pila<element>(), Pila2 = Pila<element>(), Pila3 = Pila<element>();
	bool encontrado1, encontrado2;
	NodoBin<element> * aux1, * aux2;
	bool band; 
	element aux;
	Lista<element> result = Lista<element>();
	aux1 = new NodoBin<element>;
	aux2 = new NodoBin<element>;
	aux1 = aux2 = this->raiz;
	encontrado1 = false;
	encontrado2 = false;
	this->LCA(aux1,Pila1,&encontrado1,e1);
	this->LCA(aux2,Pila2,&encontrado2,e2);
	band = true;
	while(!Pila1.esVacia() && !Pila2.esVacia() && band)
	{
		if(Pila1.getTope() == Pila2.getTope())
		{
			aux = Pila1.getTope();
			Pila1.desapilar();
			Pila2.desapilar();	
		}else
		{
			band = false;
		}
	}
	while(!Pila1.esVacia())
	{
		result.insertar(Pila1.getTope(),1);
		Pila1.desapilar();
	}
	result.insertar(aux,result.getLongitud()+1);
	if(Pila2.esVacia() && e2 != aux)
	{
		result.insertar(e2,result.getLongitud()+1);
	}else
	{
		while(!Pila2.esVacia())
		{
			result.insertar(Pila2.getTope(),result.getLongitud()+1);
			Pila2.desapilar();
		}
	}
	return result;
}
template<typename element>
void ArbolBin<element>::esAVL(NodoBin<element> * raiz,int * peso,bool * result)
{
	int pesoIzquierda, pesoDerecha;
	bool band1, band2;
	if(raiz != NULL && *result)
	{
		pesoIzquierda = 0;
		pesoDerecha = 0;
		band1 = true;
		band2 = true;
		this->esAVL(raiz->getHijoIzq(),&pesoIzquierda,&band1);
		this->esAVL(raiz->getHijoDer(),&pesoDerecha,&band2);
		if(band1 && band2 && ((pesoIzquierda-pesoDerecha) >= -1) && ((pesoIzquierda-pesoDerecha) <= 1))
		{
			*result = true;
		}else
		{
			*result = false;
		}
		*peso = *peso + 1;
	}
}
template<typename element>
bool ArbolBin<element>::esAVL()
{
	bool result;
	int peso;
	NodoBin<element> * raiz;
	raiz = new NodoBin<element>;
	raiz = this->raiz;
	result = this->esBinarioBusqueda();
	if(result)
	{
		this->esAVL(raiz,&peso,&result);
	}
	return result;
}
template<typename element>
bool ArbolBin<element>::esBinarioBusqueda()
{
	bool band;
	int i;
	element aux;
	Lista<element> list = Lista<element>();
	list = this->inorden();
	band = true;
	i = 1;
	aux = list.consultar(1);
	list.eliminar(1);
	while(band && i < list.getLongitud())
	{
		if(aux > list.consultar(1))
		{
			band = false;
		}
		aux = list.consultar(1);
		list.eliminar(1);
		i++;
	}
	return band;
}
template<typename element>
void ArbolBin<element>::LCA(NodoBin<element> * raiz, Pila<element> &Camino,bool * encontrado,element e)
{
	if(raiz !=  NULL && !*encontrado)
	{
		if(raiz->getInfo() == e)
		{
			*encontrado = true;
			Camino.apilar(e);
		}else
		{
			this->LCA(raiz->getHijoIzq(),Camino,&*encontrado,e);
			this->LCA(raiz->getHijoDer(),Camino,&*encontrado,e);
			if(*encontrado)
			{
				Camino.apilar(raiz->getInfo());
			}
		}
	}
}
template<typename element>
element  ArbolBin<element>::LCA(element e1, element e2)
{
	Pila<element> Camino1 = Pila<element>(), Camino2 = Pila<element>();
	bool encontrado1, encontrado2, band;
	NodoBin<element> * aux1, * aux2;
	element result, aux;
	aux1 = new (NodoBin<element>);
	aux2 = new (NodoBin<element>);
	encontrado1 = false;
	encontrado2 = false;
	aux1 = aux2 = this->raiz;
	LCA(aux1,Camino1,&encontrado1,e1);
	LCA(aux2,Camino2,&encontrado2,e2);
	if(encontrado1 && encontrado2)
	{
		band = true;
		while(!Camino1.esVacia() && !Camino2.esVacia() & band)
		{
			band = Camino1.getTope() == Camino2.getTope();
			if(!band)
			{
				result = aux;
			}else
			{
				aux = Camino1.getTope();
				Camino1.desapilar();
				Camino2.desapilar();
			}
		}
		if(band)
		{
			result = aux;
		}
	}
	return result;
}
template<typename element>
void ArbolBin<element>::destruir()
{
	this->raiz = NULL;
	this->peso = 0;
	delete this;
}
template<typename element>
int ArbolBin<element>::calcularPeso(NodoBin<element> * raiz)
{
	Lista<element> list = Lista<element>();
	this->preOrden(raiz,list);
	return list.getLongitud();
}
//recorridos
template<typename element>
void ArbolBin<element>::preOrden(NodoBin<element> * raiz, Lista<element>& result)
{
	if(raiz != NULL)
	{
		result.insertar(raiz->getInfo(),result.getLongitud()+1);
		this->preOrden(raiz->getHijoIzq(),result);
		this->preOrden(raiz->getHijoDer(),result);
	}
}
template<typename element>
Lista<element> ArbolBin<element>::preOrden()
{
	Lista<element> result = Lista<element>();
	NodoBin<element> * aux;
	aux = new (NodoBin<element>);
	aux = this->raiz;
	this->preOrden(aux,result);
	return result;
}
template<typename element>
void ArbolBin<element>::postOrden(NodoBin<element> * raiz, Lista<element>& result)
{
	if(raiz != NULL)
	{
		this->postOrden(raiz->getHijoIzq(),result);
		this->postOrden(raiz->getHijoDer(),result);
		result.insertar(raiz->getInfo(),result.getLongitud()+1);
	}
}
template<typename element>
Lista<element> ArbolBin<element>::postOrden()
{
	Lista<element> result = Lista<element>();
	NodoBin<element> * aux;
	aux = new (NodoBin<element>);
	aux = this->raiz;
	this->postOrden(aux,result);
	return result;
}
template<typename element>
void ArbolBin<element>::inorden(NodoBin<element> * raiz, Lista<element> &result)
{
	if(raiz != NULL)
	{
		this->inorden(raiz->getHijoIzq(),result);
		result.insertar(raiz->getInfo(),result.getLongitud()+1);
		this->inorden(raiz->getHijoDer(),result);
	}
}
template<typename element>
Lista<element> ArbolBin<element>::inorden()
{
	Lista<element> result = Lista<element>();
	NodoBin<element> * aux;
	aux = new (NodoBin<element>);
	aux = this->raiz;
	this->inorden(aux,result);
	return result;
}
template<typename element>
Lista<element> ArbolBin<element>::porNiveles()
{
	Lista<element> result = Lista<element>();
	Cola<NodoBin<element> *> ColaAux = Cola<NodoBin<element> *>();
	NodoBin<element> * aux;
	aux = new (NodoBin<element>);
	aux = this->raiz;
	ColaAux.encolar(aux);
	while(!ColaAux.esVacia())
	{
		aux = ColaAux.getFrente();
		if(aux->getHijoIzq() != NULL)
		{
			ColaAux.encolar(aux->getHijoIzq());
		}
		if(aux->getHijoDer() != NULL)
		{
			ColaAux.encolar(aux->getHijoDer());
		}
		result.insertar(ColaAux.getFrente()->getInfo(),result.getLongitud()+1);
		ColaAux.desencolar();
	}
	return result;
}
template<typename element>
void ArbolBin<element>::mostrarPreOrden()
{
	Lista<element> result;
	result = this->preOrden();
	result.mostrar();
}
template<typename element>
void ArbolBin<element>::mostrarPostOrden()
{
	Lista<element> result;
	result = this->postOrden();
	result.mostrar();
}
template<typename element>
void ArbolBin<element>::mostrarInOrden()
{
	Lista<element> result = Lista<element>();
	result = this->inorden();
	result.mostrar();
}
template<typename element>
void ArbolBin<element>::mostrarPorNiveles()
{
	Lista<element> result;
	result = this->porNiveles();
	result.mostrar();
}
template<typename element>
void ArbolBin<element>::insertar(element padre, element hijo, NodoBin<element> * raiz)
{
	NodoBin<element> * nuevo;
	if(raiz != NULL)
	{
		nuevo = new (NodoBin<element>);
		nuevo->setInfo(hijo);
		nuevo->setHijoIzq(NULL);
		nuevo->setHijoDer(NULL);
		if(raiz->getInfo() == padre)
		{
			if(raiz->getHijoIzq() == NULL)
			{
				raiz->setHijoIzq(nuevo);
				this->peso = this->peso + 1;
			}else
			{
				if(raiz->getHijoDer() == NULL)
				{
					raiz->setHijoDer(nuevo);
					this->peso = this->peso + 1;
				}
			}
		}else
		{
			this->insertar(padre,hijo,raiz->getHijoIzq());
			this->insertar(padre,hijo,raiz->getHijoDer());
		}
	}
}
template<typename element>
void ArbolBin<element>::insertarNodo(element padre, element hijo)
{
	this->insertar(padre,hijo,this->raiz);
}
template<typename element>
void ArbolBin<element>::eliminarSubArbol(int pos)
{
	NodoBin<element> * aux;
	if(pos == 1)
	{
		this->peso = this->peso - this->calcularPeso(this->raiz->getHijoIzq());
		this->raiz->setHijoIzq(this->raiz->getHijoDer());
		this->raiz->setHijoDer(NULL);
	}else
	{
		this->peso = this->peso - this->calcularPeso(this->raiz->getHijoDer());
		this->raiz->setHijoDer(NULL);
	}
}
template<typename element>
void ArbolBin<element>::insertarSubArbol(ArbolBin<element> Arbol)
{
	if(this->raiz->getHijoIzq() == NULL)
	{
		this->raiz->setHijoIzq(this->copiarNodos(Arbol.getRaiz()));
	}else
	{
		if(this->raiz->getHijoDer() == NULL)
		{
			this->raiz->setHijoDer(this->copiarNodos(Arbol.getRaiz()));
		}
	}
}
template<typename element>
NodoBin<element> * ArbolBin<element>::leerPreOrden(Lista<element> preOrden, Lista<element> inorden)
{
	NodoBin<element> * r;
	Lista<element> preIzq = Lista<element>(), inIzq = Lista<element>(), preDer = Lista<element>(), inDer = Lista<element>();
	if(!preOrden.esVacia())
	{
		r = new (NodoBin<element>);
		r->setInfo(preOrden.consultar(1));
		preOrden.eliminar(1);
		while(r->getInfo() != inorden.consultar(1))
		{
			preIzq.insertar(preOrden.consultar(1), preIzq.getLongitud()+1);
			inIzq.insertar(inorden.consultar(1),inIzq.getLongitud()+1);
			preOrden.eliminar(1);
			inorden.eliminar(1);
		}
		inorden.eliminar(1);
		while(!inorden.esVacia())
		{
			preDer.insertar(preOrden.consultar(1),preDer.getLongitud()+1);
			inDer.insertar(inorden.consultar(1),inDer.getLongitud()+1);
			preOrden.eliminar(1);
			inorden.eliminar(1);
		}
		r->setHijoIzq(this->leerPreOrden(preIzq,inIzq));
		r->setHijoDer(this->leerPreOrden(preDer,inDer));
		return r;
	}else
	{
		return NULL;
	}
}
template<typename element>
NodoBin<element> * ArbolBin<element>::leerPostOrden(Lista<element> postOrden, Lista<element> inorden)
{
	NodoBin<element> * raiz;
	Lista<element> postIzq = Lista<element>(), inIzq = Lista<element>(), postDer = Lista<element>(), inDer = Lista<element>();
	if(!postOrden.esVacia())
	{
		raiz = new (NodoBin<element>);
		raiz->setInfo(postOrden.consultar(postOrden.getLongitud()));
		postOrden.eliminar(postOrden.getLongitud());
		while(raiz->getInfo() != inorden.consultar(1))
		{
			postIzq.insertar(postOrden.consultar(1), postIzq.getLongitud()+1);
			inIzq.insertar(inorden.consultar(1),inIzq.getLongitud()+1);
			postOrden.eliminar(1);
			inorden.eliminar(1);
		}
		inorden.eliminar(1);
		while(!inorden.esVacia())
		{
			postDer.insertar(postOrden.consultar(1),postDer.getLongitud()+1);
			inDer.insertar(inorden.consultar(1),inDer.getLongitud()+1);
			postOrden.eliminar(1);
			inorden.eliminar(1);
		}
		raiz->setHijoIzq(this->leerPostOrden(postIzq,inIzq));
		raiz->setHijoDer(this->leerPostOrden(postDer,inDer));
		return raiz;
	}else
	{
		return NULL;
	}
}
template<typename element>
void ArbolBin<element>::crearArbol()
{
	Lista<element> list = Lista<element>();
	Lista<element> ListaAux = Lista<element>();
	Lista<Lista<element> > l = Lista<Lista<element> >();
	element name, tipo;
	char aux;
	int i;
	i = 2;
	while(i != 0)
	{
		cin>>tipo>>name;
		ListaAux.insertar(tipo,ListaAux.getLongitud()+1);
		list.insertar(name,list.getLongitud()+1);
		aux = cin.get();
		while(aux != '\n')
		{
			cin>>name;
			list.insertar(name,list.getLongitud()+1);
			aux = cin.get();
		}
		l.insertar(list,l.getLongitud()+1);
		list.vaciar();
		i--;
	}
	if(ListaAux.consultar(1) == "PREORDEN")
	{
		this->setRaiz(this->leerPreOrden(l.consultar(1),l.consultar(2)));
	}else
	{
		if(ListaAux.consultar(1) == "POSTORDEN")
		{
			this->setRaiz(this->leerPostOrden(l.consultar(1),l.consultar(2)));
		}else
		{
			if(ListaAux.consultar(2) == "PREORDEN")
			{
				this->setRaiz(this->leerPreOrden(l.consultar(2),l.consultar(1)));
			}else
			{
				this->setRaiz(this->leerPostOrden(l.consultar(2),l.consultar(1)));
			}
		}
	}
}
template<typename element>
int ArbolBin<element>::Distancia(element e1, element e2)
{
	Lista<element> l = Lista<element>();
	int cont;
	l = this->camino(e1,e2);
	return l.getLongitud() - 1;
}
template<typename element>
int ArbolBin<element>::DistanciaNiveles(element e1, element e2)
{
	Pila<element> Camino1 = Pila<element>(), Camino2 = Pila<element>();
	bool encontrado1, encontrado2;
	NodoBin<element> * aux1, * aux2;
	aux1 = aux2 = new (NodoBin<element>);
	encontrado1 = false;
	encontrado2 = false;
	aux1 = aux2 = this->raiz;
	LCA(aux1,Camino1,&encontrado1,e1);
	LCA(aux2,Camino2,&encontrado2,e2);
	return abs(Camino1.getLongitud()-Camino2.getLongitud());
}
#endif
