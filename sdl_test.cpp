
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <iostream>

/*
compiled with:
g++ -I"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\include" -L"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\lib" sdl_test.cpp -lSDL2main -lSDL2 && ./a
*/

int main(int argc, char* argv[]) {

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    // initialize sdl
    if (SDL_Init(SDL_INIT_VIDEO < 0)) {
        std::cout << "SDL could not be initialized. Error: " << SDL_GetError() << '\n';
        return 1;
    }

    // create window
    SDL_Window* window = SDL_CreateWindow("cool window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == nullptr) {
        std::cout << "Window failed to open. Error: " << SDL_GetError() << '\n';
        return 1;
    }

    // get window surface
    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    // fill the surface white
    SDL_FillRect(window_surface, nullptr, SDL_MapRGB(window_surface->format, 255, 255, 255));

    // apply changes
    SDL_UpdateWindowSurface(window);

    // keep window from dying immediately
    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) break;

        // actual code goes here
    }

    // exit window
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}