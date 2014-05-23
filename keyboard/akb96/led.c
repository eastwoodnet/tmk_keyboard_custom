/*
Copyright 2014 Kai Ryu <kai1103@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"
#include "led.h"
#include "action_layer.h"


/* LED pin configration
 *  CapsLock  PB5 (D9)  
 *  NumLock   PB7 (D11)
 */
void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output high
        DDRB |= (1<<PB5);
        PORTB |= (1<<PB5);
    } else {
        // Hi-Z
        DDRB &= ~(1<<PB5);
        PORTB &= ~(1<<PB5);
    }
}

#ifdef ON_LAYER_CHANGE
void layer_change(uint32_t state)
{
    if (state & (1UL<<2)) {
        // output high
        DDRB |= (1<<PB7);
        PORTB |= (1<<PB7);
    } else {
        // Hi-Z
        DDRB &= ~(1<<PB7);
        PORTB &= ~(1<<PB7);
    }
}
#endif
