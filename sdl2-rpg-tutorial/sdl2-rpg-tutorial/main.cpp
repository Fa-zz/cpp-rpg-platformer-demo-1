#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"

int main(int argc, char* args[]) {
    
    // The following two if statements alert us if there is an error with the initializing of SDL
    
    // If SDL has a problem initializing, alert user
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;
    
    // IF SDL_image has a problem initializing, alert user
    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
    
    // window is created and initialized
    RenderWindow window("GAME v1.0", 1280, 720);
    
    // creating textures
    //SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    SDL_Texture* grassTexture = window.loadTexture("ground_grass_1.png");
    
    // gameRunning: bool flag to determine if game is still running
    // event: SDL_Event obj that determines value of gameRunning
    bool gameRunning = true;
    SDL_Event event;
    
    while (gameRunning) {
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        
        // While game is running, clear window, render texture, and display it
        window.clear();
        window.render(grassTexture);
        window.display();
    }
    
    window.cleanUp();
    SDL_Quit();
    
    return 0;
}
