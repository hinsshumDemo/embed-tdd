/**
 * @file chapter3/test/test_led.cpp
 *
 * Copyright (C) 2021
 *
 * test_led.cpp is free software: you can redistribute it and/or modify
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
#include "led.h"
#include "runtime_error_stub.h"
#include <CppUTest/CommandLineTestRunner.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
/* 测试列表
 *  1. LED驱动安装完成后关闭所有的LED   ok
 *  2. 可以打开/关闭单一的LED          ok
 *  3. 可以打开/关闭多个LED            ok
 *  4. 可以打开/关闭所有LED            ok
 *  5. 查询LED状态                    ok
 *  6. 检查边界值
 *      6.1 超过最大值不会破坏任何东西  ok
 *      6.2 小于最小值不会破坏任何东西  ok
 *      6.3 运行时错误                 ok
 *  7. 检查界外值
 */

TEST_GROUP(led)
{
    uint16_t virtualleds;

    void setup(void)
    {
        led_create(&virtualleds);
    }

    void teardown(void)
    {
        led_destroy();
        runtime_error_stub_reset();
    }
};

TEST(led, LedsOffAfterCreate)
{
    uint16_t virtualleds = 0;

    led_create(&virtualleds);
    for(uint32_t i = 1; i <= 16; ++i) {
        CHECK_FALSE(led_is_on(i));
    }
}

TEST(led, TurnOnLedOne)
{
    led_turnon(1);
    CHECK_TRUE(led_is_on(1));
}

TEST(led, TurnOffLedOne)
{
    led_turnon(1);
    led_turnoff(1);
    CHECK_FALSE(led_is_on(1));
}

TEST(led, TurnOnMultipleLeds)
{
    led_turnon(8);
    led_turnon(9);
    CHECK_TRUE(led_is_on(8));
    CHECK_TRUE(led_is_on(9));
}

TEST(led, TurnOffMultipleLeds)
{
    led_turnon_all();
    led_turnoff(8);
    led_turnoff(9);
    CHECK_FALSE(led_is_on(8));
    CHECK_FALSE(led_is_on(9));
}

TEST(led, TurnOffAnyLed)
{
    led_turnon_all();
    led_turnon(8);
    led_turnoff(8);
    CHECK_FALSE(led_is_on(8));
}

TEST(led, AllOn)
{
    led_turnon_all();
    for(uint32_t i = 1; i <= 16; ++i) {
        CHECK_TRUE(led_is_on(i));
        CHECK_FALSE(led_is_off(i));
    }
}

TEST(led, AllOff)
{
    led_turnon_all();
    led_turnoff_all();
    for(uint32_t i = 1; i <= 16; ++i) {
        CHECK_FALSE(led_is_on(i));
        CHECK_TRUE(led_is_off(i));
    }
}

TEST(led, LedMemoryIsNotReadable)
{
    virtualleds = 0;
    led_turnon(8);
    CHECK_TRUE(led_is_on(8));
    CHECK_FALSE(led_is_off(8));
}

TEST(led, UpperAndLowerBounds)
{
    led_turnon(1);
    led_turnon(16);
    CHECK_TRUE(led_is_on(1));
    CHECK_FALSE(led_is_off(1));
    CHECK_TRUE(led_is_on(16));
    CHECK_FALSE(led_is_off(16));
}

TEST(led, OutOfBoundsTurnOnDoesNoHarm)
{
    led_turnon(-1);
    led_turnon(0);
    led_turnon(17);
    led_turnon(3147);
    for(uint32_t i = 1; i <= 16; ++i) {
        CHECK_FALSE(led_is_on(i));
        CHECK_TRUE(led_is_off(i));
    }
}

TEST(led, OutOfBoundsTurnOffDoesNoHarm)
{
    led_turnon_all();
    led_turnoff(-1);
    led_turnoff(0);
    led_turnoff(17);
    led_turnoff(3147);
    for(uint32_t i = 1; i <= 16; ++i) {
        CHECK_TRUE(led_is_on(i));
        CHECK_FALSE(led_is_off(i));
    }
}

TEST(led, OutOfBoundsTurnOnOneLedProducesRuntimeError)
{
    led_turnon(-1);
    STRCMP_EQUAL("LED Driver: out-of-bounds LED", runtime_error_stub_get_last_error());
    LONGS_EQUAL(-1, runtime_error_stub_get_last_parameter());
}

TEST(led, OutOfBoundsTurnOffOneLedProducesRuntimeError)
{
    led_turnoff(-1);
    STRCMP_EQUAL("LED Driver: out-of-bounds LED", runtime_error_stub_get_last_error());
    LONGS_EQUAL(-1, runtime_error_stub_get_last_parameter());
}

IGNORE_TEST(led, OutOfBoundsToDo)
{

}

TEST(led, IsOn)
{
    CHECK_FALSE(led_is_on(11));
    led_turnon(11);
    CHECK_TRUE(led_is_on(11));
}

TEST(led, OutOfBoundsLedsAreAlwaysOff)
{
    CHECK_FALSE(led_is_on(0));
    CHECK_FALSE(led_is_on(17));
    CHECK_TRUE(led_is_off(0));
    CHECK_TRUE(led_is_off(17));
}

TEST(led, IsOff)
{
    CHECK_TRUE(led_is_off(11));
    led_turnon(11);
    CHECK_FALSE(led_is_off(11));
}
