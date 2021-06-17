#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "constantes.h"
#include "fonction.c"

int main(int argc, char *argv[]){
    SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_WM_SetCaption("ROBOT", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);


    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("HOME.bmp");
    /* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
    int continuer = 1;
    SDL_Event event;
    while (continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_SPACE: /* Appui sur la touche Echap, on arrête le programme */
                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
                        SDL_Flip(ecran);
                        Initialiser(ecran);         //initialiser l'ecran
                        positionRobot.x=68;
                        positionRobot.y=150;
                        Robot=SDL_LoadBMP("Robot_bas.bmp");
                        SDL_SetColorKey(Robot, SDL_SRCCOLORKEY, SDL_MapRGB(Robot->format, 255, 255, 255));
                        SDL_SetAlpha(Robot, SDL_SRCALPHA, 255);
                        SDL_BlitSurface(Robot, NULL, ecran, &positionRobot);
                        SDL_Flip(ecran);
                        break;
                    case SDLK_c:
                        Commencer(ecran);   //commencer la vérefication des objets
                        break;
                    default:
                        break;
                }
                break;
        }
    }
    SDL_FreeSurface(imageDeFond); /* On libère la surface */
    SDL_Quit();
    return 0;
}

