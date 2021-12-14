/**
 * @file src/light_scheduler.c
 *
 * Copyright (C) 2021
 *
 * light_scheduler.c is free software: you can redistribute it and/or modify
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
#include "time_service.h"
#include "light_controller.h"

/*---------- macro ----------*/
#define MAX_EVENTS              (128)

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
typedef struct {
    int32_t id;
    int32_t minute_of_day;
    int32_t event;
    Day day_of_week;
} scheduled_light_event;

enum {
    UNUSED = -1
};

enum {
    TURN_ON = 0,
    TURN_OFF = 1
};

/*---------- variable ----------*/
static scheduled_light_event scheduled_events[MAX_EVENTS];

/*---------- function ----------*/
void light_scheduler_create(void)
{
    for(uint8_t i = 0; i < MAX_EVENTS; ++i) {
        scheduled_events[i].id = UNUSED;
    }
    time_service_set_periodic_alarm_in_seconds(60, light_scheduler_wakeup);
}

void ligth_scheduler_destroy(void)
{
    time_service_cancel_periodic_alarm_in_seconds(60, light_scheduler_wakeup);
}

static void inline _operate_light(scheduled_light_event *light_event)
{
    if(light_event->event == TURN_ON) {
        light_controller_on(light_event->id);
    } else if(light_event->event == TURN_OFF) {
        light_controller_off(light_event->id);
    }
}

static bool __does_light_respond_today(Time *time, Day day)
{
    bool retval = false;

    do {
        if(day == WEEKEND) {
            if(time->day_of_week != SATURDAY && time->day_of_week != SUNDAY) {
                break;
            }
        } else if(day == WEEKDAY) {
            if(time->day_of_week < MONDAY || time->day_of_week > FRIDAY) {
                break;
            }
        } else if(day != time->day_of_week && day != EVERYDAY) {
            break;
        }
        retval = true;
    } while(0);

    return retval;
}

static void _process_event_due_now(Time *time, scheduled_light_event *light_event)
{
    do {
        if(light_event->id == UNUSED) {
            break;
        }
        if(time->minute_of_day != light_event->minute_of_day) {
            break;
        }
        if(!__does_light_respond_today(time, light_event->day_of_week)) {
            break;
        }
        _operate_light(light_event);
    } while(0);
}

void light_scheduler_wakeup(void)
{
    Time time;

    time_service_get_time(&time);
    for(uint8_t i = 0; i < MAX_EVENTS; ++i) {
        _process_event_due_now(&time, &scheduled_events[i]);
    }
}

static int32_t _set_scheduler_event(int32_t id, Day day, int32_t minute_of_day, int32_t event)
{
    int32_t retval = LS_TOO_MANY_EVENTS;

    if(id < 0 || id >= MAX_LIGHTS) {
        retval = LS_ID_OUT_OF_BOUNDS;
    } else {
        for(uint8_t i = 0; i < MAX_EVENTS; ++i) {
            if(scheduled_events[i].id == UNUSED) {
                scheduled_events[i].id = id;
                scheduled_events[i].minute_of_day = minute_of_day;
                scheduled_events[i].event = event;
                scheduled_events[i].day_of_week = day;
                retval = LS_OK;
                break;
            }
        }
    }

    return retval;
}

int32_t light_scheduler_turnon(int32_t id, Day day, int32_t minute_of_day)
{
    return _set_scheduler_event(id, day, minute_of_day, TURN_ON);
}

void light_scheduler_turnoff(int32_t id, Day day, int32_t minute_of_day)
{
    _set_scheduler_event(id, day, minute_of_day, TURN_OFF);
}

void light_scheduler_remove(int32_t id, Day day, int32_t minute_of_day)
{
    for(uint8_t i = 0; i < MAX_EVENTS; ++i) {
        if(scheduled_events[i].id == id && 
           scheduled_events[i].day_of_week == day &&
           scheduled_events[i].minute_of_day == minute_of_day) {
            scheduled_events[i].id = UNUSED;
            break;
        }
    }
}
