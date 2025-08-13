#include "game.h"

#include <entry.h>

#include <core/amemory.h>

// TODO: Remove this.
#include <platform/platform.h>

/**
 * @brief Create a game object
 *
 * This is an implementation of the function defined at `<entry.h>`.
 * @param out_game  Pointer to the game state structure.
 */
b8 create_game(game *out_game)
{
    // Configure the appliction.
    out_game->app_config.start_pos_x = 100;
    out_game->app_config.start_pos_y = 100;
    out_game->app_config.start_width = 1280;
    out_game->app_config.start_height = 720;
    out_game->app_config.name = "Ascendant Engine Testbed";
    out_game->update = game_update;
    out_game->render = game_render;
    out_game->initialize = game_initialize;
    out_game->on_resize = game_on_resize;

    // Create the game state.
    // TODO: Check allocation success and eventually free this memory.
    out_game->state = aallocate(sizeof(game_state), MEMORY_TAG_GAME);

    return TRUE;
}