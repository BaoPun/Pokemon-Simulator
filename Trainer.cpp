#include "./Trainer.h"

Trainer::Trainer()
{
	pokemon_count = 0;
	pokeball_count = 10;
	pokeballs = new Pokeball[pokeball_count];
	for(int i = 0; i < pokeball_count; i++)
		pokeballs[i] = Pokeball();
	x = 33;
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

void Trainer::set_coordinates(int xp, int yp)
{
	x = xp;
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

void Trainer::add_pokemon(Pokemon p)
{
	pokemon[pokemon_count] = p;
	pokemon_count++;
}

void Trainer::view_current_pokemon()
{
	cout << "\nViewing currently owned Pokemon." << endl;
	for(int i = 0; i < pokemon_count; i++)
		cout << "  " << i+1 << ".  " << pokemon[i].get_name() << " ";
	cout << endl;
}
