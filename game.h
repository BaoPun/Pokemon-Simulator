#ifndef GAMEH
#define GAMEH

#include "./Trainer.h"
#include "./Wall.h"
#include "./Space.h"

class Game
{
	private:
		Field ***Route3;
		Trainer Bao;
		Treecko treecko;
		Bagon bagon;
		Froakie froakie;
		Starly starly;
		Honedge honedge;
		Larvitar larvitar;
	public:
		Game();
		~Game();
		void set_route3();
		void view_route3();
		void choose_starter_pokemon();
		void allocate_positions(int);
		void view_current_pokemon();
		void move_character();
		int wild_encounter();
		int wild_pokemon_battle(int);


		void pokemon_game();
};

#endif