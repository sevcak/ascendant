#pragma once

#include "defines.h"

struct game;

/*
 * @brief Application configuration structure.
 *
 * @param start_pos_x   Window starting position on the X axis, if applicable.
 * @param start_pos_y   Window starting position on the Y axis, if applicable.
 * @param start_width   Window staring width, if applicable.
 * @param start_height  Window staring width, if applicable.
 * @param name          The application name used in windowing, if applicable.
 */
typedef struct application_config {
    i16 start_pos_x;
    i16 start_pos_y;
    i16 start_width;
    i16 start_height;
    char *name;
} application_config;

#include "game_types.h"

AAPI b8 application_create(struct game *game_inst);

AAPI b8 application_run();