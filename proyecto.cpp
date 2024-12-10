#include <stdio.h>
#include <string.h>

#define NOMBRE_VALIDO "AngelRdz"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO "1234"
#define SALDO_INICIAL 10000


void capturarDatos(char nombre[], char numeroTarjeta[], int pin, int i){
    
    //Capturamos los datos del usuario
    printf("Por favor ingrese su nombre: ");
    scanf("%s", nombre);

    // Damos la bienvenida al usuario
    printf("-------Bienvenido a CodexBank-------\n");
    printf("\n\nDonde sus bits generan ganancias\n\n");
    printf("\t");
    printf("Buenas tardes %s\n", nombre);

    //Capturamos el número de tarjeta
    printf("Por favor %s ingrese su numero de tarjeta: ", nombre);
    scanf("%s", numeroTarjeta);

    //Capturamos el pin
    printf("Por favor ingrese su pin: ");
    scanf("%d", &pin);

    /*Tendremos que convertir el pin a cadena para poder compararlo en la funcion strcmp,
    ya que solo admite cadenas y nosotros tenemos un entero, para eso usaremos una funcion llamada
    "sprintf", la cual no imprime un valor directamente en la consola si no que devuelve la cadena*/

    char pinCadena[5];
    sprintf(pinCadena, "%d", pin);

    //Dar un maximo de 3 intentos

    // Comprobaremos que los datos sean correctos
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(numeroTarjeta, NUMERO_DE_TARJETA_VALIDO) == 0 && strcmp(pinCadena, PIN_VALIDO) == 0){
        printf("Los datos ingresados son correctos, bienvenido nuevamente %s\n", nombre, i++);
        printf("Cargando menu de opciones...\n");

        }else
        {
        printf("Los datos ingresados son incorrectos, por favor intente nuevamente.\n");
        }
    }
    
}

void mostrarMenu(int opcion, float retiro, float saldoActual, int masOpciones) {
    printf("----Ingrese el numero de opcion que desee realizar---- \n");
    printf("1. Consultar su saldo\n");
    printf("2. Mostrar las transacciones recientes\n");
    printf("3. Retirar dinero\n");
    printf("4. Salir y cerrar sesion\n");
    printf("5. Mas opciones\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("----Consulta de saldo----\t");
            printf("Su saldo actual es de: %0.2f\n", SALDO_INICIAL);
            break;

        case 2:
            printf("----Mostrar transacciones recientes----\n");

            break;

        case 3:
            printf("----Retirar dinero----\t");
            printf("Ingrese la cantidad  de dinero que desea retirar, usted cuenta con: %f\n", SALDO_INICIAL);
            scanf("%f", &retiro);

            retiro -= SALDO_INICIAL;
            saldoActual = SALDO_INICIAL - retiro;

            printf("Usted ha retirado: %0.2f\n, y su saldo actual es de %0.2f\n ", retiro, saldoActual);

            if (retiro > SALDO_INICIAL)
            {
             printf("Usted no cuenta con el dinero suficiente para realizar esta opcion");
            }
            break;

        case 4:
            printf("----Salir y cerrar sesion----\t");
            printf("Gracias por usar CodexBank, su banco de confianzza\n");
            printf("Cerrando sesion...\n");
            return;
            break;

        case 5:

            printf("----Mas opciones----\t");
            printf("1. Cambiar su pin\n");
            printf("2. Registrar su numero de telefono\n");
            printf("3. Generar un estado de cuenta detallado\n");
            printf("4. Regresar al menu principal\n");

            switch (masOpciones)
            {
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:

                break;
            case 4:

                break;
            
            default:
                break;
            }
            break;

        default:
            printf("Por favor seleccione una opcion dentro del rango (1-5)");
            return;
            break;
            
    }
}

void consultarSaldo(float saldo) {
    
}

void mostrarTransaccionesRecientes(float transacciones[], int numTransacciones) {
    
}

void retirarDinero(float *saldo, float transacciones[], int *numTransacciones) {
    
}


int main() {
    char nombre[50];
    char numeroTarjeta[50];
    int pin;
    float saldo = 50000;

    //Llamar a las funciones
    void capturarDatos(char nombre[], char numeroTarjeta[], int pin);

    return 0;
}