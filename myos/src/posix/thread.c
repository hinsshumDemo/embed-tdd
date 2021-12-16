/**
 * @file src/posix/thread.c
 *
 * Copyright (C) 2021
 *
 * thread.c is free software: you can redistribute it and/or modify
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
#include "thread.h"
#include <pthread.h>
#include <stdlib.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
typedef struct st_thread {
    thread_entry_func entry;
    void *parameter;
    bool started;
    pthread_t pthread;
} thread_t;

/*---------- variable ----------*/
/*---------- function ----------*/
thread thread_create(thread_entry_func f, void *parameter)
{
    thread self = calloc(1, sizeof(thread_t));

    self->entry = f;
    self->parameter = parameter;
    self->started = false;

    return self;
}

void thread_start(thread self)
{
    pthread_create(&self->pthread, NULL, self->entry, self->parameter);
    self->started = true;
}

void thread_destroy(thread self)
{
    if(self->started) {
        pthread_join(self->pthread, NULL);
        self->started = false;
    }
    free(self);
}
