/*

# Archivo:   displaySevenSeg
# Autor:     Wilson D. Machado T.
# Copyright: WDesigns
# Licencia:  Libre. Ejemplos para aprendizaje y referencia  

# Descripción: Este programa ilustra el uso de un display de 7 segmentos con el microcontrolador ATmega328P.
               Se realiza un contador de 0 a 9 con un display de ánodo común y se adjunta simulación.

*/


//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega328P__     // Dispositivo con el que se trabajará. Si se usa Visual Studio Code es necesario; si se usa Atmel Stuido, no
    #define __AVR_ATmega328P__
#endif

//*****************************//

// Tabla para decodificación display de 7 segmentos

#define zero  0x3F
#define one   0x06
#define two   0x5B
#define three 0x4F
#define four  0x66
#define five  0x6D
#define six   0x7D
#define seven 0x07
#define eight 0xFF
#define nine  0x67

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void){

    DDRD |= 0xFF;  // 1111 | 1111 Todo el puerto D como salida
    PORTD |= 0xFF; // Apaga todo el puerto D (el display es de ánodo común)

    uint8_t decoder[] = {zero, one, two, three, four, five, six, seven, eight, nine};
    int cont = 0;    
    
    while(1){        

        PORTD =~ decoder[cont];   // Muestra el número de cont en el display
                                  // Si se cambia el display por uno de cátodo común, no negar el decoder
        _delay_ms(500);           // Espera 500 ms
        cont++;                   // Incrementa el contador para mostrar el siguiente número en el display

        if (cont == 10) cont = 0; // Si el contador llega a 10, se reinicia a 0.        

    }
    return 0;
}