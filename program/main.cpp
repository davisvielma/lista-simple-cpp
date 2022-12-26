#include <iostream>
#include "ListaSimple.h"
#include "Controlador.h"

using namespace std;

#define ROJO "\x1B[31m"

int main(int argc, char const *argv[]) {
	
	Controlador controlador;
	ListaSimple *lista = new ListaSimple();
	int opcion = 0;

	do {

		try {
			controlador.menu();
			cin >> opcion;

			if(opcion < 1 || opcion > 6) throw -1;

			switch(opcion) {
				case 1:
					controlador.agregarDatos(lista, controlador.pedirDato());
					break;
				case 2:
					controlador.imprimirValores(lista);
					break;
				case 3:
					controlador.imprimirTamano(lista);
					break;

				case 4:
					controlador.buscarNumero(lista);
					break;

				case 5:
					controlador.eliminarElementoPorValor(lista);
					break;
			}

		} catch (int e) {
			cout << ROJO "\nERROR!! Opción invalida." << endl;
		}

	} while(opcion != 6);

	return 0;
}
