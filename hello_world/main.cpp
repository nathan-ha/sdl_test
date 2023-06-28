#include "window_functions.h"
#include <stdexcept>

/*
compiled with:
g++ -I"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\include" -L"D:\libraries\SDL2-2.28.0\x86_64-w64-mingw32\lib" main.cpp window_functions.cpp -o helloworld -lSDL2main -lSDL2 && ./helloworld
*/

void load_image(const char* filename, window& w, SDL_Surface* image_surface);

int main (int argc, char* argv[]) {
    const int SCREEN_WIDTH = 474;
    const int SCREEN_HEIGHT = 401;

    window w(SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Surface* image_surface = nullptr;
    load_image("helloworld.bmp", w, image_surface);

    w.loop();

    SDL_FreeSurface(image_surface);
    image_surface = nullptr;
    return 0;
}

void load_image(const char* filename, window& w, SDL_Surface* image_surface) {
    image_surface = SDL_LoadBMP(filename);
    if (image_surface == nullptr) throw std::runtime_error("failed to load image");

    SDL_BlitSurface(image_surface, nullptr, w.window_surface, nullptr); // stamps a copy of image onto window
    SDL_UpdateWindowSurface(w.container);
}