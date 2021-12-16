/**
 * @file src\win32\thread.c
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
#include "Windows.h"
#include <stdlib.h>

/*---------- macro ----------*/
/*---------- variable prototype ----------*/
/*---------- function prototype ----------*/
/*---------- type define ----------*/
typedef struct st_thread {
    HANDLE handle;
    thread_entry_func entry;
    void *parameter;
    bool started;
} thread_t;

/*---------- variable ----------*/
/*---------- function ----------*/
static DWORD WINAPI win32_thread_entry(LPVOID param)
{
    thread handle = (thread)param;

    return (UINT)handle->entry(handle->parameter);
}

thread thread_create(thread_entry_func f, void *parameter)
{
    DWORD thread_id;

    thread self = calloc(1, sizeof(thread_t));
    self->entry = f;
    self->parameter = parameter;
    self->handle = CreateThread(0, 0, win32_thread_entry, self, CREATE_SUSPENDED, &thread_id);

    return self;
}

void thread_start(thread self)
{
    self->started = true;
    ResumeThread(self->handle);
}

void thread_destroy(thread self)
{
    if(self->started) {
        WaitForSingleObject(self->handle, INFINITE);
        self->started = false;
    }
    CloseHandle(self->handle);
    free(self);
}
