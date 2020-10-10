// Primera prueba de programación en C usando VS Code & AVR-GCC compiler. 
// Luego probamos el AVR-DUDE para quemar el código en el micro uwu

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

//*****************************//

#define F_CPU 8000000       // Frecuencua del clock a 8 MHz :) 

#include <avr/io.h>         // Librería mágica con todos los SFR para no tener que liarse con Datasheets :D
#include <util/delay.h>     // Librería mágica para hacer tiempos de espera (de forma no óptima).


int main(void)  {

    // Vamos a conectar el LED en el PIN C5 (PIN 5 del puerto C) del ATmega328P ;)

    DDRC |= (1 << DDC5); // Definición del PIN C5 como salida UWU

    while(1) {

        PORTC ^= (1 << PORTC5); // XOR entre 1 y el estado lógico que hay en el PIN C5 (o para los amigos: 'toggle') c:

        _delay_ms(100);     // Tiempo de espera de 0.1 segundo para ver el parpadeo del LED :))

    }

    return 0;

}

