#ifndef GRAFODDIRIGIDO_H_
#define GRAFODDIRIGIDO_H_
#include <list>
#include <vector>
#include "Grafo.hpp"

using namespace std;
template <typename element>
class GrafoNoDirigido;
template <typename element>

class GrafoDirigido: public Grafo<element>{
	//Metodos
	public:
    	GrafoDirigido<int> mapear(vector<element> &mapeo);
		GrafoNoDirigido<element> convertirEnNoDirigido();
		list<element> listaBFS(element inicio);
    	list<element> listaDFS(element inicio);
};

template<typename element>
GrafoDirigido<int> GrafoDirigido<element>::mapear(vector<element> &mapeo)
{
	NodoVertice<element> * vertice;
    int i, n, v;
    GrafoDirigido<int> g = GrafoDirigido<int>();
    NodoAdy<element> * arco;
    vertice = this->primero;
    i = 0;
    n = this->getNVertices();
    while(vertice != nullptr){
        mapeo.emplace_back(vertice->getInfo());
        g.agregarVertice(i);
        vertice = vertice->getProx();
        i++;
    }
    vertice = this->primero;
    i = 0;
    while(vertice != nullptr){
        arco = vertice->getListaAdy();
        while(arco != nullptr){
            v = this->buscar(mapeo, arco->getInfo()->getInfo(), n);
            g.agregarArco(i,v, arco->getCosto());
            arco = arco->getProx();
        }
        vertice = vertice->getProx();
        i++;
    }
    return g;
}

template<typename element>
GrafoNoDirigido<element> GrafoDirigido<element>::convertirEnNoDirigido()
{
    GrafoNoDirigido<element> nuevo = GrafoNoDirigido<element>();
    nuevo.copiar(this); 
    return nuevo;
}

template<typename element>
list<element> GrafoDirigido<element>::listaBFS(element inicio){
    list<element> recorrido;
    list<int> recorridoAux;
    vector<element> mapeo;
    vector<bool> visitados;
    GrafoDirigido<int> g;
    int v, i, n;
    v = this->buscar(mapeo, inicio, this->getNVertices());
    g = this->mapear(mapeo);
    i = 0;
    n = this->getNVertices();
    while(i < n)
    {
    	visitados.emplace_back(false);
    	i++;
	}
    visitados[v] = true;
    g.BFS(v, visitados, recorridoAux);
    while(!recorridoAux.empty()){
        recorrido.push_back(mapeo[recorridoAux.front()]);
        recorridoAux.pop_front();
    }
    return recorrido;
}
template<typename element>
list<element> GrafoDirigido<element>::listaDFS(element inicio){
    list<element> recorrido;
    list<int> recorridoAux;
    vector<element> mapeo;
    vector<bool> visitados;
    GrafoDirigido<int> g;
    int v, i, n;
    v = this->buscarMapeo(mapeo, inicio, this->getNVertices());
    g = this->mapear(mapeo);
    i = 0;
    n = this->getNVertices();
    while(i < n)
    {
    	visitados.emplace_back(false);
    	i++;
	}
    visitados[v] = true;
    g.DFS(v, visitados, recorridoAux);
    while(!recorridoAux.empty()){
        recorrido.push_back(mapeo[recorridoAux.front()]);
        recorridoAux.pop_front();
    }
    return recorrido;
}

#endif
