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
			if(i == 0 || i == 34 || j == 0 || j == 34)
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
				/*set a pokemon center and store*/
				if(i == 11 && j == 11)
					Route3[i][j]->set_location('C');
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

void Game::choose_starter_pokemon()
{
	int choice, x, y;
	cout << "Choose a starter pokemon from these options: " << endl;
	cout << "(1)  Treecko" << endl;
	cout << "(2)  Bagon" << endl;
	cout << "(3)  Froakie" << endl;
	cout << "(4)  Honedge" << endl;
	cout << "(5)  Larvitar" << endl;
	cout << "(6)  Starly" << endl;
	cout << "Option: ";
	cin >> choice;
	while(choice < 1 || choice > 6){
		cout << "Please choose a valid starter: ";
		cin >> choice;
	}
	if(choice == 1){
		cout << "You have chosen Treecko as your starter." << endl;
		Bao.add_pokemon(treecko);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W'){
			x = rand()%35;
			y = rand()%35;
		}
		bagon.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == bagon.get_x() && y == bagon.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		froakie.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		honedge.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == honedge.get_x() && y == honedge.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		larvitar.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == honedge.get_x() && y == honedge.get_y()) || (x == larvitar.get_x() && y == larvitar.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		starly.set_coordinates(x, y);

		
	}
	if(choice == 2){
		cout << "You have chosen Bagon as your starter." << endl;
		Bao.add_pokemon(bagon);
		
		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W'){
			x = rand()%35;
			y = rand()%35;
		}
		treecko.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		froakie.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == froakie.get_x() && y == froakie.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		honedge.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == honedge.get_x() && y == honedge.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		larvitar.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == honedge.get_x() && y == honedge.get_y()) || (x == larvitar.get_x() && y == larvitar.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		starly.set_coordinates(x, y);

	}
	if(choice == 3){
		cout << "You have chosen Froakie as your starter." << endl;
		Bao.add_pokemon(froakie);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W'){
			x = rand()%35;
			y = rand()%35;
		}
		treecko.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		bagon.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		honedge.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == honedge.get_x() && y == honedge.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		larvitar.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == honedge.get_x() && y == honedge.get_y()) || (x == larvitar.get_x() && y == larvitar.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		starly.set_coordinates(x, y);
		
	}
	if(choice == 4){
		cout << "You have chosen Honedge as your starter." << endl;
		Bao.add_pokemon(honedge);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W'){
			x = rand()%35;
			y = rand()%35;
		}
		treecko.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		bagon.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		froakie.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		larvitar.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == larvitar.get_x() && y == larvitar.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		starly.set_coordinates(x, y);
		
	}
	if(choice == 5){
		cout << "You have chosen Larvitar as your starter." << endl;
		Bao.add_pokemon(larvitar);
		
		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W'){
			x = rand()%35;
			y = rand()%35;
		}
		treecko.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		bagon.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		froakie.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		honedge.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == honedge.get_x() && y == honedge.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		starly.set_coordinates(x, y);

	}
	if(choice == 6){
		cout << "You have chosen Starly as your starter." << endl;
		Bao.add_pokemon(starly);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W'){
			x = rand()%35;
			y = rand()%35;
		}
		treecko.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		bagon.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		froakie.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		honedge.set_coordinates(x, y);

		x = rand()%35;
		y = rand()%35;
		while(Route3[x][y]->get_location() != 'W' || (x == treecko.get_x() && y == treecko.get_y()) || (x == bagon.get_x() && y == bagon.get_y()) || (x == froakie.get_x() && y == froakie.get_y()) || (x == honedge.get_x() && y == honedge.get_y())){
			x = rand()%35;
			y = rand()%35;
		}
		larvitar.set_coordinates(x, y);
		
	}
}

void Game::view_current_pokemon()
{
	Bao.view_current_pokemon();
}

void Game::move_character()
{
	int direction;
	cout << "Up(1), Down(2), Left(3), or Right(4): ";
	cin >> direction;
	while(direction < 1 || direction > 4){
		cout << "Choose a direction... ";
		cin >> direction;
	}
	if(direction == 1){
		if(Bao.get_x_coordinate() - 1 == 0)
			move_character();
		else{
			if(Route3[Bao.get_x_coordinate() - 1][Bao.get_y_coordinate()]->get_location() == ' '){
				Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate()]->set_location(' ');
				Route3[Bao.get_x_coordinate() - 1][Bao.get_y_coordinate()]->set_location('B');
				Bao.set_coordinates(Bao.get_x_coordinate() - 1, Bao.get_y_coordinate());
			}

		}

	}
	if(direction == 2){
		if(Bao.get_x_coordinate() + 1 == 34)
			move_character();
		else{
			if(Route3[Bao.get_x_coordinate() + 1][Bao.get_y_coordinate()]->get_location() == ' '){
				Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate()]->set_location(' ');
				Route3[Bao.get_x_coordinate() + 1][Bao.get_y_coordinate()]->set_location('B');
				Bao.set_coordinates(Bao.get_x_coordinate() + 1, Bao.get_y_coordinate());
			}
		}

	}
	if(direction == 3){
		if(Bao.get_y_coordinate() - 1 == 0)
			move_character();
		else{
			if(Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() - 1]->get_location() == ' '){
				Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate()]->set_location(' ');
				Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() - 1]->set_location('B');
				Bao.set_coordinates(Bao.get_x_coordinate(), Bao.get_y_coordinate() - 1);
			}
		}

	}
	if(direction == 4){
		if(Bao.get_y_coordinate() + 1 == 34)
			move_character();
		else{
			if(Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() + 1]->get_location() == ' '){
				Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate()]->set_location(' ');
				Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() + 1]->set_location('B');
				Bao.set_coordinates(Bao.get_x_coordinate(), Bao.get_y_coordinate() + 1);
			}
		}

	}
}

/*int Game::check_grass_encounter(int d)
{

}*/









void Game::pokemon_game()
{
	int continues = 1;

	set_route3();
	choose_starter_pokemon();

	while(continues == 1){
		view_current_pokemon();
		view_route3();
		move_character();
		cout << "Continue? (1 yes): ";
		cin >> continues;
	}
}
