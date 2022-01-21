#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
Bien chavales, en esta situación tenéis que plantearos que hay que hacer también
reconocimiento de la gente que hay dentro de la seguridad de la casa del ruso.
Para  poder  categorizar  a  los  equipos  de  seguridad,  se  necesita  un  sistema  que
permita recoger la información de los seguratas que tiene el ruso en su casa.
 El  programa  almacenará  la  información  del  nombre  del  segurata  y  un  número
correspondiente a la puntuación que sacaron en su evaluación como candidatos
para securizar la casa del ruso. Como de primeras no sabemos el número de seguratas que hay, el programa debe
permitir  introducir  tantos  seguratas  como  sea  posible  (usar  para  ello  la  clase
std::vector). Una vez introducidos los datos de todos los seguratas, el sistema debe ordenarlos
de mayor a menor puntuación para saber quienes son los guardias con los que más
cuidado debemos de tener, mostrando la información ordenada por pantalla.

*/
struct alignas(16) InfoSegurata
{
public:
    string name;
    int score;
    InfoSegurata(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
};

class CasaRuso
{

private:
    vector<InfoSegurata *> seguratas;

public:
    void AddSeguratas()
    {
        bool fill = true;

        while (fill)
        {
            string a;
            int b;
            cout << "Nombre del segurata: ";
            cin >> a;
            cout << endl;
            cout << "Calificacion del segurata: ";
            cin >> b;
            cout << endl;
            InfoSegurata *is = new InfoSegurata(a, b);
            AddSegurata(is);
            delete is;
            cout << "Quiere anadir mas (0-1)?" << endl;
            cin >> fill;
        }
        SortSeguratas();
    }
    void AddSegurata(InfoSegurata* segurata) { seguratas.push_back(segurata); }

void SortSeguratas()
    {
        for (int i = 0; i < seguratas.size(); i++)
            for (int j = 0; j < seguratas.size() - 1; j++)
            {
                if (seguratas[j]->score < seguratas[j + 1]->score)
                {
                    InfoSegurata *temp = nullptr;
                    temp = seguratas[j];
                    seguratas[j] = seguratas[j + 1];
                    seguratas[j + 1] = temp;
                }
            }
    }
    void PrintSeguratas()
    {
        for (InfoSegurata* segurata : seguratas)
        {
            cout << segurata->name << ": " << segurata->score << endl;
        }
    }
};

int main(int, char **)
{
    CasaRuso ruso;
    ruso.AddSeguratas();
    ruso.PrintSeguratas();
}
