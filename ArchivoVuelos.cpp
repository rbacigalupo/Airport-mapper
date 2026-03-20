
#include "ArchivoVuelos.h"

ArchivoVuelos::ArchivoVuelos(){
	archivo_vuelos.open(ARCHIVO_VUELOS);
	costo_vuelo = 0;
	horas_vuelo = 0;
}


void ArchivoVuelos::leer_archivo(Grafo* grafo){

	while(archivo_vuelos >> codigo_partida >> codigo_llegada >> costo_vuelo >> horas_vuelo){

		verificar_vertice(codigo_partida, grafo);
		verificar_vertice(codigo_llegada, grafo);
		hallar_aristas(codigo_partida, codigo_llegada, horas_vuelo, costo_vuelo, grafo);

	}

}

void ArchivoVuelos::verificar_vertice(string codigo_partida, Grafo* grafo){
	if(grafo->existe_vertice(codigo_partida) == false){
		Vertice* vertice = new Vertice(codigo_partida);
		grafo->insertar_vertice(vertice);
	}
}

void ArchivoVuelos::hallar_aristas(string codigo_partida, string codigo_llegada, float horas_vuelo, float costo_vuelo, Grafo* grafo){
	Vertice* aux_partida = grafo->obtener_vertice(codigo_partida);
	Arista* nuevo_vertice = new Arista(codigo_partida, codigo_llegada, horas_vuelo, costo_vuelo);

	grafo->insertar_arista(aux_partida, nuevo_vertice);
}

void ArchivoVuelos::imprimir_grafo(Grafo* grafo){
	grafo->imprimir_vertices();
}

ArchivoVuelos::~ArchivoVuelos(){

}
