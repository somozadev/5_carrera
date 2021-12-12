#include <iostream>
#include <vector>

using namespace std;

enum Search
{
    name,
    genre,
    group
};
class album
{
private:
    string exp;
    string vac;
    string mes;

public:
    string getGenre() { return this->genre; }
    inline album(string expediente)
    {
        exp= expediente;
        genre = group = "";
    }
    album(string expediente, string vacuna, string mesV)
    {
        exp= expediente;
        genre = vacuna;
        group = mesV;
    };
    string ToString() { return "Numero de expediente: " + exp + "\n" + "vacuna: " + vac + "\n" + "mes de vacunación: " + mes; };
    bool IsName(const string &expediente) { return exp== expediente; }
    bool IsGenre(const string &vacuna) { return vac == vacuna; }
    bool IsGroup(const string &mesV) { return mes == mesV; }
};

class discografica
{
private:
    vector<album> albums;

public:
    void AddAlbum(album &&album) { albums.push_back(album); }
    void RemoveLastAlbum() { albums.pop_back(); }
    void FindAlbumsBy(Search search)
    {
        vector<album> found_albums = vector<album>();
        string input;
        switch (search)
        {
        case name:
            cout << "Name: " << endl;
            cin >> input;
            for (auto &it : albums)
                if (it.IsName(input))
                    found_albums.push_back(it);
            break;
        case genre:
            cout << "Genre: " << endl;
            cin >> input;
            for (auto &it : albums)
                if (it.IsGenre(input))
                    found_albums.push_back(it);
            break;
        case group:
            cout << "Group: " << endl;
            cin >> input;
            for (auto &it : albums)
                if (it.IsGroup(input))
                    found_albums.push_back(it);
            break;
        }

        if (found_albums.size() > 0)
        {
            cout << "-------------------------- " << endl
                 << "SE ENCONTRARON LOS ALBUMES " << endl
                 << "-------------------------- " << endl;
            for (auto &it : found_albums)
                cout << it.ToString() << endl
                     << endl;
        }
        else
            cout << "NO SE ENCONTRO NINGUN ALBUM" << endl
                 << endl;
    };
};

int main(int, char **)
{
    discografica s;
    s.AddAlbum(album("220609001", "rap", "kase_o"));
    s.AddAlbum(album("rojo_y_negro", "rap", "ayax_y_prok"));
    s.AddAlbum(album("rap_sin_corte", "rap", "foyone"));
    s.AddAlbum(album("el_madrilerño", "pop", "c.tangana"));
    s.AddAlbum(album("estopa", "rock", "estopa"));
    s.AddAlbum(album("el_que_mas", "rock", "obus"));
    s.AddAlbum(album("en_un_lugar_de_la_mancha", "rock", "baron_rojo"));
    s.AddAlbum(album("finisterra", "rock", "mago_de_oz"));
    int selection;
    do
    {
        cout << "--------------" << endl
             << "ALBUM SEARCHER" << endl
             << "--------------" << endl;
        cout << "1. Search by name" << endl
             << "2. Search by genre" << endl
             << "3. Search by group" << endl
             << "4. Exit" << endl;
        cin >> selection;
        switch (selection)
        {
        case 1: s.FindAlbumsBy(Search::name); break;
        case 2: s.FindAlbumsBy(Search::genre); break;
        case 3: s.FindAlbumsBy(Search::group); break;        
        default:
            cout << "Seleccion no valida" << endl; 
            break;
        }
    }
    while(selection != 4);
}
