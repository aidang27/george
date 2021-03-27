#include "window.h"


Window::Window(const char* title, int x, int y, int width, int height, Uint32 flags)
	: width(width)
	, height(height)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	p_window = SDL_CreateWindow(title, x, y, width, height, flags);
	p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);
	p_texture = SDL_CreateTexture(p_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width, height);

	texture = std::vector<std::vector<Colour>>(width, std::vector<Colour>(height));
}

Window::~Window()
{
	SDL_DestroyTexture(p_texture);
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}

int Window::Width() {
	return width;
}

int Window::Height() {
	return height;
}

int Window::UpdateTexture() {
	SDL_LockTexture(p_texture, NULL, )
}

