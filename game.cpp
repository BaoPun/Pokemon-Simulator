#include "./game.h"

Game::Game() : Bao()
{
	Route3 = new Field**[35];
	for(int i = 0; i < 35; i++)
		Route3[i] = new Field*[35];
}

Game::~Game()
{
	for(int i = 0; i < 35; i++){
		for(int j = 0; j < 35; j++)
			delete Route3[i][j];
		delete [] Route3[i];
	}
	delete [] Route3;
}

void Game::set_route3()
{
	for(int i = 0; i < 35; i++){
		for(int j = 0; j < 35; j++){
			if(i == 0 || (i == 34 && j != 17) || j == 0 || j == 34)
				Route3[i][j] = new Wall();
			else{
				Route3[i][j] = new Space();
				if(i == 34 && j == 17)
					Route3[i][j]->set_location('B');
				else
					Route3[i][j]->set_location(' ');
			}
		}
	}
}

void Game::view_route3()
{
	for(int i = 0; i < 35; i++){
		for(int j = 0; j < 35; j++)
			cout << Route3[i][j]->get_location() << " ";
		cout << endl;
	}
}
