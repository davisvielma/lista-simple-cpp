#include "ListaSimple.h"
#include <iostream>

using namespace std;


ListaSimple::ListaSimple() {
	this->inicio = new Nodo();
	this->tamano = 0;
}

bool ListaSimple::vacio() const {
	return ((!this->inicio->siguiente) ? true : false);
}

void ListaSimple::cambiarTamano(int t) {
	this->tamano += t;
}

void ListaSimple::eliminarPrimerValor() {
	if(!this->vacio()) {
		Nodo *aux = this->inicio->siguiente->siguiente;
		delete this->inicio->siguiente;

		this->inicio->siguiente = aux;
		this->cambiarTamano(-1);	
	}
}

void ListaSimple::agregar(int dato) {
	Nodo *aux = new Nodo();
	aux->dato = dato;
	aux->siguiente = this->inicio->siguiente;

	this->inicio->siguiente = aux;
	this->cambiarTamano(1); 
}

void ListaSimple::imprimir() const {
	if(!this->vacio()) {
		Nodo *aux = this->inicio->siguiente;

		cout << "\n | ";
		while(aux) {
			cout << aux->dato << " | ";
			aux = aux->siguiente;
		}

		cout << endl;
	}
}

bool ListaSimple::buscar(int n) const {
	if(this->vacio()) {
		return false;
	}

	bool encontrado = false;
	Nodo *aux = this->inicio->siguiente;

	while(aux) {
		if(aux->dato == n) {
			encontrado = true;
			break;
		}

		aux = aux->siguiente;
	} 

	return encontrado;
}

bool ListaSimple::eliminarPorValor(int dato) {
	if(this->vacio() || !this->buscar(dato)) return false;

	Nodo *aux = this->inicio;

	while(aux->siguiente) {
			if(aux->siguiente->dato != dato) {
				aux = aux->siguiente;
			} else {
				Nodo *aux2 = aux->siguiente->siguiente;
				delete aux->siguiente;
				aux->siguiente = aux2;
				this->cambiarTamano(-1);
			}
	}

	return true;
}

ListaSimple::~ListaSimple() {
	while(!this->vacio()) {
        this->eliminarPrimerValor();
    }

    delete this->inicio;
}
