#pragma once
/*
* librdkafka - Apache Kafka C library
*
* Copyright (c) 2012-2015 Magnus Edenhill
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * POSIX system support
 */
#pragma once

#include <unistd.h>
#include <sys/time.h>


/**
* Types
*/


/**
 * Annotations, attributes, optimizers
 */
#ifndef likely
#define likely(x)   __builtin_expect((x),1)
#endif
#ifndef unlikely
#define unlikely(x) __builtin_expect((x),0)
#endif

#define RD_UNUSED   __attribute__((unused))
#define RD_NORETURN __attribute__((noreturn))
#define RD_PACKED   __attribute__((packed))
#define RD_IS_CONSTANT(p)  __builtin_constant_p((p))
#define RD_TLS      __thread

/* size_t and ssize_t format strings */
#define PRIusz  "zu"
#define PRIdsz  "zd"

#define RD_FORMAT(...) __attribute__((format(__VA_ARGS__)));

#define rd_usleep(usec)  usleep(usec)


/**
* Allocation
*/
#if !defined(__FreeBSD__)
/* alloca(3) is in stdlib on FreeBSD */
#include <alloca.h>
#endif

#define rd_alloca(N)  alloca(N)


/**
* Strings, formatting, printf, ..
*/

/* size_t and ssize_t format strings */
#define PRIusz  "%zu"
#define PRIdsz  "%zd"

#define RD_FORMAT(...) __attribute__((format (printf, __VA_ARGS__)))
#define rd_snprintf(...)  sprintf_s(__VA_ARGS__)


/**
 * Errors
 */
#define rd_strerror(err) rd_strerror(err)


/**
* Misc
*/
#define rd_usleep(usec)  usleep(usec)
