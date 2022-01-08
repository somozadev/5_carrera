/*
*
*   MARCOS ELADIO SOMOZA CORRAL - 21711787 
*            entrega adicional 1
*/


#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
using namespace std;

#pragma region STACK
/*
Enunciado 1
Escribir un programa que utilice una Pila para comprobar si una determinada
frase/palabra es un palíndromo. Nota: Una palabra o frase es palíndromo cuando la
lectura directa e inversa es la misma y tiene igual valor.
*/
bool IsPalindrome(string phrase)
{
    bool isPal = true;
    GenericStack<char> *stack = new GenericStack<char>();
    for (int i = 0; i < phrase.size(); i++)
        stack->Push(phrase[i]);

    for (int i = 0; i < phrase.size(); i++)
    {
        char last = stack->Top();
        if (phrase[i] == last)
            stack->Pop();
        else
            isPal = false;
    }
    delete stack;
    return isPal;
}
void Ejercicio1()
{
    std::string palabra;
    std::cout << "Escribe la palabra: ";
    std::cin >> palabra;
    if (IsPalindrome(palabra))
        std::cout << "Es palindroma";
    else
        std::cout << "No es palindroma";
}
/*
Enunciado 2
Escribir una función, copiarPila(), que copie el contenido de una pila en otra. La
función tendrá dos argumentos de tipo pila, uno la pila fuente y otro la pila destino.
Utilizar las operaciones definidas sobre el TAD Pila para una pila enlazada.
*/
template <class T>
void CopyStack(GenericStack<T> *s1, GenericStack<T> *s2)
{
    int size = s1->Size();
    s2->Clear();
    for (int i = 0; i < size; i++)
        s2->Push(s1->Pop());
    s2->Reverse();
    s2->Print();
}
void Ejercicio2()
{
    GenericStack<char> *s1 = new GenericStack<char>();
    s1->Push('c');
    s1->Push('a');
    s1->Push('s');
    s1->Push('a');
    GenericStack<char> *s2 = new GenericStack<char>();
    s2->Push('z');

    CopyStack(s1, s2);
}
/*
Enunciado 3
Escribe un programa en el que se manejen un total de 5 pilas. La entrada de datos
será de pares de enteros (i, j), tal que 1<= abs(i) <= n. De tal forma que el criterio de
selección de pila sea:
• Si i es positivo, debe introducirse el elemento j en la Pila i.
• Si i es negativo, debe eliminarse el elemento j en la Pila i.
• Si i es 0, fin del proceso de entrada.
Los datos de entrada se introducen por teclado. Cuando termine el proceso, el
programa debe escribir el contenido de las pilas en pantalla.
*/
void Ejercicio3()
{
    GenericStack<int> *stack1 = new GenericStack<int>();
    GenericStack<int> *stack2 = new GenericStack<int>();
    GenericStack<int> *stack3 = new GenericStack<int>();
    GenericStack<int> *stack4 = new GenericStack<int>();
    GenericStack<int> *stack5 = new GenericStack<int>();

    GenericStack<int> *stacks[5] = {stack1, stack2, stack3, stack4, stack5};

    int i, j;
    do
    {
        cout << endl
             << "i +-(0-5): ";
        cin >> i;
        cout << endl
             << "j: ";
        cin >> j;
        if (i == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << endl
                     << "Stack " << (i + 1) << ":";
                stacks[i]->Print();
            }
        }
        else if (i > 0)
            stacks[i - 1]->Push(j);
        else
        {
            stacks[i - 1]->Pop();
        }

    } while (i != 0);
}
/*
Enunciado 4
Modificar el programa del ejercicio anterior para que la entrada sean triplas de
números enteros (i, j, k) donde i, j tienen el mismo significado que en el anterior, y k es
un numero entero, que puede tomar los valores -1 y o, con el siguiente significado:
• -1: hay que borrar todos los elementos de la pila
• 0: el proceso es el indicado en el apartado anterior para i y j.
*/
void Ejercicio4()
{
    GenericStack<int> *stack1 = new GenericStack<int>();
    GenericStack<int> *stack2 = new GenericStack<int>();
    GenericStack<int> *stack3 = new GenericStack<int>();
    GenericStack<int> *stack4 = new GenericStack<int>();
    GenericStack<int> *stack5 = new GenericStack<int>();

    GenericStack<int> *stacks[5] = {stack1, stack2, stack3, stack4, stack5};

    int i, j, k;
    do
    {
        cout << endl
             << "i +-(0-5): ";
        cin >> i;
        cout << endl
             << "j: ";
        cin >> j;
        cout << endl
             << "k (0,-1): ";
        cin >> k;
        if (i == 0 || k == 0)
        {
            for (int i = 0; i < 5; i++)
            {
                cout << endl
                     << "Stack " << (i + 1) << ":";
                stacks[i]->Print();
            }
        }
        else if (i > 0)
            stacks[i - 1]->Push(j);
        else if (i < 0)
        {
            stacks[i - 1]->Pop();
        }
        else if (k == -1)
        {
            stacks[i - 1]->Clear();
        }

    } while (i != 0);
}
#pragma endregion
#pragma region QUEUE
/*
1. Suponiendo que se tiene la clase cola que implementa las operaciones del TAD
cola. Escribir una función que crea un clon (una copia idéntica) de una cola
determinada. Las operaciones que se han de utilizar son únicamente las del TAD
Cola. */
template <class T>
GenericQueue<T> *ExactCopy(GenericQueue<T> *queue)
{
    GenericQueue<T> *cloned = new GenericQueue<T>();
    while (!queue->isEmpty())
    {
        T data = queue->GetStart();
        cloned->Push(data);
        queue->Pop();
    }
    return cloned;
}
void Ejercicio5()
{
    GenericQueue<int> *queueFirst = new GenericQueue<int>();

    queueFirst->Push(1);
    queueFirst->Push(2);
    queueFirst->Push(3);
    queueFirst->Push(4);
    queueFirst->Push(5);
    GenericQueue<int> *cloned = ExactCopy(queueFirst);
}
/*
2. Escribir una función que tenga como argumentos dos colas del mismo tipo. En caso
de ser idénticas, lo indique por consola al usuario. */
template <class T>
bool AreEqual(GenericQueue<T> *q1, GenericQueue<T> *q2)
{
    bool equal = q1->isEqual(*q2);
    return equal;
}
void Ejercicio6()
{
    GenericQueue<int> *queueFirst = new GenericQueue<int>();
    GenericQueue<int> *queueSecond = new GenericQueue<int>();

    queueFirst->Push(1);
    queueFirst->Push(2);
    queueFirst->Push(3);
    queueFirst->Push(4);
    queueFirst->Push(5);

    queueSecond->Push(1);
    queueSecond->Push(2);
    queueSecond->Push(3);
    queueSecond->Push(4);
    queueSecond->Push(5);

    cout << "Equal(1), No equal(0): " << AreEqual(queueFirst, queueSecond);
}
#pragma endregion

int main(int, char **)
{
    // Ejercicio1();
    // Ejercicio2();
    // Ejercicio3();
    // Ejercicio4();
    // Ejercicio5();
    // Ejercicio6();
}