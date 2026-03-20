/**
 * Arista.h
 * Graph edge: origin, destination, cost, duration.
 */

#ifndef ARISTA_H_
#define ARISTA_H_

#include <iostream>

using namespace std;


class Arista{

private:
	string origen, destino;
	float peso_horas, peso_costo;
public:

	/*
	 * PRE: Recibe dos string y un float
	 * POST: Crea un objeto de tipo Arista
	 */
	Arista(string o, string d, float p, float c);

	/*
	 * PRE: Recibe un string
	 * POST: Asigna valor al atributo origen
	 */
	void asignar_origen(string);

	/*
	 * PRE: Recibe un string
	 * POST: Asigna valor al atributo destino
	 */
	void asignar_destino(string);

	/*
	 * PRE: Recibe un float
	 * POST: Asigna valor al atributo peso horas
	 */
	void asignar_peso_horas(float);

	/*
	 * PRE: Recibe un float
	 * POST: Asigna valor al atributo peso
	 */
	void asignar_peso_costo(float);

	/*
	 * PRE: -
	 * POST: Devuelve un string
	 */
	string obtener_origen();

	/*
	 * PRE: -
	 * POST: Devuelve un string
	 */
	string obtener_destino();

	/*
	 * PRE: -
	 * POST: Devuelve un float
	 */
	float obtener_peso_horas();

	/*
	 * PRE: -
	 * POST: Devuelve un float
	 */
	float obtener_peso_costo();

	/*
	 * PRE: -
	 * POST: Devuelve un float
	 */
	float obtener_peso(int);

	/*
	 * PRE: -
	 * POST: Imprime por pantalla los atributos del objeto
	 */
	void imprimir_datos();

	/*
	 * PRE: Existe una Arista
	 * POST: Libera recursos
	 */
	~Arista();


};


#endif /* ARISTA_H_ */
