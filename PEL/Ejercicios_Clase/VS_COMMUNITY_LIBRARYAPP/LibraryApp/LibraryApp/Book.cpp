#include "Book.h"
#include <string>
using namespace std;


/*default constructor. creates empty book*/
Book::Book() {
	this->name = "";
	this->genre = "";
}

/*constructor, creates random book calling set_random_book*/
Book::Book(bool random) { if (random)set_random_book(); }

/*constructor, creates book getting name and genre from names,genres based on ids given*/
Book::Book(int id_name, int id_genre) {
	this->name = this->names[id_name];
	this->genre = this->genres[id_genre];
}

/*sets random book and genre giving random id*/
void Book::set_random_book()
{
	this->name = this->names[rand() % 20];
	this->genre = this->genres[rand() % 8];

}

/*returns books name and genre to string */
std::string Book::to_string()
{
	return this->name + "(" + this->genre + ")";
}

/*prints book string from to_string*/
void Book::print()
{
	std::cout << "Book: " << Book::to_string() <<endl;
}

/*returns books name*/
string Book::get_name()
{
	return name;
}

/*returns books genre*/
string Book::get_genre()
{
	return genre;
}

/*returns true if given book and this book are equal (same name and genre)*/
bool Book::are_equal(const Book& book)
{
	bool equal = false;
	if (this->name == book.name && this->genre == book.genre)
		equal = true;
	return equal;
}