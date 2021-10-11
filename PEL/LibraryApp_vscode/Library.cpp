#include <iostream>
#include <vector>
#include "Library.h"
#include "User.h"
#include "Book.h"
#include <map>
#include <sstream>

using namespace std;

/*returns a string with the app title (will be used for future console app) */
std::string Library::title()
{
	std::stringstream ss;
	ss << "*********************" << "*************" << "*********************" << endl
		<< "*********************" << "*************" << "*********************" << endl
		<< "***                                                 ***" << endl
		<< "***                  " << "~LIBRARY APP~" << "                  ***" << endl
		<< "***                                                 ***" << endl
		<< "*********************" << "*************" << "*********************" << endl
		<< "*********************" << "*************" << "*********************" << endl << endl;

	std::string title = string(ss.str());
	return title;
}

/*constructor, fills books and users vectors with given cuantity*/
Library::Library(int books_amount, int users_amount)
{
	Library::fill_random_books(books_amount);
	Library::fill_random_users(users_amount);
	Library::setup_availability();
}

/*adds a book books vector*/
void Library::add_book(Book book) { this->books.push_back(book); }

/*adds a user to users vector*/
void Library::add_user(User user) { this->users.push_back(user); }

/*fills users vector with given number off random users */
void Library::fill_random_users(int cuantity)
{
	for (int i= 0; i < cuantity; i++) 
	{
		User user(i,i,i);
		//user.set_random_person();
		add_user(user);
	}
}

/*fills books vector with given number off random books */
void Library::fill_random_books(int cuantity)
{
	for (int i = 0; i < cuantity; i++)
	{
		Book book(i,rand()%8);
		//book.set_random_book();
		add_book(book);
	}
}

/*prints all dictionary books whos availability is not available*/
void Library::print_notavailable_books()
{
	int counter = 1;
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if (it->second != 1)
		{
			cout << counter << "." << it->first->to_string() << endl;
			counter++;
		}
	}
}

/*prints all dictionary books whos availability is available*/
void Library::print_available_books()
{
	int counter = 1;
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if (it->second == 1)
		{
			cout << counter << "." << it->first->to_string() << endl;
			counter++;
		}
		
	}
}

/*prints all dictionay with each book current availability*/
void Library::print_availability()
{
	int counter = 1;
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if(it->second==1)
		cout << counter << "." << it->first->to_string() << "-> " << " AVAILABLE" << endl;
		else
			cout << counter << "." << it->first->to_string() << "-> " << " NOT AVAILABLE" << endl;
		counter++;
	}
}

/*sets given book to not available in the dictionary*/
void Library::set_availability_notavailable(Book* book)
{
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if (book->to_string() == it->first->to_string())
		{
			availability[it->first] = false;
			break;
		}
	}
}

/*sets given book to available in the dictionary*/
void Library::set_availability_available(Book* book)
{
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if(book->to_string() == it->first->to_string())
		{
			this->availability[it->first] = true;
			break;
		}
	}
}

/*checks if given book is available in the dictionary*/
bool Library::check_availability(Book* book)
{
	bool available = true;
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if (book->to_string() == it->first->to_string())
		{
			available = availability[it->first];
			break;
		}
	}
	return available;
}

/*fills the dictionay when constructor callled, with same number of books as in books vector*/
void Library::setup_availability() 
{
	for (size_t i = 0; i < books.size(); ++i)
	{
		Book* b = nullptr;
		b = &books[i];
		this->availability[b] = true;
	}
}

/*returns a list of all available books*/
std::vector <Book> Library::get_available_books()
{
	std::vector <Book> returner;
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if (it->second)
		{
			Book* b = it->first;
			returner.push_back(*b);
		}
	}
	return returner;
}

/*returns a list of all not available books*/
std::vector <Book> Library::get_notavailable_books()
{
	std::vector <Book> returner;
	for (map<Book*, bool>::const_iterator it = this->availability.begin(); it != this->availability.cend(); it++)
	{
		if (!it->second)
		{
			Book* b = it->first;
			returner.push_back(*b);
		}
	}
	return returner;
}

/*prints all books in library*/
void Library::print_books()
{
	for (Book b : this->books)
		b.print();
}

/*prints all users in library*/
void Library::print_users()
{
	for (User u : this->users)
		u.print_info();
}

/*returns all users in library*/
std::vector <User> Library::get_users() { return this->users; }

/*returns all books in librar*/
std::vector <Book> Library::get_books() { return this->books; }

/*returns book registred in library with the name given*/
Book* Library::get_book(std::string name)
{
	Book* returned_book = nullptr;
	for (size_t i = 0; i < books.size(); ++i)
	{
		if (books[i].get_name() == name)
			returned_book = &books[i];
	}
	return returned_book;
}

/*returns user registred in library with the name given*/
User* Library::get_user(std::string name)
{
	User* returned_user = nullptr;
	for (size_t i = 0; i < users.size(); ++i)
	{
		if (users[i].get_name() == name)
			returned_user = &users[i];
	}
	return returned_user;
}

/*sets users current book to given if given is not taken already*/
void Library::take_book(User* user, Book* book)
{
	if (check_availability(book))
	{
		Library::set_availability_notavailable(book);
		Book current = user->get_current_book();
		if (current.get_name() != "" && current.get_genre() != "")
		{
			user->add_book_to_history(&current);
			Library::set_availability_available(&current);
		}
		user->set_current_book(book);	
	}
}

/*sets current book to available and to null in users ref, adds leaved book to history*/
void Library::leave_book(User* user)
{
	Book current = user->get_current_book();
	if(!check_availability(&current))
		Library::set_availability_available(&current);
	Book empty_book;
	Book* bp = &empty_book;
	user->set_current_book(bp);
	user->add_book_to_history(&current);
}

/*checks if an user has a book currentyl*/
void Library::check_user_has_book(User* user, Book* book)
{
	if (book->are_equal(user->get_current_book()))
		cout << "user " << user->get_name() << " has "<< book->get_name();
	else
		cout << "user " << user->get_name() << " don't have "<< book->get_name();
}

/*Checks given user info*/
void Library::check_user_history(User* user)
{
	user->print_info();
	user->print_history();
}