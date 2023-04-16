#ifndef __GAME_H__
#define __GAME_H__

#include "SDL.h"

class Game {

public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool const getRunning() { return m_bRunning;  }
	SDL_Window const *getSdlWindow() { return m_pWindow;  }
	SDL_Renderer const *getSdlRenderer() { return m_pRenderer;  }
	SDL_Texture const *getSdlTexture() { return m_pTexture; }
	SDL_Rect const getSdlsourcRect() { return m_sourceRectangle; }
	SDL_Rect const getSdldestinationRect() { return m_destinationRectangle; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;
	bool m_bRunning;


};

#endif // !__GAME__

