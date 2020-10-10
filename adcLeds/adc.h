#include <avr/io.h>
#include <util/delay.h>

void adcInit();
int adcGetData(unsigned int channel);