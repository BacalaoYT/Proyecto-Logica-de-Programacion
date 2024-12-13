# Proyecto: CodexBank Cajero Automatico

## ¿De que trata mi codigo?
Este proyecto es un programa en C que simula las funciones y opciones de un cajero automatico basico. En mi proyecto podemos realizar diferentes operaciones bancarias comunes como consultar el saldo, retirar dinero, y gestionar informacion personal como el PIN o el numero de telefono.

El programa esta disenado para ejecutarse en la consola y, aunque es sencillo, incluye detalles visuales como colores y mensajes con los cuales se busca que el usuario pueda tener una experiencia comoda.

--------------------------------------------------------------------------------------------------------------------------------------------------

## ¿Que incluye mi programa?
1. **Un inicio de sesion seguro:**
   - El programa solicita nombre, numero de tarjeta y PIN para poder darle acceso al usuario.
   - Permite que el usuario pueda cambiar su PIN de forma facil y rapida.

2. **Gestion de saldo y operaciones:**
   - Podra consultar el saldo disponible de la cuenta.
   - Realizar retiros de dinero por una cantidad especifica o usando la opcion "retiro rapido" con opciones predeterminadas ($20, $50, $100).
   - Registra las ultimas 5 transacciones realizadas.

3. **Mas opciones:**
   - Generar un estado de cuenta que muestra un resumen de las transacciones realizadas.
   - Registrar o actualizar el numero de telefono asociado a la cuenta.

4. **Interfaz**
   - Incluye una interfaz usando colores para diferenciar mensajes de informacion, errores y advertencias.
   - Ofrece un menu claro e intuitivo para navegar entre las diferentes opciones del programa.

--------------------------------------------------------------------------------------------------------------------------------------------------

## Como funciona?
1. **Inicio de sesion:**
   - Al iniciar, el programa solicita el nombre, numero de tarjeta y PIN del usuario
   - Por defecto, el numero de tarjeta es `226699` y el PIN es `1234`.
   - Si el usuario introduce informacion incorrecta, se le pedira que intente de nuevo hasta que los datos sean validos.

2. **Opciones del menu principal:**

   - **1. Consultar saldo:**
   - **2. Revisar transacciones:**
   - **3. Retirar dinero:**
   - **4. Retiro rapido:**
   - **5. Opciones adicionales:**
   - **6. Salir:**

--------------------------------------------------------------------------------------------------------------------------------------------------

## ¿Como esta estructurado?
El programa esta organizado en funciones independientes y faciles de comprender como:

- **`capturarDatos`**: Gestiona la entrada de datos y valida que sean correctos.
- **`consultarSaldo`**: Muestra el saldo actual del usuario.
- **`retirarDinero`**: Permite realizar retiros verificando el saldo disponible y los limites establecidos.
- **`retiroRapido`**: Simplifica los retiros con montos predefinidos.
- **`estadoDeCuenta`**: Genera un resumen de las transacciones realizadas por el usuario.
- **`cambiarPin`**: Facilita la actualizacion del PIN de manera segura.
- **`registrarTelefono`**: Permite asociar o actualizar un numero de telefono para la cuenta.
- **`mostrarMenu`**: Controla la navegacion entre las diferentes opciones del programa.

--------------------------------------------------------------------------------------------------------------------------------------------------
## Autor
Este programa fue desarrollado por **Angel Emmanuel Rodriguez Diaz** como parte del proyecto final de logica de programacion impartido por la maestra `Estela Lizbeth Muñoz Andrade`.



                                                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⣶⣶⣦⠀⠀
                                                    ⠀⠀⣠⣤⣤⣄⣀⣾⣿⠟⠛⠻⢿⣷⠀
                                                    ⢰⣿⡿⠛⠙⠻⣿⣿⠁⠀⠀ ⠀⣶⢿⡇
                                                    ⢿⣿⣇⠀⠀⠀⠈⠏ Gracias por leer
                                                    ⠀⠻⣿⣷⣦⣤⣀⠀⠀⠀ ⠀⣾⡿⠃⠀
                                                    ⠀⠀⠀⠀⠉⠉⠻⣿⣄⣴⣿⠟⠀⠀⠀
                                                    ⠀⠀⠀⠀⠀⠀⠀⠀⣿⡿⠟⠁⠀⠀⠀