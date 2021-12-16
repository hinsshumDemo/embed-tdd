/**
 * @file mock/light_driver_spy.c
 *
 * Copyright (C) 2021
 *
 * light_driver_spy.c is free software: you can redistribute it and/or modify
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
#include "light_driver_spy.h"
#include "light_controller.h"
#include "light_driver_private.h"
#include <stdlib.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
static void light_driver_spy_destroy(light_driver base);
static void light_driver_spy_on(light_driver base);
static void light_driver_spy_off(light_driver base);

/*---------- type define ----------*/
typedef struct light_driver_spy {
    light_driver_t base;
} light_driver_spy_t;

typedef light_driver_spy_t * light_driver_spy;

/*---------- variable ----------*/
static int32_t last_id;
static int32_t last_state;
static int32_t _state[MAX_LIGHTS];
static light_driver_interface_t spy_if = {
    light_driver_spy_on,
    light_driver_spy_off,
    light_driver_spy_destroy
};

/*---------- function ----------*/
light_driver light_driver_spy_create(int32_t id)
{
    light_driver_spy self = calloc(1, sizeof(light_driver_spy_t));

    self->base.vtable = &spy_if;
    self->base.id = id;
    self->base.type = "test_driver";

    return (light_driver)self;
}

static void light_driver_spy_destroy(light_driver base)
{
    free(base);
}

void light_driver_spy_reset(void)
{
    last_id = LIGHT_ID_UNKNOWN;
    last_state = LIGHT_STATE_UNKNOWN;
    for(uint8_t i = 0; i < MAX_LIGHTS; ++i) {
        _state[i] = LIGHT_STATE_UNKNOWN;
    }
}

void light_driver_spy_add_spies_to_controller(void)
{
    for(uint8_t i = 0; i < MAX_LIGHTS; ++i) {
        light_driver spy = (light_driver)light_driver_spy_create(i);
        light_controller_add(i, spy);
    }
}

int32_t light_driver_spy_get_state(int32_t id)
{
    return _state[id];
}

static void save(int32_t id, int32_t state)
{
    _state[id] = state;
    last_id = id;
    last_state = state;
}

static void light_driver_spy_on(light_driver base)
{
    light_driver_spy self = (light_driver_spy)base;
    save(self->base.id, LIGHT_ON);
}

static void light_driver_spy_off(light_driver base)
{
    light_driver_spy self = (light_driver_spy)base;
    save(self->base.id, LIGHT_OFF);
}

int32_t light_driver_spy_get_last_id(void)
{
    return last_id;
}

int32_t light_driver_spy_get_last_state(void)
{
    return last_state;
}
