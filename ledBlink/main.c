/*

# Archivo:   ledBlink
# Autor:     Wilson D. Machado T.
# Copyright: WDesigns
# Licencia:  Libre. Ejemplos para aprendizaje y referencia  

# Descripción: Primera prueba de programación en C usando VS Code & AVR-GCC compiler.
               Se hace parpadear un LED durante un periodo de tiempo. Incluye simulación.

*/

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

//*****************************//

#define F_CPU 16000000        // Frecuencua del clock a 8 MHz :). UL = Unsigned Long 

#include <avr/io.h>           // Librería mágica con todos los SFR para no tener que liarse con Datasheets :D
#include <util/delay.h>       // Librería mágica para hacer tiempos de espera (de forma no óptima).


int main(void)  {

    // Vamos a conectar el LED en el PIN B5 (PIN 5 del puerto B) del ATmega328P ;)

    DDRB |= (1 << DDB5); // Definición del PIN B5 como salida UWU

    while(1) {

        PORTB ^= (1 << PORTB5); // XOR entre 1 y el estado lógico que hay en el PIN B5 (o para los amigos:
                                // 'toggle') c:

        _delay_ms(100);         // Tiempo de espera de 0.1 segundo para ver el parpadeo del LED :))
        
    }

    return 0;

}

