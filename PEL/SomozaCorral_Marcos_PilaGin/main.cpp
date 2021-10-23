
//Marcos Somoza Corral 21711787
template <class T>
class Pila
{
private:
    struct Node
    {
        T element;
        Node *next;
    } * last;
    unsigned int elements;

public:
    Pila() { elements = 0; }
    ~Pila()
    {
        while (elements != 0)
            Pop();
    }
    void Push(const T &elem)
    {
        Node *aux = new Node;
        aux->element = elem;
        aux->next = last;
        last = aux;
        ++elements;
    }
    void Pop()
    {
        Node *aux = last;
        last = last->next;
        delete aux;
        --elements;
    }
    T Top()
    {
        return last->element;
    }
    bool IsEmpty()
    {
        return elements == 0;
    }
    unsigned int Size()
    {
        return elements;
    }
};

#include <iostream>
using namespace std;
int main(int, char **)
{
    Pila<int> pila;
    pila.Push(1);
    pila.Push(2);
    pila.Push(3);
    pila.Push(4);
    pila.Push(5);
    cout << "last element is: " << pila.Top() << endl;
    cout << "is empty: " << pila.IsEmpty() << endl;
    cout << "size:  " << pila.Size() << endl;
    string exit;
    cin >> exit;
}
