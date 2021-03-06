/**
 * Based on tutorials from http://lazyfoo.net/tutorials/SDL/
 * Beggining Game Programming v2.0
 */

#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
SDL_Surface* gXOut = NULL;

bool init();
bool loadMedia();
void close();

int main(int argc, char* args[]) {
    if (!init()) {
        printf("Failed to initialize!\n");
    } else {
        if (!loadMedia()) {
            printf("Failed to load media!\n");
        } else {
            bool quit = false;
            SDL_Event e;
            while(!quit) {
                while(SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
                SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
                SDL_UpdateWindowSurface(gWindow);
            }
        }
    }

    close();
    return 0;
}

bool init() {
    bool success = true;

    if (SDL_Init( SDL_INIT_VIDEO) < 0) {
        printf( "SDL could not be initialized! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if (gWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia() {
    bool success = true;

    gHelloWorld = SDL_LoadBMP("../assets/hello_world.bmp");
    if(gHelloWorld == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", "assets/hello_world.bmp", SDL_GetError());
        success = false;
    }

    gXOut = SDL_LoadBMP("../assets/x.bmp");
    if(gXOut == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", "assets/hello_world.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close() {
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;
    gXOut = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();
}