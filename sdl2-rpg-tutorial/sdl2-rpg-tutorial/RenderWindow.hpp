#pragma once
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class RenderWindow {
public:
    // Constructor
    // p_title: title of the game
    // p_w: width of game
    // p_h: height of game
    RenderWindow(const char* p_title, int p_w, int p_h);
        
    // Loads textuers
    SDL_Texture* loadTexture (const char* p_filePath);
        
    // Clears screen
    void clear();
    
    // Renders texture
    void render(SDL_Texture* p_tex);
    
    // Updates screen
    void display();
    
    // destroys window object
    void cleanUp();
    
private:
    // *window: the actual window that we will draw to
    // *renderer: rasterizes pixels onto the window
    SDL_Window* window;
    SDL_Renderer* renderer;
};
