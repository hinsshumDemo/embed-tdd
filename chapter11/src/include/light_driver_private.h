/**
 * @file src/include/light_driver_private.h
 *
 * Copyright (C) 2021
 *
 * light_driver_private.h is free software: you can redistribute it and/or modify
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
#ifndef __LIGHT_DRIVER_PRIVATE_H
#define __LIGHT_DRIVER_PRIVATE_H

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
/*---------- type define ----------*/
typedef struct st_light_driver {
    char *type;
    int32_t id;
} light_driver_t;

typedef light_driver_t * light_driver;

typedef struct st_light_driver_interface {
    void (*turn_on)(light_driver base);
    void (*turn_off)(light_driver base);
    void (*destroy)(light_driver base);
} light_driver_interface_t;

typedef light_driver_interface_t * light_driver_interface;

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/

#ifdef __cplusplus
}
#endif
#endif /* __LIGHT_DRIVER_PRIVATE_H */
