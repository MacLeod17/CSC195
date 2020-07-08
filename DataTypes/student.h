#pragma once
#include <iostream>

class Student {
public:
    std::string name;
    int age;
    float gpa;

public:
    Student() {
        name = "Unknown";
        age = 18;
        gpa = 2.0f;
    }
    Student(std::string name_, int age_, float gpa_) {
        name = name_;
        age = age_;
        gpa = gpa_;
    }
    void write();
    void read();
};