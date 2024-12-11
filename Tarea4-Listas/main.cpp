#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

// Clase Encriptador
class Encriptador {
private:
    vector<int> Abecedario;

public:
    // Constructor que inicializa el vector
    Encriptador() {
        Abecedario.push_back(32);
        Abecedario.push_back(57);
        Abecedario.push_back(14);
        Abecedario.push_back(89);
        Abecedario.push_back(45);
        Abecedario.push_back(7);
        Abecedario.push_back(92);
        Abecedario.push_back(66);
        Abecedario.push_back(23);
        Abecedario.push_back(78);
        Abecedario.push_back(15);
        Abecedario.push_back(53);
        Abecedario.push_back(30);
        Abecedario.push_back(61);
        Abecedario.push_back(44);
        Abecedario.push_back(99);
        Abecedario.push_back(11);
        Abecedario.push_back(70);
        Abecedario.push_back(3);
        Abecedario.push_back(49);
        Abecedario.push_back(27);
        Abecedario.push_back(84);
        Abecedario.push_back(6);
        Abecedario.push_back(65);
        Abecedario.push_back(38);
        Abecedario.push_back(22);
    }

    // Encriptar la palabra: se convierte en números según el arreglo
    void EncriptarPalabra(const string& Palabra) {
        for (int i = 0; i < Palabra.length(); ++i) {
            char Letra = Palabra[i];
            Letra = tolower(Letra);
            if (Letra >= 'a' && Letra <= 'z') {
                int Indice = Letra - 'a'; // Obtener índice en el abecedario
                printf("%d ", Abecedario[Indice]); // Mostrar el número correspondiente
            }
        }
        printf("\n");
    }
};

// Clase Desencriptador
class Desencriptador {
private:
    vector<int> Abecedario;

public:
    // Constructor que inicializa el vector
    Desencriptador() {
        Abecedario.push_back(32);
        Abecedario.push_back(57);
        Abecedario.push_back(14);
        Abecedario.push_back(89);
        Abecedario.push_back(45);
        Abecedario.push_back(7);
        Abecedario.push_back(92);
        Abecedario.push_back(66);
        Abecedario.push_back(23);
        Abecedario.push_back(78);
        Abecedario.push_back(15);
        Abecedario.push_back(53);
        Abecedario.push_back(30);
        Abecedario.push_back(61);
        Abecedario.push_back(44);
        Abecedario.push_back(99);
        Abecedario.push_back(11);
        Abecedario.push_back(70);
        Abecedario.push_back(3);
        Abecedario.push_back(49);
        Abecedario.push_back(27);
        Abecedario.push_back(84);
        Abecedario.push_back(6);
        Abecedario.push_back(65);
        Abecedario.push_back(38);
        Abecedario.push_back(22);
    }

    // Desencriptar la palabra: se convierte de números a letras
    void DesencriptarPalabra(const string& Codigo) {
        size_t i = 0;
        while (i < Codigo.length()) {
            // Obtener el valor numérico en el código
            int Valor = 0;
            while (i < Codigo.length() && Codigo[i] != ' ') {
                Valor = Valor * 10 + (Codigo[i] - '0'); // Construir el número
                ++i;
            }
            if (Valor != 0) {
                for (int j = 0; j < Abecedario.size(); ++j) {
                    if (Abecedario[j] == Valor) {
                        printf("%c", 'a' + j); // Buscar la letra correspondiente
                        break;
                    }
                }
            }
            while (i < Codigo.length() && Codigo[i] == ' ') {
                ++i; // Avanzar por los espacios
            }
        }
        printf("\n");
    }
};

// Función para encriptar
void Encriptar(Encriptador& MiEncriptador) {
    printf("Ingrese una palabra a encriptar: ");
    string Palabra;
    cin >> Palabra;
    printf("Palabra encriptada: ");
    MiEncriptador.EncriptarPalabra(Palabra);
}

// Función para desencriptar
void Desencriptar(Desencriptador& MiDesencriptador) {
    printf("\nIngrese la palabra encriptada para desencriptar: ");
    string Codigo;
    cin.ignore();  // Para capturar el salto de línea pendiente
    getline(cin, Codigo); // Leer la entrada de números encriptados
    printf("Palabra desencriptada: ");
    MiDesencriptador.DesencriptarPalabra(Codigo);
}

// Función principal con menú
int main() {
    Encriptador MiEncriptador;
    Desencriptador MiDesencriptador;
    int opcion;

    do {
        // Mostrar menú
        printf("\n**************************\n");
        printf("\nQue desea realizar?\n");
        printf("1 - Encriptar\n");
        printf("2 - Desencriptar\n");
        printf("3 - Salir\n");
        printf("Ingrese una opción (1, 2, 3): ");
        printf("\n**************************\n");
        scanf("%d", &opcion);

        // Llamar a las funciones correspondientes
        switch(opcion) {
            case 1:
                Encriptar(MiEncriptador);
                break;
            case 2:
                Desencriptar(MiDesencriptador);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 3);  // El menú sigue hasta que el usuario elige salir

    return 0;
}

