/**
 * NodoABB.h
 * BST node: key (string), value (T), left, right, parent.
 */

#ifndef ABB_NodoABB_H
#define ABB_NodoABB_H

#include <iostream>

using namespace std;

template <class T>
class NodoABB
{
private:

    string clave;
    T valor;
    NodoABB<T>* izquierda; //Hijo izquierdo
    NodoABB<T>* derecha; //Hijo derecho
    NodoABB<T>* padre;
    bool copiado;

public:

    NodoABB(string s, T valor);
    string obtener_clave();
    T obtener_valor();
    void asignar_clave(string c);
    void asignar_valor(T v);
    void asignar_derecha(NodoABB<T>* derecha, NodoABB<T>* padre);
    void asignar_izquierda(NodoABB<T>* izquierda, NodoABB<T>* padre);
    void asignar_izquierda(NodoABB<T>* izquierda);
    void asignar_derecha(NodoABB<T>* derecha);
    void asignar_padre(NodoABB<T>* padre);
    NodoABB<T>* obtener_derecha();
    NodoABB<T>* obtener_izquierda();
    NodoABB<T>* obtener_padre();
    bool es_hoja();
    bool solo_hijo_derecha();
    bool solo_hijo_izquierda();
    void fue_copiado();
    bool es_copiado();
    ~NodoABB();
};

template <class T>
NodoABB<T>::NodoABB(string clave, T valor)
{
    this->clave = clave;
    this->valor = valor;
    this->izquierda = NULL;
    this->derecha = NULL;
    this->padre = NULL;
    this->copiado = false;
}

template <class T>
string NodoABB<T>::obtener_clave()
{
    return this->clave;
}

template <class T>
T NodoABB<T>::obtener_valor()
{
    return this->valor;
}

template <class T>
void NodoABB<T>::asignar_derecha(NodoABB<T>* derecha, NodoABB<T>* padre){
    this->derecha = derecha;
    this->padre = padre;
}

template <class T>
void NodoABB<T>::asignar_derecha(NodoABB<T>* derecha){
    this->derecha = derecha;
}

template <class T>
void NodoABB<T>::asignar_izquierda(NodoABB<T>* izquierda, NodoABB<T>* padre){
    this->izquierda = izquierda;
    this->padre = padre;
}

template <class T>
void NodoABB<T>::asignar_padre(NodoABB<T> *padre) {
    this->padre = padre;
}

template <class T>
void NodoABB<T>::asignar_clave(string clave) {
    this->clave = clave;
}

template <class T>
void NodoABB<T>::asignar_valor(T valor) {
    this->valor = valor;
}

template <class T>
void NodoABB<T>::asignar_izquierda(NodoABB<T>* izquierda){
    this->izquierda = izquierda;
}

template <class T>
NodoABB<T>* NodoABB<T>::obtener_derecha()
{
    return this->derecha;
}

template <class T>
NodoABB<T>* NodoABB<T>::obtener_izquierda()
{
    return this->izquierda;
}

template <class T>
NodoABB<T>* NodoABB<T>::obtener_padre()
{
    return this->padre;
}

template <class T>
bool NodoABB<T>::es_hoja() {
    return (this->obtener_izquierda() == NULL && this->obtener_derecha() == NULL);
}

template <class T>
bool NodoABB<T>::solo_hijo_derecha() {
    return (this->obtener_izquierda() == NULL && this->obtener_derecha() != NULL);
}

template <class T>
bool NodoABB<T>::solo_hijo_izquierda() {
    return (this->obtener_izquierda() != NULL && this->obtener_derecha() == NULL);
}

template <class T>
bool NodoABB<T>::es_copiado() {

	return copiado;
}

template <class T>
void NodoABB<T>::fue_copiado(){
    this->copiado = true;
}

template <class T>
NodoABB<T>::~NodoABB(){

	//if(copiado) this->valor = NULL;
	delete valor;
}

#endif //ABB_NodoABB_H
