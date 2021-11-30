/**
 * @file chapter3/test/test_circularbuffer.cpp
 *
 * Copyright (C) 2021
 *
 * test_circularbuffer.cpp is free software: you can redistribute it and/or modify
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
#include "circularbuffer.h"
#include <CppUTest/CommandLineTestRunner.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
/* 测试列表 
 *  1. 环形缓存创建后，检查状态（空状态）
 *  2. 可以写入单个数据，写入后状态为非空
 *  3. 可以读取单个数据，读取写入得数据长度后，状态为空，读取值与写入值相同
 *  4. 可以写入/读取多个数据
 *  5. 可以查询容量
 *  6. 检查边界值
 */

TEST_GROUP(circularbuffer)
{
    uint32_t container[101];
    circularbuffer_t buffer;

    void setup(void)
    {
        buffer = circularbuffer_create(container, 100);
        container[100] = 0xaa;
    }

    void teardown(void)
    {
        circularbuffer_destroy(buffer);
    }
};

TEST(circularbuffer, Create)
{
    uint32_t c[100];
    circularbuffer_t b = NULL;

    b = circularbuffer_create(c, 100);
    CHECK_TRUE(b != NULL);
    circularbuffer_destroy(b);
}

TEST(circularbuffer, IsEmptyAfterCreate)
{
    CHECK_TRUE(circularbuffer_is_empty(buffer));
}

TEST(circularbuffer, IsNotFullAfterCreate)
{
    CHECK_FALSE(circularbuffer_is_full(buffer));
}

TEST(circularbuffer, IsNotEmptyAfterPut)
{
    CHECK_TRUE(circularbuffer_put(buffer, 10086));
    CHECK_FALSE(circularbuffer_is_empty(buffer));
}

TEST(circularbuffer, IsNotEmptyThenEmpty)
{
    circularbuffer_put(buffer, 10086);
    circularbuffer_get(buffer);
    CHECK_TRUE(circularbuffer_is_empty(buffer));
}

TEST(circularbuffer, GetPutOneValue)
{
    circularbuffer_put(buffer, 10086);
    UNSIGNED_LONGS_EQUAL(10086, circularbuffer_get(buffer));
}

TEST(circularbuffer, GetPutAFew)
{
    circularbuffer_put(buffer, 1);
    circularbuffer_put(buffer, 2);
    circularbuffer_put(buffer, 3);
    UNSIGNED_LONGS_EQUAL(1, circularbuffer_get(buffer));
    UNSIGNED_LONGS_EQUAL(2, circularbuffer_get(buffer));
    UNSIGNED_LONGS_EQUAL(3, circularbuffer_get(buffer));
}

TEST(circularbuffer, Capacity)
{
    UNSIGNED_LONGS_EQUAL(100, circularbuffer_capacity(buffer));
}

TEST(circularbuffer, IsFull)
{
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_put(buffer, i + 100);
    }
    CHECK_TRUE(circularbuffer_is_full(buffer));
}

TEST(circularbuffer, EmptyToFullToEmpty)
{
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_put(buffer, i + 100);
    }
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_get(buffer);
    }
    CHECK_TRUE(circularbuffer_is_empty(buffer));
    CHECK_FALSE(circularbuffer_is_full(buffer));
}

TEST(circularbuffer, WarpAround)
{
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_put(buffer, i + 100);
    }
    UNSIGNED_LONGS_EQUAL(100, circularbuffer_get(buffer));
    CHECK_TRUE(circularbuffer_put(buffer, 10000));
    CHECK_TRUE(circularbuffer_is_full(buffer));
    for(uint32_t i = 1; i < circularbuffer_capacity(buffer); ++i) {
        UNSIGNED_LONGS_EQUAL(100 + i, circularbuffer_get(buffer));
    }
    UNSIGNED_LONGS_EQUAL(10000, circularbuffer_get(buffer));
    CHECK_TRUE(circularbuffer_is_empty(buffer));
    CHECK_FALSE(circularbuffer_is_full(buffer));
    UNSIGNED_LONGS_EQUAL(0xaa, container[100]);
}

TEST(circularbuffer, PutToFullThrows)
{
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_put(buffer, i + 100);
    }
    CHECK_FALSE(circularbuffer_put(buffer, 100000));
}

TEST(circularbuffer, PutToFullDoesNotDamageContents)
{
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_put(buffer, i + 100);
    }
    circularbuffer_put(buffer, 10000);
    UNSIGNED_LONGS_EQUAL(0xaa, container[100]);
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        UNSIGNED_LONGS_EQUAL(100 + i, circularbuffer_get(buffer));
    }
}

TEST(circularbuffer, GetFromEmptyReturns0)
{
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_put(buffer, i + 100);
    }
    for(uint32_t i = 0; i < circularbuffer_capacity(buffer); ++i) {
        circularbuffer_get(buffer);
    }
    UNSIGNED_LONGS_EQUAL(0, circularbuffer_get(buffer));
}
