#pragma once

#include "product.h"
#include <iostream>

class BookSeries : public Product {
private:
	int bookCount;
	int pageCount;
	std::string authorName;
public:
	BookSeries() : Product() {
		setBookCount(1);
		setPageCount(500);
		setAuthorName("Darren Shan");
	}
	BookSeries(int bookCount_, int pageCount_, std::string authorName_, std::string name_, int year_, int genre_) : Product(name_, year_, genre_){
		setBookCount(bookCount_);
		setPageCount(pageCount_);
		setAuthorName(authorName_);
	}

	void read(std::istream& istream, std::ostream& ostream);
	void write(std::ostream& ostream);

	void read(std::ifstream& istream);
	void write(std::ofstream& ostream);
	
	int getBookCount() { return bookCount; }
	void setBookCount(int bookCount_) { bookCount = bookCount_; }

	int getPageCount() { return pageCount; }
	void setPageCount(int pageCount_) { pageCount = pageCount_; }

	std::string getAuthorName() { return authorName; }
	void setAuthorName(std::string authorName_) { authorName = authorName_; }
};