/**
 * @file /home/hinsshum/Desktop/cy/embed_tdd/chapter10/test/mock/mock_io.c
 *
 * Copyright (C) 2021
 *
 * mock_io.c is free software: you can redistribute it and/or modify
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
#include "CppUTestExt/MockSupport_c.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
void io_write(uint32_t addr, uint32_t data)
{
    mock_c()->actualCall("io_write")
            ->withIntParameters("addr", addr)
            ->withIntParameters("data", data);
}

uint32_t io_read(uint32_t addr)
{
    mock_c()->actualCall("io_read")
            ->withIntParameters("addr", addr);
    
    return mock_c()->returnValue().value.intValue;
}

