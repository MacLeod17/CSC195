
#include "array.h"
#include "vector.h"
#include "list.h"
#include <iostream>

using namespace std;

//class A
//{
//public:
//    A() { cout << "Default" << endl; }
//    A(int i, float f) : data { i }, fdata{f} 
//    { 
//        cout << "Constructor" << endl; 
//    }
//    A(const A& other) 
//    { 
//        data = other.data;
//        fdata = other.fdata;
//        cout << "Copy" << endl; 
//    }
//
//    ~A() { cout << "Destructor" << endl; }
//    A& operator = (const A& other) 
//    { 
//        cout << "Assignment operator" << endl;
//        return *this; 
//    }
//
//    int getData() { return data; }
//protected:
//    int data{ 0 };
//    float fdata{ 0.0f };
//};
//
//void function(A& o) 
//{
//    //
//}

template<typename T>
void displayVector(const gk::vector<T>& v) 
{
    for (size_t i = 0; i < v.size(); i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void displayArray(const gk::array<T, 5>& a)
{
    for (size_t i = 0; i < a.size(); i++) 
    { 
        cout << a[i] << " "; 
    }
    cout << endl;
}


int main()
{
    gk::list<int> numbers{ 12, 78, 12, 34, 9 };
    numbers.push_back(10);
    numbers.push_front(8);
    numbers.write(cout);

    gk::list<int> copy;
    copy = numbers;
    copy.pop_front();
    copy.pop_back();
    copy.pop_back();
    copy.write(cout);

    copy.remove(12);
    copy.write(cout);

    copy.resize(10, 99);
    copy.write(cout);

    numbers.reverse();
    numbers.write(cout);

    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Empty: " << numbers.empty() << endl;

    
    /*
    gk::list<int> numbers;
    numbers.push_front(5);
    numbers.push_front(8);
    numbers.write(cout);
    numbers.push_back(12);
    numbers.push_back(34);
    numbers.write(cout);
    cout << "Size: " << numbers.size() << endl;
    numbers.clear();
    */

    /*
    cout << "Vector\n";
    gk::vector<int> numbers{ 43, 23, 56, 7, 16 };
    numbers[0] = 84;
    numbers.push_back(99);
    displayVector(numbers);

    cout << "Copy\n";
    gk::vector<int> copy;
    copy = numbers;
    copy.pop_back();
    copy.pop_back();
    displayVector(copy);

    cout << "Swap\n";
    numbers.swap(copy);
    displayVector(numbers);
    displayVector(copy);

    cout << "Clear\n";
    copy.clear();
    displayVector(copy);

    cout << "Resize\n";
    numbers.resize(10, 5);
    numbers.reserve(20);
    displayVector(numbers);

    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Max Size: " << numbers.max_size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    cout << "Empty: " << numbers.empty() << endl;
    cout << "Data: " << numbers.data() << endl;
    */
    
    /*
    cout << "Array\n";
    gk::array<int, 5> numbers{ 7, 10, 65, 23, 14 };
    numbers[0] = 23;
    displayArray(numbers);

    cout << "Copy\n";
    gk::array<int, 5> copy{ numbers };
    copy[0] = 56;
    copy[4] = 8;
    displayArray(copy);

    cout << "Swap\n";
    numbers.swap(copy);
    displayArray(numbers);
    displayArray(copy);

    cout << "Fill\n";
    copy.fill(21);
    displayArray(copy);

    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Data: " << numbers.data() << endl;
    */

    /*
    int i{ 1234 };
    char c{ static_cast<char>(i) };
    */

    /*
    gk::vector<int> vnumbers{5, 8};
    vnumbers.push_back(10);
    vnumbers.push_back(43);
    displayVector(vnumbers);
    */

    /*
    gk::vector<int> vcopy;
    vcopy = vnumbers;
    */
    
    /*
    gk::array<int, 5> numbers{23, 54, 12, 7, 12};
    for (int i = 0; i < 5; i++) { cout << numbers[i] << " "; }
    cout << endl;
    */
    
    /*
    gk::array<int, 5> copy{ numbers };
    copy = numbers;
    for (int i = 0; i < 5; i++) { cout << copy[i] << " "; }
    cout << endl;
    */
    
    /*
    A o1;
    A o2(1, 2.0f);
    A o4;
    o4 = o2;
    {
        A o3{ o2 };
        cout << o3.getData() << endl;
    }
    */
}
