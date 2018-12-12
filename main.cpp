/**
 * Based on tutorials from http://lazyfoo.net/tutorials/SDL/
 * Beggining Game Programming v2.0
 */

#include <iostream>
#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(){
    std::cout<<"Hello, World!"<<std::endl;

    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;

    if (SDL_Init( SDL_INIT_VIDEO) < 0) {
        printf( "SDL could not be initialized! SDL_Error: %s\n", SDL_GetError() );
    } else {
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            surface = SDL_GetWindowSurface( window );
            SDL_FillRect(surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);

            SDL_Delay(20000);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}