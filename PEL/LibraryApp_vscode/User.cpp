#include "User.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*default constructor, sets current book to a new empty one*/
User::User()
{
	Book b;
	this->current_book = b;
}

/*constructor create user from list of naems,surnames,ids by given id*/
User::User(int id_name, int id_surname, int id_dni)
{
	this->name = this->names[id_name];
	this->surname = this->surnames[id_surname];
	this->dni = this->dnis[id_dni];
}

/*constructor creates usres with random ids*/
User::User(bool random)
{
	if (random)
	{
		this->set_random_person();
		this->current_book.set_random_book();
		for (int i = 0; i < rand() % 6; i++)
		{
			Book b(true); /////////
			this->history_books.push_back(b);
		}
	}
}

/*constructor creates user with default person constructor and given book*/
User::User(Book current_book)
{
	this->current_book = current_book;
}

/*constructor creates user by book and historybook given*/
User::User(Book current_book, vector<Book> history_books)
{
	this->current_book = current_book;
	this->history_books = history_books;
}

/*sets current users book as the given one*/
void User::set_current_book(Book* current_book) { this->current_book = *current_book; }

/*returns current book*/
Book User::get_current_book() { return this->current_book; }

/*returns current user history as a vector<Book>*/
vector<Book> User::get_history_books() { return this->history_books; }

/*adds given book to history*/
void User::add_book_to_history(Book* book)
{
	history_books.push_back(*book);
}

/*prints users book history info (name,genre)*/
void User::print_history()
{
	int counter = 1;
	for(Book b  : User::get_history_books())
	{
		cout << counter << "." << b.to_string() << endl;
		counter++;
	}
}

/*prints person info (name,surname,dni) and current book info (name,genre)*/
void User::print_info()
{
	Person::print_info();
	User::current_book.print();
}

/*returns user person info as a string*/
std::string User::to_string()
{
	return this->name + " " + this->surname + " " + this->dni;
}
