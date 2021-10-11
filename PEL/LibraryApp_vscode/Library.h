#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "Book.h"
#include "User.h"

	class Library
	{
	private:
		std::vector <User> users;
		std::vector <Book> books;
		std::map<Book*, bool> availability;
		int name_counter = 0;
		int genre_counter = 0;
	public:
		std::string title();
		Library(int books_amount, int users_amount);
		void add_book(Book book);
		void add_user(User user);
		void fill_random_users(int cuantity);
		void fill_random_books(int cuantity);
		
		void print_notavailable_books();
		void print_available_books();
		void print_availability();
		void set_availability_notavailable(Book* book);
		void set_availability_available(Book* book);
		bool check_availability(Book* book);
		void setup_availability();
		
		std::vector <Book> get_available_books();
		std::vector <Book> get_notavailable_books();
		
		void print_books();
		void print_users();

		std::vector <User> get_users();
		std::vector <Book> get_books();
		
		Book* get_book(std::string name);
		User* get_user(std::string name);
		
		void take_book(User* user, Book* book);
		void leave_book(User* user);
		void check_user_has_book(User* user, Book* book);
		void check_user_history(User* user);
		
		


	};

