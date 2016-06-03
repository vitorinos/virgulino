/*
 * I would like to thank to Gjuniioor for letting 
 * me know about the danger that dangling points
 * can bring to the project.
 *
 * Thank you boy!.
 *
 * P.S.: You see, no dangling points anymore.
 *
 * To compile to plugin:
 * gcc  -pedantic -Wall -O2 -fPIC -shared plugin.c plugin_api.h -o plugin.so -ldl
 */ 


/*
 * *@Note: This is the actual plugin. Every plugin should follow this same
 * sample style and architecture. Every plugin is a plugin_name.c file that
 * must include "plugin_api.h" and everything will be handled by the 
 * plugin_controller.h"
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "plugin_api.h"

#define    LEN     32

struct plugin_state_ {
    char str[LEN];
};

static inline char *
get (plugin_state * state) {
    return state->str;
}

static inline void
set(plugin_state * state, const char * str) {
    strncpy (state->str, str, (sizeof(state->str)));
}

static plugin_state * 
plugin_init() {
    plugin_state * state = malloc (sizeof(*state));
    memset (state->str, 0x00, sizeof(state->str));

    return state;
}

static void
plugin_reload (plugin_state * state) {
    memset (state->str, 0x00, sizeof(state->str));
}


static void
plugin_print (plugin_state * state) {
    printf ("Plugin being printed !\n");
}

static void
plugin_unload(plugin_state * state) {
    
}

static void
plugin_finalize (plugin_state * state) {
    if (state) { free(state); }

    state = NULL;
}

const plugin_api PLUGIN_API = {
    .init = plugin_init,
    .reload = plugin_reload,
    .print = plugin_print,
    .unload = plugin_unload,
    .finalize = plugin_finalize,
};
