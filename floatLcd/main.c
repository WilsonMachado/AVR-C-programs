/* 

# Archivo:      floatLcd
# Autor:        Wilson D. Machado T.
# Copyright:    Microprocesadores y Ensamblador.
# Licencia:     Universidad del Valle - Ingeniería Electrónica.

#Descripción:   Este programa imprime un número flotante en la pantalla LCD usando el comando XXXXX que 
                pertenece a la librería YYYYY del compilador AVR GCC. Se usa el microcontrolador ATmega 32.

*/

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega32__     // Esto es necesario porque yo uso Visual Studio Code + AVR GCC Compiler. La razón es                        
    #define __AVR_ATmega32__ // simple: Atmel Studio es un IDE demasiado pesado, así que me tomé el trabajo de     
#endif                       // adecuar mi editor de código favorito para crear y compilar mi código. Si el profesor
                             // considera que debe preguntarme algo al respecto, con mucho gusto ;)
                             // ¿Qué puedo decir? Soy un friki de la programación tanto como del anime,
                             // me gusta muchísimo.
//*****************************//

// A partir de aquí, todo igual como en Atmel Studio ;)

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>     // Librería para dtostrf

#include "libs/lcd.h"
#include "libs/lcd.c"   // Librerías para la pantalla LCD


int main(void){

    DDRB = 0xFF;          // Pantalla LCD en el puerto B
    PORTB = 0x00;         // Inicializar el puerto B apagado

    double pi = 3.14159;  // Número flotante de prueba
    char t[10];           // Arreglo de caracteres donde se almacenará el número convertido

    dtostrf(pi, 1, 4, t); // Recibe:
                          // 1. Valor en flotante
                          // 2. ??? La verdad este argumento no estoy seguro de lo que hace jsjsjs
                          // 3. Cantidad de decimales que necesitemos (precisión)
                          // 4. Arreglo de caracteres donde se almacenará el número convertido

    lcd_init(LCD_DISP_ON);// Iniciliaza el LCD
    lcd_clrscr();         // Limpia la pantalla

    lcd_puts("PI = ");   // Mensaje personalizado
    lcd_puts(t);          // Impresión del valor flotante en la LCD

    while(1){
        asm volatile ("nop");   // Ciclo infinito que no hace nada
    }

    return 0;
}