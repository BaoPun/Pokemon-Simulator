#ifndef TRAINERH
#define TRAINERH

#include "./Pokeball.h"

class Trainer
{
	private:
		Pokeball *pokeballs;
		int pokeball_count; 
		int x, y;

	public:
		Trainer();
		~Trainer();
		int get_x_coordinate();
		int get_y_coordinate();
		void set_x_coordinate(int);
		void set_y_coordinate(int);
		int increase_pokeball_count();
		int decrease_pokeball_count();

};


#endif