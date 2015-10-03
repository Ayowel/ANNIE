
#include <stdio.h>
#include <string.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#define ANNIE_FANS

void rectMoveIn(SDL_Rect *src, int x, int y)
{
    src->x+=x;
    src->y+=y;
    src->w= (x>=src->w) ? 0 : src->w-x;
    src->h= (y>src->h) ? 0 : src->h-y;
}

void ANNIE_BuildMenu(SDL_Surface *screen, SDL_Rect *area)
{
    if(screen!=NULL)
    {
        static TTF_Font *mainfont, *subfont;
        if(mainfont==NULL)
            mainfont=TTF_OpenFont("arial.ttf", 18);
        if(subfont==NULL)
            subfont=TTF_OpenFont("arial.ttf", 15);
        if(subfont==NULL || mainfont==NULL)
        {
            fprintf(stderr, "TTF File error, can't load menu fonts\n");
            return;
        }
        Uint32 t;
        SDL_Color maincolor = {255, 255, 255, 0}, subcolor = {255, 255, 255, 0};
        Uint32 bg = SDL_MapRGB(screen->format, 21, 67, 200), splits = SDL_MapRGB(screen->format, 200, 120, 120);
        SDL_Rect mv={0,0,0,0}, dst={0,0,screen->w,screen->h};
        SDL_Surface *tmp;
        if(area!=NULL)
        {
            dst.x=area->x;
            dst.y=area->y;
            dst.w=area->w;
            dst.h=area->h;
            //mv.w=area->w;
        }
        SDL_FillRect(screen, &dst, bg);
        #ifdef ANNIE_FANS
            tmp=TTF_RenderText_Blended(mainfont, "Creations des fans", maincolor);
            mv.w=area->w;
            mv.h=area->h;
            SDL_BlitSurface(tmp, &mv, screen, &dst);
            rectMoveIn(&dst, 0, tmp->h);
            SDL_FreeSurface(tmp);
            t=dst.h;
            dst.h=2;
            SDL_FillRect(screen, &dst, splits);
            dst.h=t;
            rectMoveIn(&dst, 0, 2);


        #endif // ANNIE_FANS_H_INCLUDED
    }
}
