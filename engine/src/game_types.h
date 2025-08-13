#pragma once

#include "core/application.h"

/**
 * @brief Basic game state representation.
 *
 * Called for creation by the application.
 *
 * @param app_config    The application configuration.
 * @param initialize    Function pointer to the game's initialize function.
 * @param update        Function pointer to the game's update function.
 * @param render        Function pointer to the game's render funtion.
 * @param on_resize     Function pointer to handle resizes, if applicable.
 * @param state         Game-specific game state. Created and managed by the game.
 */
typedef struct game {
    application_config app_config;
    b8 (*initialize)(struct game *game_inst);
    b8 (*update)(struct game *game_inst, f32 delta_time);
    b8 (*render)(struct game *game_inst, f32 delta_time);
    void (*on_resize)(struct game *game_inst, u32 width, u32 height);
    void *state;
} game;