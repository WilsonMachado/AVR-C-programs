/* 

# Archivo:      keyboard
# Autor:        Wilson D. Machado T.
# Copyright:    Microprocesadores y Ensamblador.
# Licencia:     Universidad del Valle - Ingeniería Electrónica.

#Descripción:   Este programa permite usar 16 botones normales como un keyboard matricial de 4x4.
                La intención de este código es ilustrar cómo funciona la lectura de un periferico de 
                entrada como este:

                | 1 | 2 | 3 | A |   F0
                | 4 | 5 | 6 | B |   F1
                | 7 | 8 | 9 | C |   F2
                | # | 0 | * | D |   F3
                
                  C0  C1  C2  C3                 

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

#include "funcs.h"
#include "funcs.c"

int main(void){

    DDRC = 0xFF;
    PORTC = 0x00;

    unsigned char key = 0;

    kbInit();                 // Se inicializa el tecaldo

    while(1){

        key = kbGetKey();     // Se obtiene la lectura del teclado

        if(key != 0){         // Si key no es cero
            PORTC = key - 48; // Se le resta 48 a la tecla obtenida para mostrar el número en los LEDs
        }
    }   


    return 0;
}