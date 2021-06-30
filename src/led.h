#ifndef LED_H
#define LED_H

#define ON true
#define OFF false

#include <stdbool.h>

typedef struct led_t{
    bool state;
}led_t;

void led_write(led_t* led, bool state);
bool led_read(led_t* led);

#endif // LED_H
