//Adrian Ramirez 30871139
#include<iostream>
#include <list>
#include <queue>
#include <vector>
#include "Grafo.hpp"
#include "GrafoDirigido.hpp"
#include "GrafoNoDirigido.hpp"

using namespace std;

// Prototipos de funciones 
void guardar_soluc(list<int> &lista, list<int> &soluc); 
bool esValido(list<int> vecinos, vector<bool> visitados);
void guadarEnLaLista(list<int> &aux, list<int> vecinos, int num);
void leerArchivo();
void buscarOtraSoluc(GrafoNoDirigido<int> g, vector<string> vec, vector<bool> visitados, int * cont, list<string> &l,int inicio);

int main()
{
	// Inicia el procesamiento del grafo
	leerArchivo();
	return 0;
}

// Función para respaldar/actualizar la mejor solución encontrada hasta el momento
void guardar_soluc(list<string> &lista, list<string> &soluc)
{
	// Vacía la lista de solución previa
	while(!soluc.empty())
	{
		soluc.pop_front();	
	}
	// Pasa los elementos de la lista actual a la lista de solución final
	while(!lista.empty())
	{
		soluc.push_front(lista.front());
		lista.pop_front();
	}
}

// Función booleana que verifica si alguno de los nodos vecinos ya fue visitado
bool esValido(list<int> vecinos, vector<bool> visitados)
{
	bool result;
	result = true;
	// Recorre la lista de vecinos validando su estado en el vector de visitas
	while(!vecinos.empty() && result)
	{
		if(visitados[vecinos.front()])
		{
			result  = false; // Si un vecino ya fue visitado, rompe el ciclo e invalida
		}
		vecinos.pop_front();
	}
	return result;
}

// Función principal de carga, mapeo de datos y ordenamiento del grafo
void leerArchivo()
{
	GrafoNoDirigido<string> grafo = GrafoNoDirigido<string>();
	GrafoNoDirigido<int> grafoMapeado = GrafoNoDirigido<int>();
	string name1, name2;
	vector<string> vec;
	
	// Lectura de pares de nodos (aristas) e inserción en el grafo de strings
	while(cin>>name1)
	{
		cin>>name2;
		grafo.agregarVertice(name1);
		grafo.agregarVertice(name2);
		grafo.agregarArcoND(name1,name2,0);
	}
	
	// Convierte/mapea el grafo de strings a enteros para agilizar los algoritmos
	grafoMapeado = grafo.mapear(&vec);
	int mayor, cont, i;
	list<string> soluc, l;
	vector<bool> visitados;	
	mayor = 0;
	
	// Inicialización del vector de control de visitas en falso
	for(i=0;i<vec.size();i++)
	{
		visitados.push_back(false);
	}
	i = 0;
	
	// Bucle para evaluar soluciones máximas comenzando secuencialmente desde cada nodo
	while(i < vec.size())
	{
		cont = 1;
		buscarOtraSoluc(grafoMapeado,vec, visitados,&cont, l, i);
		// Si la cantidad de nodos de la nueva solución supera al mayor récord, se actualiza
		if(cont > mayor)
		{
			mayor = cont;
			guardar_soluc(l,soluc);
		}
		i++;
	}
	
	// Ordenamiento alfabético de la solución final antes de imprimir
	soluc.sort();
	while(!soluc.empty())
	{
		cout<<soluc.front()<<" ";
		soluc.pop_front();
	}
}

// Algoritmo de exploración para buscar caminos/subgrafos válidos alternativos
void buscarOtraSoluc(GrafoNoDirigido<int> g, vector<string> vec, vector<bool> visitados, int * cont, list<string> &l,int inicio)
{
	list<int> vecinos;
	int i, t;
	l.push_back(vec[inicio]);
	visitados[inicio] = true; 
	i = 0;
	
	// Evalúa la adyacencia e incorpora nodos si cumplen el criterio de vecindad válida
	while(i < vec.size())
	{
		vecinos = g.vecinos(i);
		if(esValido(vecinos,visitados) && !visitados[i])
		{
			visitados[i] = true;
			*cont = *cont + 1; // Incrementa el contador global por referencia
			l.push_back(vec[i]);
		}
		i++;
	}
}
