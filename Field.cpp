#include "./Field.h"

Field::Field()
{

}

char Field::get_location()
{
	return space;
}

void Field::set_location(char s)
{
	space = s;
}