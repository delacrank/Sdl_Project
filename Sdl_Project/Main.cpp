#include "SDL.h"
#include <iostream>
#include "Game.h"

Game* g_game = 0;

int main(int argc, char* argv[]) {

	g_game = new Game();

	std::cout << SDL_GetBasePath() << std::endl;

	g_game->init("chapter  1", 100, 100, 1000, 1000, false);

	while(g_game->getRunning()) {
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();

	return 0;
}
