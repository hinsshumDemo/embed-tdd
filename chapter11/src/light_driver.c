/**
 * @file src/light_driver.c
 *
 * Copyright (C) 2021
 *
 * light_driver.c is free software: you can redistribute it and/or modify
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
#include "light_driver.h"
#include "light_driver_private.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
void light_driver_destroy(light_driver base)
{
    if(base && base->vtable && base->vtable->destroy) {
        base->vtable->destroy(base);
    }
}

void light_driver_turn_on(light_driver base)
{
    if(base && base->vtable && base->vtable->turn_on) {
        base->vtable->turn_on(base);
    }
}

void light_driver_turn_off(light_driver base)
{
    if(base && base->vtable && base->vtable->turn_off) {
        base->vtable->turn_off(base);
    }
}

char *light_driver_get_type(light_driver base)
{
    return base->type;
}

int light_driver_get_id(light_driver base)
{
    return base->id;
}
