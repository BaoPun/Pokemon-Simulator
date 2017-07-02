#include "./Trainer.h"

Trainer::Trainer()
{
	pokeball_count = 10;
	pokeballs = new Pokeball[pokeball_count];
	for(int i = 0; i < pokeball_count; i++)
		pokeballs[i] = Pokeball();
	x = 34;
	y = 17;
}

Trainer::~Trainer()
{
	delete [] pokeballs;
}

int Trainer::get_x_coordinate()
{
	return x;
}

int Trainer::get_y_coordinate()
{
	return y;
}

void Trainer::set_x_coordinate(int xp) 
{
	x = xp;
}

void Trainer::set_y_coordinate(int yp)
{
	y = yp;
}

int Trainer::increase_pokeball_count()
{
	return pokeball_count++;
}

int Trainer::decrease_pokeball_count()
{
	return pokeball_count--;
}

