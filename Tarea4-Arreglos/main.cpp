#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

// Clase Encriptador
class Encriptador {
private:
    int Abecedario[26] = {
        32, 57, 14, 89, 45, 7, 92, 66, 23, 78,
        15, 53, 30, 61, 44, 99, 11, 70, 3, 49,
        27, 84, 6, 65, 38, 22
    };

public:
    // Encriptar la palabra: se convierte en números según el arreglo
    void EncriptarPalabra(const char* Palabra) {
        for (int i = 0; Palabra[i] != '\0'; ++i) {
            char Letra = tolower(Palabra[i]);
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
    int Abecedario[26] = {
        32, 57, 14, 89, 45, 7, 92, 66, 23, 78,
        15, 53, 30, 61, 44, 99, 11, 70, 3, 49,
        27, 84, 6, 65, 38, 22
    };

public:
    // Desencriptar la palabra: se convierte de números a letras
    void DesencriptarPalabra(const char* Codigo) {
        char LetraDesencriptada;
        int Valor;
        int i = 0;
        while (sscanf(Codigo + i, "%d", &Valor) == 1) {
            for (int j = 0; j < 26; ++j) {
                if (Abecedario[j] == Valor) {
                    LetraDesencriptada = 'a' + j; // Buscar la letra correspondiente
                    printf("%c", LetraDesencriptada);
                    break;
                }
            }
            while (Codigo[i] != ' ' && Codigo[i] != '\0') { // Saltar el espacio o final
                ++i;
            }
            if (Codigo[i] != '\0') {
                ++i; // Saltar el espacio
            }
        }
        printf("\n");
    }
};

// Función para encriptar
void Encriptar(Encriptador& MiEncriptador) {
    printf("Ingrese una palabra a encriptar: ");
    char Palabra[100];
    scanf("%s", Palabra);
    printf("Palabra encriptada: ");
    MiEncriptador.EncriptarPalabra(Palabra);
}

// Función para desencriptar
void Desencriptar(Desencriptador& MiDesencriptador) {
    printf("\nIngrese la palabra encriptada para desencriptar: ");
    char Codigo[300];
    getchar();  // Para capturar el salto de línea pendiente
    fgets(Codigo, sizeof(Codigo), stdin); // Leer la entrada de números encriptados
    printf("Palabra desencriptada: ");
    MiDesencriptador.DesencriptarPalabra(Codigo);
}

// Función principal - menú
int main() {
    Encriptador MiEncriptador;
    Desencriptador MiDesencriptador;
    int opcion;

    do {
        printf("\n*******************\n");
        printf("\nQue desea realizar?\n");
        printf("1 - Encriptar\n");
        printf("2 - Desencriptar\n");
        printf("3 - Salir\n");
        printf("\n*******************\n");
        printf("Ingrese una opción (1, 2, 3): ");
        scanf("%d", &opcion);

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
    } while (opcion != 3);

    return 0;
}

