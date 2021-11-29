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

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static uint16_t *ledaddress;

/*---------- function ----------*/
void led_create(uint16_t *led_address)
{
    ledaddress = led_address;
    *led_address = 0;
}

void led_destroy(void)
{

}

void led_turnon(uint32_t led_number)
{
    *ledaddress = 1;
}

void led_turnoff(uint32_t led_number)
{
    *ledaddress = 0;
}
