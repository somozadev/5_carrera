#include <iostream>
using namespace std;

template <class T>
class Pila // LIFO
{
private:
    T data[50];
    int elements;

public:
    Pila() : elements(0) {}
    void Push(T element)
    {
        if (elements < 50)
        {
            data[elements] = element;
            elements++;
        }
        else
            cout << "Full!"
    }
    void Pop()
    {
        if (elements > 0)
        {
            elements--;
            return data[elements];
        }
        else
            cout << "Empty!";
    }
    int Size() { return elements; }
    bool isEmpty(){return elements == 0;}
};

int main()
{

    return 0;
}
