/**
 * @file chapter3/src/include/circularbuffer.h
 *
 * Copyright (C) 2021
 *
 * circularbuffer.h is free software: you can redistribute it and/or modify
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
#ifndef __CIRCULARBUFFER_H
#define __CIRCULARBUFFER_H

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
typedef struct circularbuffer_struct *circularbuffer_t;

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern circularbuffer_t circularbuffer_create(uint32_t *container, uint32_t capacity);
extern void circularbuffer_destroy(circularbuffer_t self);
extern bool circularbuffer_is_empty(circularbuffer_t self);
extern bool circularbuffer_is_full(circularbuffer_t self);
extern bool circularbuffer_put(circularbuffer_t self, uint32_t value);
extern uint32_t circularbuffer_get(circularbuffer_t self);
extern uint32_t circularbuffer_capacity(circularbuffer_t self);

#ifdef __cplusplus
}
#endif
#endif /* __CIRCULARBUFFER_H */
