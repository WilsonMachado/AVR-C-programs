/*

# Archivo:   adcLeds
# Autor:     Wilson D. Machado T.
# Copyright: WDesigns
# Licencia:  Libre. Ejemplos para aprendizaje y referencia  

# Descripción: En este programa se ilustra el uso del ADC del microcontrolador ATmega328P.
               A través de un sensor de temperatura, se encienden (o se apagan) LEDs para determinar si la
               temperatura es fría, tibia o cálida. Incluye simulación.

*/

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega328P__     // Esto es necesario porque sino, no se puede usar los FSRs.
    #define __AVR_ATmega328P__
#endif

//*****************************//

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"        // Librería propia para mejor de ADC
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
            
            PORTB |= (1 << PORTB0);       // Enciende el PIN B0 (LED rojo de temperatura caliente)                       
            
            PORTB &= ~(1 << PORTB1);      // Apaga el PIN B1 (LED amarillo de temperatura tibia)  
            PORTB &= ~(1 << PORTB2);      // Apaga el PIN B2 (LED azul de temperatura fría)  

        } else if (result <= cold) {

            PORTB |= (1 << PORTB2);       // Enciende el PIN B2 (LED azul de temperatura fría)
            
            PORTB &= ~(1 << PORTB0);      // Apaga el PIN B0 (LED rojo de temperatura caliente) 
            PORTB &= ~(1 << PORTB1);      // Apaga el PIN B1 (LED amarillo de temperatura fría)

        }else    {
            
            PORTB |= (1 << PORTB1);       // Enciende el PIN B1 (LED amarillo de temperatura caliente)          
            
            PORTB &= ~(1 << PORTB0);      // Apaga el PIN B0 (LED rojo de temperatura caliente)
            PORTB &= ~(1 << PORTB2);      // Apaga el PIN B2 (LED azul de temperatura fría)       

        }         

    }

    return 0;
}

