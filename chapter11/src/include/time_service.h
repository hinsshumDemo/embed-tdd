/**
 * @file src/include/time_service.h
 *
 * Copyright (C) 2021
 *
 * time_service.h is free software: you can redistribute it and/or modify
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
#ifndef __TIME_SERVICE_H
#define __TIME_SERVICE_H

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
typedef struct {
    int32_t minute_of_day;
    int32_t day_of_week;
} Time;

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern void time_service_get_time(Time *time);
extern void time_service_set_periodic_alarm_in_seconds(uint32_t seconds, void (*callback)(void));
extern void time_service_cancel_periodic_alarm_in_seconds(uint32_t seconds, void (*callback)(void));

#ifdef __cplusplus
}
#endif
#endif /* __TIME_SERVICE_H */
