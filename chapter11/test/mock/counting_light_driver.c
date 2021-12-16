/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/chapter11/test/mock/counting_light_driver.c
 *
 * Copyright (C) 2021
 *
 * counting_light_driver.c is free software: you can redistribute it and/or modify
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
#include "counting_light_driver.h"
#include <stdlib.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
static void count(light_driver base);
static void destroy(light_driver base);

/*---------- type define ----------*/
typedef struct st_counting_light_driver {
    light_driver_t base;
    int32_t counter;
} counting_light_driver_t;

typedef counting_light_driver_t * counting_light_driver;

/*---------- variable ----------*/
static light_driver_interface_t interface = {
    .turn_on = count,
    .turn_off = count,
    .destroy = destroy
};

/*---------- function ----------*/
static void count(light_driver base)
{
    counting_light_driver self = (counting_light_driver)base;
    
    self->counter++;
}

static void destroy(light_driver base)
{
    free(base);
}

light_driver counting_light_driver_create(int32_t id)
{
    counting_light_driver self = calloc(1, sizeof(counting_light_driver_t));

    self->base.vtable = &interface;
    self->base.id = id;
    self->base.type = "counting_light_driver";
    self->counter = 0;

    return (light_driver)self;
}

int32_t counting_light_driver_get_call_count(light_driver base)
{
    counting_light_driver self = (counting_light_driver)base;

    return self->counter;
}
