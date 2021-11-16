#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/* 
*Ejercicio 2: Implementar en C++ un programa sencillo que simule una mochila o almacén de objetos. 
*El programa debe permitir al usuario que se “almacene” cualquier tipo de objeto que quiera el usuario (solo validos tipos de datos estándar de C++).
*Para ello, se implementará un menú de “gestión de objetos”, que permitirá seleccionar si se quiere almacenar un objeto o eliminarlo, 
*permitiendo elegir que objeto eliminar. A la hora de almacenar los datos, deben emplearse las técnicas y métodos que hagan  que  el  almacenamiento  
*sea  lo  más  eficiente  posible en  todo  momento.Para ello, deben emplearse los operadores de alineación.
*/

/*datos estandar sizeof(variable):
*char : 1 bytes
*short : 1 bytes
*int : 4 bytes
*long int : 4 bytes

*long long int : 8 bytes
*float : 4 bytes
*double : 8 bytes
*long double : 16 bytes
* puntero : 8 bytes
*/

template <class T>
class BagClass
{
public:
    BagClass(int &selection)
    {
        this = SelectType(selection);
    }

private:
    T m_data;
};

class Menu
{
private:
    int selection;

public:
    Menu()
    {
        PrintMenu();
    };
    void PrintMenu()
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
    };

};

int main(int, char **)
{
    Menu menu = Menu();
    std::cout << sizeof(BagClass<int>);
}
