#include <stdio.h>
#include <string.h>

#define NOMBRE_VALIDO "AngelRdz"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO 1234

int pin_valido = PIN_VALIDO;
float saldo = 10000;

void capturarDatos(char nombre[], char numeroTarjeta[], int pin) {
    //Capturamos los datos del usuario
    printf("Por favor ingrese su nombre: ");
    scanf("%s", nombre);

    //Bienvenida al usuario
    printf("-------Bienvenido a CodexBank-------\n");
    printf("\n\nDonde sus bits generan ganancias\n\n");
    printf("\t");
    printf("Buenas tardes %s\n", nombre);

    //Capturaremos el numero de tarjeta
    printf("Por favor %s ingrese su numero de tarjeta: ", nombre);
    scanf("%s", numeroTarjeta);

    //Capturaremos el pin
    printf("Por favor ingrese su pin: ");
    scanf("%d", &pin);

    //Comprobaremos si los datos ingresados son correctos
    if (strcmp(numeroTarjeta, NUMERO_DE_TARJETA_VALIDO) == 0 || pin == pin_valido) {
        printf("Datos correctos. Bienvenido %s\n", nombre);

    } else {
        printf("Datos incorrectos. Por favor verifique su informacion\n");
    }
}

void consultarSaldo() {
}

void mostrarTransaccionesRecientes() {

}

void retirarDinero() {

}

void mostrarMenu(int opcion, int masOpciones,int nuevoPin, char numeroTelefono[]) {

    do {
        printf("----Ingrese el numero de opcion que desee realizar---- \n");
        printf("1. Consultar su saldo\n");
        printf("2. Mostrar las transacciones recientes\n");
        printf("3. Retirar dinero\n");
        printf("4. Mas opciones\n");
        printf("5. Salir y cerrar sesion\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                consultarSaldo();
                break;
            case 2:
                mostrarTransaccionesRecientes();
                break;
            case 3:
                retirarDinero();
                break;
            case 4:
                printf("----Mas opciones----\n");
                printf("1. Cambiar su pin\n");
                printf("2. Registrar su numero de telefono\n");
                printf("3. Generar un estado de cuenta detallado\n");
                scanf("%d", &masOpciones);

                switch (masOpciones)
                {
                    case 1:
                        printf("Ingrese su nuevo pin: ");
                        scanf("%d", &nuevoPin);
                        pin_valido = nuevoPin;
                        printf("Su pin ha sido cambiado exitosamente.\n");
                        break;

                    case 2:
                        printf("Registrar su numero de telefono\n");
                        printf("Por favor ingrese su numero de telefono: ");
                        scanf("%s", numeroTelefono);
                        printf("Su numero de telefono ha sido registrado exitosamente!!!\n");
                        break;

                    case 3:
                        printf("Generar un estado de cuenta detallado\n");
                        printf("Nombre: %s\t Saldo actual %.2f\t Numero Telefonico %s\t", NOMBRE_VALIDO, saldo, numeroTelefono);
                        printf("Transacciones recientes: \n");
                        //Pendiente
                        printf("Estado de cuenta detallado generado exitosamente!!!\n");
                        break;
                }
                break;
            case 5:
                printf("Saliendo y cerrando sesion\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (opcion != 5);
}

int main() {
    char nombre[50];
    char numeroTarjeta[20];
    int pin;
    int opcion;
    int masOpciones;
    int nuevoPin;
    char numeroTelefono[20];

    capturarDatos(nombre, numeroTarjeta, pin);
    mostrarMenu(opcion, masOpciones, nuevoPin, numeroTelefono);

    return 0;
}