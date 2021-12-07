/**
 * @file src/include/light_scheduler.h
 *
 * Copyright (C) 2021
 *
 * light_scheduler.h is free software: you can redistribute it and/or modify
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
#ifndef __LIGHT_SCHEDULER_H
#define __LIGHT_SCHEDULER_H

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
enum Day {
    NONE = -1,
    EVERYDAY = 10,
    WEEKDAY,
    WEEKEND,
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURDAY,
    FRIDAY,
    SATURDAY
};

typedef enum Day Day;

enum {
    LS_OK = 0,
    LS_ID_OUT_OF_BOUNDS,
    LS_TOO_MANY_EVENTS
};

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern void light_scheduler_create(void);
extern void ligth_scheduler_destroy(void);
extern void light_scheduler_wakeup(void);
extern int32_t light_scheduler_turnon(int32_t id, Day day, int32_t minute_of_day);
extern void light_scheduler_turnoff(int32_t id, Day day, int32_t minute_of_day);
extern void light_scheduler_remove(int32_t id, Day day, int32_t minute_of_day);

#ifdef __cplusplus
}
#endif
#endif /* __LIGHT_SCHEDULER_H */
