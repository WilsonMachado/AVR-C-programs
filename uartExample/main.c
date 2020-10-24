/* 

# Archivo:      uartExample
# Autor:        Wilson D. Machado T.
# Copyright:    Microprocesadores y Ensamblador.
# Licencia:     Universidad del Valle - Ingeniería Electrónica.

#Descripción:   Este programa recibe un caracter a través de la interface RS232 y hace toggle de un LED si dicho
                caracter es 'a'. En caso contrario, devuelve 'F' y hace un retorno de carro. Todo está programado
                para el microcontrolador ATmega32 y funciona con las interrupciones.
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
#define BAUD 9600

#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>  // Librería para las interrupciones

// Librerías propias 
#include "funcs.h"
#include "funcs.c"

// Interrupciones

#include "isrs.h"
    
int main(void){

    DDRB = 0xFF;
    PORTB = 0x00;

    cli();
    uartConfig();
    sei();
    
    while(1){         
    }

    return 0;
}

