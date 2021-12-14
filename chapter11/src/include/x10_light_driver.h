/**
 * @file src/include/x10_light_driver.h
 *
 * Copyright (C) 2021
 *
 * x10_light_driver.h is free software: you can redistribute it and/or modify
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
#ifndef __X10_LIGHT_DRIVER_H
#define __X10_LIGHT_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "light_driver.h"

/*---------- macro ----------*/
#define MAX_X10_MESSAGE_LENGTH                  (10)

/*---------- type define ----------*/
typedef enum {
    X10_A,
    X10_B,
    X10_C,
    X10_D,
    X10_E,
    X10_F,
    X10_G,
    X10_H,
    X10_I,
    X10_J,
    X10_K,
    X10_L,
    X10_M,
    X10_N,
    X10_O,
    X10_P
} x10_house_code_t;

typedef struct {
    light_driver_t base;
    x10_house_code_t house;
    int32_t uint;
    char message[MAX_X10_MESSAGE_LENGTH];
} x10_light_driver_t;

typedef x10_light_driver_t * x10_light_driver;

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern light_driver x10_light_driver_create(int32_t id, x10_house_code_t code, int32_t unit);
extern void x10_light_driver_destroy(light_driver base);
extern void x10_light_driver_turnon(light_driver base);
extern void x10_light_driver_turnoff(light_driver base);

#ifdef __cplusplus
}
#endif
#endif /* __X10_LIGHT_DRIVER_H */
