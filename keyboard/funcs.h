#define KB_CONFIG_PORT  DDRB    // Configurar el puerto donde irá el teclado
#define KB_OUTPORT      PORTB   // Escribir en el puerto configurado
#define KB_INPORT       PINB    // Leer el puerto configurado

void kbInit();
unsigned char kbGetKey();
 