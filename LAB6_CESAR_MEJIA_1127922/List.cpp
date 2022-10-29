#include "List.h"

void LIST::Add(int nn, string n , int g)
{
	Nodeli* aux = new Nodeli();
	aux->pok.setNumero_nacional(nn);
	aux->pok.setNombre(n);
	aux->num_gnombre += g;
	for (int i = 0; i < n.length(); i++)
	{
		switch (toupper(n[i]))
		{
		case 'A':
			aux->num_gnombre += 0.001;
			break;
		case 'B':
			aux->num_gnombre += 0.002;
			break;
		case 'C':
			aux->num_gnombre += 0.003;
			break;
		case 'D':
			aux->num_gnombre += 0.004;
			break;
		case 'E':
			aux->num_gnombre += 0.005;
			break;
		case 'F':
			aux->num_gnombre += 0.006;
			break;
		case 'G':
			aux->num_gnombre += 0.007;
			break;
		case 'H':
			aux->num_gnombre += 0.008;
			break;
		case 'I':
			aux->num_gnombre += 0.009;
			break;
		case 'J':
			aux->num_gnombre += 0.010;
			break;
		case 'K':
			aux->num_gnombre += 0.011;
			break;
		case 'L':
			aux->num_gnombre += 0.012;
			break;
		case 'M':
			aux->num_gnombre += 0.013;
			break;
		case 'N':
			aux->num_gnombre += 0.014;
			break;
		case 'O':
			aux->num_gnombre += 0.015;
			break;
		case 'P':
			aux->num_gnombre += 0.016;
			break;
		case 'Q':
			aux->num_gnombre += 0.017;
			break;
		case 'R':
			aux->num_gnombre += 0.018;
			break;
		case 'S':
			aux->num_gnombre += 0.019;
			break;
		case 'T':
			aux->num_gnombre += 0.020;
			break;
		case 'U':
			aux->num_gnombre += 0.021;
			break;
		case 'V':
			aux->num_gnombre += 0.022;
			break;
		case 'W':
			aux->num_gnombre += 0.023;
			break;
		case 'X':
			aux->num_gnombre += 0.024;
			break;
		case 'Y':
			aux->num_gnombre += 0.025;
			break;
		case 'Z':
			aux->num_gnombre += 0.026;
			break;
		}
	}
	aux->pok.setGeneracion(g);
	aux->next = header;
	header = aux;
}

string LIST::getPokemon(int index)
{
	Nodeli* aux = header;
	for (int i = 0; i < index; i++)
	{
		aux = aux->next;
	}
	return std::to_string(aux->pok.getNumero_nacional()) + "," + aux->pok.getNombre() + "," + std::to_string(aux->pok.getGeneracion());
}

int LIST::Count()
{
	Nodeli* aux = header;
	int contador = 0;
	while (aux != nullptr)
	{
		contador++;
		aux = aux->next;
	}
	return contador;
}

void LIST::Ordenar_shell_sort(int n)
{
	Nodeli* actual = header;
	Nodeli* siguiente = header;
	
	int intervalo = n / 2;
	int naciona, gnracion;
	double gmasnombre=0.0;
	string nombre;
	/*{
		while (intervalo > 0)
		{
			actual = header;
			siguiente = header;
			for (int i = 0; i < contadora; i++)
			{
				actual = actual->next;
			}
			for (int i = 0; i < contadors; i++)
			{
				siguiente = siguiente->next;
			}
			if (actual->num_gnombre > siguiente->num_gnombre)
			{
				nombre = actual->pok.getNombre();
				naciona = actual->pok.getNumero_nacional();
				gnracion = actual->pok.getGeneracion();
				gmasnombre = actual->num_gnombre;

				actual->pok.setNombre(siguiente->pok.getNombre());
				actual->pok.setGeneracion(siguiente->pok.getGeneracion());
				actual->pok.setNumero_nacional(siguiente->pok.getNumero_nacional());
				actual->num_gnombre = siguiente->num_gnombre;

				siguiente->pok.setNombre(nombre);
				siguiente->pok.setGeneracion(gnracion);
				siguiente->pok.setNumero_nacional(naciona);
				siguiente->num_gnombre = gmasnombre;

			}
			contadora++;
			contadors++;

			if (contadors >= intervalo)
			{
				contadora = 0;
				contadors = 0;
				intervalo /= 2;
			}
		}
	}*/
	while (actual!=nullptr)
	{
		siguiente = actual->next;
		while (siguiente!=nullptr)
		{
			if (actual->num_gnombre > siguiente->num_gnombre)
			{
				naciona = actual->pok.getNumero_nacional();
				gnracion = actual->pok.getGeneracion();
				nombre = actual->pok.getNombre();
				gmasnombre = actual->num_gnombre;

				actual->pok.setNumero_nacional(siguiente->pok.getNumero_nacional());
				actual->pok.setGeneracion(siguiente->pok.getGeneracion());
				actual->pok.setNombre(siguiente->pok.getNombre());
				actual->num_gnombre = siguiente->num_gnombre;

				siguiente->pok.setGeneracion(gnracion);
				siguiente->pok.setNumero_nacional(naciona);
				siguiente->pok.setNombre(nombre);
				siguiente->num_gnombre = gmasnombre;
			}
			siguiente = siguiente->next;
		}
		actual = actual->next;
	}
}
