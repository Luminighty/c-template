#include <SDL2/SDL.h>
#include <stdint.h>

#include "SDL_timer.h"
#include "app.h"
#include "gamestate.h"
#include "input.h"
#include "poll_events.h"
#include "render.h"
#include "update.h"


void input_set_keys(Input* input) {
	// input_set_key(input, SDL_SCANCODE_UP, INPUT_UP);
}


int main() {
	GameState game = gamestate_create();
	App app = app_create();
	Input input = input_create();
	input_set_keys(&input);

	uint64_t last_time, current_time = SDL_GetTicks64();
	uint64_t delta_time = 0;
	const uint64_t FPS_TICKS = 1000 / 60;
	while (!app.quit) {
		current_time = SDL_GetTicks64();
		delta_time = current_time - last_time;

		poll_events(&app, &game, &input);
		update(&game, &input);
		render(&app, &game);

		if (delta_time < FPS_TICKS)
			SDL_Delay(FPS_TICKS - delta_time);
		last_time = SDL_GetTicks64();
	}
	
	app_destroy(&app);
	return 0;
}

