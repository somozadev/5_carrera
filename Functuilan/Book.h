#include "User_info.h"

namespace LibraryApp
{

    class Book
    {
    public:
        Book();
        Book(string name, string genre);

    private:
        std::string name;
        std::string genre;
        std::string genres[8] = {"action", "drama", "fantasy", "adventures", "comedy", "rommance", "horror", "police"};
        std::string names[20] = {"don quijote de la mancha, el guardián entre el centeno, el señor de los anillos, el principito, el hobbit, la biblia, el imperio final, el camino de los reyes, guia del autoestopista galactico, harry potter, el alquimista, el codigo da vinci, lo que el viento se llevo, el diario de ana frank, dracula, fahrenheit 451, rebelion en la granja, yo robot, fundacion y tierra, nemesis"};

    public:
        string get_genre();
    };

}
