#include "Console.h"
#include "Library.h"
#include "User.h"
#include "Book.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;
Console::Console(Library* library)
{
	set_console_size();
	loop(library);
}
void Console::set_console_size()
{
	HWND c = GetConsoleWindow();
	RECT console_rect;
	GetWindowRect(c, &console_rect);
	MoveWindow(c, console_rect.left, console_rect.top, 480, 350, TRUE);
}
void Console::clear(){ system("CLS"); }
std::string Console::title()
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
std::string Console::menu_main_options()
{
	std::stringstream ss;
	 ss << "1. Show all books" << endl
		<< "2. Show all users" << endl
		<< "3. Show books available" << endl
		<< "4. See user history" << endl
		<< "5. See if user has a book" << endl
		<< "6. Take a book" << endl
		<< "7. Return a book" << endl
		<< "8. Exit" << endl;

	std::string main = string(ss.str());
	return main;
}
std::string Console::menu_select_book(Library* library)
{
	std::vector<Book> books = library->get_books();
	string returner = "";
	for (size_t i = 0; i < books.size(); i++)
	{
		returner += std::to_string(i + 1) + "." + books[i].to_string() + "\n";
	}
	return returner;
}
std::string Console::menu_select_user(Library* library)
{
	std::vector<User> users = library->get_users();
	string returner = "";
	for (size_t i = 0; i < users.size(); i++)
	{
		returner+= std::to_string(i+1) + "." + users[i].to_string() + "\n";
	}
	return returner;
}
std::string Console::menu_see_user_history(User* user)
{
	std::vector<Book> books = user->get_history_books();
	string returner = "";
	for (size_t i = 0; i < books.size(); i++)
	{
		returner += std::to_string(i + 1) + "." + books[i].to_string() + "\n";
	}
	return returner;
}


void Console::loop(Library* library)
{
	std::vector<User> users;
	std::vector<Book> books;
	std::vector<Book> available_books;
	std::vector<Book> notavailable_books;
	int selection_user = 0;
	int book_selection = 0;
	while(!exit)
	{
	cout << title();
	cout << menu_main_options();

	int option;
	cin >> option;
	switch (option)
	{
		case 1:
			clear();
			cout << title();
			library->print_books();
			break;
		case 2:
			clear();
			cout << title();
			library->print_users();
			break;
		case 3:
			clear();
			cout << title();
			library->print_availability();
			break;
		case 4:
			clear();
			cout << title();
			cout << "Select an user: " << endl;
			cout << menu_select_user(library);
			cin >> selection_user;
			users = library->get_users();
			selection_user--;
			clear();
			cout << title();
			if (selection_user >= 0 && selection_user < (int)users.size())
			{
				User* return_user = &(users[selection_user]);
				cout << menu_see_user_history(return_user);
			}
			else
				cout << "~" << endl;
			break;
		case 5:
			clear();
			cout << title();
			cout << "Select an user: " << endl;
			cout << menu_select_user(library);
			selection_user = 0;
			cin >> selection_user;
			selection_user--;
			clear();
			cout << title();
			cout << "Select a book: " << endl;
			cout << menu_select_book(library);
			cin >> book_selection;
			book_selection--;
			users = library->get_users();
			books = library->get_books();
			if (selection_user >= 0 && selection_user < (int)users.size())
			{
				User* return_user = &(users[selection_user]);
				if (book_selection >= 0 && book_selection < (int)books.size())
				{
					Book* return_book = &(books[book_selection]);
					cout << return_user->get_current_book().to_string() << endl;
					if (return_user->get_current_book().to_string() == return_book->to_string())
					{
						cout << "user '" << return_user->to_string() << "'currently has book '" << return_book->to_string() << "'" << endl;
					}
					else
					{
						cout << "user '" << return_user->to_string() << "'currently hasn't book '" << return_book->to_string() << "'" << endl;
					}
				}
			}
			break;
		case 6:
			clear();
			cout << title();
			cout << "Select a book: " << endl;
			library->print_available_books();
			book_selection = 0;
			cin >> book_selection;
			book_selection--;
			clear();
			cout << title();
			cout << "Select an user: " << endl;
			cout << menu_select_user(library);
			selection_user = 0;
			cin >> selection_user;
			selection_user--;
			available_books = library->get_available_books();
			users = library->get_users();
			if (selection_user >= 0 && selection_user < (int)users.size())
			{
				User* return_user = &(users[selection_user]);
				if (book_selection >= 0 && book_selection < (int)available_books.size())
				{
					Book* return_book = &(available_books[book_selection]);

					library->take_book(return_user, return_book);
					cout << return_user->to_string();
				}
			}
			break;
		case 7:
			/* SELECT USER */
			clear();
			cout << title();
			cout << "Select an user: " << endl;
			cout << menu_select_user(library);
			selection_user = 0;
			cin >> selection_user;
			selection_user--;
			users = library->get_users();
			if (selection_user >= 0 && selection_user < (int)users.size())
			{
				User* return_user = &(users[selection_user]);
				clear();
				cout << title();
				Book b = return_user->get_current_book();
				if (b.get_name() != "" && b.get_genre() != "")
				{
					cout << "Returning '" << b.to_string() << "'" << endl;
					library->leave_book(return_user);
				}
				else
				{
					cout << "User has no current book" << endl;
				}

			}
			break;
		case 8:
			clear();
			this->exit = true;
			break;
		}

		string wait;
		cin >> wait;
	}
}