void adcInit()  {

    ADMUX &= ~(1 << ADLAR);     // Se ajusta la salida a la derecha. Recordar que el ADC de este micro es de 10 bits de resolución

                                // Es decir: | si ADLAR = 0: ADCH = xxxx xxbb ; ADCL = bbbb bbbb 
                                //           | si ADLAR = 1: ADCH = bbbb bbbb ; ADCL = bbxx xxxx 
                                
                                // Donde ADCH es la aprte alta del registro que contiene la información convertida
                                // y ADCL la parte baja.

    // Se estable el voltaje de referencia a AVCC

    ADMUX |= (1 << REFS0);
    ADMUX &= ~(1 << REFS1);

    // Prescaler (divisor de frecuencia) = 64 -> 8 MHz / 64 = 125 kHz    //(La entrada del CLK del ADC debe estar entre 50 y 200 kHz, esto para obtener la máxima resolución)

    ADCSRA &= ~(1 << ADPS0);
    ADCSRA |= (1 << ADPS1);
    ADCSRA |= (1 << ADPS2);

    // Configurar el ADC en modo free running

    ADCSRB &= ~(1 << ADTS0);
    ADCSRB &= ~(1 << ADTS1);
    ADCSRB &= ~(1 << ADTS2); 

}


int adcGetData(unsigned int channel) {

    // char dump;
    // unsigned int temp = 0;

    // Máscara para no alterar la parte alta de ADMUX (Ver Datasheet página 317)

    ADMUX &= (0xF0 << MUX0);            // Es decir ((1111 0000) and ADMUX)

    // Máscara para configurar el canal

    ADMUX |= (channel << MUX0);         // Es decir ((0000 channel) or ADMUX)

    ADCSRA |= (1 << ADEN);               // Activación del ADC
    _delay_us(10);                      // Tiempo de preparación del ADC

    ADCSRA |= (1 << ADSC);              // Primer muestreo
    
    while(! (ADCSRA & (1 << ADIF)) ) {  // No sale hasta que termine de convertir, esta condición la da el flag de conversión terminada 
        
    } 

    ADCSRA |= (1 << ADIF);              // Siempre que se lee un flag, debe reiniciarse. En interrupciones es diferente, luego lo revisamos

    ADCSRA &=~ (1 << ADEN);             // Se apaga el ADC, esto con el fin de ahorrar energía

    return ADC;                         // Retorna el registro que contiene la información convertida
}