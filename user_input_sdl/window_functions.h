#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <string>

struct window {
    SDL_Window* container;
    SDL_Surface* window_surface;

    // creates sdl window
    window(int width, int height, const char* name = "");
    ~window();

    // loops in order to keep window from closing immediately
    // pass in a function that runs every loop
    template <typename T> void loop(T fn());
    
    // loops in order to keep window from closing immediately
    void run_until_quit();
};

template <typename T> 
void window::loop(T fn()) {
    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return;
            fn();
        }
    }
}