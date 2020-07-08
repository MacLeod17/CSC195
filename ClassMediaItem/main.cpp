
#include "bookseries.h"
#include "movie.h"
#include "products.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

enum class Actions {
    QUIT,
    LOAD,
    SAVE,
    DISPLAY_ALL,
    DISPLAY_TYPE,
    DISPLAY_ID,
    ADD,
    REMOVE,
    REMOVE_ALL

};

int main()
{
    Products products;

    bool exitRequested = false;
    do {
        cout << "Products Menu: " << endl;
        cout << " 1 - Load File" << endl;
        cout << " 2 - Save File" << endl;
        cout << " 3 - Display All Products" << endl;
        cout << " 4 - Display Products By Type" << endl;
        cout << " 5 - Display Products By ID" << endl;
        cout << " 6 - Add Product" << endl;
        cout << " 7 - Remove Products By ID" << endl;
        cout << " 8 - Remove All Products" << endl;
        cout << " 0 - Quit" << endl;

        int selection;
        cin >> selection;
        cin.ignore(80, '\n');
        Actions act = (Actions)selection;

        switch (act)
        {
        case Actions::QUIT:
            exitRequested = true;
            break;
        case Actions::LOAD:
        {
            cout << "Enter File Name: ";
            string fileName;
            getline(cin, fileName);
            products.load(fileName);
            break;
        }
        case Actions::SAVE:
        {
            cout << "Enter File Name: ";
            string fileName;
            getline(cin, fileName);
            products.save(fileName);
            break;
        }
        case Actions::DISPLAY_ALL:
            products.display();
            break;
        case Actions::DISPLAY_TYPE:
        {
            cout << "Types Available: " << endl;
            cout << " 0 - Book Series" << endl;
            cout << " 1 - Movie" << endl;
            int typeSelection;
            cin >> typeSelection;
            products.display((Product::Type)typeSelection);
            break;
        }
        case Actions::DISPLAY_ID:
        {
            cout << "Enter Product ID: ";
            int idSelection;
            cin >> idSelection;
            products.display(idSelection);
            break;
        }
        case Actions::ADD:
        {
            cout << "Types Available: " << endl;
            cout << " 0 - Book Series" << endl;
            cout << " 1 - Movie" << endl;
            int typeSelection;
            cin >> typeSelection;
            cin.ignore(80, '\n');
            Product* p = products.create((Product::Type)typeSelection);
            p->read(cin, cout);
            products.add(p);
            break;
        }
        case Actions::REMOVE:
        {
            cout << "Enter Product ID: ";
            int id;
            cin >> id;
            products.remove(id);
            break;
        }
        case Actions::REMOVE_ALL:
            products.remove();
            break;
        default:
            cout << "Invalid input. Please try again" << endl;
            break;
        }
    } while (!exitRequested);
}


