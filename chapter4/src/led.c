/**
 * @file chapter3/src/led.c
 *
 * Copyright (C) 2021
 *
 * led.c is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author HinsShum hinsshum@qq.com
 *
 * @encoding utf-8
 */

/*---------- includes ----------*/
#include "led.h"
#include "runtime_error.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
enum {
    ALL_LEDS_ON = 0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum {
    FIRST_LED = 1,
    LAST_LED = 16
};

/*---------- variable ----------*/
static uint16_t *ledaddress;
static uint16_t leds_image;

/*---------- function ----------*/
static uint16_t inline _convert_led_number_to_bit(uint32_t led_number)
{
    return (uint16_t)(1 << (led_number - 1));
}

static void inline _update_hardware(void)
{
    *ledaddress = leds_image;
}

static bool inline _is_led_number_out_of_bounds(uint32_t led_number)
{
    return (led_number < FIRST_LED || led_number > LAST_LED);
}

static void inline _set_led_image_bit(uint32_t led_number)
{
    leds_image |= _convert_led_number_to_bit(led_number);
}

static void inline _clear_led_image_bit(uint32_t led_number)
{
    leds_image &= ~_convert_led_number_to_bit(led_number);
}

void led_create(uint16_t *led_address)
{
    ledaddress = led_address;
    leds_image = (uint16_t)ALL_LEDS_OFF;
    _update_hardware();
}

void led_destroy(void)
{

}

void led_turnon(uint32_t led_number)
{
    if(_is_led_number_out_of_bounds(led_number)) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    } else {
        _clear_led_image_bit(led_number);
        _update_hardware();
    }
}

void led_turnoff(uint32_t led_number)
{
    if(_is_led_number_out_of_bounds(led_number)) {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", -1);
    } else {
        _set_led_image_bit(led_number);
        _update_hardware();
    }
}

void led_turnon_all(void)
{
    leds_image = (uint16_t)ALL_LEDS_ON;
    _update_hardware();
}

void led_turnoff_all(void)
{
    leds_image = (uint16_t)ALL_LEDS_OFF;
    _update_hardware();
}

bool led_is_on(uint32_t led_number)
{
    bool retval = !(leds_image & _convert_led_number_to_bit(led_number));

    if(_is_led_number_out_of_bounds(led_number)) {
        retval = false;
    }

    return retval;
}

bool led_is_off(uint32_t led_number)
{
    return !led_is_on(led_number);
}
