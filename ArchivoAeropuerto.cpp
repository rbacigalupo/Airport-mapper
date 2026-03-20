
#include "ArchivoAeropuerto.h"

ArchivoAeropuerto::ArchivoAeropuerto(){
	archivo_aeropuertos.open(ARCHIVO_AERO);


}

void ArchivoAeropuerto::cargar_arbol(ABB<Aeropuerto*>* arbol){

	Aeropuerto* aero;

	while(archivo_aeropuertos >> codigo >> nombre >> ciudad >> pais >> superficie
			>> cant_terminales >> dest_nacionales >> dest_internacionales){

		aero = new Aeropuerto(nombre, ciudad, pais, superficie, cant_terminales, dest_nacionales, dest_internacionales);

		arbol->insertar(codigo, aero);
	}
}

ArchivoAeropuerto::~ArchivoAeropuerto(){

	archivo_aeropuertos.close();

}

