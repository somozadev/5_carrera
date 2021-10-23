#include "Person.h"
#include <iostream>
#include <random>

using namespace std;
/*default constructor, creates an empty person*/
Person::Person() 
{ 
	this->name = "";
	this->surname = "";
	this->dni = "";
}

/*constructor that creates a person with given values*/
Person::Person(string name, string surname, string dni)
{
	this->name = name;
	this->surname = surname;
	this->dni = dni;
}

/*constructor that creates a person from the list of names,surnames and dnis based on given id */
Person::Person(int id_name, int id_surname, int id_dni)
{
	this->name = names[id_name];
	this->surname = surnames[id_surname];
	this->dni = dnis[id_dni];
}

/* constructur that creates a random person, by assigning random ids for the lists*/
Person::Person(bool random) { set_random_person(); }

/*function : assigns the random previously mentioneds*/
void Person::set_random_person()
{
	this->name = this->names[rand() % 20];
	this->surname = this->surnames[rand() % 20];
	this->dni = this->dnis[rand() % 20];
}

/*returns string of current name*/
string Person::get_name() { return this->name; }

/*returns string of current surname*/
string Person::get_surname() { return this->surname; }

/*returns string of current dni*/
string Person::get_dni() { return this->dni; }

/*prints person info*/
void  Person::print_info()
{
	cout << Person::get_name() << " " << Person::get_surname() << " (" << Person::get_dni()<<")"<< endl;
}
