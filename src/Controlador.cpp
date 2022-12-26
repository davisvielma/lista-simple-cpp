#include "Controlador.h"
#include <iostream>

using namespace std;

#define VERDE "\x1B[32m"
#define AMARILLO "\x1B[33m"

void Controlador::vacia() const {
	cout << AMARILLO "\nLista vaciá." << endl;
}

void Controlador::menu() const {
	cout << VERDE "\n\t\tPractica de Listas Simples\n" << endl;
	cout << "1)Agregar un elemento." << endl;
	cout << "2)Ver elementos en la lista." << endl;
	cout << "3)Ver tamaño en la lista." << endl; 
	cout << "4)Encontrar un numero en la lista." << endl;
	cout << "5)Eliminar elemento por su valor." << endl;
	cout << "6)salir." << endl;
	cout << "*Elija una opción: ";
}

int Controlador::pedirDato() {
	int dato = 0;

	cout << "\nIngrese un numero a operar en la lista: ";
	cin >> dato;

	return dato;
}

int Controlador::pedirPosicion() {
	int posicion = 0;

	cout << "Ingrese la posición en la que desea operar en la lista: ";
	cin >> posicion;

	return posicion;
}

void Controlador::agregarDatos(ListaSimple *l, int dato) {
	l->agregar(dato);
}

void Controlador::imprimirValores(ListaSimple *l) const {
	if(l->vacio()) {
		this->vacia();
		return;
	}

	l->imprimir();
}

void Controlador::imprimirTamano(ListaSimple *l) const {
	cout << "\nTamaño de la lista: " << l->verTamano() << endl;
}

void Controlador::buscarNumero(ListaSimple *l) {
	if(l->vacio()) {
		this->vacia();
		return;
	}

	int dato = this->pedirDato();

	if(l->buscar(dato)) {
		cout << "\nEl numero " << dato << " existe en la lista." << endl;
	} else {
		cout << AMARILLO "\nEl numero " << dato << " no existe en la lista." << endl;
	}
}

void Controlador::eliminarElementoPorValor(ListaSimple *l) {
	if(l->vacio()) {
		this->vacia();
		return;
	}

	int dato = this->pedirDato();

	if(l->eliminarPorValor(dato)) {
		cout << "\nSe elimino el numero: " << dato << "." << endl;
	} else {
		cout << AMARILLO "\nEl numero " << dato << " no existe en la lista." << endl;
	
	}
}