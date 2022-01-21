#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 *
 *Bien,  pasamos  a  la  situación  3.  Esta  vez  queremos  poder  manejar  la  información
almacenada en el vector de seguratas de la situación anterior. Planteando que el
TAD InfoSegurata tiene la siguiente estructura, hay que realizar lo siguiente:

- Se siguen almacenando los datos dentro de un objeto
std::vector<InfoSegurata>  y  debe  estar  ordenado  por  la  evaluación  del
candidato.
 - Es necesario realizar un programa, que pueda calcular y obtener las
evaluaciones  máximas  y  mínimas  de  cada  segurata.  Así  podremos  saber
cual es el segurata más y menos peligroso.
- También  se  debe  obtener  el  promedio  de  las  seguratas  para  saber  la
dificultad de este y futuros golpes.
- Toda esta información debe mostrarse en pantalla.
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
    vector<InfoSegurata> seguratas;

public:
    #pragma region SITUACION2
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
            AddSegurata(*is);
            delete is;
            cout << "Quiere anadir mas (0-1)?" << endl;
            cin >> fill;
        }
        SortSeguratas();
    }
    void AddSegurata(InfoSegurata segurata) { seguratas.push_back(segurata); }
    void SortSeguratas()
    {
        for (int i = 0; i < seguratas.size(); i++)
            for (int j = 0; j < seguratas.size() - 1; j++)
            {
                if (seguratas[j].score < seguratas[j + 1].score)
                {
                    InfoSegurata temp = seguratas[j];
                    seguratas[j] = seguratas[j + 1];
                    seguratas[j + 1] = temp;
                }
            }
    }
    void PrintSeguratas()
    {
        for (InfoSegurata segurata : seguratas)
        {
            cout << segurata.name << ": " << segurata.score << endl;
        }
    }
    #pragma endregion SITUACION3
    #pragma region SITUACION3
    InfoSegurata GetMinRatedSegurata() { return seguratas[seguratas.size() - 1]; }
    InfoSegurata GetMaxRatedSegurata() { return seguratas[0]; }
    float GetMediaSegurata()
    {
        float returner = 0;
        for (size_t i = 0; i < seguratas.size(); i++)
        {
            returner += seguratas[i].score;
        }

        return (returner / seguratas.size());
    }
    #pragma endregion SITUACION3
};

int main(int, char **)
{
    CasaRuso ruso;
    ruso.AddSeguratas();
    cout << "MinRated->" << ruso.GetMinRatedSegurata().name << ": " << ruso.GetMinRatedSegurata().score << endl;
    cout << "MaxRated-> " << ruso.GetMaxRatedSegurata().name << ": " << ruso.GetMaxRatedSegurata().score << endl;
    cout << "Media-> " << ruso.GetMediaSegurata() << endl;
}
