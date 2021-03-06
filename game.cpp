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
				/*set player space*/
				if(i == Bao.get_x_coordinate() && j == Bao.get_y_coordinate())
					Route3[i][j]->set_location('B');
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
	cout << "Treecko coordinates: " << treecko.get_x() << " " << treecko.get_y() << endl;
	cout << "Bagon coordinates: " << bagon.get_x() << " " << bagon.get_y() << endl;
	cout << "Froakie coordinates: " << froakie.get_x() << " " << froakie.get_y() << endl;
	cout << "Honedge coordinates: " << honedge.get_x() << " " << honedge.get_y() << endl;
	cout << "Larvitar coordinates: " << larvitar.get_x() << " " << larvitar.get_y() << endl;
	cout << "Starly coordinates: " << starly.get_x() << " " << starly.get_y() << endl;
	cout << "Trainer coordinates: " << Bao.get_x_coordinate() << " " << Bao.get_y_coordinate() << endl;
}

void Game::choose_starter_pokemon()
{
	int choice;
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
	allocate_positions(choice);
}

void Game::allocate_positions(int choice)
{
	int x, y;
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
			else if(Route3[Bao.get_x_coordinate() - 1][Bao.get_y_coordinate()]->get_location() == 'C')
				cout << "You have entered the Pokemon Center" << endl;
			else if(Route3[Bao.get_x_coordinate() - 1][Bao.get_y_coordinate()]->get_location() == 'W'){
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
			else if(Route3[Bao.get_x_coordinate() + 1][Bao.get_y_coordinate()]->get_location() == 'C')
				cout << "You have entered the Pokemon Center" << endl;
			else if(Route3[Bao.get_x_coordinate() + 1][Bao.get_y_coordinate()]->get_location() == 'W'){
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
			else if(Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() - 1]->get_location() == 'C')
				cout << "You have entered the Pokemon Center" << endl;
			else if(Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() - 1]->get_location() == 'W'){
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
			else if(Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() + 1]->get_location() == 'C')
				cout << "You have entered the Pokemon Center" << endl;
			else if(Route3[Bao.get_x_coordinate()][Bao.get_y_coordinate() + 1]->get_location() == 'W'){
				Bao.set_coordinates(Bao.get_x_coordinate(), Bao.get_y_coordinate() + 1);
			}
		}

	}
}

int Game::wild_encounter()
{
	if(Bao.get_x_coordinate() == treecko.get_x() && Bao.get_y_coordinate() == treecko.get_y()){
		system("clear");
		cout << "A wild Treecko has appeared!" << endl;
		return 1;
	}
	if(Bao.get_x_coordinate() == bagon.get_x() && Bao.get_y_coordinate() == bagon.get_y()){
		system("clear");
		cout << "A wild Bagon has appeared!" << endl;
		return 2;
	}
	if(Bao.get_x_coordinate() == froakie.get_x() && Bao.get_y_coordinate() == froakie.get_y()){
		system("clear");
		cout << "A wild Froakie has appeared!" << endl;
		return 3;
	}
	if(Bao.get_x_coordinate() == honedge.get_x() && Bao.get_y_coordinate() == honedge.get_y()){
		system("clear");
		cout << "A wild Honedge has appeared!" << endl;
		return 4;
	}
	if(Bao.get_x_coordinate() == larvitar.get_x() && Bao.get_y_coordinate() == larvitar.get_y()){
		system("clear");
		cout << "A wild Larvitar has appeared!" << endl;
		return 5;
	}
	if(Bao.get_x_coordinate() == starly.get_x() && Bao.get_y_coordinate() == starly.get_y()){
		system("clear");
		cout << "A wild Starly has appeared!" << endl;
		return 6;
	}
	return 0;
}

int Game::wild_pokemon_battle(int w)
{
	int end = 0, catched, choice;
	if(w == 1){
		cout << "Do you want to run(1) or catch(2)? ";
		cin >> choice;
		while(choice != 1 && choice != 2){
			cout << "Do you want to run(1) or catch(2)? ";
			cin >> choice;
		}
		if(choice == 1)
			cout << "You ran away!" << endl;
		else{
			if(Bao.get_pokeball_count() == 0)
				cout << "But you have no more Poke balls..." << endl;
			else{
				Bao.decrease_pokeball_count();
				catched = treecko.check_if_catched();
				if(catched == 0)
					return 1;
				else{
					Bao.add_pokemon(treecko);
					treecko.set_coordinates(0, 0);
				}
			}
		}
	}
	if(w == 2){
		cout << "Do you want to run(1) or catch(2)? ";
		cin >> choice;
		while(choice != 1 && choice != 2){
			cout << "Do you want to run(1) or catch(2)? ";
			cin >> choice;
		}
		if(choice == 1)
			cout << "You ran away!" << endl;
		else{
			if(Bao.get_pokeball_count() == 0)
				cout << "But you have no more Poke balls..." << endl;
			else{
				Bao.decrease_pokeball_count();
				catched = bagon.check_if_catched();
				if(catched == 0)
					return 1;
				else{
					Bao.add_pokemon(bagon);
					bagon.set_coordinates(0, 0);
				}
			}
		}
	}
	if(w == 3){
		cout << "Do you want to run(1) or catch(2)? ";
		cin >> choice;
		while(choice != 1 && choice != 2){
			cout << "Do you want to run(1) or catch(2)? ";
			cin >> choice;
		}
		if(choice == 1)
			cout << "You ran away!" << endl;
		else{
			if(Bao.get_pokeball_count() == 0)
				cout << "But you have no more Poke balls..." << endl;
			else{
				Bao.decrease_pokeball_count();
				catched = froakie.check_if_catched();
				if(catched == 0)
					return 1;
				else{
					Bao.add_pokemon(froakie);
					froakie.set_coordinates(0, 0);
				}
			}
		}
	}
	if(w == 4){
		cout << "Do you want to run(1) or catch(2)? ";
		cin >> choice;
		while(choice != 1 && choice != 2){
			cout << "Do you want to run(1) or catch(2)? ";
			cin >> choice;
		}
		if(choice == 1)
			cout << "You ran away!" << endl;
		else{
			if(Bao.get_pokeball_count() == 0)
				cout << "But you have no more Poke balls..." << endl;
			else{
				Bao.decrease_pokeball_count();
				catched = honedge.check_if_catched();
				if(catched == 0)
					return 1;
				else{
					Bao.add_pokemon(honedge);
					honedge.set_coordinates(0, 0);
				}
			}
		}
	}
	if(w == 5){
		cout << "Do you want to run(1) or catch(2)? ";
		cin >> choice;
		while(choice != 1 && choice != 2){
			cout << "Do you want to run(1) or catch(2)? ";
			cin >> choice;
		}
		if(choice == 1)
			cout << "You ran away!" << endl;
		else{
			if(Bao.get_pokeball_count() == 0)
				cout << "But you have no more Poke balls..." << endl;
			else{
				Bao.decrease_pokeball_count();
				catched = larvitar.check_if_catched();
				if(catched == 0)
					return 1;
				else{
					Bao.add_pokemon(larvitar);
					larvitar.set_coordinates(0, 0);
				}
			}
		}
	}
	if(w == 6){
		cout << "Do you want to run(1) or catch(2)? ";
		cin >> choice;
		while(choice != 1 && choice != 2){
			cout << "Do you want to run(1) or catch(2)? ";
			cin >> choice;
		}
		if(choice == 1)
			cout << "You ran away!" << endl;
		else{
			if(Bao.get_pokeball_count() == 0)
				cout << "But you have no more Poke balls..." << endl;
			else{
				Bao.decrease_pokeball_count();
				catched = starly.check_if_catched();
				if(catched == 0)
					return 1;
				else{
					Bao.add_pokemon(starly);
					starly.set_coordinates(0, 0);
				}
			}
		}
	}
	return end;
}



void Game::pokemon_game()
{
	int continues = 1, wild, battle;

	set_route3();
	choose_starter_pokemon();

	while(continues == 1){
		set_route3();
		view_current_pokemon();
		view_route3();
		move_character();
		wild = wild_encounter();
		if(wild != 0){
			do{
				battle = wild_pokemon_battle(wild);
			}while(battle != 0);
		}


		cout << "Continue? (1 yes): ";
		cin >> continues;
	}
}
