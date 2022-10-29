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
	void Ordenar_shell_sort(int);
private:
	Nodeli* header = nullptr;
};

