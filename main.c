#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "menu.h"
// A New Natural and Innovative Environment


int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
        return -1;
    if(TTF_Init()==-1)
        return -1;
    SDL_Surface *screen=SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    if(screen==NULL)
        return -1;
    SDL_Event event;
    SDL_Rect src={0,0,0,0};
    while(SDL_GetTicks()<5000)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_VIDEORESIZE:
                SDL_FillRect(screen, NULL, 0x00000000);
                screen->w=event.resize.w;
                screen->h=event.resize.h;
                src.y = screen->h/5;
                src.w = screen->w/4;
                src.h = screen->h*4/5;
                ANNIE_BuildMenu(screen, &src);
                SDL_Flip(screen);
        }
    }
    TTF_Quit();
    SDL_Quit();
    return 0;
}




