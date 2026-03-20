/**
 * Vertice.h
 * Graph vertex: IATA code, id, adjacency list of edges.
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include <iostream>
#include <list>
#include "Arista.h"

using namespace std;

class Vertice{

private:
	list<Arista*> lista_ady;
	string codigo;
	int id;

public:
	/*
	 * PRE:-
	 * POST: Crea un objeto vertice en null
	 */
	Vertice();

	/*
	 * PRE: Recibe un string
	 * POST: Crea un objeto de tipo Vertice
	 */
	Vertice(string);

	/*
	 * PRE: Recibe un string
	 * POST: Asigna un valor al atributo codigo
	 */
	void asignar_codigo(string);
	/*
	 * PRE: Recibe un int
	 * POST: Asigna un id al vertice.
	 */
	void asignar_id(int i);

	/*
	 * PRE: -
	 * POST: Devuelve un string
	 */
	string obtener_codigo();

	/*
	 * PRE: -
	 * POST: Devuelve el dato en id.
	 */
	int obtener_id();

	/*
	 * PRE: -
	 * POST: Devuelve list<Vertice*>
	 */
	list<Arista*> obtener_lista();

	/*
	 * PRE: Recibe un Vertice*
	 * POST:Agrega un vertice a la lista de adyacentes
	 */
	void agregar_ady(Arista*);

	/*
	 * PRE: -
	 * POST: Imprime la informacion de una arista
	 */
	void imprimir_ady();

	/*
	 * PRE: Existe el grafo
	 * POST: Destruye el objeto, libera recursos, etc.
	 */
	~Vertice();

	/*
	 * PRE: Existe el grafo y las aritas estan en el
	 * POST: El grafo queda modificado con la eliminacion de la arista
	 */
	void eliminar_arista(Vertice* o, Vertice* d);

	/*
	 * PRE: Existe el grafo
	 * POST: Arista es un valor valido
	 */
	bool existe_arista(string d);

	/*
	 * PRE: Existe un vertice
	 * POST: Elimina todos los datos de lista_ady
	 */
	void eliminar_todo();

	/*
	 * PRE: Existe vertice
	 * POST: Si la lista esta vacia devuelve true, caso contrario false
	 */
	bool esta_vacia();

	/*
	 * PRE: Existe vertice
	 * POST: Devuelve Arista*
	 */
	Arista* obtener_arista(string c);

};



#endif /* VERTICE_H_ */
