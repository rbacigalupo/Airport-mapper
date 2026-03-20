/**
 * ArchivoAeropuerto.h
 * Reads aeropuertos.txt and loads airports into the ABB.
 */

#ifndef ARCHIVOAEROPUERTO_H_
#define ARCHIVOAEROPUERTO_H_

#include <iostream>
#include <fstream>
#include "ABB.h"
#include "Aeropuerto.h"

using namespace std;

const string ARCHIVO_AERO = "aeropuertos.txt";

class ArchivoAeropuerto{
private:
	string nombre, ciudad, pais, codigo;
	float superficie;
	unsigned cant_terminales, dest_nacionales, dest_internacionales;
	ifstream archivo_aeropuertos;

public:
	/*
	 * PRE: -
	 * POST: Crea un objeto de tipo ArchivoAeropuertos
	 */
	ArchivoAeropuerto();

	/*
	 * PRE: -
	 * POST: Lee los datos del atributo archivo_aeropuertos y los inserta en el arbol
	 */
	void cargar_arbol(ABB<Aeropuerto*>* arbol);

	~ArchivoAeropuerto();


};



#endif /* ARCHIVOAEROPUERTO_H_ */
