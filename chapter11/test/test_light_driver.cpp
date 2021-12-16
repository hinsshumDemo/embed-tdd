/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/chapter11/test/test_light_driver.cpp
 *
 * Copyright (C) 2021
 *
 * test_light_driver.cpp is free software: you can redistribute it and/or modify
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
#include "light_driver_private.h"
#include "CppUTest/CommandLineTestRunner.h"

/*---------- macro ----------*/
#define NONSENSE_POINTER                ((light_driver)~0)

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
static void should_not_be_called(light_driver self);

/*---------- type define ----------*/
/*---------- variable ----------*/
static light_driver saved_driver = NONSENSE_POINTER;
light_driver_interface_t interface = {
    should_not_be_called,
    should_not_be_called,
    should_not_be_called
};
light_driver_t test_driver = {
    (char *)"test_driver",
    13
};

/*---------- function ----------*/
static void should_not_be_called(light_driver self)
{
    saved_driver = self;
}


TEST_GROUP(light_driver)
{
    void setup(void)
    {

    }

    void teardown(void)
    {

    }
};

TEST(light_driver, NullDriverDoesNotCrash)
{
    light_driver_set_interface(&interface);
    light_driver_turn_on(NULL);
    light_driver_turn_off(NULL);
    light_driver_destroy(NULL);
    POINTERS_EQUAL(NONSENSE_POINTER, saved_driver);
}

TEST(light_driver, NullInterfaceDoesNotCrash)
{
    light_driver_set_interface(NULL);
    light_driver_turn_on(&test_driver);
    light_driver_turn_off(&test_driver);
    light_driver_destroy(&test_driver);
    POINTERS_EQUAL(NONSENSE_POINTER, saved_driver);
}
