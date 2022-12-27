#pragma once
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

/*
 Entity is the building block for all drawable things in the game
 
 Anything that can be rendered to the screen will be an entity
 
 Without Entity class loaded textures would take up the entire window dimensions (where to place texture would not be specified)
*/

class Entity {

public:
    // Constructor
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    
    // Getters for x and y
    float getX();
    float getY();
    
    // Getters for currentFrame and texture
    SDL_Rect getCurrentFrame();
    SDL_Texture* getTexture();
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};
