#include <stdio.h>
#include <string.h>
#include <conio.h>

// DATOS FIJOS
#define NOMBRE_VALIDO "AngelRdz"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO 1234
#define MAXIMO_DE_TRANSACCIONES 10

int pin_valido = PIN_VALIDO;
float saldo = 10000;
char numeroTelefono[20] = ""; // Vacio ya que no hay por el momento un numero de telefono asignado

/* Tendremos que definir desde aca el arreglo de transacciones y el numero de transacciones
para usarlas y mostrarlas mas adelante */

float transacciones[MAXIMO_DE_TRANSACCIONES];
int numTransacciones = 0;

void agregarTransaccion(float monto){
    if (numTransacciones < MAXIMO_DE_TRANSACCIONES){
        transacciones[numTransacciones] = monto;
        numTransacciones++;
    }
    else{
        //Movemos la cadena
        for (int i = 1; i < MAXIMO_DE_TRANSACCIONES; i++) {
            transacciones[i - 1] = transacciones[i];
        }
        transacciones[MAXIMO_DE_TRANSACCIONES - 1] = monto;
    }
}

void capturarDatos(char nombre[], char numeroTarjeta[], int pin) {
    // Capturaremos su nombre
    printf("Por favor ingrese su nombre: ");
    scanf("%s", nombre);

    //Bienvenida al usuario
    printf("-------Bienvenido a CodexBank-------\n");
    printf("Donde sus bits generan ganancias\n");

    printf("Por favor ingrese su numero de tarjeta: ");
    scanf("%s", numeroTarjeta);

    /* En esta parte del codigo se solicita al usuario que ingrese su PIN
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

    //Comprobar que los datos sean correctos
    if (strcmp(numeroTarjeta, NUMERO_DE_TARJETA_VALIDO) == 0 && pin == pin_valido) {
        printf("Datos correctos. Bienvenido %s\n", nombre);
    } else {
        printf("Los datos ingresados son incorrectos, por favor intentelo de nuevo\n");
        capturarDatos(nombre, numeroTarjeta, pin);
    }
}

void consultarSaldo() {
    printf("Su saldo actual es: $%.2f\n", saldo);
}

void estadoDeCuenta() {
    printf("\n----Estado de Cuenta----\n");
    printf("Nombre: %s\n", NOMBRE_VALIDO);
    printf("Saldo actual: $%.2f\n", saldo);
    printf("Numero Telefonico: %s\n", numeroTelefono);
    printf("\nTransacciones recientes:\n");

    if (numTransacciones == 0){
        printf("No hay transacciones aun\n");
    } else{
        for (int i = 0; i < numTransacciones; i++) {
            printf("Transaccion %d: $%.2f\n", i + 1, transacciones[i]);
        }
    }
    printf("\n");
}

void mostrarTransaccionesRecientes() {
    printf("Mostrando transacciones recientes...\n");
    estadoDeCuenta();
}

void retirarDinero() {
    int opcion;
    float retiro = 0;

    printf("\n----Retirar dinero----\n");
    printf("1. Retiro personalizado (maximo $1000)\n");
    printf("2. Retiro rapido $20\n");
    printf("3. Retiro rapido $50\n");
    printf("4. Retiro rapido $100\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Ingrese la cantidad a retirar: ");
            scanf("%f", &retiro);
            break;
        case 2:
            retiro = 20;
            break;
        case 3:
            retiro = 50;
            break;
        case 4:
            retiro = 100;
            break;
        default:
            printf("Por favor seleccione una opcion del menu\n");
            return;
    }

    if (retiro <= 0 || retiro > 1000){//Revisamos que este en el rango permitido
        printf("La transaccion no pudo completarse ($1-1000)\n");
        return;
    }

    if (retiro > saldo){// Revisamos el saldo
        printf("TRANSACCION FALLIDA, FONDOS INSUFICIENTES\n");
        printf("Su saldo actual es: $%.2f\n", saldo);
        return;
    }

    saldo -= retiro;
    agregarTransaccion(retiro);
    printf("\nRetiro exitoso por la cantidad de: $%.2f\n", retiro);
    printf("Su nuevo saldo es: $%.2f\n", saldo);
    estadoDeCuenta(); // Llamamos la funcion para mostrar las transacciones despues
}

void cambiarPin() {
    int nuevoPin;
    printf("Ingrese su nuevo pin: ");
    scanf("%d", &nuevoPin);
    pin_valido = nuevoPin;
    printf("Su pin ha sido cambiado exitosamente!\n");
}

void registrarTelefono() {
    printf("----Registrar su numero de telefono----\n");
    printf("Por favor ingrese su numero de telefono: ");
    scanf("%s", numeroTelefono);
    printf("Numero registrado exitosamente!!!\n");
}

void mostrarMenu() {
    int opcion;
    do {
        printf("----Ingrese el numero de opcion que desea realizar----\n");
        printf("1. Consultar su saldo\n");
        printf("2. Mostrar ultimas transacciones\n");
        printf("3. Retirar dinero\n");
        printf("4. Mas opciones\n");
        printf("5. Salir y cerrar sesion\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                consultarSaldo();
                break;
            case 2:
                estadoDeCuenta();
                break;
            case 3:
                retirarDinero();
                break;
            case 4:
                printf("----Mas opciones----\n");
                printf("1. Cambiar su PIN\n");
                printf("2. Registrar su numero de telefono\n");
                printf("3. Generar un estado de cuenta detallado\n");
                printf("4. Regresar al menu principal\n");
                printf("Seleccione una opcion: ");

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
                        printf("Regresando al menu principal...\n");
                        break;
                    default:
                        printf("OPCION NO VALIDA\n");
                        break;
                }
                break;
            case 5:
                printf("Saliendo y cerrando sesion...\n");
                break;
            default:
                printf("OPCION NO VALIDA\n");
                break;
        }
    } while (opcion != 5);
}

int main() {
    char nombre[50];
    char numeroTarjeta[20];
    int pin;

    capturarDatos(nombre, numeroTarjeta, pin);
    mostrarMenu();

    return 0;
}