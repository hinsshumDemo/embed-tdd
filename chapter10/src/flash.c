/**
 * @file src/flash.c
 *
 * Copyright (C) 2021
 *
 * flash.c is free software: you can redistribute it and/or modify
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
#include "flash.h"
#include "m28w160ect.h"
#include "micro_time.h"
#include "io.h"

/*---------- macro ----------*/
#define FLASH_TIMEOUT_IN_MICROSECONDS                   (5000)

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
/*---------- function ----------*/
static int32_t write_error(int32_t status)
{
    int32_t retval = FLASH_UNKNOWN_ERROR;

    io_write(COMMAND_REGISTER, RESET);
    if(status & VPP_BIT) {
        retval = FLASH_VPP_ERROR;
    } else if(status & PROGRAM_BIT) {
        retval = FLASH_PROGRAM_ERROR;
    } else if(status & PROGRAM_BIT) {
        retval = FALSH_PROTECTED_BLOCK_ERROR;
    }

    return retval;
}

int32_t flash_write(uint32_t addr, uint32_t data)
{
    uint32_t status = 0;
    uint32_t timestamp = micro_time_get();

    io_write(COMMAND_REGISTER, PROGRAM_COMMAND);
    io_write(addr, data);
    do {
        if((micro_time_get() - timestamp) > FLASH_TIMEOUT_IN_MICROSECONDS) {
            return FLASH_TIMEOUT_ERROR;
        }
        status = io_read(STATUS_REGISTER);
    } while((status & READY_BIT) == 0);
    if(status != READY_BIT) {
        return write_error(status);
    }
    if(io_read(addr) != data) {
        return FLASH_READ_BACK_ERROR;
    }

    return FLASH_SUCCESS;
}
