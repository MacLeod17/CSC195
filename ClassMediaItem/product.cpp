
#include "product.h"
#include <iostream>
#include <string>

int Product::uniqueId = 0;

using namespace std;

void Product::read(std::istream& istream, std::ostream& ostream) {
	ostream << "Name: ";
	string inputSeries;
	getline(istream, inputSeries);
	setName(inputSeries);

	ostream << "Year: ";
	int inputYear;
	istream >> inputYear;
	setYear(inputYear);

	showGenres();
	int inputGenre;
	istream >> inputGenre;
	setGenre(inputGenre);

	istream.ignore(80, '\n');
}
void Product::write(std::ostream& ostream) {
	ostream << "Type: " << getType() << endl;
	ostream << "Id: " << getId() << endl;
	ostream << "Name: " << getName() << endl;
	ostream << "Year: " << getYear() << endl;
	ostream << "Genre: " << getGenre() << endl;
}

void Product::read(std::ifstream& istream) {
	istream >> id;
	istream.ignore(80, '\n');

	string inputSeries;
	getline(istream, inputSeries);
	setName(inputSeries);

	int inputYear;
	istream >> inputYear;
	setYear(inputYear);
	istream.ignore(80, '\n');

	string inputGenre;
	getline(istream, inputGenre);
	setGenre(convertGenre(inputGenre));
}
void Product::write(std::ofstream& ostream) {
	ostream << getType() << endl;
	ostream << id << endl;
	ostream << getName() << endl;
	ostream << getYear() << endl;
	ostream << getGenre() << endl;
}

std::string Product::getGenre()
{
	switch (genre)
	{
	case Product::Genre::HORROR:
		return "Horror";
		break;
	case Product::Genre::DARK_FANTASY:
		return "Dark Fantasy";
		break;
	case Product::Genre::FANTASY:
		return "Fantasy";
		break;
	case Product::Genre::SCIENCE_FICTION:
		return "Science Fiction";
		break;
	case Product::Genre::NONFICTION:
		return "Non-Fiction";
		break;
	case Product::Genre::REALISTIC_FICTION:
		return "Realistic Fiction";
		break;
	case Product::Genre::THRILLER:
		return "Thriller";
		break;
	case Product::Genre::ADVENTURE:
		return "Adventure";
		break;
	case Product::Genre::MYSTERY:
		return "Mystery";
		break;
	case Product::Genre::ROMANCE:
		return "Romance";
		break;
	case Product::Genre::HISTORICAL_FICTION:
		return "Historical Fiction";
		break;
	case Product::Genre::DYSTOPIAN:
		return "Dystopian";
		break;
	case Product::Genre::COOKING:
		return "Cooking";
		break;
	case Product::Genre::OTHER:
		return "Other";
		break;
	default:
		return "Unspecified Genre";
		break;
	}
}

void Product::setGenre(int genre_)
{
	genre = (Product::Genre)genre_;
}

int Product::convertGenre(string genre_)
{
	if (genre_ == "Horror") { return 0; }
	else if (genre_ == "Dark Fantasy") { return 1; }
	else if (genre_ == "Fantasy") { return 2; }
	else if (genre_ == "Science Fiction") { return 3; }
	else if (genre_ == "Non-Fiction") { return 4; }
	else if (genre_ == "Realistic Fiction") { return 5; }
	else if (genre_ == "Thriller") { return 6; }
	else if (genre_ == "Adventure") { return 7; }
	else if (genre_ == "Mystery") { return 8; }
	else if (genre_ == "Romance") { return 9; }
	else if (genre_ == "Historical Fiction") { return 10; }
	else if (genre_ == "Dystopian") { return 11; }
	else if (genre_ == "Cooking") { return 12; }
	else if (genre_ == "Other") { return 13; }
}

void Product::showGenres()
{
	cout << "Genre: " << endl;
	cout << " 0 - Horror" << endl;
	cout << " 1 - Dark Fantasy" << endl;
	cout << " 2 - Fantasy" << endl;
	cout << " 3 - Science Fiction" << endl;
	cout << " 4 - Non-Fiction" << endl;
	cout << " 5 - Realistic Fiction" << endl;
	cout << " 6 - Thriller" << endl;
	cout << " 7 - Adventure" << endl;
	cout << " 8 - Mystery" << endl;
	cout << " 9 - Romance" << endl;
	cout << " 10 - Historical Fiction" << endl;
	cout << " 11 - Dystopian" << endl;
	cout << " 12 - Cooking" << endl;
	cout << " 13 - Other" << endl;
}

std::string Product::getType()
{
	switch (type)
	{
	case Product::Type::BOOKSERIES:
		return "Book Series";
		break;
	case Product::Type::MOVIE:
		return "Movie";
		break;
	default:
		break;
	}
}

void Product::setType(Product::Type type_)
{
	type = type_;
}

int Product::convertType(std::string type_)
{
	if (type_ == "Book Series") { return 0; }
	else if (type_ == "Movie") { return 1; }
}

void Product::showTypes()
{
	cout << "Types: " << endl;
	cout << " 0 - Book Series" << endl;
	cout << " 1 - Movie" << endl;
}
