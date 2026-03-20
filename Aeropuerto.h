/**
 * Aeropuerto.h
 * Airport entity: name, city, country, surface, terminals, destinations.
 */

#ifndef AEROPUERTO_H_
#define AEROPUERTO_H_

#include <iostream>

using namespace std;

class Aeropuerto {

private:

	string nombre, ciudad, pais;
	float superficie;
	unsigned cant_terminales, dest_nacionales, dest_internacionales;

public:

	//constructor nulo
	Aeropuerto();

	//constructor con parametros
	Aeropuerto(string n, string c, string p, float s, unsigned ter, unsigned nac, unsigned inter);

	//getters y setters
	void asignar_nombre(string);
	void asignar_ciudad(string);
	void asignar_pais(string);
	void asignar_superficie(float);
	void asignar_terminales(unsigned);
	void asignar_internacional(unsigned);
	void asignar_nacional(unsigned);
	string obtener_nombre();
	string obtener_ciudad();
	string obtener_pais();
	float obtener_superficie();
	unsigned obtener_terminales();
	unsigned obtener_internacional();
	unsigned obtener_nacional();
	void imprimir_datos();
	~Aeropuerto();

};

#endif /* AEROPUERTO_H_ */
