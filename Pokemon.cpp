#include "./Pokemon.h"

Pokemon::Pokemon()
{
	name = "";
	ATK = DEF = SPD = HP = catch_rate = x = y = 0;
}	

string Pokemon::get_name()
{
	return name;
}

int Pokemon::get_ATK()
{
	return ATK;
}

int Pokemon::get_DEF()
{
	return DEF;
}

int Pokemon::get_SPD()
{
	return SPD;
}

int Pokemon::get_x()
{
	return x;
}

int Pokemon::get_y()
{
	return y;
}

void Pokemon::set_coordinates(int xs, int ys)
{
	x = xs;
	y = ys;
}

int Pokemon::check_if_catched()
{
	int rate = (catch_rate * 2) + catch_rate;
	int catched = rand()%100;
	if(catched >= rate){
		cout << "You have caught the pokemon!" << endl;
		return 1;
	}
	else{
		cout << "Oh no, the pokemon broke free!" << endl;
		return 0;
	}
}

