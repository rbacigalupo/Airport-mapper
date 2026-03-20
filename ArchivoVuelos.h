/**
 * ArchivoVuelos.h
 * Reads vuelos.txt and builds the flight graph.
 */

#ifndef ARCHIVOVUELOS_H_
#define ARCHIVOVUELOS_H_

#include <iostream>
#include <fstream>
#include "Grafo.h"

using namespace std;

const string ARCHIVO_VUELOS = "vuelos.txt";

class ArchivoVuelos{

private:
	float costo_vuelo, horas_vuelo;
	string codigo_partida, codigo_llegada;
	ifstream archivo_vuelos;

public:

	/*
	 * PRE: -
	 * POST: Crea un objeto de tipo ArchivoVuelos
	 */
	ArchivoVuelos();

	/*
	 * PRE: El archivo vuelos.txt se abrio correctamente
	 * POST: Lee correctamente el archivo
	 */
	void leer_archivo(Grafo *grafo);

	/*
	 * PRE: Recibe un string
	 * POST: Si el string no existe en el grafo lo inserta, caso contrario lo descarta
	 */
	void verificar_vertice(string c, Grafo * grafo);


	/*
	 * PRE: Recibe strings y un float
	 * POST: Inserta en la lista del vertice su correspondiente Arista
	 */
	void hallar_aristas(string codigo_partida, string codigo_llegada, float horas_vuelo, float costo_vuelo, Grafo* grafo);

	/*
	 *
	 * PRE:-
	 * POST: Imprime los vuelos en orden.
	 */
	void imprimir_grafo(Grafo *grafo);
	~ArchivoVuelos();

};



#endif /* ARCHIVOVUELOS_H_ */
