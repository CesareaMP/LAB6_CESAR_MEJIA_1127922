#pragma once
#include<string>
#include "Pokemons.h"
using namespace std;
class LIST
{
	struct Nodeli
	{
		Pokemon pok;
		Nodeli* next;
		double num_gnombre;
	};

public:
	void Add(int, string, int);
	string getPokemon(int);
	int Count();
	void Shell_sort_Nacional(int);
	void Shell_sort_Generacion(int);
private:
	Nodeli* header = nullptr;
};

