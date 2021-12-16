/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/chapter11/test/mock/include/counting_light_driver.h
 *
 * Copyright (C) 2021
 *
 * counting_light_driver.h is free software: you can redistribute it and/or modify
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
#ifndef __COUNTING_LIGHT_DRIVER_H
#define __COUNTING_LIGHT_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "light_driver_private.h"

/*---------- macro ----------*/
/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern light_driver counting_light_driver_create(int32_t id);
extern int32_t counting_light_driver_get_call_count(light_driver base);

#ifdef __cplusplus
}
#endif
#endif /* __COUNTING_LIGHT_DRIVER_H */
