#include "render.h"


void render(App* app, GameState* game) {
	SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 255);
	SDL_RenderClear(app->renderer);

	// Render here

	SDL_RenderPresent(app->renderer);
}
