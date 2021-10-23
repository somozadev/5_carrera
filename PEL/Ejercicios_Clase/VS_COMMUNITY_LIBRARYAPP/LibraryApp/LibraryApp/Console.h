#pragma once
#include <string>
#include "Library.h"

class Console
{
public:
	Console(Library* library);
private:
	bool exit = false;
public:
	void clear();
	void loop(Library* library);
	void set_console_size();
	std::string title();
	std::string menu_main_options();
	std::string menu_select_user(Library* library);
	std::string menu_see_user_history(User* user);
	std::string menu_select_book(Library* library);
};

