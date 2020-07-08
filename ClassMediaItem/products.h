#pragma once

#include "bookseries.h"
#include "movie.h"
#include <list>

class Products
{
public:
	Products() {

	}

	void load(const std::string& filename);
	void save(const std::string& filename);
	void display();
	void display(Product::Type type);
	void display(int id);

	Product* create(Product::Type type);
	void add(Product* product);
	void remove();
	void remove(int id);

protected:
	std::list<class Product*> products;
};

