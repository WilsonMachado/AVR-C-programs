/* 

# Archivo:      adcLcdTwoChannels
# Autor:        Wilson D. Machado T.
# Copyright:    Laboratorio de Microprocesadores y Ensamblador
# Licencia:     Universidad del Valle - Ingeniería Electrónica

#Descripción:   Este programa lee dos potenciómetros conectados en los pines A1 y A6 del microcontrolador. Es capaz de
                mostrar la lectura de ambos en un LCD de 2x16 configurado en el puerto B del ATmega32.

                Es un ejemplo claro de cómo leer dos entradas analógicas al tiempo.

*/

//*****************************//

// Definición del dispositivo  //

#ifndef __AVR_ATmega32__     // Definición del microcontrolador a usar. Es info es obtenida de io.h
    #define __AVR_ATmega32__
#endif

//*****************************//

#define timeMux 100

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>     // Librería para dtostrf

#include "libs/lcd.h"
#include "libs/lcd.c"   // Librerías para el manejo de la LCD

#include "funcs.h"
#include "funcs.c"      // Librerías para usar el ADC

int main(void) {

    DDRB = 0x00; 
    PORTB = 0x00;    

    int temp = 0;
    char result[10];
        
    adcInit();
    
    lcd_init(LCD_DISP_ON);          // Inicializa el display encendido

    lcd_clrscr();                   // Limpia la pantalla LCD
    lcd_home();                     // Ubica el puntero en la posición inicial (0,0)    
    

    while(1)    {

        lcd_puts("Canal 1: ");       

        temp = adcGetData(1); 

        dtostrf(temp, 1, 0, result);  // Convertir el valor del ADC a string para verlo en la pantalla uwu

        lcd_puts(result);
        
        lcd_gotoxy(0, 1);
        
        lcd_puts("Canal 6: ");       

        temp = adcGetData(6); 

        dtostrf(temp, 1, 0, result);  // Convertir el valor del ADC a string para verlo en la pantalla uwu    
             
        lcd_puts(result); 

        _delay_ms(timeMux);

        lcd_clrscr();                   // Limpia la pantalla LCD
        
        lcd_home();                     // Ubica el puntero en la posición inicial (0,0)
                     

    }

    return 0;
}

