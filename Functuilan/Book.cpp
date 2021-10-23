#include "Book.h"
using namespace LibraryApp;
using namespace std;

Book::Book(string name, string genre)
{
    this->name = name;
    this->genre = genre;
}
Book::Book()
{
    this->name = this->names[rand() % 20];
    this->genre = this->genres[rand()%8];
}
string Book::get_genre() { return this->genre; }
