#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "core/amemory.h"
#include "game_types.h"

/**
 * @brief Externally-defined function to create a game.
 *
 * @param out_game  Pointer to the game state structure.
 */
extern b8 create_game(game *out_game);

/**
 * @brief The main entry point of the application.
 */
int main(void)
{
    initialize_memory();

    // Request the game instance from the application.
    game game_inst;
    if (!create_game(&game_inst)) {
        AFATAL("Could not create game!");
        return -1;
    }

    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        AFATAL("The game's function pointers must be assinged!");
        return -2;
    }

    // Initialize the game.
    if (!application_create(&game_inst)) {
        AINFO("Appliaction failed to create.");
        return 1;
    }

    // Begin the game loop.
    if (!application_run()) {
        AINFO("The application did not shutdown gracefully.");
        return 2;
    }

    shutdown_memory();

    return 0;
}