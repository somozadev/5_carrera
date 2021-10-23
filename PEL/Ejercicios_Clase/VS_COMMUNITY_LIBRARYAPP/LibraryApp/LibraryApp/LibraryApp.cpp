#include <iostream>
#include "Book.h"
#include "Person.h"
#include "User.h"
#include "Library.h"
using namespace std;
int main()
{
	/*create library instance, giving number of books and users*/
	Library library(20, 10);
	/*prints prettify title*/
	cout << library.title();
	/*prints all books in library*/
	cout << "***************BOOKS***************" << endl;
	library.print_books();
	cout << endl;
	/*prints all users in library*/
	cout << "***************USERS***************" << endl;
	library.print_users();
	cout << endl;
	/*create user pointer to one in library with the same name*/
	User* paula_user = library.get_user("paula");
	/*create book pointer to one in library with the same name*/
	Book* dracula_book = library.get_book("dracula");
	Book* yo_robot_book = library.get_book("yo robot");
	/*given user takes given book, added to its current book. olso set that book availavility to not available*/
	library.take_book(paula_user, dracula_book);
	library.take_book(paula_user, yo_robot_book);
	/*given user leaves given book, added to its history and cleared current book. olso set that book availavility to available*/
	library.leave_book(paula_user);
	cout << endl;
	/*print user history books*/
	cout << "***************HISTORY***************" << endl;
	paula_user->print_history();
	cout << endl;
	/*checks if given user currently has given book*/
	cout << "***************HAS_BOOK***************" << endl;
	library.check_user_has_book(paula_user, dracula_book);
	cout << endl;
	library.check_user_has_book(paula_user, yo_robot_book);
	cout << endl;
	/*prints all available books in the library*/
	cout << "***************AVAILABLE***************" << endl;
	library.print_available_books();
	cout << endl;
	/*prints all not available books in the library*/
	cout << endl;
	cout << "***************NOT_AVAILABLE***************" << endl;
	library.print_notavailable_books();
	/*or if wanted to see all books and its availability use this: */
	cout << endl;
	cout << "***************AVAILABILITY***************" << endl;
	library.print_availability();
}
