#ifndef GRAFO_H_
#define GRAFO_H_
#include <list>
#include <queue>
#include <vector>
#include "NodoVertice.hpp"
#include "NodoAdy.hpp"

using namespace std;
template <typename element>

class Grafo{
	//Atributos
	private:
		int nVertices, nArcos;
		NodoVertice<element> * primero;
	//Metodos
	public:
		//Constructores
		Grafo();
		Grafo(int nNodos, int nArcos, NodoVertice<element> * primero);
		//Setters y Getters
		int getNVertices();
		int getNArcos();
		NodoVertice<element> * getPrimero();
		void setNVertices(int nNodos);
		void setNArcos(int nArcos);
		void setPrimero(NodoVertice<element> * primero);
		//Operaciones
		NodoVertice<element> * getVertice(element v);
		list<element> sucesores(NodoVertice<element> * v);
		list<element> sucesores(element v);
		list<element> predecesores(NodoVertice<element> * v);
		list<element> predecesores(element v);
		list<element> vertices();
		bool esVacia();
		bool existeArco(element v, element w);
		float getPesoArco(element v, element w);
		void setPesoArco(element v, element w, float peso);
		void agregarVertice(element v);
		void eliminarVertice(element v);
		void mostrar();
		void BFS(int v, vector<bool> &visitados, list<int> &recorrido);
		void DFS(int v, vector<bool> &visitados, list<int> &recorrido);
		bool esGrafoCompleto();
		int buscar(vector<element> vec, int n, element v);
		void agregarArco(element v, element w, float peso);
		void eliminarArco(element v, element w);
		float sumaPeso();
		void copiar(Grafo<element> &A);
		list<int> caminoDijkstra(int v, int w, float *peso = nullptr);
        list<int> caminoObstaculos(int v, int w, vector<bool> obstaculos, float *peso = nullptr);
        void mayorCamino(int v, int w, float peso, vector<bool> *visitados, list<int> *camino, float *pesoMayor, list<int> *caminoMayor, bool *prim);
        void BFS(int v, vector<bool> &visitados);
};

//Constructores
template <typename element>
Grafo<element>::Grafo()
{
	this->primero = nullptr;
	this->nArcos = 0;
	this->nVertices = 0;
}

template <typename element>
Grafo<element>::Grafo(int nNodos, int nArcos, NodoVertice<element> * primero)
{
	this->primero = primero;
	this->nArcos = nArcos;
	this->nVertices = nNodos;
}
//Setters y Getters
template <typename element>
int Grafo<element>::getNVertices()
{
	return this->nVertices;
}

template <typename element>
int Grafo<element>::getNArcos()
{
	return this->nArcos;
}

template<typename element>
void Grafo<element>::copiar(Grafo<element> &A){
	float peso;
    NodoVertice<element> * vertice;
    NodoAdy<element> * arco;
    vertice = A.getPrimero();
    while(vertice != nullptr){
        this->agregarVertice(vertice->getInfo());
        vertice = vertice->getSig();
    }
    vertice = A.getPrimero();
    while(vertice != nullptr){
        arco = vertice->getListaAdy();
        while(arco != nullptr){
            peso = arco->getCosto();
            this->agregarArco(vertice->getInfo(), arco->getInfo()->getInfo(), peso);
            arco = arco->getProx();
        }
        vertice = vertice->getSig();
    }
}

template <typename element>
NodoVertice<element> * Grafo<element>::getPrimero()
{
	return this->primero;
}

template <typename element>
void Grafo<element>::setNVertices(int nNodos)
{
	this->nVertices = nVertices;
}

template <typename element>
void Grafo<element>::setNArcos(int nArcos)
{
	this->nArcos = nArcos;
}

template <typename element>
void Grafo<element>::setPrimero(NodoVertice<element> * primero)
{
	this->primero = primero;
}
//Operaciones
template <typename element>
NodoVertice<element> * Grafo<element>::getVertice(element v)
{
	NodoVertice<element> * aux, * result;
	bool band;
	band = false;
	result = new NodoVertice<element>;
	result = nullptr;
	aux = this->primero;
	while(aux != nullptr && !band)
	{
		if(aux->getInfo() == v)
		{
			band = true;
			result = aux;
		}else
		{
			aux = aux->getProx();
		}
	}
	return result;
}

template <typename element>
list<element> Grafo<element>::sucesores(NodoVertice<element> * v)
{
	list<element> l;
	NodoAdy<element> * aux;
	if(v != nullptr)
	{
		aux = v->getListaAdy();
		while(aux != nullptr)
		{
			l.push_back(aux->getInfo()->getInfo());
			aux = aux->getProx();
		}
	}
	return l;
}

template <typename element>
list<element> Grafo<element>::sucesores(element v)
{
	return sucesores(this->getVertice(v));
}

template <typename element>
list<element> Grafo<element>::predecesores(NodoVertice<element> * v)
{
	NodoAdy<element> * aux;
	NodoVertice<element> * vertices;
	list<element> l;
	if(v != nullptr)
	{
		vertices = this->primero;
		while(vertices != nullptr)
		{
			if(vertices != v)
			{
				aux = vertices->getListaAdy();
				while(aux != nullptr)
				{
					if(aux->getInfo->getInfo() == v->getInfo())
					{
						l.push_back(vertices->getInfo());
					}
					aux = aux->getProx();
				}
			}
			vertices = vertices->getProx();
		}
	}
	return l;
}

template <typename element>
list<element> Grafo<element>::predecesores(element v)
{
	return predecesores(this->getVertice(v));
}

template <typename element>
list<element> Grafo<element>::vertices()
{
	list<element> l;
	NodoVertice<element> * aux;
	aux = this->primero;
	while(aux != nullptr)
	{
		l.push_back(aux->getInfo());
		aux = aux->getProx();
	}
	return l;
}

template <typename element>
bool Grafo<element>::esVacia()
{
	return this->primero == nullptr;
}

template <typename element>
bool Grafo<element>::existeArco(element v, element w)
{
	NodoAdy<element> * arco;
	NodoVertice<element> * vertice;
	bool result;
	result = false;
	vertice = this->getVertice(v);
	if(vertice != nullptr)
	{
		arco = vertice->getListaAdy();
		while(arco != nullptr && !result)
		{
			if(arco->getInfo()->getInfo() == w)
			{
				result = true;
			}
			arco = arco->getProx();
		}
	}
	return result;
}

template <typename element>
float Grafo<element>::getPesoArco(element v, element w)
{
	float result;
	bool band;
	NodoVertice<element> * vertice;
	NodoAdy<element> * arco;
	vertice = this->getVertice(v);
	result = -1;
	band = false;
	if(vertice != nullptr)
	{
		arco = vertice->getListaAdy();
		while((arco != nullptr) && (arco->getInfo()->getInfo() != w))
		{
			arco = arco->getProx();
		}
		if(arco != nullptr)
		{
			result = arco->getCosto();
		}
	}
	return result; 
}

template <typename element>
void Grafo<element>::setPesoArco(element v, element w, float peso)
{
	NodoAdy<element> * arco;
	NodoVertice<element> * vertice;
	vertice = this->primero;
	if(vertice != nullptr)
	{
		arco = vertice->getListaAdy();
		while(arco != nullptr && arco->getInfo()->getInfo() != w)
		{
			arco = arco->getProx();
		}
		if(arco != nullptr)
		{
			arco->setCosto(peso);
		}
	}
}

template <typename element>
void Grafo<element>::agregarVertice(element v)
{
	NodoVertice<element> * aux, * prim;
	aux = new NodoVertice<element>;
	prim = this->primero;
	if(this->getVertice(v) == nullptr)
	{
		aux->setInfo(v);
		aux->setProx(this->primero);
		aux->setListaAdy(nullptr);
		this->primero = aux;
		this->nVertices = this->nVertices + 1;
	}
}

template <typename element>
void Grafo<element>::eliminarVertice(element v)
{
	NodoVertice<element> * prim, * vertice;
    list<element> l;
    prim = this->primero;
    vertice = nullptr;
    if(prim != nullptr){
        l = this->sucesores(v);
        while(!l.empty()){
            this->eliminarArco(v,l.front());
            l.pop_front();
        }
        l = this->predecesores(v);
        while(!l.empty()){
            this->eliminarArco(l.front(),v);
            l.pop_front();
        }
        if(prim->getInfo() == v){
            vertice = prim;
            this->primero = vertice->getSig();
            vertice->setSig(nullptr);
        }else{
            while((prim->getSig() != nullptr) && (prim->getSig()->getInfo() != v)){
                prim = prim->getSig();
            }
            vertice = prim->getSig();
            if(vertice == nullptr) return;
            prim->setSig(vertice->getSig());
            vertice->setSig(nullptr);
        }
        delete vertice;
        this->nVertices = this->nVertices - 1;
    }
}

template <typename element>
void Grafo<element>::mostrar()
{
	NodoAdy<element> * arco;
	NodoVertice<element> * vertice;
	vertice = this->primero;
	while(vertice != nullptr)
	{
		arco = vertice->getListaAdy();
		while(arco != nullptr)
		{
			cout<<vertice->getInfo()<<" "<<arco->getInfo()->getInfo()<<" "<<this->getPesoArco(vertice->getInfo(),arco->getInfo()->getInfo())<<endl;
			arco = arco->getProx();
		}
		vertice = vertice->getProx();
	}
}

template <typename element>
void Grafo<element>::BFS(int v, vector<bool> &visitados, list<int> &recorrido)
{
	queue<int> cola;
    list<int> vecinos;
    int w;
    cola.push(v);
    if(!visitados.empty())
	{
        visitados[v] = true;
        while(!cola.empty())
		{
            v = cola.front();
            vecinos = this->sucesores(v);
            while(!vecinos.empty())
			{
                w = vecinos.front();
                if(!visitados[w])
				{
                    visitados[w] = true;
                    cola.push(w);
                }
                vecinos.pop_front();
            }
            cola.pop();
        }
    }
}

template <typename element>
void Grafo<element>::DFS(int v, vector<bool> &visitados, list<int> &recorrido)
{
	queue<int> cola;
    list<int> vecinos;
    int w;
    cola.push(v);
    if(!visitados.empty()){
        visitados[v] = true;
        while(!cola.empty()){
            v = cola.front();
            recorrido.push_back(v);
            vecinos = this->sucesores(v);
            while(!vecinos.empty()){
                w = vecinos.front();
                if(!visitados[w]){
                    visitados[w] = true;
                    cola.push(w);
                }
                vecinos.pop_front();
            }
            cola.pop();
        }
    }
    return;
}

template <typename element>
bool Grafo<element>::esGrafoCompleto()
{
	return (this->nArcos == (this->nVertices * (this->nVertices - 1)));
}

template <typename element>
int Grafo<element>::buscar(vector<element> vec, int n, element v)
{
	int i, result;
	bool band;
	result = -1;
	band = false;
    i = 0;
    while(i < n && !band)
    {
    	if(vec[i] == v)
    	{
    		band = true;
    		result = i;
		}
    	i++;
	}
	return result;
}

template <typename element>
void Grafo<element>::agregarArco(element v, element w, float peso)
{
	NodoVertice<element> * prim, * vertice, * verticeLlegada;
	NodoAdy<element> * nuevo, * arco;
	prim = this->primero;
	if(prim != nullptr)
	{
		vertice = this->getVertice(v);
		verticeLlegada = this->getVertice(w);
		if(vertice != nullptr && verticeLlegada != nullptr)
		{
			arco = vertice->getListaAdy();
			nuevo = new NodoAdy<element>;
			nuevo->setProx(nullptr);
			nuevo->setCosto(peso);
			nuevo->setInfo(verticeLlegada);
			if(arco == nullptr)
			{
				vertice->setListaAdy(nuevo);
			}else
			{
				while(arco->getProx() != nullptr)
				{
					arco = arco->getProx();
				}
				arco->setProx(nuevo);
			}
			this->setNArcos(this->nArcos+1);
		}
	}
}

template <>
void Grafo<int>::BFS(int v, vector<bool> &visitados){
    queue<int> cola;
    list<int> vecinos;
    int w;
    cola.push(v);
    if(!visitados.empty()){
        visitados.at(v) = true;
 
        while(!cola.empty()){
            v=cola.front();
            vecinos = this->sucesores(v);
            while(!vecinos.empty()){
                w = vecinos.front();
                if(!visitados.at(w)){
                    visitados.at(w) = true;
                    cola.push(w);
                }
                vecinos.pop_front();
            }
            cola.pop();
        }
    }
    return;
}

template <typename element>
void Grafo<element>::eliminarArco(element v, element w)
{
	NodoVertice<element> * prim, * verticeInicio, * verticeLlegada;
	NodoAdy<element> * arcoEliminar, * arco;
	prim = this->primero;
	if(prim != nullptr && this->existeArco(v,w))
	{
		verticeInicio = this->getVertice(v);
		arco = verticeInicio->getListaAdy();
		if(arco->getInfo()->getInfo() == w)
		{
			verticeInicio->setListaAdy(nullptr);
			delete arco;
		}else
		{
			while(arco->getProx()->getInfo()->getInfo() != w)
			{
				arco = arco->getProx();
			}
			arcoEliminar = arco->getProx();
			arco->setProx(arcoEliminar->getProx());
			arcoEliminar->setProx(nullptr);
			delete arcoEliminar;
		}
		this->setNArcos(this->nArcos-1);
	}
}

template <typename element>
float Grafo<element>::sumaPeso()
{
	float result;
	list<element> l;
	Grafo<element> g = Grafo<element>();
	result = 0;
	g.copiar(this);
	while(!g.esVacia())
	{
		l = g.sucesores(g.primero->getInfo());
		while(!l.empty())
		{
			result = result + g.getPesoArco(g.primero->getInfo(),l.front());
			l.pop_front();
		}
		g.eliminarVertice(g.primero->getInfo());
	}
	return result;
}

template <>
list<int> Grafo<int>::caminoDijkstra(int v, int w, float *peso){
    vector<float> costos;
    vector<int> camino;
    list<int> resultado, vecinos;
    queue<int> cola;
    int i, actual, destino;
    float costo; 

    for(i=0;i<this->getNVertices();i++){
        costos.push_back(-1);
        camino.push_back(-1);
    }
    if((v<this->getNVertices()) && (w<this->getNVertices())){
        costos.at(v) = 0;
        cola.push(v);
        while(!cola.empty()){
            actual=cola.front();
            vecinos = this->sucesores(actual);
            while(!vecinos.empty()){
                destino = vecinos.front();
                if(camino.at(actual) == -1){
                    costo=costos.at(actual) + this->getPesoArco(actual,destino);
                }
                else{
                    costo=costos.at(camino.at(actual)) + this->getPesoArco(camino.at(actual), actual) + this->getPesoArco(actual,destino);
                }
                if((costo<costos.at(destino)) || (costos.at(destino) == -1)){
                    costos.at(destino) = costo;
                    camino.at(destino) = actual;
                    cola.push(destino);
                }
                vecinos.pop_front();
            }
            cola.pop();
        }
        if(camino.at(w) != -1){
            if (peso != nullptr){
                *peso = costos.at(w);
            }
            resultado.push_back(w);
            actual = w;
            while((actual != v) && (actual != -1)){
                actual = camino.at(actual);
                resultado.push_front(actual);
            }
        }
    }
    return resultado;
}


template <>
list<int> Grafo<int>::caminoObstaculos(int v, int w, vector<bool> obstaculos, float *peso){
    vector<float> costos;
    vector<int> camino;
    list<int> resultado, vecinos;
    queue<int> cola;
    int i, actual, destino;
    float costo; 

    for(i=0;i<this->getNVertices();i++){
        costos.push_back(-1);
        camino.push_back(-1);
    }
    if((v<this->getNVertices()) && (w<this->getNVertices())){
        costos.at(v) = 0;
        cola.push(v);
        while(!cola.empty()){
            actual=cola.front();
            vecinos = this->sucesores(actual);
            while(!vecinos.empty()){
                destino = vecinos.front();
                if(!obstaculos.at(destino)){
                    if(camino.at(actual) == -1){
                        costo=costos.at(actual) + this->getPesoArco(actual,destino);
                    }
                    else{
                        costo=costos.at(camino.at(actual)) + this->getPesoArco(camino.at(actual), actual) + this->getPesoArco(actual,destino);
                    }
                    if((costo<costos.at(destino)) || (costos.at(destino) == -1)){
                        costos.at(destino) = costo;
                        camino.at(destino) = actual;
                        cola.push(destino);
                    }
                }
                vecinos.pop_front();
            }
            cola.pop();
        }
        if(camino.at(w) != -1){
            if (peso != nullptr){
                *peso = costos.at(w);
            }
            resultado.push_back(w);
            actual = w;
            while((actual != v) && (actual != -1)){
                actual = camino.at(actual);
                resultado.push_front(actual);
            }
        }
    }
    return resultado;
}


template<>
void Grafo<int>::mayorCamino(int v, int w, float peso, vector<bool> *visitados, list<int> *camino, float *pesoMayor, list<int> *caminoMayor, bool *prim){
    list<int> vecinos = this->sucesores(v);
    int sig;
    while(!vecinos.empty()){
        sig = vecinos.front();
        if(!visitados->at(sig)){
            visitados->at(sig) = true;
            peso = peso + this->getPesoArco(v,sig);
            camino->push_back(sig);
            if ((sig == w) && ((peso > *pesoMayor) || *prim)){
                *caminoMayor = *camino;
                *pesoMayor = peso;
                *prim = false;
            }
            this->mayorCamino(sig,w,peso,visitados, camino, pesoMayor, caminoMayor, prim);
            camino->pop_back();
            peso = peso - this->getPesoArco(v, sig);
            visitados->at(sig) = false;
        }
        vecinos.pop_front();
    }
}
#endif
