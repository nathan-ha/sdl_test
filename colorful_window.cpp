
#define SDL_MAIN_HANDLED

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>
#include <chrono>

#include <SDL2/SDL.h>
#include <windows.h>

/*
compiled with:
g++ -I"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\include" -L"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\lib" colorful_window.cpp -lSDL2main -lSDL2 && ./a
*/

int random_integer_inclusive(int min, int max) {
  return floor(rand() * (max - min + 1)) + min;
}

int main(int argc, char* argv[]) {
    srand(time(0));
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    if (SDL_Init(SDL_INIT_VIDEO < 0)) {
        std::cout << "SDL could not be initialized. Error: " << SDL_GetError() << '\n';
        return 1;
    }
    
    SDL_Window* window = SDL_CreateWindow("cool window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "Window failed to open. Error: " << SDL_GetError() << '\n';
        return 1;
    }


    SDL_Surface* window_surface = SDL_GetWindowSurface(window);
    SDL_UpdateWindowSurface(window);
    
    int r = random_integer_inclusive(0,255);
    int g = random_integer_inclusive(0,255);
    int b = random_integer_inclusive(0,255);

    SDL_Event event;
    while (true) {

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) break;

        int i = 1;
        r = 255 * sin(i * r);
        g = 255 * sin(i * g);
        b = 255 * sin(i * b);
        i = (i + 1) % INT_MAX;

        SDL_FillRect(window_surface, nullptr, SDL_MapRGB(window_surface->format, r, g, b));
        SDL_UpdateWindowSurface(window);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}