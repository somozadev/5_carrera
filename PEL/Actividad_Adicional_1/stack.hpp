#include <iostream>
template <class T>
class GenericStack
{
    class Node
    {
    public:
        Node *next;
        T element;
        Node(T node)
        {
            element = node;
            next = nullptr;
        };
    };

    Node *top;

public:
    GenericStack() { top = nullptr; }
    bool const isEmpty() { return top == nullptr; }
    void Push(T element)
    {
        Node *node;
        node = new Node(element);
        node->next = top;
        top = node;
    }
    T Pop()
    {
        if (isEmpty())
            throw "Empty stack, cant remove.";
        T aux = top->element;
        top = top->next;
        return aux;
    }
    T Top()
    {
        if (isEmpty())
            throw "Empty stack.";
        return top->element;
    }
    void Clear()
    {
        Node *node;
        while (!isEmpty())
        {
            node = top;
            top = top->next;
            delete node;
        }
    }
    int Size()
    {
        int count = 0;
        Node *current = top;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    void Reverse()
    {
        Node *prev, *curr, *succ;
        curr = prev = top;
        curr = curr->next;
        prev->next = nullptr;
        while (curr != nullptr)
        {
            succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }
        top = prev;
    }
    void Print()
    {
        if (isEmpty())
            return;
        T p = Top();
        Pop();
        Print();
        std::cout << p << " ";
    }
/*
    bool Find(T t)
    {
        bool founded = false;
        int size = Size();
        Node *current = top;

        while (current != nullptr)
        {
            if (!founded)
            {
                if (current->element == t)
                    founded = true;

                else
                    current = current->next;
            }
        }
        return founded;
    }
    */

    ~GenericStack() { Clear(); }
};