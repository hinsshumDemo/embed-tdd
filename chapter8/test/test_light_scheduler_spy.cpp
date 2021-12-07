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
#include "light_controller_spy.h"
#include "CppUTest/CommandLineTestRunner.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
TEST_GROUP(lightschedulerspy)
{
    void setup(void)
    {
        light_controller_create();
    }

    void teardown(void)
    {
        light_controller_destroy();
    }
};

TEST(lightschedulerspy, Create)
{
    LONGS_EQUAL(LIGHT_ID_UNKNOWN, light_controller_spy_get_last_id());
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, light_controller_spy_get_last_state());
}

TEST(lightschedulerspy, RememberTheLastIDControlled)
{
    light_controller_on(10);
    LONGS_EQUAL(10, light_controller_spy_get_last_id());
    LONGS_EQUAL(LIGHT_ON, light_controller_spy_get_last_state());
}

TEST(lightschedulerspy, RememberAllLightsState)
{
    light_controller_on(0);
    light_controller_off(31);
    LONGS_EQUAL(LIGHT_ON, light_controller_spy_get_light_state(0));
    LONGS_EQUAL(LIGHT_OFF, light_controller_spy_get_light_state(31));
}