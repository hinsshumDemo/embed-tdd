/**
 * @file test/fake_time_service.c
 *
 * Copyright (C) 2021
 *
 * fake_time_service.c is free software: you can redistribute it and/or modify
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

/*---------- includes ----------*/
#include "light_scheduler.h"
#include "fake_time_service.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static Time _time = {
    .minute_of_day = TIME_UNKNOWN,
    .day_of_week = TIME_UNKNOWN
};

static void (*callback)(void);
static uint32_t alarm_period;

/*---------- function ----------*/
void time_service_get_time(Time *time)
{
    time->day_of_week = _time.day_of_week;
    time->minute_of_day = _time.minute_of_day;
}

void time_service_set_periodic_alarm_in_seconds(uint32_t seconds, void (*cb)(void))
{
    alarm_period = seconds;
    callback = cb;
}

void time_service_cancel_periodic_alarm_in_seconds(uint32_t seconds, void (*cb)(void))
{
    if(seconds == alarm_period && callback == cb) {
        alarm_period = 0;
        callback = NULL;
    }
}

void fake_time_service_set_minute(int32_t minute)
{
    _time.minute_of_day = minute;
}

void fake_time_service_set_day(Day day)
{
    _time.day_of_week = day;
}

void fake_time_service_create(void)
{
    _time.day_of_week = TIME_UNKNOWN;
    _time.minute_of_day = TIME_UNKNOWN;
}

void fake_time_service_destroy(void)
{
    _time.day_of_week = TIME_UNKNOWN;
    _time.minute_of_day = TIME_UNKNOWN;
}

void *fake_time_service_get_alarm_callback(void)
{
    return (void *)callback;
}

uint32_t fake_time_service_get_alarm_period(void)
{
    return alarm_period;
}