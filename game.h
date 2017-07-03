#ifndef GAMEH
#define GAMEH

#include "./Bagon.h"
#include "./Froakie.h"
#include "./Starly.h"
#include "./Honedge.h"
#include "./Larvitar.h"
#include "./Treecko.h"
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
};

#endif