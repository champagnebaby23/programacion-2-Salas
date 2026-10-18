#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream archivo("ejemplo-escrito.txt");
    if (archivo.is_open()) {
        archivo << "Hola, ejemplo de ofstream en C++." << endl;
        archivo.close();
        cout << "Archivo escrito correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }

    return 0;
}