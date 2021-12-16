/**
 * @file src/include/light_driver.h
 *
 * Copyright (C) 2021
 *
 * light_driver.h is free software: you can redistribute it and/or modify
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
#ifndef __LIGHT_DRIVER_H
#define __LIGHT_DRIVER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*---------- macro ----------*/
/*---------- type define ----------*/
// typedef enum {
//     TEST_LIGHT_DRIVER,
//     X10,
//     ACME_WIRELESS,
//     MEMORY_MAPPED
// } light_driver_type_t;

typedef struct st_light_driver * light_driver;
typedef struct st_light_driver_interface * light_driver_interface;

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern void light_driver_set_interface(light_driver_interface i);
extern void light_driver_destroy(light_driver base);
extern void light_driver_turn_on(light_driver base);
extern void light_driver_turn_off(light_driver base);
extern char *light_driver_get_type(light_driver base);
extern int light_driver_get_id(light_driver base);

#ifdef __cplusplus
}
#endif
#endif /* __LIGHT_DRIVER_H */
