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


