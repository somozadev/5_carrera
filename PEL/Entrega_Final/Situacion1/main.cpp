#include <iostream>

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
template <class T>
class Dequeue
{

private:
    class Node
    {
    public:
        Node *next;
        T data;
        Node(T t)
        {
            this->data = t;
            next = nullptr;
        }
    };
    Node *start;
    Node *end;

public:
    Dequeue()
    {
        start = end = nullptr;
    };
    bool inline isEmpty() { const return start == nullptr; }
    void Push(T data)
    {
        Node *node;
        node = new Node(data);
        if (this->isEmpty())
            this->start = node;
        else
            this->end->next = node;
        this->end = node;
    };
};

int main(int, char **)
{
}
