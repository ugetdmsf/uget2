/*
 *
 *   Copyright (C) 2013-2018 by C.H. Huang
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

#ifndef UGTK_1TO2_H
#define UGTK_1TO2_H

#include <UgetNode.h>
#include <UgtkSetting.h>
#include "UgSetting.h"
#include "UgCategory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct	Ugtk1to2    Ugtk1to2;

struct Ugtk1to2
{
	UgSetting   setting1;
	UgtkSetting setting;

	UgetNode    real;
	char*       config_path;
};

Ugtk1to2*  ugtk_1to2_new (const char* config_path);
void       ugtk_1to2_free (Ugtk1to2* u1t2);

// return TRUE/FALSE
int   ugtk_1to2_load_setting (Ugtk1to2* u1t2);
int   ugtk_1to2_save_setting (Ugtk1to2* u1t2);

// return number of category load/save
int   ugtk_1to2_load_category (Ugtk1to2* u1t2);
int   ugtk_1to2_save_category (Ugtk1to2* u1t2);

#ifdef __cplusplus
}
#endif

#endif // UGTK_1TO2_H
