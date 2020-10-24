void uartConfig(){

    // Configurar el USART (asíncrona, síncrona)

    UCSRC &= ~(1 << UMSEL);  // En este caso, el USART como UART (comunicación asíncrona)

    // Configrurar la paridad de la comunicación (desactivada, par o impar)

    UCSRC &= ~(1 << UPM0);
    UCSRC &= ~(1 << UPM1);  // En este caso, desactivada

    // Configurar la cantidad de bits de parada (1 bit o 2 bits de parada)

    UCSRC &= (1 << USBS);   // En este caso, un bit de parada

    // Configurar el formato de los datos (5, 6, 7 u 8 bits )

    // NOTA: esta configuración se hace con dos registros. El fabricante trolleó y puso el bit UCSZ2 en el registro
    //       UCSRB; sin embargo, los bits UCSZ1 y UCSZ0 se encuentran en el registro UCSRC

    UCSRC |= (1 << UCSZ0);
    UCSRC |= (1 << UCSZ1);
    UCSRB &= ~(1 << UCSZ2);  // En este caso, formato de datos de 8 bits. 

    // Configurar la velocidad de comunicación (la tasa esa en baudios (bits por segundo))

    // NOTA: Si el bit U2X está en 0, el número que multiplica en el denominador al BaudRate es 16; de lo contrario
    //       es 8.

    UCSRA |= (1 << U2X);
    UBRRH = 0x00;
    UBRRL = (F_CPU / 8 / BAUD) - 1;

    // Finalmente, habilitar los pines D0 y D1 como RX y TX respectivamente (funciones multiplexadas)

    UCSRB |= (1 << RXEN);
    UCSRB |= (1 << TXEN);

    // TRABJANDO CON INTERRUPCIONES

    UCSRB |= (1 << RXCIE); // Activar interrupción por recepción

    // Todo listo ;)

}

