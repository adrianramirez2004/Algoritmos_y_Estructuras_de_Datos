#ifndef GRAFONODIRIGIDO_H_
#define GRAFONODIRIGIDO_H_
#include <list>
#include <vector>
#include "Grafo.hpp"

using namespace std;

template <typename element>
class GrafoNoDirigido: public Grafo<element>{
    public:
        list<element> vecinos(NodoVertice<element> * v);
        list<element> vecinos(element v);
        void modificarPesoArcoND(element v, element w, float nuevo);
        void agregarArcoND(element v, element w, float peso = 0);
        void eliminarArcoND(element v, element w);
        GrafoNoDirigido<int> mapear(vector<element> *mapeo);
        list<element> listaBFS(element inicio);
        list<element> listaDFS(element inicio);
        list<element> caminoMenor(element v, element w, float *peso = nullptr);
        list<element> caminoMenorConBloqueo(element v, element w, list<element> bloqueados, float *peso = nullptr);
        list<element> caminoMayor(element v, element w);
        list<list<element>> puentes();
        bool esConexo();
        list<list<element>> puentesM();
        bool esConexoM();
};

template<typename element>
list<element> GrafoNoDirigido<element>::vecinos(NodoVertice<element> * v){
    list<element> lista;
    NodoAdy<element> * arco;
    if(v!=nullptr){
        arco = v->getListaAdy();
        while (arco!=nullptr){
            lista.push_back(arco->getInfo()->getInfo());
            arco = arco->getProx();
        }
    }
    return lista;            
}

template<typename element>
list<element> GrafoNoDirigido<element>::vecinos(element v){
    return this->vecinos(this->getVertice(v));            
}

template <typename element>
void GrafoNoDirigido<element>::modificarPesoArcoND(element v, element w, float nuevo){
    this->setPesoArco(v,w,nuevo);
    this->setPesoArco(w,v,nuevo);
}

template <typename element>
void GrafoNoDirigido<element>::agregarArcoND(element v,element w, float peso){
    this->agregarArco(v,w,peso);
    this->agregarArco(w,v,peso);
}

template <typename element>
void GrafoNoDirigido<element>::eliminarArcoND(element v, element w){
    this->eliminarArco(v,w);
    this->eliminarArco(w,v);
}

template<typename element>
GrafoNoDirigido<int> GrafoNoDirigido<element>::mapear(vector<element> *mapeo){
    NodoVertice<element> * actual;
    int i, dim, v;
    GrafoNoDirigido<int> grafo = GrafoNoDirigido<int>();
    NodoAdy<element> * arco;
    i=0;
    dim=this->getNVertices();
    actual = this->getPrimero();
    while(actual != nullptr){
        mapeo->emplace_back(actual->getInfo());
        grafo.agregarVertice(i);
        actual = actual->getProx();
        i++;
    }
    actual = this->getPrimero();
    i=0;
    while(actual != nullptr){
        arco = actual->getListaAdy();
        while(arco != nullptr){
            v = this->buscar(*mapeo, dim, arco->getInfo()->getInfo());
            grafo.agregarArco(i,v, arco->getCosto());
            arco=arco->getProx();
        }
        actual=actual->getProx();
        i++;
    }
    return grafo;
}

template<typename element>
list<element> GrafoNoDirigido<element>::listaBFS(element inicio){
    list<element> recorrido;
    list<int> recorridoAux;
    vector<element> mapeo;
    vector<bool> visitados;
    GrafoNoDirigido<int> aux;
    int i, v;
    aux = this->mapear(&mapeo);
    v = this->buscar(mapeo,this->getNVertices(),inicio);
    for(i=0;i<this->getNVertices();i++){
        visitados.emplace_back(false);
    }
    visitados.at(v) = true;
    aux.BFS(v, visitados, recorridoAux);
    while(!recorridoAux.empty()){
        recorrido.push_back(mapeo.at(recorridoAux.front()));
        recorridoAux.pop_front();
    }
    return recorrido;

}

template<typename element>
list<element> GrafoNoDirigido<element>::listaDFS(element inicio){
    list<element> recorrido;
    list<int> recorridoAux;
    vector<element> mapeo;
    vector<bool> visitados;
    GrafoNoDirigido<int> aux = this->mapear(&mapeo);
    int i, v;
    v = this->buscar(mapeo, this->getNVertices(),inicio);
    for(i=0;i<this->getNVertices();i++){
        visitados.emplace_back(false);
    }
    visitados.at(v) = true;
    aux.DFS(v, visitados, recorridoAux);
    while(!recorridoAux.empty()){
        recorrido.push_back(mapeo.at(recorridoAux.front()));
        recorridoAux.pop_front();
    }
    return recorrido;
}

template <typename element>
list<element> GrafoNoDirigido<element>::caminoMenor(element v, element w, float * peso){
    vector<element> mapeo;
    GrafoNoDirigido<int> aux;
    int inicio, fin;
    list<int> camino;
    list<element> resultado;
    aux = this->mapear(&mapeo);
    inicio = this->buscar(mapeo, this->getNVertices(),v);
    fin = this->buscar(mapeo,this->getNVertices(),w);
    camino = aux.caminoDijkstra(inicio, fin, peso);
    while(!camino.empty()){
        resultado.push_back(mapeo[camino.front()]);
        camino.pop_front();
    }
    return resultado;
}

template <typename element>
list<element> GrafoNoDirigido<element>::caminoMayor(element v, element w){
    vector<element> mapeo;
    GrafoNoDirigido<int> aux;
    int inicio, fin, i;
    list<int> camino, caminoMayor;
    vector<bool> visitados;
    float peso, pesoMayor;
    bool primero = true;
    list<element> resultado;
    peso = 0;
    pesoMayor = -1;
    aux = this->mapear(&mapeo);
    inicio = this->buscar(mapeo,this->getNVertices(), v);
    fin = this->buscar(mapeo, this->getNVertices(),w);
    for(i=0;i<this->getNVertices();i++){
        visitados.emplace_back(false);
    }
    camino.push_back(inicio);
    aux.mayorCamino(inicio, fin, peso, &visitados, &camino, &pesoMayor, &caminoMayor, &primero);
    while(!caminoMayor.empty()){
        resultado.push_back(mapeo[caminoMayor.front()]);
        caminoMayor.pop_front();
    }
    return resultado;
}

template <typename element>
bool GrafoNoDirigido<element>::esConexo()
{
    vector<element> mapeo;
    vector<bool> visitados;
    int i;
    GrafoNoDirigido<int> g;
    g = this->mapear(&mapeo);
    for(i=0;i<this->getNVertices();i++)
	{
        visitados.emplace_back(false);
    }
    g.BFS(0, visitados);
    for(i=0;i<this->getNVertices();i++)
	{
        if(!visitados.at(i)) return false;
    }
    return true;
}

template<typename element>
list<list<element>> GrafoNoDirigido<element>::puentes(){
    list<list<element>> arcosPuente;
    list<element> arco;
    list<int> vecinos;
    float peso;
    int i,w;
    vector<element> m;
    GrafoNoDirigido<int> aux = this->mapear(&m);
    for (i=0; i<this->getNVertices(); i++)
	{ 
        vecinos = aux.vecinos(i);
        while(!vecinos.empty())
		{
            w = vecinos.front();
            peso = aux.getPesoArco(i,w);
            aux.eliminarArcoND(i,w);
            if((!aux.esConexoM()) && (i < w))
			{
                arco.clear();
                arco.push_back(m.at(i));
                arco.push_back(m.at(w));
                arcosPuente.push_back(arco);
            }
            aux.agregarArcoND(i,w,peso);
            vecinos.pop_front();
        }

    }
    return arcosPuente;
}
template<typename element>
list<list<element>> GrafoNoDirigido<element>::puentesM(){
    list<list<element>> arcosPuente;
    list<element> arco;
    list<int> vecinos;
    float peso;
    int i,w;
    for (i=0; i<this->getNVertices(); i++)
	{
        vecinos = this->vecinos(i);
        while(!vecinos.empty())
		{
            w = vecinos.front();
            peso = this->getPesoArco(i,w);
            this->eliminarArcoND(i,w);
            if((!this->esConexoM()) && (i<w))
			{
                arco.clear();
                arco.push_back(i);
                arco.push_back(w);
                arcosPuente.push_back(arco);
            }
            this->agregarArcoND(i,w, peso);
            vecinos.pop_front();
        }

    }
    return arcosPuente;
}

template <typename Tipo>
bool GrafoNoDirigido<Tipo>::esConexoM(){
    vector<bool> visitados;
    int i;
    for(i=0;i<this->getNVertices();i++){
        visitados.emplace_back(false);
    }
    this->BFS(0, visitados);
    for(i=0;i<this->getNVertices();i++){
        if(!visitados.at(i)) return false;
    }

    return true;
}

#endif
