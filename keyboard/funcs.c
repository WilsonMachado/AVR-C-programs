void kbInit(){
    KB_CONFIG_PORT = 0xF0; // 1111 0000 (Salidas en la parte alta, entradas en la parte baja)
    KB_OUTPORT     = 0xFF; // Salidas encendidas y resistencias de pull-up activadas 
}
unsigned char kbGetKey(){

    int i;

    for(i = 0; i < 4; i++){             // Desde 0 hasta 3 

        KB_OUTPORT     = 0xFF;          // Se reinician todos los pines del puerto donde está el teclado

        KB_OUTPORT &= ~(1 << (i + 4));  // Barrido con un cero en los pines 4 a 7 
        
        if(! (KB_INPORT & (1 << 0)) ){  // Si se detecta un cero en la fila 0
            switch (i){

                case 0:
                    return '1';
                case 1:
                    return '2';
                case 2:
                    return '3';
                case 3:
                    return 'A';
            
            }
        }

        if(! (KB_INPORT & (1 << 1)) ){  // Si se detecta un cero en la fila 1
            switch (i){

                case 0:
                    return '4';
                case 1:
                    return '5';
                case 2:
                    return '6';
                case 3:
                    return 'B';
            
            }
        }

        if(! (KB_INPORT & (1 << 2)) ){  // Si se detecta un cero en la fila 2
            switch (i){

                case 0:
                    return '7';
                case 1:
                    return '8';
                case 2:
                    return '9';
                case 3:
                    return 'C';
            
            }
        }

        if(! (KB_INPORT & (1 << 3)) ){  // Si se detecta un cero en la fila 3
            switch (i){

                case 0:
                    return '#';
                case 1:
                    return '0';
                case 2:
                    return '*';
                case 3:
                    return 'D';
            
            }
        }

            
        _delay_ms(22);                  // Espera antirebote
        
    }    
    return 0;
}