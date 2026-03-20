
#include "Grafo.h"

Grafo::Grafo(){
	tam = 0;
}

bool Grafo::esta_vacio(){
	return lista_vertices.empty() == 1;
}


bool Grafo::existe_vertice(string c){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	bool existe = false;
	while( iterador != lista_vertices.end() && existe != true){
		if(c == (*iterador)->obtener_codigo()){
			existe = true;
		} else {
			iterador ++;
		}
	}
	return existe;
}

void Grafo::insertar_vertice(Vertice* v){
	lista_vertices.push_back(v);
	v->asignar_id(tam);
	tam++;

}

void Grafo::imprimir_vertices(){
	list<Vertice*> :: iterator iterador;
	for(iterador = lista_vertices.begin(); iterador != lista_vertices.end(); iterador++){
		cout << (*iterador)->obtener_codigo() << "->";
		(*iterador)->imprimir_ady();
		cout << endl;
	}
}

Vertice* Grafo::obtener_vertice(string codigo){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	Vertice* aux = NULL;
	while( iterador != lista_vertices.end()){
		if(codigo == (*iterador)->obtener_codigo()){
				aux = (*iterador);
				break;
			}
		iterador ++;
	}
	return aux;
}

void Grafo::insertar_arista(Vertice* o, Arista* d){
	 list<Vertice*> :: iterator iterador;
	 iterador = lista_vertices.begin();
	 bool existe = false;
	 while( iterador != lista_vertices.end() && existe != true){
		 if(o->obtener_codigo() == (*iterador)->obtener_codigo()){
			 (*iterador)->agregar_ady(d);
			 existe = true;
		 } else {
			 iterador ++;
		 }
	 }
}

void Grafo::eliminar_todo(){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	while(esta_vacio() == false){
		Vertice* aux;
		aux = (*iterador);
		iterador ++;
		lista_vertices.remove(aux);
		delete aux;
	}
}

void Grafo::iniciar(float distancia[], bool visitado[], int previo[]){

	for( int i = 0 ; i < tam ; ++i ){

		distancia[ i ] = INF;
	    previo[ i ] = -1;
	    visitado[i]=false;
	}
}

void Grafo::Dijkstra(Vertice* inicial, int op){

		bool visitado[MAX_V];

		this->iniciar(distancia, visitado, previo);
		cola_prioridad.insertar(inicial, 0);
		distancia[inicial->obtener_id()]= 0;

		Vertice* actual;

		while (!cola_prioridad.esVacia()){
			actual = cola_prioridad.desacolar();

			if (visitado[actual->obtener_id()]) continue;
			visitado[actual->obtener_id()] = true;
			recorrer(actual, visitado, op);
		}

}

void Grafo::recorrer(Vertice* actual, bool visitado[], int op){
	Vertice* adyacente;
	list<Arista*> :: iterator iterador;
	list<Arista*> aux = actual->obtener_lista();
	float peso;

	for(iterador = aux.begin(); iterador != aux.end(); iterador++){

		adyacente = obtener_vertice((*iterador)->obtener_destino());
		peso = (*iterador)->obtener_peso(op);

		comparacion(actual, adyacente, peso);
  }
}

void Grafo::comparacion(Vertice* actual, Vertice* adyacente, float &pes){

	if(distancia[actual->obtener_id()] + pes <  distancia[adyacente->obtener_id()]){

		distancia[adyacente->obtener_id()] = distancia[actual->obtener_id()] + pes;
		previo[adyacente->obtener_id()] = actual->obtener_id();

		cola_prioridad.insertar(adyacente, distancia[adyacente->obtener_id()]);
	}

}

void Grafo::imprimir_dijkstra(int dest, float & horas, float & costo){

	if((previo[dest]<lista_vertices.size()) && (previo[dest] > -1)){

		this->imprimir_dijkstra(previo[dest], horas, costo);
		Vertice* aux_destino = obtener_vertice(dest);
		Vertice* aux_origen = obtener_vertice(previo[dest]);
		Arista* aux_a = aux_origen->obtener_arista(aux_destino->obtener_codigo());
		horas = horas + aux_a->obtener_peso_horas();
		costo = costo + aux_a->obtener_peso_costo();
		aux_a->imprimir_datos();

	}else if (distancia[dest] == INF){
		cout << "No existe conexion entre los aeropuertos ingresados.\n" << endl;
	}
}

Vertice* Grafo::obtener_vertice(int dest){
	list<Vertice*> :: iterator iterador;
	iterador = lista_vertices.begin();
	Vertice* aux = NULL;
	while( iterador != lista_vertices.end()){
		if(dest == (*iterador)->obtener_id()){
				aux = (*iterador);
				break;
			}
		iterador ++;
	}
	return aux;
}

Grafo::~Grafo(){
	eliminar_todo();
}
