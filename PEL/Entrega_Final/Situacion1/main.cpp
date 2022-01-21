#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
A la hora de acceder a la caja fuerte de un ruso de estos ricachones, en donde
están las claves de acceso a un bunker blindado en donde se guardan uno de los
botines más jugosos del mundo (o eso aseguraba Berlín), nos encontramos que el
patrón de ordenación de las claves de acceso sigue una secuencia de 10 números
escrita en una tabla hash. Para extraer los datos, debemos ordenar los elementos
de tipo double de esa tabla hash de mayor a menor.  Tenéis  que  diseñar  un  objeto  llamado  deque,  en  el  que  podáis  almacenar  los
elementos  ubicados  en  las  tablas  hash.  Tras  esto,  implementad  un  algoritmo  de
ordenación (podéis llamarlo sort) que ordene la secuencia de dichos elementos,
pudiendo así obtener las claves de desbloqueo de la caja fuerte del ruso.
*/
class Dequeue
{
private:
    vector<double> hash;

public:
    void AddHash(double num) { this->hash.push_back(num); }
    void Print()
    {
        for (auto &&i : hash)
            cout << i << ';';
        cout << endl;
    }
    void Sort()
    {
        for (size_t i = 0; i < hash.size(); i++)
        {
            for (size_t j = 0; j < hash.size() - 1; j++)
            {
                if (hash[j] < hash[j + 1])
                {
                    double temp;
                    temp = hash[j];
                    hash[j] = hash[j + 1];
                    hash[j + 1] = temp;
                }
            }
        }
    }
};

int main(int, char **)
{
    Dequeue dq;
    dq.AddHash(59);
    dq.AddHash(20);
    dq.AddHash(61);
    dq.AddHash(7);
    dq.AddHash(120);
    dq.AddHash(19);
    dq.AddHash(1);
    dq.AddHash(155);
    dq.AddHash(90);
    dq.AddHash(21);
    cout << "Pre sort" << endl;
    dq.Print();
    dq.Sort();
    cout << "Post sort" << endl;
    dq.Print();
}
