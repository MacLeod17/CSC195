
#include <iostream>
#include <vector>

using namespace std;

void function(int i) {
    cout << i << endl;
    cout << &i << endl;
}

void overflow() {
    int big[10000];
    overflow();
}

void swap(int& i1, int& i2) {
    int temp = i1;
    i1 = i2;
    i2 = temp;
}

void swap(int* i1, int* i2) {
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}

void print(vector<int>& numbers) {

}

int main()
{
    int i = 5;
    i += 5;

    int j = 8;

    int& r = i; //reference
    int* p = &i; //pointer
    //Pointers can be null, references cannot
    //If p references to i and i references to r, changing p changes r

    cout << &i << endl; //Address of i
    cout << p << endl; //Address of variable that p points to (i)
    cout << *p << endl; //Value of variable that p points to
    cout << &p << endl; //Address of p

    int* q = new int(4); //new Allocates memory on the heap (permanent memory)
    int* k = new int[80];

    delete q; //delete de-allocates the heap memory for the variable
    delete[] k;

    //overflow();
    //function(i);

    swap(i, j);

    cout << i << endl;
    cout << &i << endl;

    cout << j << endl;
    cout << &j << endl;

    vector<int> numbers[1000];
    /*
        & prints memory address of variable
        passing variable into a function copies the value, but not memory address, of variable (creating a separate, temporary variable)
        putting variable& into function parameters references original variable, changes to variable will stay after function ends
    */
}