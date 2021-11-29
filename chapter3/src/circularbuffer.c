/**
 * @file chapter3/src/circularbuffer.c
 *
 * Copyright (C) 2021
 *
 * circularbuffer.c is free software: you can redistribute it and/or modify
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
#include <string.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
typedef struct {
    uint32_t *pbuf;
    uint32_t size;
    uint32_t avaiable_size;
} circularbuffer_t;

/*---------- variable ----------*/
static circularbuffer_t circularbuffer;

/*---------- function ----------*/
void circularbuffer_create(uint32_t *buffer, uint32_t size)
{
    circularbuffer.pbuf = buffer;
    circularbuffer.size = size;
    circularbuffer.avaiable_size = 0;
    memset(buffer, 0, size * sizeof(uint32_t));
}

void circularbuffer_destroy(void)
{

}

void circularbuffer_write(uint32_t *data, uint32_t length)
{
    memcpy(circularbuffer.pbuf, data, length * sizeof(uint32_t));
    circularbuffer.avaiable_size += length;
}

void circularbuffer_read(uint32_t *data, uint32_t length)
{
    memcpy(data, circularbuffer.pbuf, length * sizeof(uint32_t));
    circularbuffer.avaiable_size -= length;
}

uint32_t circularbuffer_get_size(void)
{
    return circularbuffer.avaiable_size;
}