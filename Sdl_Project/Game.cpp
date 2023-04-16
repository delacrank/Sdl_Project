#include "Game.h"
#include <iostream>

Game::Game():
m_pWindow(0),
m_pRenderer(0),
m_bRunning(false) {}

Game::~Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	
}

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		int flags = 0;

		if(fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (m_pWindow != 0) {
			std::cout << "SDL init success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if(m_pRenderer != 0) {
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			} else {
				std::cout << "render init fail\n";
				return false;
			}
		} else {
			std::cout << "window init fail\n";
			return false;
		} 
	} else {
		std::cout << "SDL init fail\n";
		return false;
	}


	SDL_Surface* pTempSurface = SDL_LoadBMP("../resources/animate.bmp");

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	/*SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.h, &m_sourceRectangle.w);*/



	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;

	m_destinationRectangle.w = m_sourceRectangle.w = 128;
	m_destinationRectangle.h = m_sourceRectangle.h = 82;
	

	std::cout << "init success\n";
	m_bRunning = true;
			
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL);

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if(SDL_PollEvent(&event)) {
		switch(event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default: break;
		}
	}
}

void Game::update() {
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 120) % 6));

}