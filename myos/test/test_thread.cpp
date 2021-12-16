/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/myos/test/test_thread.cpp
 *
 * Copyright (C) 2021
 *
 * test_thread.cpp is free software: you can redistribute it and/or modify
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
#include "thread.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static bool thread_ran;
static thread handle;

/*---------- function ----------*/
static void *thread_entry(void *p)
{
    thread_ran = true;

    return NULL;
}

TEST_GROUP(thread)
{
    void setup(void)
    {
        thread_ran = false;
    }

    void teardown(void)
    {
        handle = NULL;
    }
};

TEST(thread, CreateDoesNotStartThread)
{
    handle = thread_create(thread_entry, 0);
    thread_destroy(handle);
    CHECK(false == thread_ran);
}

TEST(thread, StartedThreadRunsBeforeItIsDestroyed)
{
    handle = thread_create(thread_entry, 0);
    thread_start(handle);
    thread_destroy(handle);
    CHECK(true == thread_ran);
}
