#include "products.h"
#include <iostream>
#include <string>

using namespace std;

void Products::load(const std::string& filename)
{
    remove();//This clears everything in products so that entries from 2 files don't mix

    ifstream ifile(filename);
    if (ifile.is_open()) {
        while (!ifile.eof()) {
            Product* p = nullptr;
            string type;
            getline(ifile, type);
            if (type == "Book Series") {
                p = new BookSeries;
                p->setType(Product::Type::BOOKSERIES);
                p->read(ifile);
                products.push_back(p);
            }
            else if (type == "Movie") {
                p = new Movie;
                p->setType(Product::Type::MOVIE);
                p->read(ifile);
                products.push_back(p);
            }
            else {
                cout << "Error!" << endl;
            }
            if (ifile.peek() == EOF) break;
        }
        ifile.close();
    }
}

void Products::save(const std::string& filename)
{
    ofstream ofile(filename);
    if (ofile.is_open()) {
        for (Product* p : products) {
            p->write(ofile);
        }
    }
    ofile.close();
}

void Products::display()
{
    for (Product* p : products) {
        p->write(cout);
    }
}

void Products::display(Product::Type type)
{
    for (Product* p : products) {
        if (type == (Product::Type)p->convertType(p->getType())) {
            p->write(cout);
        }
    }
}

void Products::display(int id)
{
    for (Product* p : products) {
        if (id == p->getId()) {
            p->write(cout);
        }
    }
}

Product* Products::create(Product::Type type)
{
    Product* p = nullptr;

    switch (type)
    {
    case Product::Type::BOOKSERIES:
        p = new BookSeries();
        break;
    case Product::Type::MOVIE:
        p = new Movie();
        break;
    }
    return p;
}

void Products::add(Product* product)
{
    products.push_back(product);
}

void Products::remove()
{
    for (Product* p : products) {
        delete p;
    }
    products.clear();
}

void Products::remove(int id)
{
    for (auto iter = products.begin(); iter != products.end(); iter++)
    {
        if ((*iter)->getId() == id)
        {
            delete* iter;
            products.erase(iter);
            break;
        }
    }

}
