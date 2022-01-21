#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*

Bien chavales, esta va a ser la última situación. Siguiendo los desarrollos realizados
hasta ahora. Deberéis escribir una función que separe en 2 los datos almacenados
en  el  vector.  En  el  primero  estarán  únicamente  aquellos  más  peligrosos  (una
evaluación mayor a 8), y en el otro aquellos que, dentro de ser chungos, no van a
dar muchos problemas.  Pero, en este caso tenéis que hacerlo de dos formas diferentes:

- La  primera  forma  es  usando  2  vectores  adicionales,  uno  de  seguratas
peligrosos  y  otro  de  seguratas  menos  peligrosos,  conservando  el  original
durante la separación y eliminándolo al terminar de separarlos.

 - La otra forma, es generar una función de seguratas peligrosos, que
compruebe del vector original cuales son peligrosos y sacándolos del vector
original  e  introduciéndolos  en  el  nuevo.  Dejando  en  el  vector  original  los
menos peligrosos y en el nuevo los más peligrosos.

- Para ambas formas, realizar las funciones sin usar métodos iterativos.
Únicamente recursivos.

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
    vector<InfoSegurata *> seguratasMuyPeligrosos;
    vector<InfoSegurata *> seguratasPocoPeligrosos;

public:
#pragma region SITUACION2

    void AddSegurata(InfoSegurata *segurata)
    {
        seguratas.push_back(segurata);
    }
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
        cout << "SEGURATAS" << endl;
        for (InfoSegurata *segurata : seguratas)
        {
            cout << segurata->name << ": " << segurata->score << endl;
        }
    }
#pragma endregion SITUACION2

#pragma region SITUACION4

    vector<InfoSegurata *> &GetVector()
    {
        return this->seguratas;
    }

    void DivideSeguratasBorrar(vector<InfoSegurata *> &vec)
    {
        if (vec.size() > 0)
        {
            InfoSegurata s = *vec[vec.size() - 1];
            InfoSegurata *sptr = new InfoSegurata(vec[vec.size() - 1]->name, vec[vec.size() - 1]->score);
            if (vec[vec.size() - 1]->score >= 8)
                seguratasMuyPeligrosos.push_back(sptr);
            else
                seguratasPocoPeligrosos.push_back(sptr);

            delete vec[vec.size() - 1];
            vec.pop_back(); // this calls the object destructor... bc its a pointer its needed to free memory as well with delete like so:
            DivideSeguratasBorrar(vec);
        }
    }
    void DivideSeguratasMantener(vector<InfoSegurata *> &vec, int i)
    {
        if (i < vec.size())
        {
            if (vec[i]->score >= 8)
            {
                InfoSegurata s = *vec[i];
                InfoSegurata *sptr = new InfoSegurata(vec[i]->name, vec[i]->score);
                seguratasMuyPeligrosos.push_back(sptr);
                InfoSegurata *deleter = nullptr;
                deleter = vec[i];
                vec.erase(vec.begin() + i);
                delete deleter;
                i = -1;
            }
            i++;
            DivideSeguratasMantener(vec, i);
        }
    }
    void PrintPocoPelig()
    {
        cout << "SEGURATAS POCO PELIGROSOS" << endl;
        for (InfoSegurata *segurata : seguratasPocoPeligrosos)
        {
            cout << segurata->name << ":" << segurata->score << endl;
        }
    }
    void PrintMuyPelig()
    {
        cout << "SEGURATAS MUY PELIGROSOS" << endl;
        for (InfoSegurata *segurata : seguratasMuyPeligrosos)
        {
            cout << segurata->name << ":" << segurata->score << endl;
        }
    }

#pragma endregion SITUACION4
};

int main(int, char **)
{
    CasaRuso ruso;

    ruso.AddSegurata(new InfoSegurata("Manuel", 5));
    ruso.AddSegurata(new InfoSegurata("Angel", 10));
    ruso.AddSegurata(new InfoSegurata("Marcos", 9));
    ruso.AddSegurata(new InfoSegurata("Gonzalo",3));
    ruso.AddSegurata(new InfoSegurata("Roberto", 4));
    ruso.AddSegurata(new InfoSegurata("Fer", 1));
    ruso.AddSegurata(new InfoSegurata("Silvia", 10));

    ruso.SortSeguratas();

    // ruso.DivideSeguratasBorrar(ruso.GetVector());
    // ruso.PrintPocoPelig();
    // ruso.PrintMuyPelig();

    ruso.DivideSeguratasMantener(ruso.GetVector(), 0);
    ruso.PrintSeguratas();
    ruso.PrintMuyPelig();

}
