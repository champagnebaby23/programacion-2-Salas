#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Pokemon {
    int id;
    string nombre;
    string tipo1;
    string tipo2;
    short int total;
    short int hp;
    short int ataque;
    short int ataqueEspecial;
    short int defensaEspecial;
    short int velocidad;
    bool generacion;
    bool legendario;
};

bool cargarDatos(const string & nombreArchivo, vector<Pokemon> &pokemones) {
    ifstream archivo(pokemon_150_registros.csv);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    };

    string linea;
    getline(archivo, linea);

    while(getline(archivo, linea)) {
        if(linea.empty()) {
            continue;
        }
    stringstream ss(linea);
    Pokemon p;
    string temp;

    getline(ss, p.id, ',;');
    getline(ss, p.nombre, ',;');
    getline(ss, p.tipo1, ',');
    getline(ss, p.tipo2, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');
    getline(ss, temp, ',');

    lista.Pokemon.push_back(p);
    };

    archivo.close();
    return true;
}

void mostrarDetallesPokemon(const Pokemon &p) {
    cout << "Numero de Pokedex:" << p.id << p.nombre << endl;
    cout << "Tipo 1:" << p.tipo1 << endl;
    cout << "Tipo 2: " << p.tipo2 << endl;
    cout << "Total: " << p.total << endl;
    cout << "HP: " << p.hp << endl;
    cout << "Ataque: " << p.ataque << endl;
    cout << "Ataque Especial: " << p.ataqueEspecial << endl;
    cout << "Defensa Especial: " << p.defensaEspecial << endl;
    cout << "Velocidad: " << p.velocidad << endl;
    cout << "Generacion: " << p.generacion << endl;
    cout << "Legendario: " << p.legendario << endl;
    if (p.legendario == true) {
        cout << "Este pokemon es legendario" << endl;
    } else {
        cout << "Este pokemon no es legendario" << endl;
    }
}

void buscarPorNum (const vector<Pokemon> &pokemones, int num) {
    short int num;
    cout << "Ingrese el numero de Pokedex del pokemon que desea buscar: ";
    cin >> num;
    if (num < 1 || num > 150) {
        cout << "El numero de Pokedex debe estar entre 1 y 150" << endl;
    }
    bool encontrado = false;
    for (const auto &p : pokemones) {
        if (p.id == num) {
            mostrarDetallesPokemon(p);
            encontrado = true;
            break;
        }
    }
}

void buscarPorNombre (const vector<Pokemon> &pokemones, const string &nombre) {
    string nombreBuscado;
    cout << "Ingrese el nombre del pokemon que desea buscar: ";
    cin >> nombreBuscado;
    bool encontrado = false;
    for (const auto &p : pokemones) {
        if (p.nombre == nombreBuscado) {
            mostrarDetallesPokemon(p);
            encontrado = true;
            break;
        } else {
            cout << "No se encontro el pokemon" << endl;
        }
}

void buscarPorTipo (const vector<Pokemon> &pokemones, const string &tipo) {
    string tipoBuscado;
    cout << "Ingrese el tipo del pokemon que desea buscar: ";
    cin >> tipoBuscado;
    bool encontrado = false;
    for (const auto &p : pokemones) {
        if (p.tipo1 == tipoBuscado || p.tipo2 == tipoBuscado) {
            mostrarDetallesPokemon(p);
            encontrado = true;
        } else {
            cout << "No se encontro el pokemon" << endl;
        }
}

