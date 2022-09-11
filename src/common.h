/* -*- Mode: C ; c-basic-offset: 2 -*- */
/*
 * LADI Session Handler (ladish)
 *
 * Copyright (C) 2009,2011,2012 Nedko Arnaudov <nedko@arnaudov.name>
 *
 **************************************************************************
 * This file contains stuff that is needed almost everywhere in ladish
 **************************************************************************
 *
 * LADI Session Handler is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * LADI Session Handler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LADI Session Handler. If not, see <http://www.gnu.org/licenses/>
 * or write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef LANV_COMMON_H__82C9504A_ACD2_435D_9743_781943473E6A__INCLUDED
#define LANV_COMMON_H__82C9504A_ACD2_435D_9743_781943473E6A__INCLUDED

//#include "config.h"             /* configure stage result */

#include <stdbool.h>            /* C99 bool */
#include <stdint.h>             /* fixed bit size ints */
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef __cplusplus
//#include "common/klist.h"
#endif

#define LANV_PUBLIC __attribute__ ((visibility ("default")))
#define UNUSED(x) UNUSED_ ## x __attribute__((unused))

#define ASSERT(expr) assert(expr)
#define ASSERT_NO_PASS assert(false)

#define log_debug(fmt, args...)       void(fmt, ## args)
#define log_info(fmt, args...)        void(fmt, ## args)
#define log_warn(fmt, args...)        void(fmt, ## args)
#define log_error(fmt, args...)       void(fmt, ## args)
#define log_error_plain(fmt, args...) void(fmt, ## args)

#define _(x) x

#endif /* #ifndef LANV_COMMON_H__82C9504A_ACD2_435D_9743_781943473E6A__INCLUDED */
