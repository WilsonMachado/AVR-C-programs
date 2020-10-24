void adcInit(){ 

    // Inicialización del ADC

    // 1.
    ADMUX &= ~(1 << ADLAR);            // Configurar la alineación de la conversión a la izquierda

    // 2.
    ADMUX |=  (1 << REFS0);
    ADMUX &=  ~(1 << REFS1);           // Configurar la referencia a AVCC

    // 3.
    ADCSRA |= (1 << ADPS0);
    ADCSRA |= (1 << ADPS1);
    ADCSRA |= (1 << ADPS2);            // Configurar un PRESCALER de 128: CLK = 16M/128 = 125 kHz

    // 4.
    SFIOR &=~ (1 << ADTS0);
    SFIOR &=~ (1 << ADTS1);
    SFIOR &=~ (1 << ADTS2);            // ADC en modo free running   

    //5. 
    ADCSRA |= (1 << ADATE);            // Habilitar Auto trigger para el modo free running  

    // 6.
    ADCSRA |= (1 << ADEN);             // Activación del ADC 
        
    
}

int adcGetData(int channel){

    // Obtener datos del ADC

    // 1.
    ADMUX &=  0xF0;                    // Reset de canal, esto con el fin de configurar el canal deseado en la 
                                       // siguiente instrucción
    ADMUX  |= (channel << MUX0);       // Configuración del canal  

    
    // 2.    
    ADCSRA |= (1 << ADSC);             // Primer muestreo        
    
    // 3.
    while(! (ADCSRA & (1 << ADIF)) );  // Espera hasta que la conversión haya terminado

    // 4.
    ADCSRA |= (1 << ADIF);             // Se resetea el bit ADIF     

    // 5.
    return ADC;                        // Se regresa el valor convertido    
}