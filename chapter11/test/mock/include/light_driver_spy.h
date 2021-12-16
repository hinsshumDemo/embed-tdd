/**
 * @file test/include/light_driver_spy.h
 *
 * Copyright (C) 2021
 *
 * light_driver_spy.h is free software: you can redistribute it and/or modify
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
#ifndef __LIGHT_DRIVER_SPY_H
#define __LIGHT_DRIVER_SPY_H

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
enum {
    LIGHT_ID_UNKNOWN = -1,
    LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0,
    LIGHT_ON = 1
};

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern light_driver light_driver_spy_create(int32_t id);
extern void light_driver_spy_add_spies_to_controller(void);
extern void light_driver_spy_reset(void);
extern int32_t light_driver_spy_get_last_id(void);
extern int32_t light_driver_spy_get_last_state(void);
extern int32_t light_driver_spy_get_state(int32_t id);
extern void light_driver_spy_install_interface(void);

#ifdef __cplusplus
}
#endif
#endif /* __LIGHT_DRIVER_SPY  _H */