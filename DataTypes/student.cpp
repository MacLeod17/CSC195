
#include "student.h"
#include <string>
#include <iostream>

using namespace std;

void Student::write() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
}

void Student::read() {
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "GPA: ";
    cin >> gpa;
}