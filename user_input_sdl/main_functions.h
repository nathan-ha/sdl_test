#include "window_functions.h"
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
    
void frame(const SDL_Event& event, const window& curr_window);

//Key press surfaces constants
enum key_press {
    KEY_DEFAULT,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    NUM_KEY_PRESSES
};

// stores all of the key presses in an array
SDL_Surface* key_press_surfaces [NUM_KEY_PRESSES];

// keeps window open until quit
// takes a function as an argument
void loop(const window& curr_window) {
    while (true) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) return;
            frame(event, curr_window);
        }
    }
}

// the code that is run every frame
void frame(const SDL_Event& event, const window& curr_window) {
    if (event.type != SDL_KEYDOWN) return;

    SDL_Surface* surface = nullptr;

    switch (event.key.keysym.sym) {
        case SDLK_w: surface = key_press_surfaces[KEY_UP]; break;
        case SDLK_s: surface = key_press_surfaces[KEY_DOWN]; break;
        case SDLK_a: surface = key_press_surfaces[KEY_LEFT]; break;
        case SDLK_d: surface = key_press_surfaces[KEY_RIGHT]; break;
        default: surface = key_press_surfaces[KEY_DEFAULT]; break;
    }

    // SDL_BlitSurface(surface, nullptr, curr_window.window_surface, nullptr); // applies the image (no stretching)
	// stretches the image
	SDL_Rect stretched_rect;
	stretched_rect.x = 0;
	stretched_rect.y = 0;
	stretched_rect.w = SCREEN_WIDTH;
	stretched_rect.h = SCREEN_HEIGHT;
	SDL_BlitScaled(surface, nullptr , curr_window.window_surface, &stretched_rect);
    SDL_UpdateWindowSurface(curr_window.container);
}

// loads (but does not update window) the surface at the given path
// takes in a path to a bmp file
// returns a pointer to the surface
SDL_Surface* load_surface(const std::string& path) {
    SDL_Surface* new_surface = SDL_LoadBMP(path.c_str());
    if (new_surface == nullptr) {
        std::string error(SDL_GetError());
        throw std::runtime_error("failed to load surface at " + path + ". Error: " + error);
    }
    return new_surface;
}

// loads an image similarly but more optimally
SDL_Surface* load_surface(const std::string& path, const window & curr_window) {
	SDL_Surface* temp_surface = SDL_LoadBMP(path.c_str());
	if (temp_surface == nullptr) {
        std::string error(SDL_GetError());
        throw std::runtime_error("failed to load surface at " + path + ". Error: " + error);
    }
	SDL_Surface* new_surface = SDL_ConvertSurface(temp_surface, curr_window.window_surface->format, 0);
	if (new_surface == nullptr) {
        std::string error(SDL_GetError());
        throw std::runtime_error("failed to load surface at " + path + ". Error: " + error);
    }
	SDL_FreeSurface(temp_surface);
	return new_surface;
}

// loads images and stores them into key_press_surfaces
void load_images() {
    // default key
    key_press_surfaces[KEY_DEFAULT] = load_surface("images/default.bmp");
    if (key_press_surfaces[KEY_DEFAULT] == nullptr) {
        throw std::runtime_error("failed to load default key press");
    }

    // Up key
    key_press_surfaces[KEY_UP] = load_surface("images/W.bmp");
    if (key_press_surfaces[KEY_UP] == nullptr) {
        throw std::runtime_error("failed to load Up key press");
    }

    // Down key
    key_press_surfaces[KEY_DOWN] = load_surface("images/S.bmp");
    if (key_press_surfaces[KEY_DOWN] == nullptr) {
        throw std::runtime_error("failed to load Down key press");
    }

    // Left key
    key_press_surfaces[KEY_LEFT] = load_surface("images/A.bmp");
    if (key_press_surfaces[KEY_LEFT] == nullptr) {
        throw std::runtime_error("failed to load Left key press");
    }

    // Right key
    key_press_surfaces[KEY_RIGHT] = load_surface("images/D.bmp");
    if (key_press_surfaces[KEY_RIGHT] == nullptr) {
        throw std::runtime_error("failed to load Right key press");
    }
}

// loads images but uses more optimal types
void load_images(const window& curr_window) {
    // default key
    key_press_surfaces[KEY_DEFAULT] = load_surface("images/default.bmp", curr_window);
    if (key_press_surfaces[KEY_DEFAULT] == nullptr) {
        throw std::runtime_error("failed to load default key press");
    }

    // Up key
    key_press_surfaces[KEY_UP] = load_surface("images/W.bmp", curr_window);
    if (key_press_surfaces[KEY_UP] == nullptr) {
        throw std::runtime_error("failed to load Up key press");
    }

    // Down key
    key_press_surfaces[KEY_DOWN] = load_surface("images/S.bmp", curr_window);
    if (key_press_surfaces[KEY_DOWN] == nullptr) {
        throw std::runtime_error("failed to load Down key press");
    }

    // Left key
    key_press_surfaces[KEY_LEFT] = load_surface("images/A.bmp", curr_window);
    if (key_press_surfaces[KEY_LEFT] == nullptr) {
        throw std::runtime_error("failed to load Left key press");
    }

    // Right key
    key_press_surfaces[KEY_RIGHT] = load_surface("images/D.bmp", curr_window);
    if (key_press_surfaces[KEY_RIGHT] == nullptr) {
        throw std::runtime_error("failed to load Right key press");
    }
}

