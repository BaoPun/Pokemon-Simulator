#ifndef FIELDH
#define FIELDH

class Field
{
	protected:
		char space;
	public:
		Field();
		char get_location();
		void set_location(char);
};

#endif

