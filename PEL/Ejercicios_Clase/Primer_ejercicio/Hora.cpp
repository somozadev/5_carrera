#include <iostream>
using namespace std;

class Hora
{
public:
    int h, m, s;
    void Visualize();
    void Add(Hora obj1, Hora obj2);
    void Set(Hora hora);

    Hora() { this->h = this->m = this->s = 0; }
    Hora(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
};

void Hora::Visualize()
{
    cout << this->h << ":" << this->m << ":" << this->s;
}

void Hora::Add(Hora obj1, Hora obj2)
{
    this->s = obj2.s + obj1.s;
    this->m = obj2.m + obj1.m + this->s / 60;
    this->s = this->s % 60;
    this->h = obj2.h + obj1.h + this->m/60;
    this->m = this->m % 60;
};

int main()
{
    Hora hora1(12, 44, 3);
    Hora hora2(12, 1, 6);

    Hora horaVacia;
    horaVacia.Add(hora1, hora2);
    horaVacia.Visualize();
    return 0;
}
