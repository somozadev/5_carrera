#include <iostream>
#include <list>
#include <map>
#include "Book.h"

using namespace LibraryApp;
using namespace std;
int main(int, char **)
{
    Book book("name","genre");
    cout << book.get_genre();
    return 0;
}
