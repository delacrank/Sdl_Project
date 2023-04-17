#include "Game.h"
#include <iostream>


Game::Game():
m_pWindow(NULL),
m_pRenderer(NULL),
m_bRunning(false) {}

Game::~Game() {
	m_pWindow = 0;
	m_pRenderer = 0;
	
}

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == NULL) {

		int flags = 0;

		if(fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		if (m_pWindow != NULL) {

			std::cout << "SDL init success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if(m_pRenderer != NULL) {
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
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

	if (!TheTextureManager::Instance()->load("../resources/animate-alpha.png", "animate", m_pRenderer)) return false;

	m_bRunning = true;
			
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);

	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
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
	m_currentFrame = int(((SDL_GetTicks() / 120) % 6));
}

