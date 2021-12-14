/**
 * @file src/include/light_controller.h
 *
 * Copyright (C) 2021
 *
 * light_controller.h is free software: you can redistribute it and/or modify
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
#ifndef __LIGHT_CONTROLLER_H
#define __LIGHT_CONTROLLER_H

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
#define MAX_LIGHTS                  (32)

/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern void light_controller_create(void);
extern void light_controller_destroy(void);
extern void light_controller_on(int32_t id);
extern void light_controller_off(int32_t id);
extern bool light_controller_add(int32_t id, light_driver drv);

#ifdef __cplusplus
}
#endif
#endif /* __LIGHT_CONTROLLER_H */
