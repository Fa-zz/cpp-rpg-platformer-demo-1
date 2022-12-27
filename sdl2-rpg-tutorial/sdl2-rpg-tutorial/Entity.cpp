#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

// Entity constructor
Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex):x(p_x), y(p_y), texture(p_tex) {
    
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

// Getters for all member vars
float Entity::getX() { return x; }
float Entity::getY() { return y; }
SDL_Rect Entity::getCurrentFrame() { return currentFrame; }
SDL_Texture* Entity::getTexture() { return texture; }
