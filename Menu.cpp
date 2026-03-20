#include "Menu.h"


Menu::Menu(){
	arbol = new ABB<Aeropuerto*>();
	archivo_aeropuerto.cargar_arbol(arbol);
	archivo_vuelos.leer_archivo(&grafo);
}

Menu::~Menu(){
	delete arbol;
}

void Menu::iniciar(){

	int num=0;

	while( num != FINALIZAR_APLICACION){
		seleccionar_opcion(num);
		realizar_accion(num);
	}
}

void Menu::seleccionar_opcion(int &num){

	cout << "Ingrese la opcion de la accion que quiere realizar: "<< endl;
	cout << "\t(1) Consultar por un aeropuerto" << endl;
	cout << "\t(2) Agregar un nuevo aeropuerto" << endl;
	cout << "\t(3) Eliminar un aeropuerto" << endl;
	cout << "\t(4) Mostrar todos los aeropuertos ordenados" << endl;
	cout << "\t(5) Mostrar todos los aeropuertos por nivel en el arbol" << endl;
	cout << "\t(6) Imprimir el grafo por pantalla" << endl;
	cout << "\t(7) Buscar el itinerario de conexiones mas eficiente" << endl;
	cout << "\t(8) Finalizar la aplicacion" << endl;
	cout << "---------------------------------------\n" << endl;
	cout << "INPUT: ";
	cin >> num;

}

void Menu::ingresar_entrada(string &origen, string &destino, int& op){

	cout << "Ingrese origen: " << endl;
	cin >> origen;
	verificar_codigo(origen);
	cout << "Ingrese destino: " << endl;
	cin >> destino;
	verificar_codigo(destino);
	cout << "Ver recorrido minimo por (1) Duracion de vuelo (2) Costo del vuelo" << endl;
	cin >> op;
}

void Menu::realizar_accion(int num){

	string origen, destino;
	int op;
	bool activo = true;

	limpiar_pantalla();

	switch(num){
		case 1:
				consultar_aeropuerto();
				break;
		case 2:
				agregar_aeropuerto();
				break;
		case 3:
				eliminar_aeropuerto();
				break;
		case 4:
				arbol->imprimir_en_orden();
				break;
		case 5:
				mostrar_aeropuertos_por_nivel();
				break;
		case 6:
				archivo_vuelos.imprimir_grafo(&grafo);
				break;
		case 7:{
				float total_horas = 0, total_costo = 0;
				ingresar_entrada(origen, destino, op);
				Vertice* ver_origen = grafo.obtener_vertice(origen);
				Vertice* ver_destino = grafo.obtener_vertice(destino);
				if (ver_origen == NULL || ver_destino == NULL) {
					cout << "Error: aeropuerto no encontrado.\n" << endl;
					break;
				}
				grafo.Dijkstra(ver_origen, op);
				cout << "\nLas conexiones encontradas son:\n" << endl;
				grafo.imprimir_dijkstra(ver_destino->obtener_id(), total_horas, total_costo);
				imprimir_totales(total_horas, total_costo);
				break;
			}
		case 8:
				activo = false;
				cout << "FIN DE LA APLICACION" << endl;
				break;

		default:
				activo = false;
				cout << "\nCaracter ingresado no valido, por favor intente nuevamente.\n" << endl;

	}

	if(activo){
		continuar();
	}
}

void Menu::verificar_codigo(string& c){
	if(!grafo.existe_vertice(c)){
		cout << "El codigo ingresado no existe, por favor ingrese otro" << endl;
		cin >> c;
		verificar_codigo(c);
	}
}

void Menu::continuar(){

	string entrada;
	cout << "\nPara volver al menu ingrese cualquier letra y presione ENTER." << endl;
	cin >> entrada;
	limpiar_pantalla();
}

void Menu::limpiar_pantalla(){

	cout << string(50, '\n');

	#if defined(__linux__) || defined(__APPLE__)
		system("clear");
	#else
		system("cls");
	#endif
}

void Menu::imprimir_totales(float &horas, float &costo){

	cout << "\t Tiempo total: " << horas << "hs\t" << "Coste total: $" << costo << endl;
}

void Menu::consultar_aeropuerto(){

	string clave;
	cout << "Ingrese el codigo IATA del aeropuerto por el que desea CONSULTAR: " << endl;
	cin >> clave;

	NodoABB<Aeropuerto*>* nodo = arbol -> buscar(clave);

	if (nodo != NULL){
		mostrar_aeropuerto(nodo);
	}else{
		cout << "El aeropuerto no existe" << endl;
	}
}

void Menu::mostrar_aeropuerto(NodoABB<Aeropuerto*>* nodo){

	Aeropuerto *valor = nodo->obtener_valor();
	cout << nodo->obtener_clave() << " ";
	valor->imprimir_datos() ;

}

void Menu::agregar_aeropuerto(){
	string clave;

	cout << "Ingrese el código IATA del aeropuerto que desea AGREGAR: " << endl;
	cin >> clave;

	NodoABB<Aeropuerto*>* nodo = arbol -> buscar(clave);

	if( nodo == NULL){
		ingresar_aeropuerto(clave);
	}
	else{
		cout << "Error, ha ingresado el codigo de un aeropuerto ya existente" ;
	}

}

void Menu::ingresar_aeropuerto(string clave){
	string nombre, ciudad, pais;
	float superficie;
	unsigned cant_terminales, dest_nacionales, dest_internacionales;

	cin.clear();
	cin.ignore(100,'\n');

	cout << "Ingrese: " << endl;
	cout << "Nombre del Aeropuerto: " << endl;
	getline(cin, nombre);

	cout << "Pais en el que se ubica: " << endl;
	cin.clear();
	getline(cin, pais);

	cout << "Nombre de la ciudad: " << endl;
	cin.clear();
	getline(cin, ciudad);

	cout << "Superficie: " << endl;
	cin >> superficie;

	cout << "Cantidad de terminales: " << endl;
	cin >> cant_terminales;

	cout << "Destinos nacionales: " << endl;
	cin >> dest_nacionales;

	cout << "Destinos internacionales: " << endl;
	cin >> dest_internacionales;


	Aeropuerto* aero = new Aeropuerto(nombre, ciudad, pais, superficie, cant_terminales, dest_nacionales, dest_internacionales);

	arbol->insertar(clave, aero);
}


void Menu::eliminar_aeropuerto(){
	string clave;

	cout << "Ingrese el código IATA del aeropuerto que desea ELIMINAR: " << endl;
	cin >> clave;

	NodoABB<Aeropuerto*>* nodo = arbol -> buscar(clave);

	if( nodo != NULL){
		arbol->eliminar(clave);
	}
	else{
		cout << "Error, el codigo ingresado NO EXISTE" << endl;
	}

}


void Menu::mostrar_aeropuertos_por_nivel(){

	NodoABB<Aeropuerto*>* nodo;
	Cola<NodoABB<Aeropuerto*>*> cola;
	cola.insertar(arbol->obtener_raiz());

	while(!cola.esVacia()){

		nodo = cola.desacolar();
		cout << nodo->obtener_clave() << endl;

		agregar_claves(cola, nodo->obtener_izquierda());
		agregar_claves(cola, nodo->obtener_derecha());

	}
}

void Menu::agregar_claves(Cola<NodoABB<Aeropuerto*>*> &cola, NodoABB<Aeropuerto*>* nodo){
	if(nodo != NULL)
		cola.insertar(nodo);
}
