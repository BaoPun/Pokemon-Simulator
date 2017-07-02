#ifndef POKEBALLH
#define POKEBALLH

#include "./Pokemon.h"

class Pokeball
{
	private:
		string description;
		int catch_multiplier;
	public:
		Pokeball();
		string ball_description();
		int catch_rate();
};


#endif