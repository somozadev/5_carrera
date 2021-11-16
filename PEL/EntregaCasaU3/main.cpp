#include <iostream>
#include <vector>

/*
mejorar la eficiencia del mismo (hay que usar semánticas de copia y movimiento). 
Se entregará la carpeta de proyecto comprimida en un .zip y con el nombre [Apellido1][Apellido2]_[Nombre]_SCM.zip.
El objetivo es mejorar su eficiencia mediante estos métodos aprendidos, cualquier otro tipo de mejora no será
 relevante para la entrega. 
*/

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class MyClass
{
private:
    int *data;

public:
    explicit MyClass(int d)
    {
        data = new int;
        *data = d;
        cout << "Constructor 1 is called for data "<< *data << endl;
    };

    MyClass(MyClass &source) : MyClass(*source.data)
    {
        cout << "Copy Constructor is called for data "<< *data << endl;
    }

    MyClass(MyClass &&source) : data(source.data)
    {
        cout << "Move Constructor is called for data "<< *data << endl;
    }

    int getData() const
    {
        return *data;
    }

    ~MyClass()
    {
        delete data;
        cout << "Destructor is called for data "<< *data << endl;
    }
};

void printVec(const vector<MyClass> &vec)
{

    for (const auto &i : vec)
    {
        cout << i.getData() << " ";
    }
    cout << endl;
}

int main()
{
    vector<MyClass> vec;

    vec.push_back(MyClass(10));
    vec.push_back(MyClass(11));
    cout << "------------------" << endl;
    printVec(vec);
    return EXIT_SUCCESS;
}