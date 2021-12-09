/**
 * @file src/include/m28w160ect.h
 *
 * Copyright (C) 2021
 *
 * m28w160ect.h is free software: you can redistribute it and/or modify
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
#ifndef __M28W160ECT_H
#define __M28W160ECT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*---------- macro ----------*/
#define READY_BIT                   (1 << 7)
#define VPP_BIT                     (1 << 3)
#define PROGRAM_BIT                 (1 << 4)
#define PROTECT_BIT                 (1 << 1)

/*---------- type define ----------*/
typedef enum {
    COMMAND_REGISTER = 0x0,
    STATUS_REGISTER = 0x0
} flash_registers;

typedef enum {
    PROGRAM_COMMAND = 0x40,
    RESET = 0xFF
} flash_command;

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/

#ifdef __cplusplus
}
#endif
#endif /* __M28W160ECT_H */
