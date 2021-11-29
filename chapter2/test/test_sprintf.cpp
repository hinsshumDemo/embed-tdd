/**
 * @file chapter1/test/test_sprintf.cpp
 *
 * Copyright (C) 2021
 *
 * test_sprintf.cpp is free software: you can redistribute it and/or modify
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
#include <CppUTest/CommandLineTestRunner.h>
#include <stdio.h>
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
TEST_GROUP(sprintf)
{
    char output[100];
    const char *expected;

    void setup(void)
    {
        memset(output, 0xaa, sizeof(output));
        expected = "";
    }

    void teardown(void)
    {
    }

    void expect(const char *s)
    {
        expected = s;
    }

    void given(int chars_written)
    {
        LONGS_EQUAL(strlen(expected), chars_written);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(output) + 1]);
    }
};

TEST(sprintf, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(sprintf, InsertString)
{
    expect("Hello, world\n");
    given(sprintf(output, "Hello, %s\n", "world"));
}
