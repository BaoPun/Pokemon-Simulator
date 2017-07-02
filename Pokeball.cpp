#include "./Pokeball.h"

Pokeball::Pokeball()
{
	description = "A standard Poke ball with a normal catch rate";
	catch_multiplier = 25;
}

string Pokeball::ball_description()
{
	cout << description << endl;
	return description;
}

int Pokeball::catch_rate()
{
	/*catch rate out of 100*/
	return catch_multiplier;
}