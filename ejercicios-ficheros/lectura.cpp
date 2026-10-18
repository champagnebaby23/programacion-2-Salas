#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream archivo("ejemplo-escrito.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();    
    } else {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
    return 0;
}