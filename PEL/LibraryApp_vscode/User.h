#pragma once
#include "Person.h"
#include "Book.h"
#include <vector>
#include <string>

class User :
	public Person
{
public:
	User();
	User(int id_name, int id_surname, int id_dni);
	User(bool random);
	User(Book current_book);
	User(Book current_book, std::vector<Book> history_books);

private:
	Book current_book;
	std::vector<Book> history_books;

public:
	void set_current_book(Book* book);
	Book get_current_book();
	void add_book_to_history(Book* book);
	std::vector<Book> get_history_books();
	void print_history();
	void print_info() override;
	std::string to_string();
};

