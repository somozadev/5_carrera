#pragma once
#include <iostream>
class Book
{
public:
	Book();
	Book(bool random);
	Book(int,int);

private:
	std::string name;
	std::string genre;
	std::string genres[8] = { "action", "drama", "fantasy", "adventures", "comedy", "rommance", "horror", "police" };
	std::string names[20] = { "don quijote de la mancha", "el guardián entre el centeno", "el señor de los anillos", "el principito", "el hobbit", "la biblia", "el imperio final", "el camino de los reyes", "guia del autoestopista galactico", "harry potter", "el alquimista", "el codigo da vinci", "lo que el viento se llevo", "el diario de ana frank", "dracula", "fahrenheit 451", "rebelion en la granja", "yo robot", "fundacion y tierra", "nemesis" };

public:
	void set_random_book();
	std::string to_string();
	void print();
	std::string get_name();
	std::string get_genre();
	bool are_equal(const Book& book);
};