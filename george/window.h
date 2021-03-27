#pragma once
#include "SDL.h"
#include "utils.h"
#include <vector>

class Window {
private:
	SDL_Window* p_window;
	SDL_Renderer* p_renderer;
	SDL_Texture* p_texture;
	int width, height;

public:
	std::vector<std::vector<Colour>> texture;

	Window(const char* title, int x, int y, int width, int height, Uint32 flags);
	~Window();
	int Width();
	int Height();
	int UpdateTexture();

};