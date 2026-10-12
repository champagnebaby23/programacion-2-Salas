#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

// Funcion crear arreglo dinamico
int* crearArray(int tamanio) {
    if (tamanio <= 0)  {
        cout << "Error: no se puede asignar memoria RAM" << endl; // Validacion de tamanio, debe ser mayor a 0
        return nullptr;
    }
    int* array = new int[tamanio]; // Array dinamico
    if (array == nullptr) { 
        cout << "Error: no se pudo asignar memoria RAM" << endl; // Validacion de asignacion de memoria
        return nullptr;
    }
    return array;
}

// Funcion llenar arreglo dinamico
void llenarArray(int* array, int tamanio) {
    if (array == nullptr || tamanio <= 0) {
        cout << "Error: el array no ha sido creado" << endl; // Validacion de array
        return;
    }
    cout << "Ingrese: " << tamanio << " elementos: \n";
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese elemento " << i << endl; // Llenar el array
        cin >> array[i];
    }
}
// Funcion mostrar arreglo dinamico
void mostrarArray(int* array, int tamanio) {
    if (array == nullptr || tamanio <= 0) {
        cout << "El arreglo esta vacio o no existe" << endl;
        return;
    }
    
    cout << "Elementos del arreglo" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << array[i] << endl;
    }
}
// Funcion encontrar el numero mayor del arreglo
int encontrarMayor(int* array, int tamanio) {
    if (array == nullptr || tamanio <= 0) {
        return 0;
    }

    cout << "Encontrar el numero mayor del arreglo" << endl;
    mayor = array[0];
    for (int i = 0; i < tamanio; i++) {
        if (array[i] > mayor) {
            mayor = array[i]
        }
    }
    return mayor;
}
// Funcion para calcular el promedio
float calcularPromedio(int* array, int tamanio) {
    if (array == nullptr || tamanio <= 0) {
        cout << "El arreglo no existe" << endl;
        return 0.0f;
    }

    cout << "Calcular promedio del arreglo" << endl;
    suma = 0
    for (int i = 0; i < tamanio; i++) {
        suma += array[i]
    }
    promedio = (suma / tamanio);
    return promedio;
}
// Liberar array
void liberarArray(int* array) {
    if (array = nullptr) {
        cout << "El arreglo no existe" << endl;
    } else {
        delete[] array;
        array = nullptr
        cout << "Memoria liberada" << endl;
    }
}

void mostrarMenu() {
    cout << "\n=== GESTION DE ARREGLOS DINAMICOS ===" << endl;
    cout << "1. Crear y llenar arreglo" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Encontrar arreglo mayor" << endl;
    cout << "4. Calcular promedio" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    // Variables principales inicializadas en 0
     int* arreglo = nullptr;
     int tamanio = 0;
     int opcion = 0;
    
     do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion): {
            case 1: {
                cout << "Ingrese el tamanio del arreglo" << endl;
                cin >> tamanio;
                
                array = crearArray(tamanio);
                if (arreglo != nullptr) {
                    llenarArray(array, tamanio);
                    cout << "Arreglo creado y llenado correctamente" << endl;
                } else {
                    cout << "Error al crear el arreglo" << endl;
                }
                break;
            }

            case 2: {
                if (Array =! nullptr) {
                    mostrarArray(array, tamanio);
                } else {
                    cout << "No hay un arreglo creado" << endl;
                 }
                break;
            }
            
            case 3: {
                if (array != nullptr && tamanio > 0) {
                    int mayor = encontrarMayor(array, tamanio);
                    cout << "El numero mayor es: " << mayor << endl;
                } else {
                    cout << "No existe el arreglo"
                }
            }
            break;

            case 4: {
                if (array != nullptr && tamanio > 0) {
                    float promedio = calcularPromedio(array, tamanio);
                    cout << "El promedio es: " << promedio << endl;
                } else {
                    cout << "El arreglo no existe" << endl;
                }
            }
            break;

            case 5: {
                cout << "Saliendo del programa..." << endl;
                break;
            }

            default: {
                couit << "Opcion invalida" << endl;
            }
        }
      } while (opcion =! 5);

      liberarArray(array);
      cout << "Programa finalizado. Memoria liberada" << endl;
      return 0;
}