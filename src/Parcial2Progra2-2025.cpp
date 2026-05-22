//Adrian Ramirez 30871139

/*
El programa procesa múltiples casos de prueba construyendo árboles dinámicos
a partir de secuencias de enteros en una lista, evaluando posteriormente 
propiedades estructurales como el Máximo Subconjunto Independiente (MSI) y el factor de balance.
*/
#include<iostream>
#include "Nodobin.hpp"
#include "Lista.hpp"
#include "Cola.hpp"
#include "Pila.hpp"
#include "Arbolbin.hpp"
#include "ArbolN.hpp"

using namespace std;

// Prototipos de funciones
int CHUPA(ArbolN<int> Arbol,Lista<int> list);
void leerArchivo();
int main()
{
	leerArchivo();
	return 0;
}

/*
Lee la cantidad de casos de prueba, el tamaño del árbol y los elementos
que se insertarán en la lista de datos para luego construir la estructura
*/
void leerArchivo()
{
	int casosPrueba, nNodos, i, numero, result;
	Lista<int> list = Lista<int>();
	ArbolN<int> Arbol = ArbolN<int>();
	cin>>casosPrueba;
	while(casosPrueba != 0)
	{
		cin>>nNodos;
		i = 1;
		while(i <= nNodos)
		{
			cin>>numero;
			list.insertar(numero,list.getLongitud()+1);
			i++;
		}
		// Construcción dinámica del Árbol Enario basado en el número de nodos
		Arbol.crearArbol(nNodos);
		cout<<CHUPA(Arbol,list)<<endl;
		// Liberación de memoria/elementos de la lista para el siguiente caso
		list.vaciar();
		casosPrueba--;
	}
}

/*
Calcula un indicador combinado basado en las propiedades del árbol.
Multiplica el resultado del Máximo Subconjunto Independiente (MSI) 
por el factor de balance del árbol n-ario para determinar la simetría y distribución.
Arbol Estructura de árbol n-ario ya construida y cargada.
list Lista de soporte con los datos asociados a los nodos.
int Producto resultante de las métricas MSI y Balance.
*/
int CHUPA(ArbolN<int> Arbol,Lista<int> list)
{
	return Arbol.MSI(list) * Arbol.balance();
}

