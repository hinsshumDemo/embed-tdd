/**
 * @file test/include/fake_time_service.h
 *
 * Copyright (C) 2021
 *
 * fake_time_service.h is free software: you can redistribute it and/or modify
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
#ifndef __FAKE_TIME_SERVICE_H
#define __FAKE_TIME_SERVICE_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "time_service.h"

/*---------- macro ----------*/
/*---------- type define ----------*/
enum {
    TIME_UNKNOWN = -1,
};

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern void fake_time_service_create(void);
extern void fake_time_service_destroy(void);
extern void fake_time_service_set_minute(int32_t minute);
extern void fake_time_service_set_day(int32_t day);
extern void *fake_time_service_get_alarm_callback(void);
extern uint32_t fake_time_service_get_alarm_period(void);

#ifdef __cplusplus
}
#endif
#endif /* __FAKE_TIME_SERVICE_H */
