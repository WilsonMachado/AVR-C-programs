// En este programa se ilustra el uso del ADC del microcontrolador ATmega328P.
// A través de un sensor de temperatura, se encienden (o se apagan) LEDs para determinar si la temperatura
// es fría, tibia o cálida. 


//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega328P__     // Esto es necesario porque sino, no se puede usar los FSRs.
    #define __AVR_ATmega328P__
#endif

//*****************************//

#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"
#include "adc.c"

#define cold 18.0       // Temperatura fría
#define hot  30.0       // Temperatura caliente


int main(void)  {

    DDRB  = 0xFF;        // Es decir:  1111 1111. Mi recomendación es que si no se usa un pin del micro, establecerlo como salida
    PORTB = 0x00;       // Todas las salidas apagadas y las entradas sin resistencia de pull-up 

    adcInit();          // Inicializamos el ADC    
    
    while(1)    {
        
        float result = (adcGetData(0))/2; // Conversión de la lectura del LM35 a Temperatura, relación 10 mV : 1 °C
        
        if(result >= hot){            
            
            PORTB |= (1 << PORTB0);                               
            
            PORTB &= ~(1 << PORTB1);
            PORTB &= ~(1 << PORTB2);

        } else if (result <= cold) {

            PORTB |= (1 << PORTB2);
            
            PORTB &= ~(1 << PORTB0);
            PORTB &= ~(1 << PORTB1);

        }else    {
            
            PORTB |= (1 << PORTB1);            
            
            PORTB &= ~(1 << PORTB0);
            PORTB &= ~(1 << PORTB2);           

        }         

    }

    return 0;
}

