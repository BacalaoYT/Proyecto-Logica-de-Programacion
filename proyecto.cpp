#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// DATOS FIJOS
#define NOMBRE_VALIDO "AngelRdz"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO 1234
#define MAXIMO_DE_TRANSACCIONES 10

int pin_valido = PIN_VALIDO;
float saldo = 10000;
char numeroTelefono[20] = "";// Vacio ya que no hay por el momento un numero de telefono asignado
float transacciones[MAXIMO_DE_TRANSACCIONES];
int numTransacciones = 0;

//Usaremos esta funcion para cambiar el color de nuestro texto
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void agregarTransaccion(float monto) {
    if (numTransacciones < MAXIMO_DE_TRANSACCIONES) {
        transacciones[numTransacciones] = monto;
        numTransacciones++;
    } else {
        //Recorrer la cadena
        for (int i = 1; i < MAXIMO_DE_TRANSACCIONES; i++) {
            transacciones[i - 1] = transacciones[i];
        }
        transacciones[MAXIMO_DE_TRANSACCIONES - 1] = monto;
    }
}

// Función para imprimir un cuadro con título y contenido
void imprimirCuadro(const char* titulo, const char* contenido) {
    int longitud = 40;
    setColor(10);
    //ARRIBA
    for (int i = 0; i < longitud + 2; i++) printf("*");
    printf("\n");

    //TITULO
    printf("* %s", titulo);
    for (int i = strlen(titulo) + 2; i < longitud; i++) printf(" ");
    printf(" *\n");

    //DIVISION
    for (int i = 0; i < longitud + 2; i++) printf("*");
    printf("\n");

    //CONTENIDO
    printf("* %s", contenido);
    for (int i = strlen(contenido) + 2; i < longitud; i++) printf(" ");
    printf(" *\n");

    //ABAJO
    for (int i = 0; i < longitud + 2; i++) printf("*");
    printf("\n");
    setColor(15);
}

//capturar datos del usuario
void capturarDatos(char nombre[], char numeroTarjeta[], int pin) {
    system("cls");
    imprimirCuadro("BIENVENIDO AL CAJERO AUTOMÁTICO", "");

    setColor(10);
    printf("Por favor ingrese su nombre: ");
    setColor(15);
    scanf("%s", nombre);

    setColor(6);
    printf("-------Bienvenido a CodexBank-------\n");
    printf("Donde sus bits generan ganancias\n");
    setColor(15);

    setColor(14);
    printf("Por favor ingrese su numero de tarjeta: ");
    setColor(15);
    scanf("%s", numeroTarjeta);

    setColor(14);
    printf("Por favor ingrese su pin: ");
    setColor(15);
    pin = 0;
    char cadena;
    while ((cadena = getch()) != '\r') {
        if (cadena >= '0' && cadena <= '9') {
            pin = pin * 10 + (cadena - '0');
            printf("*");
        }
    }
    printf("\n");

    //Verificamos los datos
    if (strcmp(numeroTarjeta, NUMERO_DE_TARJETA_VALIDO) == 0 && pin == pin_valido) {
        setColor(10);
        printf("Datos correctos. Bienvenido %s\n", nombre);
        setColor(15);
    } else {
        setColor(4);
        printf("Los datos ingresados son incorrectos, por favor intentelo de nuevo\n");
        setColor(15);
        system("pause");
        capturarDatos(nombre, numeroTarjeta, pin);
    }
}

//Consultamos saldo
void consultarSaldo() {
    system("cls");
    char contenido[50];
    sprintf(contenido, "Su saldo actual es: $%.2f", saldo);
    imprimirCuadro("CONSULTA DE SALDO", contenido);
}

//Estado de cuenta
void estadoDeCuenta() {
    system("cls");
    char contenido[200];
    sprintf(contenido, "Nombre: %s\nSaldo actual: $%.2f\nNúmero Telefónico: %s\n", NOMBRE_VALIDO, saldo, numeroTelefono);
    imprimirCuadro("ESTADO DE CUENTA", contenido);

    printf("Transacciones recientes:\n");
    if (numTransacciones == 0) {
        printf("No hay transacciones aún\n");
    } else {
        for (int i = 0; i < numTransacciones; i++) {
            printf("Transacción %d: $%.2f\n", i + 1, transacciones[i]);
        }
    }
}

//Ultimas transacciones
void mostrarTransaccionesRecientes() {
    system("cls");
    imprimirCuadro("TRANSACCIONES RECIENTES", "");
    estadoDeCuenta();
}

//retirar dinero
void retirarDinero() {
    system("cls");
    imprimirCuadro("RETIRO DE DINERO", "");

    if (numTransacciones >= MAXIMO_DE_TRANSACCIONES) {
        setColor(12);
        printf("Ha alcanzado el límite de transacciones diarias.\n");
        setColor(15);
        return;
    }

    float monto;
    printf("Ingrese el monto a retirar (máximo $1000): ");
    scanf("%f", &monto);

    if (monto > 1000) {
        setColor(12);
        printf("El monto excede el límite por transacción.\n");
        setColor(15);
        return;
    }
    if (monto > saldo) {
        setColor(12);
        printf("Fondos insuficientes.\n");
        setColor(15);
        return;
    }

    saldo -= monto;
    agregarTransaccion(-monto);
    setColor(10);
    printf("Transacción exitosa. Su nuevo saldo es: $%.2f\n", saldo);
    setColor(15);
}

// Funcion para cambiar el PIN
void cambiarPin() {
    system("cls");
    imprimirCuadro("CAMBIAR PIN", "");

    int nuevoPin;
    printf("Ingrese su nuevo PIN: ");
    scanf("%d", &nuevoPin);
    pin_valido = nuevoPin;
    setColor(10);
    printf("PIN cambiado exitosamente.\n");
    setColor(15);
}

//Registrar numero telefonico
void registrarTelefono() {
    system("cls");
    imprimirCuadro("REGISTRAR TELÉFONO", "");

    printf("Ingrese su número de teléfono: ");
    scanf("%s", numeroTelefono);
    setColor(10);
    printf("Número registrado exitosamente.\n");
    setColor(15);
}

//Mostramos las opciones adicionales
void mostrarMasOpciones() {
    int opcion;
    do {
        system("cls");
        imprimirCuadro("MÁS OPCIONES", "");

        printf("1. Cambiar su PIN\n");
        printf("2. Registrar su número de teléfono\n");
        printf("3. Generar un estado de cuenta detallado\n");
        printf("4. Regresar al menú principal\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
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
                setColor(12);
                printf("Opción no válida. Intente de nuevo.\n");
                setColor(15);
                break;
        }
        if (opcion != 4) {
            system("pause");
        }
    } while (opcion != 4);
}

//Mostramos el menu
void mostrarMenu() {
    int opcion;
    do {
        system("cls");
        imprimirCuadro("MENÚ PRINCIPAL", "");

        printf("1. Consultar su saldo\n");
        printf("2. Mostrar últimas transacciones\n");
        printf("3. Retirar dinero\n");
        printf("4. Más opciones\n");
        printf("5. Salir y cerrar sesión\n");
        printf("Seleccione una opción: ");
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
                mostrarMasOpciones();
                break;
            case 5:
                setColor(12);
                printf("Saliendo y cerrando sesión...\n");
                setColor(15);
                break;
            default:
                setColor(12);
                printf("Opción no válida. Intente de nuevo.\n");
                setColor(15);
                break;
        }
        if (opcion != 5) {
            system("pause");
        }
    } while (opcion != 5);
}

// Función principal
int main() {
    char nombre[50];
    char numeroTarjeta[20];
    int pin;

    numTransacciones = 0;
    saldo = 10000;

    capturarDatos(nombre, numeroTarjeta, pin);
    mostrarMenu();

    return 0;
}