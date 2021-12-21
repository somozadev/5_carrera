#include <iostream>
#include "pelicula.cpp"
#include <limits>
#include <vector>

using namespace std;

bool cargarPelicula (pelicula &p);
int pintarMenuPrincipal();
pelicula pintarMenuCargar();
int alquilerPeliculas();
int devolucionPeliculas();
void verDisponibilidad();

vector vec = vector<pelicula>();

int main() {
    int opcion;
    int res;
    pelicula pe;

    vec.push_back(pelicula("Titanic" , "Blu-Ray", 66, false));
    vec.push_back(pelicula("Fate" , "DVD", 150, true));
    vec.push_back(pelicula("Batman" , "DVD", 23, false));
    vec.push_back(pelicula("kimetsu no yaiba" , "Blu-Ray", 10, false));

    do {
    opcion = pintarMenuPrincipal();
    bool carga_exito;
        switch (opcion) {
            case 1:
                pe = pintarMenuCargar();
                carga_exito = cargarPelicula(pe);
                if (carga_exito){
                    cout << "Se ha guardado la pelicula correctamente" << endl;
                }else {
                    cout << "Ha ocurrido un error" << endl;
                }
                break;
            case 2:
                res = alquilerPeliculas();
                switch (res) {
                    case -1:
                        cout << "No se ha encontrado la pelicula." << endl;
                        break;
                    case -2:
                        cout << "No se ha alquilado la pelicula." << endl;
                        break;
                    case -3:
                        cout << "No es posible alquilar esta pelicula" << endl;
                        break;
                    default:
                        cout << "Se ha alquilado la pelicula correctamente." << endl;
                        break;
                }
                break;
            case 3:
                res = devolucionPeliculas();
                switch (res) {
                    case -1:
                        cout << "No se ha encontrado la pelicula." << endl;
                        break;
                    case -2:
                        cout << "No es posible devolver esta pelicula" << endl;
                        break;
                    default:
                        cout << "Pelicula devuelta con exito" << endl;
                        break;
                }
                break;
            case 4:
                verDisponibilidad();
                break;
            case 5:
            default:
                cout << "Saliendo del programa..." << endl;
                break;
        }

    } while (opcion != 5);
    return 0;
}

bool cargarPelicula(pelicula &p) {
    try{
        vec.push_back(p);
    }catch (exception& ex){
        return false;
    }
    return true;
}
int pintarMenuPrincipal() {
    int opcion;
    cout << "-- Menu principal --" << endl;
    cout << "1 - Cargar Pelicula" << endl;
    cout << "2 - Alquilar Pelicula" << endl;
    cout << "3 - Devolver Pelicula" << endl;
    cout << "4 - Ver disponibilidad de Pelicula" << endl;
    cout << "5 - Salir" << endl;
    cout << "Escriba una opcion: " << endl;

    try{
        cin >> opcion;
        if (cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw 1;
        }
    } catch (int error) {
        cout << "Escriba un numero entero" << endl;
    }
    return opcion;
}
pelicula pintarMenuCargar() {
    string tit;
    int tipo;
    double precio;
    cout << "-- Cargar Peliculas --" << endl;
    cout << "Escriba el titulo de la pelicula: " << endl;
    cin.ignore();
    getline(cin, tit);
    do{
        cout << "Es DVD(1) o Blu-Ray(2): " << endl;
        cin >> tipo;
    }while(tipo != 1 && tipo != 2);
    cout << "Escriba el precio de la pelicula: " << endl;
    cin >> precio;
    if ( tipo == 1 ){
        pelicula p(tit , "DVD", precio, false);
        return p;
    }else{
        pelicula p(tit , "Blu-Ray", precio, false);
        return p;
    }
}

int alquilerPeliculas(){
    char res;
    int cont = 0;
    string tit;
    cout << "-- Alquilar Peliculas --" << endl;
    cout << "Escriba el titulo de la pelicula que desee alquilar: " << endl;
    cin.ignore();
    getline(cin, tit);
    for (pelicula &p : vec) {
        if (p.getPelTitulo() == tit){
            if (p.isPelAlquilado()){
                return -3;
            }else{
                cout << "Desea alquilar ";
                p.imprimirDatos();
                cout << "Y: si\nN: no" << endl;
                cin >> res;
                switch (res) {
                    case 'Y':
                    case 'y':
                        vec[cont].alquilaPelicula();
                        return cont;
                        break;
                    case 'N':
                    case 'n':
                    default:
                        cout << "Saliendo..." << endl;
                        return -2;
                        break;
                }
            }
        }
        cont++;
    }
    return -1;
}
int devolucionPeliculas(){
    int cont = 0;
    string tit;
    cout << "-- Devoluciones Peliculas --" << endl;
    cout << "Escriba el titulo de la pelicula que desee devolver: " << endl;
    cin.ignore();
    getline(cin, tit);
    for (pelicula &p : vec) {
        if (p.getPelTitulo() == tit){
            if (!p.isPelAlquilado()){
                return -2;
            }else{
                vec[cont].devolverPelicula();
                return cont;
            }
        }
        cont++;
    }
    return -1;
}
void verDisponibilidad(){
    cout << "-- Disponibilidad Peliculas --" << endl;
    for (pelicula &p : vec) {
        if (!p.isPelAlquilado()){
            p.imprimirDatos();
        }
    }
}