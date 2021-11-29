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
/* TODO:
 *  1. 控制16个有两个状态的LED
 *  2. 可以在不影响其他LED的情况下打开或者关闭任意一个LED
 *  3. 可以通过单一的接口调用来打开所有的LED
 *  4. LED驱动程序的用户可以查看任何LED的状态
 *  5. 当加电时，硬件的默认状态是所有的LED都锁定在打开状态，需要由软件来把它们关闭
 *  6. LED会在内存中映射到一个16位的字上（在一个尚未确定的地址上）
 *  7. 在某一位置上置1会点亮对应的LED，置0则会将之关闭
 *  8. 最小一位对应LED1；最大一位对应LED16
 */

/* 测试列表
 *  1. LED驱动安装完成后关闭所有的LED   ok
 *  2. 可以打开/关闭单一的LED
 *  3. 可以打开/关闭多个LED
 *  4. 可以打开/关闭所有LED
 *  5. 查询LED状态
 *  6. 检查边界值
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

    }
};

TEST(led, LedsOffAfterCreate)
{
    uint16_t virtualleds = 0xFFFF;

    led_create(&virtualleds);
    UNSIGNED_LONGS_EQUAL(0, virtualleds);
}

TEST(led, TurnOnLedOne)
{
    led_turnon(1);
    UNSIGNED_LONGS_EQUAL(1, virtualleds);
}

TEST(led, TurnOffLedOne)
{
    led_turnon(1);
    led_turnoff(1);
    UNSIGNED_LONGS_EQUAL(0, virtualleds);
}
