#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// DATOS FIJOS
#define NOMBRE_VALIDO "AngelRodriguez"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO 1234
#define MAXIMO_DE_TRANSACCIONES 10

int pin_valido = PIN_VALIDO;
float saldo = 1000;
char numeroTelefono[20] = ""; // No tenemos un numero de telefono asignado
float transacciones[MAXIMO_DE_TRANSACCIONES];
int numTransacciones = 0;

/*Con esta funcion podremos usar colores en nuestro codigo*/
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void imprimirLinea() {
    setColor(6);
    printf("****************************************\n");
    setColor(15);
}

void agregarTransaccion(float monto) {
    if (numTransacciones < MAXIMO_DE_TRANSACCIONES) {
        transacciones[numTransacciones] = monto;
        numTransacciones++;
    } else {
        for (int i = 1; i < MAXIMO_DE_TRANSACCIONES; i++) {
            transacciones[i - 1] = transacciones[i];
        }
        transacciones[MAXIMO_DE_TRANSACCIONES - 1] = monto;
    }
}

// Con esta funcion capturaremos los datos del usuario
void capturarDatos(char nombre[], char numeroTarjeta[], int *pin) {
    system("cls");
    imprimirLinea();

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
    *pin = 0;
    char cadena;
    while ((cadena = getch()) != '\r') {
        if (cadena >= '0' && cadena <= '9') {
            *pin = *pin * 10 + (cadena - '0');
            printf("*");
        }
    }
    printf("\n");

    // Comprobaremos que los datos ingresados sean correctos
    if (strcmp(numeroTarjeta, NUMERO_DE_TARJETA_VALIDO) == 0 && *pin == pin_valido) {
        setColor(10);
        printf("Datos correctos. Bienvenido %s\n", nombre); //Caso correcto
        setColor(15);
    } else {
        setColor(4);
        printf("Los datos ingresados son incorrectos, por favor intentelo de nuevo\n"); //Dato incorrecto ingresado
        setColor(15);
        system("pause");
        capturarDatos(nombre, numeroTarjeta, pin);
    }

    imprimirLinea();
}

//Funcion para consultar el saldo
void consultarSaldo() {
    system("cls");
    imprimirLinea();
    printf("Su saldo actual es: $%.2f\n", saldo);
    imprimirLinea();
}

//Esado de cuenta
void estadoDeCuenta() {
    system("cls");
    imprimirLinea();
    printf("Nombre: %s\n", NOMBRE_VALIDO);
    printf("Saldo actual: $%.2f\n", saldo);
    printf("Numero Telefonico: %s\n", numeroTelefono);
    printf("\nTransacciones recientes:\n");

    if (numTransacciones == 0) {
        printf("No hay transacciones aun\n");
    } else {
        for (int i = 0; i < numTransacciones; i++) {
            printf("Transaccion %d: $%.2f\n", i + 1, transacciones[i]);
        }
    }
    imprimirLinea();
}

// Funcion para mostrar transacciones recientes
void mostrarTransaccionesRecientes() {
    system("cls");
    imprimirLinea();
    estadoDeCuenta();
    imprimirLinea();
}

// Funcion para retirar dinero
void retirarDinero() {
    system("cls");
    imprimirLinea();

    if (numTransacciones >= MAXIMO_DE_TRANSACCIONES) {
        setColor(12);
        printf("Ha alcanzado el limite de transacciones diarias.\n"); //Limite de transacciones diarias limitado a 10
        setColor(15);
        imprimirLinea();
        return;
    }

    float monto;
    printf("Ingrese el monto a retirar (maximo $1000): "); //Podremos retirar un maximo de $1000 POR TRANSACCION
    scanf("%f", &monto);

    if (monto > 1000) {
        setColor(12);
        printf("El monto excede el limite por transaccion.\n");
        setColor(15);
        imprimirLinea();
        return;
    }
    if (monto > saldo) {
        setColor(12);
        printf("Fondos insuficientes.\n"); //No contamos con el suficiente dinero
        setColor(15);
        imprimirLinea();
        return;
    }

    saldo -= monto;
    agregarTransaccion(-monto);
    setColor(10);
    printf("Transaccion exitosa. Su nuevo saldo es: $%.2f\n", saldo);
    setColor(15);
    imprimirLinea();
}

//Esta funcion nos permitira retirar dinero de manera mas rapida
void retiroRapido() {
    system("cls");
    imprimirLinea();
    setColor(14);
    printf("----Seleccione una cantidad para retiro rapido----\n");
    printf("1. $20\n");
    printf("2. $50\n");
    printf("3. $100\n");
    printf("Seleccione una opcion: ");
    setColor(15);
    int opcion;
    scanf("%d", &opcion);

    float monto;
    switch (opcion) {
        case 1:
            monto = 20;
            break;
        case 2:
            monto = 50;
            break;
        case 3:
            monto = 100;
            break;
        default:
            setColor(12);
            printf("Opcion no valida. Intente de nuevo.\n");
            setColor(15);
            imprimirLinea();
            return;
    }
    //Comprobamos que contemos con dinero suficiente
    if (monto > saldo) {
        setColor(12);
        printf("Fondos insuficientes.\n");
        setColor(15);
        imprimirLinea();
        return;
    }

    saldo -= monto;
    agregarTransaccion(-monto);
    setColor(10);
    printf("Transaccion exitosa. Su nuevo saldo es: $%.2f\n", saldo);
    setColor(15);
    imprimirLinea();
}

//Con esta funcion cambiaremos nuestro pin inicial por uno personalizado
void cambiarPin() {
    system("cls");
    imprimirLinea();

    int nuevoPin;
    setColor(1);
    printf("Ingrese su nuevo PIN: ");
    setColor(15);
    scanf("%d", &nuevoPin);
    pin_valido = nuevoPin;
    setColor(10);
    printf("PIN cambiado exitosamente.\n");
    setColor(15);
    imprimirLinea();
}

//Con esta funcion podremos agregar nuestro numero telefonico en caso de ser neceaario
void registrarTelefono() {
    system("cls");
    imprimirLinea();

    printf("Ingrese su numero de telefono: ");
    scanf("%s", numeroTelefono);
    setColor(10);
    printf("Numero registrado exitosamente.\n");
    setColor(15);
    imprimirLinea();
}

//Mostraremos mas opciones que no estan en el menu principal
void mostrarMasOpciones() {
    int opcion;
    do {
        system("cls");
        imprimirLinea();
        setColor(2);
        printf("1. Cambiar su PIN\n");
        printf("2. Registrar su numero de telefono\n");
        printf("3. Generar un estado de cuenta detallado\n");
        printf("4. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
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
                printf("Opcion no valida. Intente de nuevo.\n");
                setColor(15);
                break;
        }
        if (opcion != 4) {
            system("pause");
        }
        imprimirLinea();
    } while (opcion != 4);
}

//Funcionq que llama al menu de opciones basicas
void mostrarMenu() {
    int opcion;
    do {
        system("cls");
        imprimirLinea();
        setColor(11);
        printf("1. Consultar su saldo\n");
        printf("2. Mostrar ultimas transacciones\n");
        printf("3. Retirar dinero\n");
        printf("4. Retiro rapido\n");
        printf("5. Mas opciones\n");
        printf("6. Salir y cerrar sesion\n");
        printf("Seleccione una opcion: ");
        setColor(15);
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
                retiroRapido();
                break;
            case 5:
                mostrarMasOpciones();
                break;
            case 6:
                setColor(12);
                printf("Saliendo y cerrando sesion...\n");
                setColor(15);
                break;
            default:
                setColor(12);
                printf("Opcion no valida. Intente de nuevo.\n");
                setColor(15);
                break;
        }
        if (opcion != 6) {
            system("pause");
        }
        imprimirLinea();
    } while (opcion != 6);
}

int main() {
    char nombre[50];
    char numeroTarjeta[20];
    int pin;
    numTransacciones = 0;
    saldo = 1000.0;

    while (1) {
        capturarDatos(nombre, numeroTarjeta, &pin);
        mostrarMenu();
    }
    return 0;
}