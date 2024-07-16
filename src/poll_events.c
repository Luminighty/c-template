#include "poll_events.h"


void poll_events(App* app, GameState* game, Input* input) {
	input_update(input);
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			app->quit = 1;
			return;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				app->quit = 1;
			input_key_down(input, event.key.keysym.scancode);
			break;
		case SDL_KEYUP:
			input_key_up(input, event.key.keysym.scancode);
			break;
		}
	}
}
