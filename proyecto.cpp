#include <stdio.h>
#include <string.h>

#define NOMBRE_VALIDO "AngelRdz"
#define NUMERO_DE_TARJETA_VALIDO "226699"
#define PIN_VALIDO "1234"


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
void mostrarMenu() {
    
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