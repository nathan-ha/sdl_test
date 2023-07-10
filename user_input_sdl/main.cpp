#include "main_functions.h"
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

    load_images(w);

    loop(w);

    return 0;
}
