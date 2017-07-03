#ifndef POKEMONH
#define POKEMONH

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Pokemon
{
	protected:
		string name;
		int ATK, DEF, SPD, HP, catch_rate, x, y;
	public:
		Pokemon();
		string get_name();
		int get_ATK();
		int get_DEF();
		int get_SPD();
		int get_x();
		int get_y();
		void set_coordinates(int, int);
		int check_if_catched();
};



#endif