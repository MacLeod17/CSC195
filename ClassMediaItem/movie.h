#pragma once

#include "product.h"
#include <iostream>

class Movie : public Product {
private:
	int minutesLong;
public:
	Movie() : Product() {
		setMinutesLong(120);
	}
	Movie(int minutesLong_, std::string name_, int year_, int genre_) : Product(name_, year_, genre_) {
		setMinutesLong(minutesLong_);
	}

	void read(std::istream& istream, std::ostream& ostream);
	void write(std::ostream& ostream);

	void read(std::ifstream& istream);
	void write(std::ofstream& ostream);

	int getMinutesLong() { return minutesLong; }
	void setMinutesLong(int minutesLong_) { minutesLong = minutesLong_; }
};