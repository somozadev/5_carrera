#pragma once
#include <string>

class Person
{
public:
	Person();
	Person(bool random);
	Person(std::string name, std::string surname, std::string dni);
	Person(int id_name, int id_surname, int id_dni);

protected:
	std::string name;
	std::string surname;
	std::string dni;
	std::string names[20] = { "paula", "manuel", "jose", "alberto", "maria", "lucia", "marta", "alejandro", "maya", "carlos", "juan", "rocio", "isaac", "roberto", "alvaro", "ignacio", "laura", "bosco", "bruno", "ricardo" };
	std::string surnames[20] = { "sanchez", "martin", "perez", "lopez", "moreno", "matrinez", "gomez", "santos", "garcia", "torres", "fernandez", "alonso", "silva", "santana", "garcia", "megias", "eulalia", "castañeda", "gill", "amor" };
	std::string dnis[20] = { "12125615S", "16315726D", "65082010Z", "29601850E", "65525832M", "09215004P", "05391999V", "69595466L", "22071679M", "26177875B", "80436171L", "59294050G", "96467899B", "64345031R", "71882973S", "13556717B", "78588768E", "31558193P", "71126720W", "68248602N" };

public:
	void set_random_person();
	std::string get_name();
	std::string get_surname();
	std::string get_dni();
	virtual void print_info();

};

