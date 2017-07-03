#ifndef TRAINERH
#define TRAINERH

#include "./Pokeball.h"
#include "./Treecko.h"
#include "./Bagon.h"
#include "./Froakie.h"
#include "./Honedge.h"
#include "./Starly.h"
#include "./Larvitar.h"

class Trainer
{
	private:
		Pokemon pokemon[6];
		Pokeball *pokeballs;
		int pokeball_count, pokemon_count; 
		int x, y;

	public:
		Trainer();
		~Trainer();
		int get_x_coordinate();
		int get_y_coordinate();
		void set_coordinates(int, int);
		int get_pokeball_count();
		void increase_pokeball_count();
		void decrease_pokeball_count();
		void add_pokemon(Pokemon);
		void view_current_pokemon();

};


#endif