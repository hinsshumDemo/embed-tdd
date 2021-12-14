/**
 * @file src/x10_light_driver.c
 *
 * Copyright (C) 2021
 *
 * x10_light_driver.c is free software: you can redistribute it and/or modify
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
#include "x10_light_driver.h"
#include <stdlib.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
static void format_turnon_message(x10_light_driver self)
{

}

static void format_turnoff_message(x10_light_driver self)
{

}

light_driver x10_light_driver_create(int32_t id, x10_house_code_t code, int32_t unit)
{
    x10_light_driver self = calloc(1, sizeof(x10_light_driver_t));

    self->base.type = X10;
    self->base.id = id;
    self->house = code;
    self->uint = unit;

    return (light_driver)self;
}

void x10_light_driver_destroy(light_driver base)
{
    free(base);
}

void x10_light_driver_turnon(light_driver base)
{
    x10_light_driver self = (x10_light_driver)base;

    format_turnon_message(self);
    // send_message(self);
}

void x10_light_driver_turnoff(light_driver base)
{
    x10_light_driver self = (x10_light_driver)base;

    format_turnoff_message(self);
    // send_message(self);
}