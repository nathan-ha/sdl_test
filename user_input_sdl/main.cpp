#include "window_functions.h"
#include <iostream>

void loop(void fn(SDL_Event& event));
void frame(SDL_Event& event);

/*
compiled with:
g++ -I"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\include" -L"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\lib" main.cpp window_functions.cpp -lSDL2main -lSDL2 && ./a
*/

int main() {

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    window w(SCREEN_WIDTH, SCREEN_HEIGHT, "input test");

    SDL_FillRect(w.window_surface, nullptr, SDL_MapRGB(w.window_surface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(w.container);



    loop(frame);

    return 0;
}

// keeps window open until quit
// takes a function as an argument
void loop(void fn(SDL_Event& event)) {
    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return;
            frame(event);
        }
    }
}

void frame(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        std::cout << "key down\n";
    }
    else if (event.type == SDL_KEYUP) {
        std::cout << "key up\n";
    }
}