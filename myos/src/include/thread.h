/**
 * @file src/include/thread.h
 *
 * Copyright (C) 2021
 *
 * thread.h is free software: you can redistribute it and/or modify
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
#ifndef __THREAD_H
#define __THREAD_H

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
typedef struct st_thread * thread;
typedef void *(*thread_entry_func)(void *);

/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
extern thread thread_create(thread_entry_func f, void *parameter);
extern void thread_start(thread t);
extern void thread_destroy(thread t);

#ifdef __cplusplus
}
#endif
#endif /* __THREAD_H */
