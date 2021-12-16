/**
 * @file chapter4/utils/runtime_error_stub.c
 *
 * Copyright (C) 2021
 *
 * runtime_error_stub.c is free software: you can redistribute it and/or modify
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
#include "runtime_error_stub.h"

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
/*---------- variable ----------*/
static const char *message = "No Error";
static int32_t parameter = -1;
static const char *file = NULL;
static int32_t line = -1;

/*---------- function ----------*/
void runtime_error_stub_reset(void)
{
    message = "No Error";
    parameter = -1;
}

const char *runtime_error_stub_get_last_error(void)
{
    return message;
}

int32_t runtime_error_stub_get_last_parameter(void)
{
    return parameter;
}

void runtime_error(const char *m, int p, const char *f, int32_t l)
{
    message = m;
    parameter = p;
    file = f;
    line = l;
}
