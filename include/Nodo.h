#ifndef NODO_H
#define NODO_H

class Nodo {
	private:
		int dato;
		Nodo *siguiente;

	friend class ListaSimple;
};

#endif //NODO_H