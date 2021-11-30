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
typedef struct circularbuffer_struct {
    uint32_t *container;
    uint32_t capacity;
    uint32_t count;
    uint32_t index;
    uint32_t outdex;
} circularbuffer_struct;

/*---------- variable ----------*/
static circularbuffer_struct _circularbuffer;

/*---------- function ----------*/
circularbuffer_t circularbuffer_create(uint32_t *container, uint32_t capacity)
{
    memset(container, 0, capacity * sizeof(uint32_t));
    _circularbuffer.container = container;
    _circularbuffer.capacity = capacity;
    _circularbuffer.count = 0;
    _circularbuffer.index = 0;
    _circularbuffer.outdex = 0;

    return &_circularbuffer;
}

void circularbuffer_destroy(circularbuffer_t self)
{
    self->container = NULL;
    self->capacity = 0;
    self->count = 0;
    self->index = 0;
    self->outdex = 0;
}

bool circularbuffer_is_empty(circularbuffer_t self)
{
    return !self->count;
}

bool circularbuffer_is_full(circularbuffer_t self)
{
    return (self->count == self->capacity);
}

bool circularbuffer_put(circularbuffer_t self, uint32_t value)
{
    bool retval = true;

    if(circularbuffer_is_full(self)) {
        retval = false;
    } else {
        self->count++;
        self->container[self->index++] = value;
        if(self->index >= self->capacity) {
            self->index = 0;
        }
    }

    return retval;
}

uint32_t circularbuffer_get(circularbuffer_t self)
{
    uint32_t retval = 0;

    if(!circularbuffer_is_empty(self)) {
        self->count--;
        retval = self->container[self->outdex++];
        if(self->outdex >= self->capacity) {
            self->outdex = 0;
        }
    }

    return retval;
}

uint32_t circularbuffer_capacity(circularbuffer_t self)
{
    return self->capacity;
}
