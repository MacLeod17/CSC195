
#include "bookseries.h"
#include <iostream>
#include <string>

using namespace std;

void BookSeries::read(std::istream& istream, std::ostream& ostream)
{
	Product::read(istream, ostream);

	ostream << "Author Name: ";
	string inputAuthor;
	getline(istream, inputAuthor);
	setAuthorName(inputAuthor);

	ostream << "Book Count: ";
	int inputBookCount;
	istream >> inputBookCount;
	setBookCount(inputBookCount);

	ostream << "Page Count (Total): ";
	int inputPageCount;
	istream >> inputPageCount;
	setPageCount(inputPageCount);

	ostream << endl;
	istream.ignore(80, '\n');

	Product::setType((Product::Type)0);
}

void BookSeries::write(std::ostream& ostream)
{
	Product::write(ostream);

	ostream << "Author Name: " << getAuthorName() << endl;
	ostream << "Book Count: " << getBookCount() << endl;
	ostream << "Page Count (Total): " << getPageCount() << endl;
	ostream << endl;
}

void BookSeries::read(std::ifstream& istream)
{
	Product::read(istream);

	string inputAuthor;
	getline(istream, inputAuthor);
	setAuthorName(inputAuthor);

	int inputBookCount;
	istream >> inputBookCount;
	setBookCount(inputBookCount);
	istream.ignore(80, '\n');

	int inputPageCount;
	istream >> inputPageCount;
	setPageCount(inputPageCount);
	istream.ignore(80, '\n');
}

void BookSeries::write(std::ofstream& ostream)
{
	Product::write(ostream);

	ostream  << getAuthorName() << endl;
	ostream << getBookCount() << endl;
	ostream << getPageCount() << endl;
}
