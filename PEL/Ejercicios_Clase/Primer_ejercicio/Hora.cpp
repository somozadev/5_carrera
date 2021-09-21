#include <iostream>
using namespace std;

class Hora
{
public:
    int h, m, s;
    void Visualize();
    Hora Add(Hora obj1, Hora obj2);
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

Hora Hora::Add(Hora obj1, Hora obj2)
{
    Hora horaObj;

    horaObj.h = obj2.h + obj1.h;
    horaObj.m = obj2.m + obj1.m;
    horaObj.s = obj2.s + obj1.s;
    return(horaObj);
}



int main()
{
    Hora hora1(1,2,3);
    Hora hora2(2,4,6);

    Hora horaVacia = hora1.Add(hora1,hora2);
    horaVacia.Visualize();
    return 0;
}
