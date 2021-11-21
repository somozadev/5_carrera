#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
using namespace std;

/* Ejercicio 5: Realizar un juego de un usuario que consiste en adivinar un 
número en C++. 
El ordenador debe generar un número aleatorio entre 1 y 100, mientras que el 
usuario debe intentar adivinarlo. Para ello, cada vez que el usuario introduce un 
valor, el ordenador debe decir si el valor es mayor o menor que el introducido. 
Cuando el usuario adivine el valor, debe imprimir por pantalla el numero de veces 
que se a intentado adivinar dicho número. 
El programa debe poder manejar las correspondientes excepciones posibles que 
genere el usuario. 
Deben usarse las técnicas necesarias para mejorar la eficiencia del programa lo 
máximo posible implementando lo estudiado. */

void adivina(){
    bool numc=false; //boleano para salir del bucle
    int cont=0; //contador de intentos
    int num=1+rand() % (101-1); //Num aleatorios entre 1 y 100
    double x;
    cout<<"Adivina el numero generado aleatoriamente";
    cout<<"\nEscribe un numero entre el 1 y 100: ";
   
   
    while(numc==false){
        cont++; //intentos
        cin>>x;
        if (x==false){
            cout<<"\nSolo puedes introducir numeros\n";
            break;

        }else{
           
            if(x>100 || x<1){
                cout<<"\nRecuerda que el numero esta entre 1 y 100!, intentalo otra vez: ";
            }
            else if(x>num){
                cout<<"\nIncorrecto, el numero es menor, escribe otro numero: ";
            }
            else if(x<num){
                cout<<"\nIncorrecto, el numero es mayor, escribe otro numero: ";
            }
                
            else
                numc=true;
            }
        }

        if(numc==true){
            cout<<"\nCorrecto!";
            cout<<"\nLo has adivinado en " <<cont<< " intentos\n";
        }
}

int main(){
    srand(time(NULL)); //Inicializar numeros aleatorios
    adivina();
    system("pause");

    return 0;
}