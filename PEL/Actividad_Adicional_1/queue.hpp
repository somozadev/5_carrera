#include <iostream>
template <class T>
class GenericQueue
{
    class Node
    {
    public:
        Node *next;
        T element;
        Node(T t)
        {
            element = t;
            next = nullptr;
        }
    };
    Node *start;
    Node *end;

public:
    GenericQueue()
    {
        start = end = nullptr;
        std::cout << "creating a queue..." << std::endl;
    }
    bool isEqual(GenericQueue<T>& q2)
    {
        bool equal = true;
        if (Size() != q2.Size())
            equal = false;

        Node *current1 = nullptr;
        Node *current2 = nullptr;

        current1 = start;
        current2 = q2.start;
        while (current1 != nullptr && current2 != nullptr && equal)
        {
            if (current1->element != current2->element)
                equal = false;
            current1 = current1->next;
            current2 = current2->next;
        }
        delete current1;
        delete current2;
        return equal;
    }
    bool isEmpty() const { return start == nullptr; };
    void Push(T element)
    {
        Node *node;
        node = new Node(element);
        std::cout << "Pushing :" << node->element << std::endl;
        if (isEmpty())
            start = node;
        else
            end->next = node;
        end = node;
    }
    int Size()
    {
        int count = 0;
        Node *current = start;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }
    T Pop()
    {
        if (isEmpty())
            throw "Empty queue, cant remove.";
        T aux = start->element;
        std::cout << "Popping :" << aux << std::endl;
        Node *node = start;
        start = start->next;
        delete node;
        return aux;
    }
    void Clear()
    {
        while (start != nullptr)
        {
            Node *node;
            node = start;
            start = start->next;
            delete node;
        }
        end = nullptr;
    }
    T GetStart() const
    {
        if (isEmpty())
            throw "Empty queue";
        return start->element;
    }
    ~GenericQueue() { Clear(); }
};