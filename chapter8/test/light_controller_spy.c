/**
 * @file src/light_controller_spy.c
 *
 * Copyright (C) 2021
 *
 * light_controller_spy.c is free software: you can redistribute it and/or modify
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
#include "light_controller_spy.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static int32_t last_id;
static int32_t last_state;
static int32_t _state[32];

/*---------- function ----------*/
void light_controller_create(void)
{
    last_id = LIGHT_ID_UNKNOWN;
    last_state = LIGHT_STATE_UNKNOWN;
    for(uint8_t i = 0; i < MAX_LIGHTS; ++i) {
        _state[i] = LIGHT_STATE_UNKNOWN;
    }
}

void light_controller_destroy(void)
{
    last_id = LIGHT_ID_UNKNOWN;
    last_state = LIGHT_STATE_UNKNOWN;
}

void light_controller_on(int32_t id)
{
    last_id = id;
    last_state = LIGHT_ON;
    _state[id] = LIGHT_ON;
}

void light_controller_off(int32_t id)
{
    last_id = id;
    last_state = LIGHT_OFF;
    _state[id] = LIGHT_OFF;
}

int32_t light_controller_spy_get_last_id(void)
{
    return last_id;
}

int32_t light_controller_spy_get_last_state(void)
{
    return last_state;
}

int32_t light_controller_spy_get_light_state(int32_t id)
{
    return _state[id];
}
