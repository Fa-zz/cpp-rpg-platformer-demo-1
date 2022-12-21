#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"

// RenderWindow constructor
// Preconditions: SDL has no problems initializing
// Postconditions: Window object has been created, window and renderer member vars are initialized. A renderer obj is not created in the driver file.
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:window(NULL), renderer(NULL) {
    
    // SDL_CreateWindow returns a pointer to an SDL window, we set it equal to window
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    // if the window fails to initialize, notify user
    if (window == NULL) {
        std::cout<< "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }
    
    // SDL_CreateRenderer returns a pointer to a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// loadTexture
// Preconditions: SDL has been initialized and window obj has been created
// Postconditions: Texture obj pointers have been created for the textures used in the game
SDL_Texture* RenderWindow::loadTexture (const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    
    if (texture == NULL) {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    
    return texture;
}

// clear
// Preconditions: SDL is initialized, window obj is initialized, texture objs are initialized, game is running
// Postconditions: Entire rendering target has been cleared
void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

// render
// Preconditions: Game is running
// Postconditions: A portion of the texture has been copied to the current rendering target (in this case the renderer obj)
void RenderWindow::render(SDL_Texture* p_tex) {
    SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

// display
// Preconditions: Game is running and window's render function has been called for each texture
// Postconditions: Screen is updated with new rendering
void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

// cleanUp: destroys window obj (not the same as a destructor)
// Preconditions: User has decided to quit the game
// Postconditions: SDL_DestroyWindow has been called on window obj
void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}
