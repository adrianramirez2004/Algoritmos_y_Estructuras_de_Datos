/*
El programa procesa una lista de nombres de participantes y simula un juego
dinámico de eliminación circular basado en condiciones matemáticas (pares/impares),
determinando finalmente un único ganador.
*/

#include<iostream>
#include "Lista.hpp"
#include "Cola.hpp"
#include "Pila.hpp"
#include "Nodo.hpp"

using namespace std;

// Prototipos de funciones
void brindis(Lista<string> list,int k,int p,int q);
void leerArchivo();
int main()
{
	leerArchivo();
	return 0;
}

/*
Lee y formatea los datos de entrada desde el estándar input (cin).
Procesa el número de casos, las constantes del juego (k, p, q) y parsea
los nombres de los participantes que vienen delimitados por comillas.
*/

void leerArchivo()
{
	int n, k, p, q;
	string nombre;
	Lista<string> list = Lista<string>();
	char aux;
	cin>>n>>k>>p>>q;
	cin>>aux;
	while(n != 0)
	{
		if(aux == '"')
		{
			aux = cin.get();
			while(aux != '"')
			{
				nombre.push_back(aux);
				aux = cin.get();
			}
			// Inserta el nombre al final de la lista de participantes
			list.insertar(nombre,list.getLongitud()+1);
			cout<<aux<<endl;
			nombre = "";
		}
		if(aux == '\n')
		{
			list.mostrar();
			brindis(list,k,p,q);
			list.vaciar();
			// Lectura de parámetros para el próximo ciclo
			cin>>k>>p>>q;
			cin>>aux;
			n--;
		}else
		{
			aux = cin.get();	// Avanza al siguiente carácter
		}
	}
}

/*
Ejecuta la simulación del juego de eliminación "Brindis".
Utiliza una lista auxiliar indexada para simular un comportamiento circular 
e invertido. Elimina nodos secuencialmente bajo saltos dinámicos (parámetros k, p, q)
hasta que quede un único elemento en la lista.

list Lista con los nombres de los participantes.
k Cantidad de saltos iniciales antes de la primera eliminación.
p Nuevos saltos a aplicar si el índice eliminado es par.
q Nuevos saltos a aplicar si el índice eliminado es impar.
*/
void brindis(Lista<string> list,int k,int p,int q)
{
	int i, longitud, aux;
	Lista<int> listAux = Lista<int>();
	i = 1;
	longitud = list.getLongitud();
	while(i <= longitud)
	{
		listAux.insertar(i,listAux.getLongitud()+1);
		i++;
	}
	i = 1;
	// Ciclo de eliminación: continúa hasta que solo quede 1 participante
	while(listAux.getLongitud() != 1)
	{
		// Condición: Se alcanzó el número de saltos 'k', se ejecuta eliminación
		if(i == k)
		{
			aux = listAux.consultar(1); // Obtiene el índice actual evaluado
			if(aux%2 == 0)
			{
				k = p;
			}else
			{
				k = q;
			}
			i = 1;
			listAux.eliminar(1); // Elimina al participante seleccionado

			// Simulación circular: Mueve el nuevo frente al final e invierte la lista
			listAux.insertar(listAux.consultar(1),listAux.getLongitud()+1);
			listAux.eliminar(1);
			listAux.invertir();
		}else
		{
			// Simulación circular: Pasa el elemento del frente al final
			listAux.insertar(listAux.consultar(1),listAux.getLongitud()+1);
			listAux.eliminar(1);
			i++;
		}
	}
	cout<<list.consultar(listAux.consultar(1))<<endl;
}
