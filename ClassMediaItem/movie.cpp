#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

void Movie::read(std::istream& istream, std::ostream& ostream)
{
	Product::read(istream, ostream);

	ostream << "Minutes Long: ";
	int lengthInput;
	istream >> lengthInput;
	setMinutesLong(lengthInput);

	istream.ignore(80, '\n');

	Product::setType((Product::Type)1);
}

void Movie::write(std::ostream& ostream)
{
	Product::write(ostream);

	ostream << "Minutes Long: " << getMinutesLong() << endl;
	ostream << endl;
}

void Movie::read(std::ifstream& istream)
{
	Product::read(istream);

	int lengthInput;
	istream >> lengthInput;
	setMinutesLong(lengthInput);
	istream.ignore(80, '\n');
}

void Movie::write(std::ofstream& ostream)
{
	Product::write(ostream);

	ostream << getMinutesLong() << endl;
}
