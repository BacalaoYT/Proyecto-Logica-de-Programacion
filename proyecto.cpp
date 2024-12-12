#include <stdio.h>
#include <string.h>
#include <conio.h>

//DATOS FIJOS
#define NOMBRE_VALIDO "AngelRdz"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO 1234

int pin_valido = PIN_VALIDO;
float saldo = 10000;
char numeroTelefono[20];

void capturarDatos(char nombre[], char numeroTarjeta[], int pin) {

    //Registramos su nombre
    printf("Por favor ingrese su nombre: ");
    scanf("%s", nombre);

    //Binvenida al usuario
    printf("-------Bienvenido a CodexBank-------\n");
    printf("Donde sus bits generan ganancias\n");

    printf("Por favor ingrese su numero de tarjeta: \n", nombre);
    scanf("%s", numeroTarjeta);

    /*En esta parte del codigo se solicicta al usuario que ingrese su PIN
    Se evalua que los digitos sean del 0-9, cadena toma el valor del numero,
    se multiplica por el 10 y se suma 1 para construir la cadena en tiempo real
    cada vez que se ingresa un numero, se cambia por un asterisco, y se deja de
    contar cuando presionamos la tecla del Enter ("\r") */

    printf("Por favor ingrese su pin: ");
    pin = 0;
    char cadena;
    while ((cadena = getch()) != '\r') {
        if (cadena >= '0' && cadena <= '9') {
            pin = pin * 10 + (cadena - '0');
            printf("*");
        }
    }
    printf("\n");

    //Tendremos que comprobar que los datos sean correctps
    if (strcmp(numeroTarjeta, NUMERO_DE_TARJETA_VALIDO) == 0 && pin == pin_valido) {
        printf("Datos correctos. Bienvenido %s\n", nombre);
    } else
    {
        printf("Los datos ingresados son incorrectos, por favor intentelo de nuevo\n");
        capturarDatos(nombre, numeroTarjeta, pin);
    }
}

/*Haremos los voids desde aqui para posteriormente irlos llamando en la funcion del menu
esto con el objetivo de hazerlo mas eficiente y facil de modificar*/

void consultarSaldo() {
    printf("Su saldo actual es: $%.2f\n", saldo);
}

void mostrarTransaccionesRecientes() {
    //Pendiente
    printf("Mostrando transacciones recientes...\n");
}

void retirarDinero() {
    //Pendiente
}

void cambiarPin() {
    int nuevoPin;
    printf("Ingrese su nuevo pin: ");
    scanf("%d", &nuevoPin);
    pin_valido = nuevoPin;
    printf("Su pin ha sido cambiado exitosamente!!!\n");
}

void registrarTelefono(){
    printf("----Registrar su numero de telefono----\n");
    printf("Por favor ingrese su numero de telefono: ");
    scanf("%s", numeroTelefono);
    printf("Su numero de telefono ha sido registrado exitosamente!!!\n");
}

void estadoDeCuenta() {
    printf("Generacion de su estado de cuenta...\n");
    printf("Nombre: %s\t Saldo actual %.2f\t Numero Telefonico %s\t", NOMBRE_VALIDO, saldo, numeroTelefono);
    printf("Transacciones recientes: \n");
    // Pendiente

}

void mostrarMenu(int opcion, int masOpciones) {

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
                printf("4. Regresar al menu principal\n");

                int masOpciones;
                scanf("%d", &masOpciones);

                switch (masOpciones) {
                    case 1:
                        cambiarPin();
                        break;

                    case 2:
                        registrarTelefono();
                        break;

                    case 3:
                        estadoDeCuenta();
                        break;

                    case 4:
                        printf("Regresar al menu principal\n");
                        break;

                    default:
                        printf("Opcion no valida\n");
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
    int pin, opcion, masOpciones;

    capturarDatos(nombre, numeroTarjeta, pin);
    mostrarMenu(opcion, masOpciones);

    return 0;
}