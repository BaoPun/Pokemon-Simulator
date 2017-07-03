#ifndef POKEMONH
#define POKEMONH

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Pokemon
{
	protected:
		string name;
		int ATK, DEF, SPD, HP;
	public:
		Pokemon();
		void set_name(string);
		int get_ATK();
		int get_DEF();
		int get_SPD();
};



#endif