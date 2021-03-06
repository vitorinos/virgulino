/*
 * steg_plugin_api.h
 *
 * Copyright (C) 2016 - userx
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _STEG_PLUGIN_API_H_
#define _STEG_PLUGIN_API_H_

#include "plugin_api.h"

#define STEG_PLUGIN_API(obj) 	((steg_plugin_api *)obj)

typedef enum {
	HIDDEN,
	ASCII,
} StegStatus;

typedef struct steg_plugin_api_ steg_plugin_api;
struct steg_plugin_api_ {
 	plugin_state * (* init) (const char * config_filepath);
 	void (* finalize) (plugin_state * state);
	void (* reload) (plugin_state * state);
	void (* unload) (plugin_state * state);
 
 	void (* hide) (plugin_state * state, const char * content, const char * dst_filename);
 	char * (* unhide) (plugin_state * state, const char * dst_filename);
};

extern const steg_plugin_api STEG_PLUGIN_API;

#endif /* _STEG_PLUGIN_API_H_ */
