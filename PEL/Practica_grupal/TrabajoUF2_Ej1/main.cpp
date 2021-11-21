#include <iostream>
#include <conio.h>
using namespace std;

/*
Ejercicio 1. Implementar en C++ un programa que tenga las siguientes 3 opciones. 
Para ello, debe hacerse uso del registro %rsp:
• Solicite al usuario por consola un valor que almacenar en la pila de usuario.
• Permita ver que valores se almacenan en la pila del usuario en las diferentes posiciones.
• Debe poder eliminarse el valor de cualquier posición de la pila de usuario.
El código generado debe ser a prueba de errores. Para ello implementa los métodos
necesarios para poder mantener el proceso de ejecución.
*/

struct Pila {
    int pNum;
    Pila *siguiente;
};

void addPila(Pila *&pila, int num) {
    Pila *nuevaPila = new Pila();
    nuevaPila->pNum = num;
    nuevaPila->siguiente = pila;
    pila = nuevaPila;
}
void getPila(Pila *&pila, int &num) {
    Pila *x = pila;
    num = x ->pNum;
    pila = x->siguiente;
}

void deletePila(Pila *&pila, int &num) {
    Pila *x = pila;
    num = x ->pNum;
    pila = x->siguiente;
    delete x;
}

int mostrarOpciones() 
{
    cout << endl;
    cout << endl;
    cout << "[MENU] Selecciona una de las opciones: " << endl;
    cout << "  1 - Almacenar nuevo valor" << endl;
    cout << "  2 - Ver valores almacenados" << endl;
    cout << "  3 - Eliminar valores" << endl;
    cout << "  S - Salir" << endl;
    int res;
    cout << ">>: "; 
    cin >> res;
    cin.ignore(1, '\n');
    cout << endl;
    return res;
}

int main()
{
    Pila *pila = NULL;
    int num;
    bool c = true;
    while (c)
    {
        switch (mostrarOpciones())
        {
        case 1:
        cout << endl;
        cout << "Introduce un numero:";
        cin >> num;
        addPila(pila, num);
            break;
        case 2:
        cout << endl;
        cout << "Elementos de la pila:" << endl;
        while (pila != NULL)
        {
            getPila(pila, num);
            cout << num << endl;
            
        }
        
            break;
        case 3:
        while (pila != NULL)
        {
            deletePila(pila, num);
        }
        cout << "Pila borrada" << endl;
        
            break;
        
        default:
            c = false;
            break;
        }
    }
    
    
    return 0;
}
