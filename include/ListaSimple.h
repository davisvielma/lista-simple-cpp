#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include "Nodo.h"

class ListaSimple {
	private:
		Nodo *inicio;
		int tamano;
		void cambiarTamano(int);
		void eliminarPrimerValor();

	public:
		explicit ListaSimple();
		~ListaSimple();

		inline int verTamano() const { return this->tamano; }

		bool vacio() const;
		void agregar(int);
		void imprimir() const;
		bool buscar(int) const;
		bool eliminarPorValor(int);	
};

#endif //LISTA_SIMPLE_H