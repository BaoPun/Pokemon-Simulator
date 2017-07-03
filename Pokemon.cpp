#include "./Pokemon.h"

Pokemon::Pokemon()
{
	name = "";
	ATK = DEF = SPD = HP = 0;
}	

void Pokemon::set_name(string s)
{
	name = s;
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
