#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("ejemplo-escrito.txt", ios::app);

    if (archivo.is_open()) {
        archivo << "Esta linea se ha agregado" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
    return 0;
}