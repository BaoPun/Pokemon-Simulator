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
				this->Route3[i][j] = new Wall();
			else{
				this->Route3[i][j] = new Space();
				/*set player space*/
				if(i == Bao.get_x_coordinate() && j == Bao.get_y_coordinate())
					Route3[i][j]->set_location('B');
				/*set multiple patches of grass*/
				if(i > 2 && i < 9 && j > 5 && j < 14)
					Route3[i][j]->set_location('W');
				if(i > 13 && i < 26 && j > 1 && j < 6)
					Route3[i][j]->set_location('W');
				if(i > 11 && i < 15 && j > 23 && j < 33)
					Route3[i][j]->set_location('W');
				if(i > 20 && i < 26 && j > 18 && j < 24)
					Route3[i][j]->set_location('W');
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
