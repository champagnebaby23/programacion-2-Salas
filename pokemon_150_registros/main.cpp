#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Estructura del Pokemon
struct Pokemon {
    int id;
    string nombre;
    string tipo1;
    string tipo2;
    int total;
    int hp;
    int ataque;
    int defensa;
    int ataqueEsp;
    int defensaEsp;
    int velocidad;
    int generacion;
    string legendario;
};

// Funcion para limpiar espacios en linea
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

// Funcion para cargar los datos del CSV
bool cargarDatos(const string &nombreArchivo, vector<Pokemon> &pokemones) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return false;
    }

    string linea;
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }
        
        stringstream ss(linea);
        Pokemon p;
        string temp;

        try {
            getline(ss, temp, ','); p.id = stoi(trim(temp));
            getline(ss, p.nombre, ','); p.nombre = trim(p.nombre);
            getline(ss, p.tipo1, ','); p.tipo1 = trim(p.tipo1);
            getline(ss, p.tipo2, ','); p.tipo2 = trim(p.tipo2);
            getline(ss, temp, ','); p.total = stoi(trim(temp));
            getline(ss, temp, ','); p.hp = stoi(trim(temp));
            getline(ss, temp, ','); p.ataque = stoi(trim(temp));
            getline(ss, temp, ','); p.defensa = stoi(trim(temp));
            getline(ss, temp, ','); p.ataqueEsp = stoi(trim(temp));
            getline(ss, temp, ','); p.defensaEsp = stoi(trim(temp));
            getline(ss, temp, ','); p.velocidad = stoi(trim(temp));
            getline(ss, temp, ','); p.generacion = stoi(trim(temp));
            getline(ss, p.legendario, ','); p.legendario = trim(p.legendario);

            pokemones.push_back(p);
        } catch (...) {
            continue;
        }
    }

    archivo.close();
    return true;
}

// Funcion para mostrar los detalles completos del Pokemon
void mostrarDetallesPokemon(const Pokemon &p) {
    cout << "Numero de Pokedex: " << p.id << " - " << p.nombre << endl;
    cout << "Tipo 1: " << p.tipo1 << (p.tipo2.empty() ? "" : " / Tipo 2: " + p.tipo2) << endl;
    cout << "Estadisticas totales: " << p.total << endl;
    cout << "HP: " << p.hp << " | Ataque: " << p.ataque << " | Defensa: " << p.defensa << endl;
    cout << "Ataque especial.: " << p.ataqueEsp << " | Defensa Esp.: " << p.defensaEsp << endl;
    cout << "Velocidad: " << p.velocidad << " | Generacion: " << p.generacion << endl;
}

// Funcion para mostrar info mediante el numero de Pokedex
void buscarPorNum(const vector<Pokemon> &pokemones) {
    int num;
    cout << "Ingrese el numero de Pokedex del Pokemon que desea buscar (1-150): ";
    cin >> num;
    
    if (num < 1 || num > 150) {
        cout << "El numero de Pokedex debe estar entre 1 y 150." << endl;
        return;
    }
    
    bool encontrado = false;
    for (const auto &p : pokemones) {
        if (p.id == num) {
            mostrarDetallesPokemon(p);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontro ningun Pokemon con el numero " << num << "." << endl;
    }
}

// Funcion para buscar info mediante el nombre del Pokemon
void buscarPorNombre(const vector<Pokemon> &pokemones) {
    string nombreBuscado;
    cout << "Ingrese el nombre del Pokemon que desea buscar: ";
    cin >> ws; // Limpiar buffer
    getline(cin, nombreBuscado);
    
    bool encontrado = false;
    for (const auto &p : pokemones) {
        if (p.nombre == nombreBuscado) {
            mostrarDetallesPokemon(p);
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro el Pokemon \"" << nombreBuscado << "\"." << endl;
    }
}

// Funcion para ver los Pokemons por tipo
void buscarPorTipo(const vector<Pokemon>& lista) {
    string tipo;
    cout << "Ingrese el tipo de Pokemon (ej. Grass, Fire, Water, Poison, etc.): ";
    cin >> ws;
    getline(cin, tipo);
    
    cout << "\n--- POKEMONS DE TIPO: " << tipo << " ---" << endl;
    int contador = 0;
    for (const auto& p : lista) {
        if (p.tipo1 == tipo || p.tipo2 == tipo) {
            cout << left << setw(5) << p.id << " - " 
                 << setw(15) << p.nombre 
                 << " (Total Stats: " << p.total << ")" << endl;
            contador++;
        }
    }
    cout << "Total encontrados: " << contador << endl;
}   

// Mostrar Pokemons mas fuertes y mas debiles
void mostrarTopEstadisticas(const vector<Pokemon>& lista) {
    if (lista.empty()) return;
    
    vector<Pokemon> copia = lista;
    
    sort(copia.begin(), copia.end(), [](const Pokemon& a, const Pokemon& b) {
        return a.total > b.total;
    });
    
    cout << "\n========================================" << endl;
    cout << "       TOP 3 POKEMON MAS FUERTES        " << endl;
    cout << "========================================" << endl;
    for (size_t i = 0; i < 3 && i < copia.size(); ++i) {
        cout << i + 1 << ". " << copia[i].nombre << " (Estadisticas totales: " << copia[i].total << ")" << endl;
    }
    
    cout << "\n========================================" << endl;
    cout << "       TOP 3 POKEMON MAS DEBILES        " << endl;
    cout << "========================================" << endl;
    for (size_t i = 0; i < 3 && i < copia.size(); ++i) {
        size_t idx = copia.size() - 1 - i;
        cout << i + 1 << ". " << copia[idx].nombre << " (Estadisticas totales: " << copia[idx].total << ")" << endl;
    }
}

// Funcion del menu
void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "             MENU POKEDEX               " << endl;
    cout << "========================================" << endl;
    cout << "1. Ver info de Pokemon por numero de Pokedex" << endl;
    cout << "2. Buscar Pokemon por nombre" << endl;
    cout << "3. Ver Pokemon por tipo" << endl;
    cout << "4. Ver info detallada por nombre" << endl;
    cout << "5. Ver Top 3 mas fuertes y Top 3 mas debiles" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    string archivoCSV = "pokemon_150_registros.csv";
    vector<Pokemon> lista; 
    
    if (!cargarDatos(archivoCSV, lista)) {
        return 1;
    } else {
        cout << "¡Se cargaron " << lista.size() << " registros exitosamente!" << endl;
    }

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                buscarPorNum(lista);
                break;
            case 2:
                buscarPorNombre(lista);
                break;
            case 3:
                buscarPorTipo(lista);
                break;
            case 4:
                buscarPorNombre(lista);
                break;
            case 5:
                mostrarTopEstadisticas(lista);
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente nuevamente." << endl;
                break;
        }
    } while (opcion != 6);

    return 0;
}
