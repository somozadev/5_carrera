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
    string name;
    string genre;
    string group;

public:
    string getGenre() { return this->genre; }
    inline album(string _name)
    {
        name = _name;
        genre = group = "";
    }
    album(string _name, string _genre, string _group)
    {
        name = _name;
        genre = _genre;
        group = _group;
    };
    string ToString() { return "Name: " + name + "\n" + "Genre: " + genre + "\n" + "Group: " + group; };
    bool IsName(const string &_name) { return name == _name; }
    bool IsGenre(const string &_genre) { return genre == _genre; }
    bool IsGroup(const string &_group) { return group == _group; }
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
    discografica discografica_disco_stu;
    discografica_disco_stu.AddAlbum(album("el_circulo", "rap", "kase_o"));
    discografica_disco_stu.AddAlbum(album("rojo_y_negro", "rap", "ayax_y_prok"));
    discografica_disco_stu.AddAlbum(album("rap_sin_corte", "rap", "foyone"));
    discografica_disco_stu.AddAlbum(album("el_madrilerño", "pop", "c.tangana"));
    discografica_disco_stu.AddAlbum(album("estopa", "rock", "estopa"));
    discografica_disco_stu.AddAlbum(album("el_que_mas", "rock", "obus"));
    discografica_disco_stu.AddAlbum(album("en_un_lugar_de_la_mancha", "rock", "baron_rojo"));
    discografica_disco_stu.AddAlbum(album("finisterra", "rock", "mago_de_oz"));
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
        case 1: discografica_disco_stu.FindAlbumsBy(Search::name); break;
        case 2: discografica_disco_stu.FindAlbumsBy(Search::genre); break;
        case 3: discografica_disco_stu.FindAlbumsBy(Search::group); break;        
        default:
            cout << "Seleccion no valida" << endl; 
            break;
        }
    }
    while(selection != 4);
}
