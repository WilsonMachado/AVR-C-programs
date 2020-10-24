/* 

# Archivo:      adcLcd
# Autor:        Wilson D. Machado T.
# Copyright:    Laboratorio de Microprocesadores y Ensamblador
# Licencia:     Universidad del Valle - Ingeniería Electrónica

#Descripción:   Este programa lee un sensor LM35 para determinar la temperatura del ambiente. Es capaz de mostrar
                dicha temperatura en un LCD de 2x16 configurada en el puerto B del ATmega32.

*/

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega32__     // Definición del microcontrolador a usar. Es info es obtenida de io.h
    #define __AVR_ATmega32__
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

#define timeMux 100

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "libs/lcd.h"
#include "libs/lcd.c"   // Librerías para el manejo de la LCD

#include "funcs.h"
#include "funcs.c"      // Librerías para usar el ADC

int main(void) {

    DDRB = 0x00;
    DDRC = 0xFF;

    PORTB = 0x00;
    PORTC = 0xFF;

    //int decoder[] = {zero, one, two, three, four, five, six, seven, eight, nine};  
    signed int temp = 0;
        
    adcInit();
    
    lcd_init(LCD_DISP_ON);          // Inicializa el display encendido

    lcd_clrscr();                   // Limpia la pantalla LCD
    lcd_home();                     // Ubica el puntero en la posición inicial (0,0)

    lcd_gotoxy(0, 1);

    lcd_puts("Wil es un crack");
    

    while(1)    {
        
        lcd_home();                     // Ubica el puntero en la posición inicial (0,0)

        lcd_puts("Temperatura: ");       

        temp = adcGetData(3) / 4;      
     
        lcd_putc((temp/10) + 48);
        lcd_putc((temp%10) + 48);        

        _delay_ms(timeMux);  

    }

    return 0;
}

/*      
        Temperatura mostrada en displays multiplexados

        PORTC = 0xFF;               // Apagar todos los displays
        PORTC &= ~(1 << PORTC0);    // Encender el display de las unidades

        PORTB = ~decoder[temp % 10];

        _delay_ms(timeMux);
        
        PORTC = 0xFF;               // Apagar todos los displays
        PORTC &= ~(1 << PORTC1);    // Encender el display de las decenas

        PORTB = ~decoder[temp / 10]; 

        _delay_ms(timeMux); 
        
*/