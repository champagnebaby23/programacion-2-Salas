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
    }

