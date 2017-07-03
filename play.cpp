#include "./game.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	cout << "|-----------     THIS IS A MOCK VERSION OF THE POKEMON GAMES     ----------|" << endl;

	Game g;
	g.pokemon_game();

	return 0;
}
