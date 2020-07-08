// DataTypes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "math.h"
#include "student.h"
#include <iostream>

using namespace std;

int main()
{
    Student greg("Greg", 19, 3.7f);
    //greg.name = "Greg";
    //greg.age = 19;
    //greg.gpa = 3.7f;

    greg.read();
    greg.write();

    cout << "Square: " << square(5) << endl;
    cout << "Square: " << square(5.5f) << endl;
}
