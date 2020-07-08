#pragma once

#include <iostream>
#include <fstream>

class Product {
public:
	enum class Genre {
		HORROR,
		DARK_FANTASY,
		FANTASY,
		SCIENCE_FICTION,
		NONFICTION,
		REALISTIC_FICTION,
		THRILLER,
		ADVENTURE,
		MYSTERY,
		ROMANCE,
		HISTORICAL_FICTION,
		DYSTOPIAN,
		COOKING,
		OTHER
	};
	enum class Type {
		BOOKSERIES,
		MOVIE
	};
private:
	std::string name;
	int year;
	Genre genre;
	Type type;
protected:
	int id;
	static int uniqueId;
public:
	Product() {
		setName("The Thin Executioner");
		setYear(2019);
		setGenre(1);
		id = uniqueId++;
	};
	Product(std::string name_, int year_, int genre_) {
		setName(name_);
		setYear(year_);
		setGenre(genre_);
		id = uniqueId++;
	}

	virtual void read(std::istream& istream, std::ostream& ostream);
	virtual void write(std::ostream& ostream);

	virtual void read(std::ifstream& istream);
	virtual void write(std::ofstream& ostream);

	std::string getName() { return name; }
	void setName(std::string name_) { name = name_; }

	int getYear() { return year; }
	void setYear(int year_) { year = year_; }

	std::string getGenre();
	void setGenre(int genre_);
	int convertGenre(std::string genre_);
	void showGenres();

	std::string getType();
	void setType(Type type_);
	int convertType(std::string type_);
	void showTypes();

	int getId() { return id; }
};