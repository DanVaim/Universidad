#include <iostream>
#include <fstream>
#include "matrix.h"

using namespace std;

int main() {
    ifstream inputFile("text.txt");

    if (!inputFile.is_open()) {
        cout << "No se encontró el archivo";
        return 501;
    }

    string line;
    getline(inputFile, line); // Obtención de línea de entrada

    int validate = 0; // Estado de validación: 0 -> expresión no válida; 1 -> expresión válida
    string word = "";  // Almacenamiento de la expresión regular
    char car = '$';    // Almacenamiento de caracter procesado
    int state = 0;     // Estado inicial (q1 en el autómata)

    for (int i = 0; i < line.length(); i++) {
        car = line[i];

        // Validar si el caracter es uno de los esperados: 'p', 'l', 'o', 'a', 'z'
        int charIndex;
        switch (car) {
            case 'p': charIndex = 0; break;
            case 'l': charIndex = 1; break;
            case 'o': charIndex = 2; break;
            case 'a': charIndex = 3; break;
            case 'z': charIndex = 4; break;
            default:  // Si no es un caracter válido, reiniciar la palabra y continuar
                if (validate == 1) {
                    cout << "Expresión válida: " << word << endl;
                }
                word = "";
                state = 0;
                validate = 0;
                continue;
        }

        // Realizar la transición de estados
        state = matrix[state][charIndex];

        // Validar estado de error
        if (state == -1) {
            i--;  // Retrocede el índice si el estado es de error
            state = 0;
            word = "";
            continue;
        }

        // Verificar si se ha llegado a un estado de aceptación
        validate = acceptance[state];
        word += car;
    }

    // Validar al final del procesamiento
    if (validate == 1) {
        cout << "Expresión válida: " << word << endl;
    }

    return 0;
}

