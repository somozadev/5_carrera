#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class alignas(8) BagParent
{
public:
    int size;
    int align;
    string name;
    void PrintInfo() { cout << "variable type: " << name << " and size of: " << size << ", and align of: " << align << endl; };
};
template <class T>
class alignas(T) BagClass : public BagParent
{
public:
    T m_data;
    BagClass()
    {
        this->align = alignof(T);
        this->size = sizeof(T);
        this->name = typeid(m_data).name();
    };
};

class Menu
{
private:
    int selection;

public:
    int PrintBaseMenu()
    {
        cout << "Que desea hacer: " << endl;
        cout << "1. Anadir" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Ver los elementos" << endl;
        cout << "4. Salir" << endl;
        cin >> selection;
        return selection;
    }
    int PrintRemove()
    {
        cin >> selection;
        return 0;
    };
    int PrintMenu()
    {
        cout << "Selecciona un tipo a guardar [1-8]: " << endl;
        cout << "1. short" << endl;
        cout << "2. char" << endl;
        cout << "3. int" << endl;
        cout << "4. long int" << endl;
        cout << "5. float" << endl;
        cout << "6. double" << endl;
        cout << "7. puntero" << endl;
        cout << "8. long double" << endl;
        cin >> selection;
        return selection;
    };
};
class Bag
{
public:
    vector<BagParent> bag;
    void Show()
    {
        for (BagParent i : bag)
        {
            i.PrintInfo();
        }
    };
    void Add(Menu menu)
    {
        switch (menu.PrintMenu())
        {
        case 1:
            bag.push_back(BagClass<short>());
            break;
        case 2:
            bag.push_back(BagClass<char>());
            break;
        case 3:
            bag.push_back(BagClass<int>());
            break;
        case 4:
            bag.push_back(BagClass<long int>());
            break;
        case 5:
            bag.push_back(BagClass<float>());
            break;
        case 6:
            bag.push_back(BagClass<double>());
            break;
        case 7:
            bag.push_back(BagClass<int *>());
            break;
        case 8:
            bag.push_back(BagClass<long double>());
            break;

        default:
            break;
        }
        cout << "\033c";
    };
    void Remove()
    {
        for (size_t i = 0; i < bag.size(); i++)
        {
            cout << i + 1 << ".";
            bag[i].PrintInfo();
        }
        int selected = 0;
        cin >> selected;
        bag.erase(bag.begin() + (selected - 1));
    };
};

void Init(Bag bag, Menu menu)
{
    int num = menu.PrintBaseMenu();
    bool ingame = true;
    while (num != 5 && ingame)
    {
        if (num == 1)
            bag.Add(menu);
        else if (num == 2)
            bag.Remove();
        else if (num == 3)
            bag.Show();
        else
            ingame = false;
        num = menu.PrintBaseMenu();
    }
}
int main(int, char **)
{
    Init(Bag(), Menu());
}