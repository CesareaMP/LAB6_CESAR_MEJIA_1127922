#include "List.h"

void LIST::Add(int nn, string n , int g)
{
	Nodeli* aux = new Nodeli();
	aux->pok.setNumero_nacional(nn);
	aux->pok.setNombre(n);
	aux->num_gnombre = g;
		switch (toupper(n[0]))
		{
		case 'A':
			aux->num_gnombre += 0.1;
			break;
		case 'B':
			aux->num_gnombre += 0.02;
			break;
		case 'C':
			aux->num_gnombre += 0.03;
			break;
		case 'D':
			aux->num_gnombre += 0.04;
			break;
		case 'E':
			aux->num_gnombre += 0.05;
			break;
		case 'F':
			aux->num_gnombre += 0.06;
			break;
		case 'G':
			aux->num_gnombre += 0.07;
			break;
		case 'H':
			aux->num_gnombre += 0.08;
			break;
		case 'I':
			aux->num_gnombre += 0.09;
			break;
		case 'J':
			aux->num_gnombre += 0.10;
			break;
		case 'K':
			aux->num_gnombre += 0.11;
			break;
		case 'L':
			aux->num_gnombre += 0.12;
			break;
		case 'M':
			aux->num_gnombre += 0.13;
			break;
		case 'N':
			aux->num_gnombre += 0.14;
			break;
		case 'O':
			aux->num_gnombre += 0.15;
			break;
		case 'P':
			aux->num_gnombre += 0.16;
			break;
		case 'Q':
			aux->num_gnombre += 0.17;
			break;
		case 'R':
			aux->num_gnombre += 0.18;
			break;
		case 'S':
			aux->num_gnombre += 0.19;
			break;
		case 'T':
			aux->num_gnombre += 0.20;
			break;
		case 'U':
			aux->num_gnombre += 0.21;
			break;
		case 'V':
			aux->num_gnombre += 0.22;
			break;
		case 'W':
			aux->num_gnombre += 0.23;
			break;
		case 'X':
			aux->num_gnombre += 0.24;
			break;
		case 'Y':
			aux->num_gnombre += 0.25;
			break;
		case 'Z':
			aux->num_gnombre += 0.26;
			break;
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

void LIST::Shell_sort_Generacion(int n)
{
	Nodeli* anterior = header;
	Nodeli* siguiente = header;

	int intervalo = n / 2, contadora = 0, contadors = 0;
	int nacional = 0, generacion = 0;
	double gmasnombre = 0;
	string nombre = "";

	while (intervalo > -1)
	{
		contadors = intervalo + 1;
		while (contadors < n)
		{
			anterior = header;
			siguiente = header;
			for (int i = 0; i < contadora; i++)
			{
				anterior = anterior->next;
			}
			for (int j = 0; j < contadors; j++)
			{
				siguiente = siguiente->next;
			}
			if (anterior->num_gnombre < siguiente->num_gnombre)
			{
				nacional = anterior->pok.getNumero_nacional();
				generacion = anterior->pok.getGeneracion();
				nombre = anterior->pok.getNombre();
				gmasnombre = anterior->num_gnombre;

				anterior->pok.setNumero_nacional(siguiente->pok.getNumero_nacional());
				anterior->pok.setGeneracion(siguiente->pok.getGeneracion());
				anterior->pok.setNombre(siguiente->pok.getNombre());
				anterior->num_gnombre = siguiente->num_gnombre;

				siguiente->pok.setNumero_nacional(nacional);
				siguiente->pok.setGeneracion(generacion);
				siguiente->pok.setNombre(nombre);
				siguiente->num_gnombre = gmasnombre;
			}
			contadora++;
			contadors++;
		}
		if (intervalo == 0)
		{
			intervalo -= 2;
		}
		else {
			intervalo /= 2;
			contadors = 0;
			contadora = 0;
		}
	}
}

void LIST::Shell_sort_Nacional(int n)
{
	Nodeli* anterior = header;
	Nodeli* siguiente=header;
	
	int intervalo = n / 2,contadora=0,contadors=0;
	int nacional=0, generacion=0;
	double gmasnombre=0;
	string nombre="";
	
	while (intervalo>-1)
	{
		contadors = intervalo+1;
		while (contadors<n)
		{
			anterior = header;
			siguiente = header;
			for (int i = 0; i < contadora; i++)
			{
				anterior = anterior->next;
			}
			for (int j = 0; j < contadors; j++)
			{
				siguiente = siguiente->next;
			}
			if (anterior->pok.getNumero_nacional() < siguiente->pok.getNumero_nacional())
			{
				nacional = anterior->pok.getNumero_nacional();
				generacion = anterior->pok.getGeneracion();
				nombre = anterior->pok.getNombre();
				gmasnombre = anterior->num_gnombre;

				anterior->pok.setNumero_nacional(siguiente->pok.getNumero_nacional());
				anterior->pok.setGeneracion(siguiente->pok.getGeneracion());
				anterior->pok.setNombre(siguiente->pok.getNombre());
				anterior->num_gnombre = siguiente->num_gnombre;

				siguiente->pok.setNumero_nacional(nacional);
				siguiente->pok.setGeneracion(generacion);
				siguiente->pok.setNombre(nombre);
				siguiente->num_gnombre = gmasnombre;
			}
			contadora++;
			contadors++;
		}
		if (intervalo==0)
		{
			intervalo -= 2;
		}
		else {
			intervalo /= 2;
			contadors = 0;
			contadora = 0;
		}
	}
	
}
