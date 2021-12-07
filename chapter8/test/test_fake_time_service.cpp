/**
 * @file test/test_fake_timer_server.cpp
 *
 * Copyright (C) 2021
 *
 * test_fake_timer_server.cpp is free software: you can redistribute it and/or modify
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
#include "light_scheduler.h"
#include "CppUTest/CommandLineTestRunner.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
TEST_GROUP(faketimeservice)
{
    void setup(void)
    {
        fake_time_service_create();
    }

    void teardown(void)
    {
        fake_time_service_destroy();
    }
};

TEST(faketimeservice, Create)
{
    Time time;

    time_service_get_time(&time);
    LONGS_EQUAL(TIME_UNKNOWN, time.minute_of_day);
    LONGS_EQUAL(TIME_UNKNOWN, time.day_of_week);
}

TEST(faketimeservice, Set)
{
    Time time;

    fake_time_service_set_minute(42);
    fake_time_service_set_day(SATURDAY);
    time_service_get_time(&time);
    LONGS_EQUAL(42, time.minute_of_day);
    LONGS_EQUAL(SATURDAY, time.day_of_week);
}
