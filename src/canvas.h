/* -*- Mode: C ; c-basic-offset: 2 -*- */
/*
 * LADI Session Handler (ladish)
 *
 * Copyright (C) 2009, 2010, 2011 Nedko Arnaudov <nedko@arnaudov.name>
 *
 **************************************************************************
 * This file contains the interface to the canvas functionality
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

#ifndef CANVAS_H__BE110B39_CB54_47C2_A5B2_FFB3BA7CDA6D__INCLUDED
#define CANVAS_H__BE110B39_CB54_47C2_A5B2_FFB3BA7CDA6D__INCLUDED

#include "common.h"

typedef struct canvas_tag { int unused; } * canvas_handle;
typedef struct canvas_module_tag { int unused; } * canvas_module_handle;
typedef struct canvas_port_tag { int unused; } * canvas_port_handle;

#ifdef __cplusplus
extern "C" {
#endif
#if 0
} /* Adjust editor indent */
#endif

bool
canvas_init(
  void);

bool
canvas_create(
  double width,
  double height,
  void * canvas_context,
  void (* connect_request)(void * port1_context, void * port2_context),
  void (* disconnect_request)(void * port1_context, void * port2_context),
  void (* module_location_changed)(void * module_context, double x, double y),
  void (* fill_canvas_menu)(GtkMenu * menu, void * canvas_context),
  void (* fill_module_menu)(GtkMenu * menu, void * module_context),
  void (* fill_port_menu)(GtkMenu * menu, void * port_context),
  canvas_handle * canvas_handle_ptr);

GtkWidget *
canvas_get_widget(
  canvas_handle canvas);

void
canvas_destroy(
  canvas_handle canvas);

void
canvas_clear(
  canvas_handle canvas);

void
canvas_get_size(
  canvas_handle canvas,
  double * width_ptr,
  double * height_ptr);

void
canvas_scroll_to_center(
  canvas_handle canvas);

double
canvas_get_zoom(
  canvas_handle canvas);

void
canvas_set_zoom(
  canvas_handle canvas,
  double pix_per_unit);

void
canvas_set_zoom_fit(
  canvas_handle canvas);

void
canvas_arrange(
  canvas_handle canvas);

size_t
canvas_get_selected_modules_count(
  canvas_handle canvas);

bool
canvas_get_one_selected_module(
  canvas_handle canvas,
  void ** module_context_ptr);

bool
canvas_get_two_selected_modules(
  canvas_handle canvas,
  void ** module1_context_ptr,
  void ** module2_context_ptr);

bool
canvas_create_module(
  canvas_handle canvas,
  const char * name,
  double x,
  double y,
  bool show_title,
  bool show_port_labels,
  void * module_context,
  canvas_module_handle * module_handle_ptr);

bool
canvas_destroy_module(
  canvas_handle canvas,
  canvas_module_handle module);

void
canvas_set_module_name(
  canvas_module_handle module,
  const char * name);

const char *
canvas_get_module_name(
  canvas_module_handle module);

bool
canvas_create_port(
  canvas_handle canvas,
  canvas_module_handle module,
  const char * name,
  bool is_input,
  int color,
  void * port_context,
  canvas_port_handle * port_handle_ptr);

bool
canvas_destroy_port(
  canvas_handle canvas,
  canvas_port_handle port);

int
canvas_get_port_color(
  canvas_port_handle port);

void
canvas_set_port_name(
  canvas_port_handle port,
  const char * name);

const char *
canvas_get_port_name(
  canvas_port_handle port);

bool
canvas_add_connection(
  canvas_handle canvas,
  canvas_port_handle port1,
  canvas_port_handle port2,
  uint32_t color);

bool
canvas_remove_connection(
  canvas_handle canvas,
  canvas_port_handle port1,
  canvas_port_handle port2);

bool
canvas_enum_modules(
  canvas_handle canvas,
  void * callback_context,
  bool (* callback)(void * context, canvas_module_handle module));

bool
canvas_enum_module_ports(
  canvas_handle canvas,
  canvas_module_handle module,
  void * callback_context,
  bool (* callback)(void * context, canvas_port_handle port));

#if 0
{ /* Adjust editor indent */
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* #ifndef CANVAS_H__BE110B39_CB54_47C2_A5B2_FFB3BA7CDA6D__INCLUDED */
