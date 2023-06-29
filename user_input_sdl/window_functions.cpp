#include "window_functions.h"
#include <stdexcept>

window::window(int width, int height, const char* name)
{
    if (SDL_Init(SDL_INIT_VIDEO < 0)) throw std::runtime_error("failed to initialize sdl");
    container = SDL_CreateWindow(name, 
                                 SDL_WINDOWPOS_UNDEFINED, 
                                 SDL_WINDOWPOS_UNDEFINED, 
                                 width, 
                                 height, 
                                 SDL_WINDOW_SHOWN);
    if (container == nullptr) throw std::runtime_error("Window failed to open");
    
    window_surface = SDL_GetWindowSurface(container);
}

void window::run_until_quit() {
    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return;
        }
    }
}

window::~window() {
    SDL_DestroyWindow(container); // window_surface is also freed here
    container = nullptr;
    window_surface = nullptr;
}