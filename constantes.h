void Initialiser(SDL_Surface *ecran);
void Avance(SDL_Surface *ecran);
int Verefier(int n);
void Gauche(SDL_Surface *ecran,int i);
void Droite(SDL_Surface *ecran,int i);
void Deplacer(SDL_Surface *ecran,int i);
void Recule(SDL_Surface *ecran);
void SDL_PutPixel32(SDL_Surface *ecran, int x, int y, Uint32 pixel);
Uint32 SDL_GetPixel32(SDL_Surface *ecran, int x, int y);
void Line(SDL_Surface* ecran,int x1,int y1, int x2,int y2,Uint32 couleur);
void Tracer_Chemin(SDL_Surface *ecran,int n,Uint32 couleur);
void Commencer(SDL_Surface *ecran);




#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define TAILLE_BLOC         34 // Taille d'un bloc (carré) en pixels
    #define NB_BLOCS_LARGEUR    18
    #define NB_BLOCS_HAUTEUR    14
    #define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
    #define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR





#endif

