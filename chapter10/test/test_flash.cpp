/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/chapter10/test/test_flash.cpp
 *
 * Copyright (C) 2021
 *
 * test_flash.cpp is free software: you can redistribute it and/or modify
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
#include "mock_io.h"
#include "flash.h"
#include "fake_mirco_time.h"
#include "m28w160ect.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTestExt/MockSupport.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
TEST_GROUP(flash)
{
    uint32_t addr;
    uint32_t data;

    void setup(void)
    {
        addr = 0x1000;
        data = 0xBEEF;
    }

    void teardown(void)
    {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(flash, WriteSucceedsReadyImmediately)
{
    mock().expectOneCall("io_write")
            .withParameter("addr", COMMAND_REGISTER)
            .withParameter("data", PROGRAM_COMMAND);
    mock().expectOneCall("io_write")
            .withParameter("addr", addr)
            .withParameter("data", data);
    mock().expectOneCall("io_read")
            .withParameter("addr", STATUS_REGISTER)
            .andReturnValue(READY_BIT);
    mock().expectOneCall("io_read")
            .withParameter("addr", addr)
            .andReturnValue(data);
    LONGS_EQUAL(FLASH_SUCCESS, flash_write(addr, data));
}

TEST(flash, WriteFailsVppError)
{
    mock().expectOneCall("io_write")
            .withParameter("addr", COMMAND_REGISTER)
            .withParameter("data", PROGRAM_COMMAND);
    mock().expectOneCall("io_write")
            .withParameter("addr", addr)
            .withParameter("data", data);
    mock().expectOneCall("io_read")
            .withParameter("addr", STATUS_REGISTER)
            .andReturnValue(READY_BIT | VPP_BIT);
    mock().expectOneCall("io_write")
            .withParameter("addr", COMMAND_REGISTER)
            .withParameter("data", RESET);
    LONGS_EQUAL(FLASH_VPP_ERROR, flash_write(addr, data));
}

TEST(flash, WriteFailsFlashReadBackError)
{
    mock().expectOneCall("io_write")
            .withParameter("addr", COMMAND_REGISTER)
            .withParameter("data", PROGRAM_COMMAND);
    mock().expectOneCall("io_write")
            .withParameter("addr", addr)
            .withParameter("data", data);
    mock().expectOneCall("io_read")
            .withParameter("addr", STATUS_REGISTER)
            .andReturnValue(READY_BIT);
    mock().expectOneCall("io_read")
            .withParameter("addr", addr)
            .andReturnValue(data - 1);
    LONGS_EQUAL(FLASH_READ_BACK_ERROR, flash_write(addr, data));
}

TEST(flash, WriteFailsTimeout)
{
    fake_micro_time_init(0, 500);
    mock().expectOneCall("io_write")
            .withParameter("addr", COMMAND_REGISTER)
            .withParameter("data", PROGRAM_COMMAND);
    mock().expectOneCall("io_write")
            .withParameter("addr", addr)
            .withParameter("data", data);
    for(uint8_t i = 0; i < 10; ++i) {
        mock().expectOneCall("io_read")
                .withParameter("addr", STATUS_REGISTER)
                .andReturnValue(~READY_BIT);
    }
    LONGS_EQUAL(FLASH_TIMEOUT_ERROR, flash_write(addr, data));
}

TEST(flash, WriteFailsTimeoutAtEndOfTime)
{
    fake_micro_time_init(0xFFFFFFFF, 500);
    mock().expectOneCall("io_write")
            .withParameter("addr", COMMAND_REGISTER)
            .withParameter("data", PROGRAM_COMMAND);
    mock().expectOneCall("io_write")
            .withParameter("addr", addr)
            .withParameter("data", data);
    for(uint8_t i = 0; i < 10; ++i) {
        mock().expectOneCall("io_read")
                .withParameter("addr", STATUS_REGISTER)
                .andReturnValue(~READY_BIT);
    }
    LONGS_EQUAL(FLASH_TIMEOUT_ERROR, flash_write(addr, data));
}
