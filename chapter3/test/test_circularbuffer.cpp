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
 *  1. 环形缓存创建后，缓存全部为初始化状态（全0）
 *  2. 可以写入单个整型数据
 *  3. 可以读取单个整型数据
 *  4. 可以写入多个整型数据
 *  5. 可以读取多个整型数据
 *  6. 可以查询环形缓存中的存储数据数量
 *  7. 检查边界值
 *  8. 检查界外值
 */

TEST_GROUP(circularbuffer)
{
    uint32_t buffer[100];

    void setup(void)
    {
        circularbuffer_create(buffer, sizeof(buffer) / sizeof(buffer[0]));
    }

    void teardown(void)
    {

    }
};

TEST(circularbuffer, BufferClearAfterCreate)
{
    uint32_t buffer[100], check_buffer[100] = {0};

    memset(buffer, 0xaa, sizeof(buffer));
    circularbuffer_create(buffer, sizeof(buffer) / sizeof(buffer[0]));
    MEMCMP_EQUAL(check_buffer, buffer, sizeof(buffer));
}

TEST(circularbuffer, WriteOneToCircularBuffer)
{
    uint32_t data = 0xaa;

    circularbuffer_write(&data, 1);
    UNSIGNED_LONGS_EQUAL(0xaa, buffer[0]);
}

TEST(circularbuffer, ReadOneFromCircularBuffer)
{
    uint32_t data = 0xaa;

    circularbuffer_write(&data, 1);
    data = 0;
    circularbuffer_read(&data, 1);
    UNSIGNED_LONGS_EQUAL(0xaa, data);
}

TEST(circularbuffer, WriteMultiToCircularBuffer)
{
    uint32_t data[] = {0x01, 0x02, 0x03};

    circularbuffer_write(data, sizeof(data) / sizeof(data[0]));
    MEMCMP_EQUAL(data, buffer, sizeof(data));
}

TEST(circularbuffer, ReadMultiFromCircularBuffer)
{
    uint32_t data[] = {0x01, 0x02, 0x03};

    circularbuffer_write(data, sizeof(data) / sizeof(data[0]));
    memset(data, 0, sizeof(data));
    circularbuffer_read(data, sizeof(data) / sizeof(data[0]));
    MEMCMP_EQUAL(buffer, data, sizeof(data));
}

TEST(circularbuffer, GetSizeAfterWriteThree)
{
    uint32_t data[] = {0x01, 0x02, 0x03};

    circularbuffer_write(data, sizeof(data) / sizeof(data[0]));
    UNSIGNED_LONGS_EQUAL(sizeof(data) / sizeof(data[0]), circularbuffer_get_size());
}

TEST(circularbuffer, GetSizeAfterWriteThreeAndReadThree)
{
    uint32_t data[] = {0x01, 0x02, 0x03};

    circularbuffer_write(data, sizeof(data) / sizeof(data[0]));
    circularbuffer_read(data, sizeof(data) / sizeof(data[0]));
    UNSIGNED_LONGS_EQUAL(0, circularbuffer_get_size());
}

TEST(circularbuffer, GetSizeAfterWriteThreeAndReadOne)
{
    uint32_t data[] = {0x01, 0x02, 0x03};

    circularbuffer_write(data, sizeof(data) / sizeof(data[0]));
    circularbuffer_read(data, 1);
    UNSIGNED_LONGS_EQUAL(2, circularbuffer_get_size());
}