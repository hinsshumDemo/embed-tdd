/**
 * @file src/include/flash.h
 *
 * Copyright (C) 2021
 *
 * flash.h is free software: you can redistribute it and/or modify
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
#ifndef __FLASH_H
#define __FLASH_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*---------- macro ----------*/
enum {
    FLASH_SUCCESS = 0,
    FLASH_VPP_ERROR,
    FLASH_PROGRAM_ERROR,
    FALSH_PROTECTED_BLOCK_ERROR,
    FLASH_UNKNOWN_ERROR,
    FLASH_READ_BACK_ERROR,
    FLASH_TIMEOUT_ERROR
};

/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern int32_t flash_write(uint32_t addr, uint32_t data);

#ifdef __cplusplus
}
#endif
#endif /* __FLASH_H */
