/**
 * @file test/test_light_driver_spy.cpp
 *
 * Copyright (C) 2021
 *
 * test_light_driver_spy.cpp is free software: you can redistribute it and/or modify
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
#include "CppUTest/CommandLineTestRunner.h"
#include "light_driver_spy.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
TEST_GROUP(light_driver_spy)
{
    light_driver spy;

    void setup(void)
    {
        light_driver_spy_reset();
        spy = light_driver_spy_create(1);
    }

    void teardown(void)
    {
        light_driver_spy_destroy(spy);
    }
};

TEST(light_driver_spy, Create)
{
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, light_driver_spy_get_state(1));
}

TEST(light_driver_spy, On)
{
    light_driver_spy_on(spy);
    LONGS_EQUAL(LIGHT_ON, light_driver_spy_get_state(1));
}

TEST(light_driver_spy, Off)
{
    light_driver_spy_off(spy);
    LONGS_EQUAL(LIGHT_OFF, light_driver_spy_get_state(1));
}

TEST(light_driver_spy, RecordsLastIdLastTurnOn)
{
    light_driver_spy_on(spy);
    LONGS_EQUAL(1, light_driver_spy_get_last_id());
    LONGS_EQUAL(LIGHT_ON, light_driver_spy_get_last_state());
}

TEST(light_driver_spy, RecordsLastIdLastTurnOff)
{
    light_driver_spy_off(spy);
    LONGS_EQUAL(1, light_driver_spy_get_last_id());
    LONGS_EQUAL(LIGHT_OFF, light_driver_spy_get_last_state());
}