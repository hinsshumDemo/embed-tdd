/**
 * @file test/test_light_controller.cpp
 *
 * Copyright (C) 2021
 *
 * test_light_controller.cpp is free software: you can redistribute it and/or modify
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
#include "light_controller.h"
#include "light_driver_spy.h"
#include "counting_light_driver.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
TEST_GROUP(light_controller)
{
    light_driver spy;

    void setup(void)
    {
        light_controller_create();
        light_driver_spy_add_spies_to_controller();
        light_driver_spy_reset();
    }

    void teardown(void)
    {
        light_controller_destroy();
    }
};

TEST(light_controller, TurnOn)
{
    light_controller_on(7);
    LONGS_EQUAL(LIGHT_ON, light_driver_spy_get_state(7));
}

TEST(light_controller, AddingDriverDestroysPrevious)
{
    light_driver spy = light_driver_spy_create(1);
    light_controller_add(1, spy);
    light_controller_destroy();
}

TEST(light_controller, turnOnDifferentDriverTypes)
{
    light_driver other = counting_light_driver_create(5);

    light_controller_add(5, other);
    light_controller_on(7);
    light_controller_on(5);
    light_controller_off(5);
    LONGS_EQUAL(LIGHT_ON, light_driver_spy_get_state(7));
    LONGS_EQUAL(2, counting_light_driver_get_call_count(other));
}
