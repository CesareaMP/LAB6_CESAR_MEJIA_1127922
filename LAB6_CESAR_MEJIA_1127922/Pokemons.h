#pragma once
#include <string>

using namespace std;
class Pokemon
{
private:
	int numero_nacional;
	string nombre;
	int generacion;
public:
	void setNumero_nacional(int n) {
		numero_nacional = n;
	}
	void setNombre(string n) {
		nombre = n;
	}
	void setGeneracion(int g) {
		generacion = g;
	}

	int getNumero_nacional() {
		return this->numero_nacional;
	}
	string getNombre() {
		return this->nombre;
	}
	int getGeneracion() {
		return this->generacion;
	}

};


