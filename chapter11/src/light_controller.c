/**
 * @file src/light_controller.c
 *
 * Copyright (C) 2021
 *
 * light_controller.c is free software: you can redistribute it and/or modify
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
#include "light_controller.h"
#include "light_driver.h"
#include "x10_light_driver.h"
#include "light_driver_spy.h"
#include <string.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static light_driver light_drivers[MAX_LIGHTS];

/*---------- function ----------*/
void light_controller_create(void)
{
    memset(light_drivers, 0, sizeof(light_drivers));
}

void light_controller_on(int32_t id)
{
    light_driver drv = light_drivers[id];

    if(drv) {
        switch(drv->type) {
            case X10:
                x10_light_driver_turnon(drv);
                break;
            case ACME_WIRELESS:
                break;
            case MEMORY_MAPPED:
                break;
            case TEST_LIGHT_DRIVER:
                light_driver_spy_on(drv);
                break;
            default:
                break;
        }
    }
}

void light_controller_off(int32_t id)
{
    light_driver drv = light_drivers[id];

    if(drv) {
        switch(drv->type) {
            case X10:
                x10_light_driver_turnoff(drv);
                break;
            case ACME_WIRELESS:
                break;
            case MEMORY_MAPPED:
                break;
            case TEST_LIGHT_DRIVER:
                light_driver_spy_off(drv);
                break;
            default:
                break;
        }
    }
}

static void _light_controller_destroy(light_driver base)
{
    if(base) {
        switch(base->type) {
            case X10:
                x10_light_driver_destroy(base);
                break;
            case ACME_WIRELESS:
                break;
            case MEMORY_MAPPED:
                break;
            case TEST_LIGHT_DRIVER:
                light_driver_spy_destroy(base);
                break;
            default:
                break;
        }
    }
}

void light_controller_destroy(void)
{
    for(uint8_t i = 0; i < MAX_LIGHTS; ++i) {
        light_driver drv = light_drivers[i];
        _light_controller_destroy(drv);
        light_drivers[i] = NULL;
    }
}

bool light_controller_add(int32_t id, light_driver drv)
{
    light_drivers[id] = drv;
    
    return true;
}
