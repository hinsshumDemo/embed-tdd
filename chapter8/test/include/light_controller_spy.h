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
#ifndef __LIGHT_CONTROLLER_SPY_H
#define __LIGHT_CONTROLLER_SPY_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "light_controller.h"

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
extern int32_t light_controller_spy_get_last_id(void);
extern int32_t light_controller_spy_get_last_state(void);
extern int32_t light_controller_spy_get_light_state(int32_t id);

#ifdef __cplusplus
}
#endif
#endif /* __LIGHT_CONTROLLER_SPY_H */
