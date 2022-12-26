#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "ListaSimple.h"

class Controlador {
	private:
		void vacia() const;

	public:
		Controlador() { }
		~Controlador() { }
		void menu() const;
		int pedirDato();
		int pedirPosicion();
		void agregarDatos(ListaSimple *, int);
		void imprimirValores(ListaSimple *) const;
		void imprimirTamano(ListaSimple *) const;
		void buscarNumero(ListaSimple *);
		void eliminarElementoPorValor(ListaSimple *);
};

#endif //CONTROLADOR_H