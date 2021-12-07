/**
 * @file chapter4/utils/include/runtime_error_stub.h
 *
 * Copyright (C) 2021
 *
 * runtime_error_stub.h is free software: you can redistribute it and/or modify
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
#ifndef __RUNTIME_ERROR_STUB_H
#define __RUNTIME_ERROR_STUB_H

#ifdef __cplusplus
extern "C"
{
#endif

/*---------- includes ----------*/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*---------- macro ----------*/
/*---------- type define ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern void runtime_error_stub_reset(void);
extern const char *runtime_error_stub_get_last_error(void);
extern int32_t runtime_error_stub_get_last_parameter(void);

#ifdef __cplusplus
}
#endif
#endif /* __RUNTIME_ERROR_STUB_H */
