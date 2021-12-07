/**
 * @file test/test_light_scheduler.cpp
 *
 * Copyright (C) 2021
 *
 * test_light_scheduler.cpp is free software: you can redistribute it and/or modify
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
#include "fake_time_service.h"
#include "light_controller_spy.h"
#include "light_scheduler.h"
#include "CppUTest/CommandLineTestRunner.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
/* 测试列表:
 *  1.灯光在初始化下没有变化
 *  2.时间是错的，日期也是错的，灯光不会改变
 *  3.日期正确，时间错误，灯光不会改变
 *  4.时间正确，日期错误，灯光不会改变
 *  5.日期正确，时间正确，灯光打开
 *  6.日期正确，时间错误，灯光关闭
 *  7.调度每天
 *  8.调度特定的日期
 *  9.调度所有的非周末
 *  10.调度周末
 *  11.移除调度事件
 *  12.移除不存在的事件
 *  13.同时调度多个事件
 *  14.为同一盏灯调度多个事件
 *  15.移除没有调度的调度记录
 *  16.调度所支持的最大事件条目数（128）
 *  17.调度过多事件
 */
TEST_GROUP(lightscheduler)
{
    void setup(void)
    {
        light_controller_create();
        light_scheduler_create();
    }

    void teardown(void)
    {
        ligth_scheduler_destroy();
        light_controller_destroy();
    }

    void set_time_to(Day day, int32_t minute_of_day)
    {
        fake_time_service_set_day(day);
        fake_time_service_set_minute(minute_of_day);
    }

    void check_light(int32_t id, int32_t state)
    {
        if(id == LIGHT_ID_UNKNOWN) {
            LONGS_EQUAL(id, light_controller_spy_get_last_id());
            LONGS_EQUAL(state, light_controller_spy_get_last_state());
        } else {
            LONGS_EQUAL(state, light_controller_spy_get_light_state(id));
        }
    }
};

TEST(lightscheduler, NoSchedulerNothingHappens)
{
    set_time_to(MONDAY, 100);
    light_scheduler_wakeup();
    check_light(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(lightscheduler, SchedulerOnEverydayNotTimeYet)
{
    light_scheduler_turnon(3, EVERYDAY, 1200);
    set_time_to(MONDAY, 1199);
    light_scheduler_wakeup();
    check_light(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(lightscheduler, SchedulerOnEverydayItsTime)
{
    light_scheduler_turnon(3, EVERYDAY, 1200);
    set_time_to(MONDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
}

TEST(lightscheduler, SchedulerOffEverydayItsTime)
{
    light_scheduler_turnoff(3, EVERYDAY, 1200);
    set_time_to(MONDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_OFF);
}

TEST(lightscheduler, SchedulerTuesdayButItsMonday)
{
    light_scheduler_turnon(3, TUESDAY, 1200);
    set_time_to(MONDAY, 1200);
    light_scheduler_wakeup();
    check_light(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(lightscheduler, SchedulerTuesdayAndItsTuesday)
{
    light_scheduler_turnon(3, TUESDAY, 1200);
    set_time_to(TUESDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
}

TEST(lightscheduler, SchedulerWeekEndAndItsFriday)
{
    light_scheduler_turnon(3, WEEKEND, 1200);
    set_time_to(FRIDAY, 1200);
    light_scheduler_wakeup();
    check_light(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(lightscheduler, SchedulerWeekEndAndItsSaturday)
{
    light_scheduler_turnon(3, WEEKEND, 1200);
    set_time_to(SATURDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
}

TEST(lightscheduler, SchedulerWeekEndAndItsSunday)
{
    light_scheduler_turnon(3, WEEKEND, 1200);
    set_time_to(SUNDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
}

TEST(lightscheduler, SchedulerWeekEndAndItsMonday)
{
    light_scheduler_turnon(3, WEEKEND, 1200);
    set_time_to(MONDAY, 1200);
    light_scheduler_wakeup();
    check_light(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(lightscheduler, SchedulerWeekDayAndItsSaturday)
{
    light_scheduler_turnon(3, WEEKDAY, 1200);
    set_time_to(SATURDAY, 1200);
    light_scheduler_wakeup();
    check_light(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(lightscheduler, SchedulerWeekDayAndItsMonday)
{
    light_scheduler_turnon(3, WEEKDAY, 1200);
    set_time_to(MONDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
}

TEST(lightscheduler, SchedulerWeekDayAndItsFriday)
{
    light_scheduler_turnon(3, WEEKDAY, 1200);
    set_time_to(FRIDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
}

TEST(lightscheduler, SchedulerTwoEventAtTheSameTime)
{
    light_scheduler_turnon(3, SUNDAY, 1200);
    light_scheduler_turnon(12, SUNDAY, 1200);
    set_time_to(SUNDAY, 1200);
    light_scheduler_wakeup();
    check_light(3, LIGHT_ON);
    check_light(12, LIGHT_ON);
}

TEST(lightscheduler, RejectsTooManyEvents)
{
    for(uint8_t i = 0; i < 128; ++i) {
        LONGS_EQUAL(LS_OK, light_scheduler_turnon(6, MONDAY, 600 + i));
    }
    LONGS_EQUAL(LS_TOO_MANY_EVENTS, light_scheduler_turnon(6, MONDAY, 599));
}

TEST(lightscheduler, RemoveRecyclesScheduleSlot)
{
    for(uint8_t i = 0; i < 128; ++i) {
        LONGS_EQUAL(LS_OK, light_scheduler_turnon(6, MONDAY, 600 + i));
    }
    light_scheduler_remove(6, MONDAY, 600);
    LONGS_EQUAL(LS_OK, light_scheduler_turnon(6, MONDAY, 1000));
}

TEST(lightscheduler, RemoveMultipleScheduledEvent)
{
    light_scheduler_turnon(6, MONDAY, 600);
    light_scheduler_turnon(7, MONDAY, 600);
    light_scheduler_remove(6, MONDAY, 600);
    set_time_to(MONDAY, 600);
    light_scheduler_wakeup();
    check_light(6, LIGHT_STATE_UNKNOWN);
    check_light(7, LIGHT_ON);
}

TEST(lightscheduler, AcceptsValidLights)
{
    LONGS_EQUAL(LS_OK, light_scheduler_turnon(0, MONDAY, 600));
    LONGS_EQUAL(LS_OK, light_scheduler_turnon(15, MONDAY, 600));
    LONGS_EQUAL(LS_OK, light_scheduler_turnon(31, MONDAY, 600));
}

TEST(lightscheduler, AcceptsInvalidLights)
{
    LONGS_EQUAL(LS_ID_OUT_OF_BOUNDS, light_scheduler_turnon(-1, MONDAY, 600));
    LONGS_EQUAL(LS_ID_OUT_OF_BOUNDS, light_scheduler_turnon(32, MONDAY, 600));
}


TEST_GROUP(lightschedulerinitandcleanup)
{

};

TEST(lightschedulerinitandcleanup, CreateStartsOneMinuteAlarm)
{
    light_scheduler_create();
    POINTERS_EQUAL((void *)light_scheduler_wakeup, (void *)fake_time_service_get_alarm_callback());
    LONGS_EQUAL(60, fake_time_service_get_alarm_period());
    ligth_scheduler_destroy();
}

TEST(lightschedulerinitandcleanup, DestroyCancelOneMinuteAlarm)
{
    light_scheduler_create();
    ligth_scheduler_destroy();
    POINTERS_EQUAL(NULL, (void *)fake_time_service_get_alarm_callback());
    LONGS_EQUAL(0, fake_time_service_get_alarm_period());
}