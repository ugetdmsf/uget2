/*
 *
 *   Copyright (C) 2012-2014 by C.H. Huang
 *   plushuang.tw@gmail.com
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  ---
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU Lesser General Public License in all respects
 *  for all of the code used other than OpenSSL.  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so.  If you
 *  do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 *
 */

#ifndef UG_UTIL_H
#define UG_UTIL_H

#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------------
// Time

// Change the modified time of file
int      ug_modify_file_time (const char *file_utf8, time_t mod_time);
uint64_t ug_get_time_count (void);

// ----------------------------------------------------------------------------
// URI

char*  ug_unescape_uri (const char *uri, int length);

// ----------------------------------------------------------------------------
// Unicode

uint16_t*  ug_utf8_to_utf16 (const char* string, int stringLength,
                             int* utf16len);
int        ug_utf8_get_invalid (const uint8_t* input, uint8_t* ch);

// ----------------------------------------------------------------------------
// Base64

char*  ug_base64_encode (const uint8_t* data, int input_length,
                         int* output_length);

// ----------------------------------------------------------------------------
// file & directory functions

int   ug_file_is_exist (const char* file);
int   ug_file_is_dir (const char* file);
int   ug_create_dir_all (const char* dir, int len);
//int ug_delete_dir_all (const char* dir, int len);
char* ug_build_filename (const char* first_element, ...);

// ----------------------------------------------------------------------------
// Power Management

// Suspend does not turn off your computer. It puts the computer and all peripherals on a low power consumption mode.
// Hibernate saves the state of your computer to the hard disk and completely powers off.

void  ug_reboot (void);
void  ug_shutdown (void);
void  ug_suspend (void);
void  ug_hibernate (void);

// ----------------------------------------------------------------------------
// Others

char* ug_sys_release (void);

#ifdef __cplusplus
}
#endif

#endif // End of UG_UTIL_H
