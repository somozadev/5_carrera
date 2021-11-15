#include <iostream>

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
class BagClass
{
public:
    BagClass();
private:
    char m_char;
    short m_short;
    int m_int;
    long int m_long_int;
    float m_float;
    double m_double;
    long double m_long_double;
};
int main(int, char **)
{
    std::cout << sizeof(BagClass);
}
