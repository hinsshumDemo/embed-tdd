/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/chapter10/test/mock/fake_mirco_time.c
 *
 * Copyright (C) 2021
 *
 * fake_mirco_time.c is free software: you can redistribute it and/or modify
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
#include "fake_mirco_time.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static uint32_t time;
static uint32_t increment;
static uint32_t to_delay;

/*---------- function ----------*/
void fake_micro_time_init(uint32_t start, uint32_t inc)
{
    time = start;
    increment = inc;
    to_delay = 0;
}

uint32_t fake_mirco_time_get(void)
{
    uint32_t t = time;

    time += increment;

    return t;
}

uint32_t micro_time_get(void)
{
    return fake_mirco_time_get();
}
