#include <iostream>
#include <cstdlib>

using namespace std;

class pelicula{
private:
    string pel_titulo, pel_tipo;
    double pel_precio;
    bool pel_alquilado;
public:
    pelicula() { pel_titulo = "sin definir"; pel_tipo = "sin definir"; pel_precio = 0; pel_alquilado = false; }
    pelicula(const string &pelTitulo, const string &pelTipo, double pelPrecio, bool pelAlquilado) : pel_titulo(
            pelTitulo), pel_tipo(pelTipo), pel_precio(pelPrecio), pel_alquilado(pelAlquilado) {};
    void alquilaPelicula();
    void devolverPelicula();
    void imprimirDatos();

    // Getters
    string &getPelTitulo();
    bool isPelAlquilado();
};
void pelicula::alquilaPelicula() {
    pel_alquilado = true;
}
void pelicula::devolverPelicula() {
    pel_alquilado = false;
}
void pelicula::imprimirDatos(){
    cout << "--> " << pel_titulo << " - " << pel_tipo << " - "
    << pel_precio << " Euros" << endl ;
}
string &pelicula::getPelTitulo() {
    return pel_titulo;
}
bool pelicula::isPelAlquilado() {
    return pel_alquilado;
}


