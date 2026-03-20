/**
 * Grafo.h
 * Directed graph of airports (vertices) and flights (edges).
 * Implements Dijkstra for shortest path by duration or cost.
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <list>

#include "Vertice.h"
#include "Cola.h"

#define INF 999999
#define MAX_V 50

using namespace std;

class Grafo{

private:
	//atributos
	list<Vertice*> lista_vertices;
	Cola<Vertice*> cola_prioridad;
	float distancia[MAX_V];
	int previo[MAX_V];
	int tam;

	//metodos
	//Inicia las variables de dijkstra.
	void iniciar(float distancia[], bool visitado[], int previo[]);
	//compara un vertice con su adyacente para calculo de camino minimo.
	void comparacion(Vertice*, Vertice*, float &);


public:
	/*
	 * PRE: -
	 * POST: Genera un grafo vacio
	 */
	Grafo();

	/*
	 * PRE: Existe el grafo
	 * POST: Nodo es un valor valido
	 */
	bool existe_vertice(string);

	/*
	 * PRE: Existe el grafo, la arista no esta previamente y existan en el grafo los nodos de origen y destino
	 * POST: El grafo queda modificado por el agregado de una nueva arista
	 */
	void insertar_arista(Vertice* origen, Arista* destino);

	/*
	 * PRE: Existe un grafo y el nodo no esta previamente
	 * POST: El grafo queda modificado con el nuevo nodo agregado
	 */
	void insertar_vertice(Vertice*);

	/*
	 * PRE: Existe un grafo
	 * POST: Libera recursos
	 */
	~Grafo();

	/*
	 * PRE: -
	 * POST: Imprime por pantalla los datos el Vertice
	 */
	void imprimir_vertices();

	/*
	 *  PRE: Existe el grafo
	 *  POST: Devuelve true si el grafo esta vacio, false en caso contrario
	 */
	bool esta_vacio();

	/*
	 * PRE: Recibe un string
	 * POST: Devuelve Vertice*
	 */
	Vertice* obtener_vertice(string);

	/*
	 * PRE: Recibe un int
	 * POST: Devuelve un Vertice*
	 */
	Vertice* obtener_vertice(int);

	/*
	 * PRE: Existe el grafo
	 * POST: Elimina el atributo lista_vertice, libera recursos, etc.
	 */
	void eliminar_todo();

	/*
	 * PRE: Existe, vertice y estan cargadas los vuelos y sus conexiones
	 * POST: Arma los caminos y pesos minimos hacia todos los vertices
	 *		 desde el vertice pasado como parametro.
	 */
	void Dijkstra(Vertice* inicial, int op);

	/*
	 * PRE: Existe el grafo
	 * POST: Imprime el camino minimo segun Dijkstra
	 */
	void imprimir_dijkstra(int, float&, float&);

	/*
	 * PRE: Existe el grafo, recibe un vertice un vector de booleanos y un int
	 * POST: Recorre los adyacentes del vertice recibido por parametro
	 */
	void recorrer(Vertice* actual, bool visitado[], int op);



};

#endif /* GRAFO_H_ */
