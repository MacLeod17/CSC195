
#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

// pointer swap (4a)
//void swap(v1, v2)
void swap(int* i1, int* i2) 
{
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}

// reference swap (7a)
//void swap(v1, v2)
void swap(int& i1, int& i2) {
	int temp = i1;
	i1 = i2;
	i2 = temp;
}

// template (11)
 template<typename T>
 T max_value(T v1, T v2) {
	 return max(v1, v2);
 }

// animal class
class Animal {
public:
	Animal() {
		setName("Bruh");
		setLifespan(10);
	}
	Animal(string name_, int lifespan_) {
		setName(name_);
		setLifespan(lifespan_);
	}

	virtual string say() { return ""; };

	string getName() { return name; }
	void setName(string name_) { name = name_; }

	int getLifespan() { return lifespan; }
	void setLifespan(int lifespan_) { lifespan = lifespan_; }
protected:
	string name;
	int lifespan;
};

// derived animal class 1
class Dog : public Animal {
public:
	Dog() : Animal() {};
	Dog(string name_, int lifespan_) : Animal(name_, lifespan_) {};

	string say() override { return "Woof"; }
};

// derived animal class 2
class Cat : public Animal {
public:
	Cat() : Animal() {};
	Cat(string name_, int lifespan_) : Animal(name_, lifespan_) {};

	string say() override { return "Meow"; }
};

ostream& operator << (ostream& stream, Animal* animal)
{
	cout << animal->getName() << " " << animal->getLifespan() << endl;
	return stream;
}

int main()
{
	// POINTER

	// 1) create a pointer (ptr1) that points to i1
	int i1 = 10;

	int* ptr1 = &i1;

	// 2a) change the value of i1 to 20 by a pointer dereference of ptr1 
	// 2b) print the dereference of ptr1
	*ptr1 = 20;
	cout << *ptr1 << endl;

	// 3) create a pointer (ptr2) and set it to point at what ptr1 points at
	int* ptr2 = &(*ptr1);
	cout << *ptr2 << endl;

	// 4a) create a function to swap i2 and i3 with pointers
	// 4b) print the values of i2 and i3 after the swap
	int i2 = 23;
	int i3 = 45;
	swap(&i2, &i3);
	cout << i2 << " " << i3 << endl;

	// REFERENCE

	// 5) create a reference (ref1) that references i5
	int i5 = 30;

	int& ref1 = i5;
	
	// 6a) change the value of i5 using the reference variable
	// 6b) print i5 to show that a change was made
	ref1 = 69;
	cout << i5 << endl;

	// 7a) create a function to swap i2 and i3 with references
	// 7b) print the values of i2 and i3 after the swap
	swap(i2, i3);
	cout << i2 << " " << i3 << endl;

	// DYNAMIC MEMORY (HEAP)

	// 8) create a pointer (ptr3) that points to an array of 10 ints that are created on the heap (new)
	array<int, 10> *ptr3 = new array<int, 10>;

	// 9a) iterate through the array with the pointer (ptr3[]) and set them to a random number between 1 and 10
	// 9b) iterate through the array with the pointer (ptr3[]) and print out only even values (use the % 2 to determine if it is even)
	srand(time(0));
	for (int &i : *ptr3) {
		i = rand() % 10;
	}
	for (int &i : *ptr3) {
		if (i % 2 == 0) {
			cout << i << endl;
		}
	}
	// 10) free the memory of ptr3 (when deleting an array use delete[])
	delete[] ptr3;

	// TEMPLATE

	// 11a) create a template function called max_value to return the max value of two types
	// 11b) call the template function with two float values and display the answer
	float v = max_value(11.1f, 2.2f);
	cout << v << endl;

	// INHERITANCE - create a class hierarchy using Animal as the base class and two different animals as the child class
	// !!! these classes can be created at the top of this file or put in separate files !!!

	// BASE CLASS (Animal)
	// 12a) add members (string name, int lifespan)
	// 12b) create a default constructor
	// 12c) create a constructor that takes in the name and the lifespan
	// 12d) create accessor methods (get/set) for name and lifespan
	// 12e) create a function called Say() that returns a string literal of the noise the animal makes
	// 12f) allow the Say() function to be overridden by derived classes by declaring it virtual

	// DERIVED CLASS (Specific Animal)
	// !! create two derived classes of animals !!
	// 13a) create a default constructor
	// 13b) create a constructor that takes in the name and the lifespan and initialize the base class with these parameters
	// 13c) allow the derived classes to override the Say() method
	// example: string Say() override { return "quack"; }

	// POLYMORPHISM
	// 14a) create a list<> of Animal*
	list<Animal*> animals;
	
	// 14b) create an animal on the heap (new)
	Animal* dog1 = new Dog("Bella", 14);
	// example:
	// Animal* animal;
	// animal = new SpecificAnimal(<name>, <lifespan>);
	// 14c) add the animal to the list
	animals.push_back(dog1);
	// 14d) create the other animal on the heap (new)
	Animal* cat1 = new Cat("Dovah", 16);
	// 14e) add the other animal to the list
	animals.push_back(cat1);
	// 14f) iterate through the list displaying the Say() string on all the animals
	for (auto iter = animals.begin(); iter != animals.end(); iter++) {
		cout << (*iter)->say() << endl;
	}

	// OPERATOR OVERLOADING
	// 15a) create an operator overload for the cout stream << to stream out the Animal class data (name, lifespan)
	// 15b) iterate through the animals list using a for loop and display the animals using the cout << 

	//Operator overload is done above main
	for (Animal* a : animals) {
		cout << a;
	}

	// TYPEDEF / AUTO / CONST
	// 16a) create a new type name currency_t to a double using typedef
	// 16b) create a new type name u8_t to an unsigned char using 'using'
	// 16c) use the auto keyword on a variable named 'value' assigned to a float value
	// 16d) define a constant float variable named PI to the value 3.1415f

	typedef double currency_t;
	using u8_t = unsigned(char);
	auto value = 12.0f;
	const float PI = 3.1415f;

	// CONTAINERS
	// 17a) create a vector of ints called numbers and initialize it with { 43, 23, 12, 65, 8 }
	// 17b) add another int to the end of the vector, whatever value you'd like
	// 17c) display all the elements of the vector using a for range loop

	vector<int> numbers = { 43, 23, 12, 65, 8 };
	numbers.push_back(8);

	for (int in : numbers) {
		cout << in << " ";
	}
	cout << endl;

	// ALGORITHMS
	// 18a) reverse the order of the vector of ints (numbers) and display the vector
	// 18b) sort the order of the vector of ints
	reverse(numbers.begin(), numbers.end());
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	sort(numbers.begin(), numbers.end());

	// 18c) using the animal list above, use the find algorithm to find an animal by the name, this will pass back the iterator
	// 18d) display the animal that was returned above in the iterator
	// 18e) display all the animals
	auto a1 = find(animals.begin(), animals.end(), dog1);
	cout << (*a1);
	for (Animal* a : animals) {
		cout << a;
	}

	// HEAP DEALLOCATION
	// 19a) iterate through the list of animals and call delete on them to free the memory
	// 19b) clear() the animals list
	for (Animal* a : animals) {
		delete a;
	}
	animals.clear();

	// WELL-BEING
	// 20a) You are an awesome person who is capable of doing whatever you put your time and energy into.
	// 20b) Enjoy your day because now is the most important time!
}

