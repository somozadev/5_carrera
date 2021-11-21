/** EJERCICIO 4
 * Implementar en C++ un sistema sencillo de altas y bajas de usuarios. 
 * En dicho sistema de altas y bajas debe poder crearse un objeto “usuario” con nombre, apellidos y número de usuario, correspondiente al número de usuarios dados de alta.  
 * Importante remarcar que los ID de usuarios no se sustituyen. Si se han creado 3 usuarios y se da de baja el tercero, el nuevo usuario tendrá el id 3. 
 * Para dar de baja un usuario, debe eliminarse usando el destructor del objeto usuario, mostrando por pantalla que usuarios han sido destruido.
**/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Se crea la clase usuario, donde se le asignan los atriutos del nombre, apellidos y id correspondiente al número de usuarios dados de alta.
class Usuario
{
    private:
        string nombre, apellidos;
        int numUsuario;

    public:
        Usuario(string nom, string ape, int numUser);    // Constructor
        Usuario(){} // Constructor vacío

        ~Usuario(); // Destructor

        // MÉTODOS

        // Se insertan los datos del usuario: Nombre, apellidos y id
        void insertarDatos(string n, string a, int id);
        // Se muestran los datos del usuario correspondiente
        void mostrarDatos();

        // Se retorna el nombre del usuario
        string getNombre()
        {
            return nombre;
        }
};

// Constructor de usuario
Usuario::Usuario(string nom, string ape, int numUser) 
{ 
    nombre = nom;
    apellidos = ape;
    numUsuario = numUser;
}

// Destructor de Usuario
Usuario::~Usuario() {}

void Usuario::insertarDatos(string n, string a, int id)
{
    this->nombre = n;
    this->apellidos = a;
    this->numUsuario = id;
}

void Usuario::mostrarDatos()
{
    cout << "Nombre: "<< nombre << endl;
    cout << "Apellidos: "<< apellidos << endl;
    cout << "Numero de usuario: "<< numUsuario << endl;
    cout << endl;
}

string mostrarOpciones() 
{
    cout << "[MENU] Selecciona una de las opciones: " << endl;
    cout << "  [1] - Introducir un usuario" << endl;
    cout << "  [2] - Mostrar usuarios" << endl;
    cout << "  [3] - Eliminar un usuario" << endl;
    cout << "  [4] - Salir" << endl;
    
    string res;
    cout << ">>: "; 
    cin >> res;
    cin.ignore(1, '\n');
    cout << endl;
    return res;
}


int main() 
{
    // Se crea el vector de usuarios
    vector<Usuario> usuarios;

    // Se declaran variables
    int id = 0;
    string nom, ape, input;
    bool nomValido;

    // Hasta que el usuario no escriba un "4" el programa segirá en funcionamiento mediante un while
    do 
    {
        // Mediante un comando se limpia la pantalla del terminal
        system("cls");
        // Se guarda en "input" la respuesta del usuario ante el Menú
        input = mostrarOpciones();

        // Si el usuario ha introducido un 1: AÑADIR USUARIO
        if (input == "1") 
        {
            // Mediante un comando se limpia la pantalla del terminal
            system("cls");

            // Se crea un objeto llamado user
            Usuario user = Usuario();

            // Se asegura que el nombre no se repita en otros usuarios, ya que este tiene que ser único
            do
            {
                // Se inicializa la variable "nomValido" a true
                nomValido = true;

                // Se piden los atributos de dicho usuario y se guardan siempre que no estén vacíos
                cout << "Nombre: ";
                cin >> nom;
                cout << "Apellidos: ";
                cin >> ape;

                // Se recorre el vector "usuarios" através de un for
                for (int i = 0; i < usuarios.size(); i++)
                {
                    // Si el nombre introducido coincide con uno de los objetos creados, da error y se pide de nuevo los campos
                    if (usuarios[i].getNombre() == nom)
                    {
                        nomValido = false;

                        system("cls");

                        cout << "El nombre de usuario "<< nom << " ya existe, pruebe otro\n" << endl;
                        break;
                    }
                }

            } while (!nom.empty() && !ape.empty() && !nomValido);

            // Mediante el método "insertarDatos", se guardan los atributos introducidos anteriormente en el objeto
            user.insertarDatos(nom, ape, id);

            // Se añade el objeto creado con anterioridad en el vector
            usuarios.push_back(user);
            // El id se suma en uno para que los siguientes usuarios dados de alta se diferencien
            id++;
            // Mediante un comando se añade una pausa para que el usuario tenga que pulsar un botón para renaudar el progama
            system("pause");
        }
        // Si el usuario ha introducido un 2: MOSTRAR TODOS LOS USUARIOS
        else if (input == "2")
        {
            // Mediante un comando se limpia la pantalla del terminal
            system("cls");
            // Se recorre el vector "usuarios" através de un for
            cout << "| USUARIOS |" << endl;
            for (int i = 0; i < usuarios.size(); i++)
            {
                // Mediante el método "mostrarDatos", se muestran por pantalla todos los usuarios dados de alta
                usuarios[i].mostrarDatos();
            }
            // Mediante un comando se añade una pausa para que el usuario tenga que pulsar un botón para renaudar el progama
            system("pause");
            
        }
        // Si el usuario ha introducido un 3: DESTRUIR USUARIO
        else if (input == "3")
        {
            // Mediante un comando se limpia la pantalla del terminal
            system("cls");
            string nombre;
            // Se pide al usaurio que escriba el nombre del usuario a elimnar y se guarda en una varible
            cout << "Ingrese el nombre de usuario a eliminar" << endl;
            cin >> nombre;

            // Se recorre el vector "usuarios" através de un for
            for (int i = 0; i < usuarios.size(); i++)
            {
                // Si el nombre introducido coincide con uno de los objetos creados, se elimina dicho objeto
                if (usuarios[i].getNombre() == nombre)
                {
                    // Eliminamos el elemento por posición de la lista
                    usuarios.erase(usuarios.begin() + i);

                    // Eliminamos el objeto por medio del DESTRUCTOR
                    usuarios[i].~Usuario();

                    cout << "El objeto usuario de nombre "<< nombre << " ha sido destruido\n" << endl;
                    break;
                }
            }
            // Mediante un comando se añade una pausa para que el usuario tenga que pulsar un botón para renaudar el progama
            system("pause");
        }

    } while (input != "4");

}
