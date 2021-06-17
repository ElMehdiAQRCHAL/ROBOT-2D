
/*
----------------------MENU DES OBJETS----------------------

	1-CERCLE
	2-RECTANGLE
	3-CARRé
*/

#ifndef DEF_FONCTION
#define DEF_FONCTION


int Zone1[]={2,3,1,3,2,1};
int Zone2[]={0,0,0,0,0,0};
int Position1[]={0,0,0,0,0,0};		//tableau contient les positions du robot dans la zone 1
int Position2[21][2];				//tableau contient les positions du robot de l'état initiale à l'état finale(21 car le max des positions dans le cas qu'on a 6 cercles dans la zone 1


SDL_Surface *Robot=NULL;
SDL_Rect positionRobot;


void Initialiser(SDL_Surface *ecran)
{
	int i,d;
	SDL_Surface *objet=NULL;
	SDL_Rect positionobjet;
    positionobjet.x=68;
    positionobjet.y=68;
	for(i=0;i<6;i++){
		d=Zone1[i];
		switch(d)
		{
			case 1:
				objet=SDL_LoadBMP("Cercle.bmp");	//on charge cercle dans la zone 1
				positionobjet.x+=75;
				SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
				Position1[i]=positionobjet.x;
				break;
			case 2:
				objet=SDL_LoadBMP("Rectangle.bmp");	//on charge Rectangle dans la zone 1
				positionobjet.x+=75;
				SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
				Position1[i]=positionobjet.x;
				positionobjet.x-=32;				//car l'objet rectangle de format 36*68 (68-32=36)
				break;
			case 3:
				objet=SDL_LoadBMP("Carré.bmp");		//on charge Carré dans la zone 1
				positionobjet.x+=75;
				SDL_BlitSurface(objet, NULL, ecran, &positionobjet);
				Position1[i]=positionobjet.x;
				break;
		}
	}
	SDL_Flip(ecran);
	return;
}


void Avance(SDL_Surface *ecran)
{
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));	//on colloré l'ecran (bleau)
    SDL_Flip(ecran);
    Initialiser(ecran);													//on initialise l'écran 
	positionRobot.x=143;												//avance le robot vers la zone 1
    positionRobot.y=68;
	Robot=SDL_LoadBMP("Robot_bas.bmp");
	SDL_SetColorKey(Robot, SDL_SRCCOLORKEY, SDL_MapRGB(Robot->format, 255, 255, 255));
	SDL_SetAlpha(Robot, SDL_SRCALPHA, 255);
	SDL_BlitSurface(Robot, NULL, ecran, &positionRobot);
	SDL_Flip(ecran);
	return;
}


int Verefier(int n)
{
    if(n==1) return 1;
    else return 0;
}



void Gauche(SDL_Surface *ecran,int i)
{
	int j;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    SDL_Flip(ecran);
    Initialiser(ecran);						//on initialise l'écran 
	SDL_Surface *objet=NULL;
	SDL_Rect positionobjet;
	objet=SDL_LoadBMP("Cercle.bmp");		//on charge l'objet cercle
	positionobjet.x=68;
	positionobjet.y=272;
	for(j=0;j<i+1;j++)
	{
		if(Verefier(Zone1[j]==1))
		{
			positionobjet.x+=75;
			SDL_BlitSurface(objet, NULL, ecran, &positionobjet);	//on charge une cercle dans la zone 2
			SDL_Flip(ecran);
		}
	}
	Robot=SDL_LoadBMP("Robot_bas.bmp");
	positionRobot.x=positionobjet.x;
    positionRobot.y=272;
    SDL_SetColorKey(Robot, SDL_SRCCOLORKEY, SDL_MapRGB(Robot->format, 255, 255, 255));
    SDL_SetAlpha(Robot, SDL_SRCALPHA, 255);
    SDL_BlitSurface(Robot, NULL, ecran, &positionRobot);
    SDL_Flip(ecran);
	return;
}



void Droite(SDL_Surface *ecran,int i)
{
	int j;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    SDL_Flip(ecran);
    Initialiser(ecran);						//on initialise l'écran
	SDL_Surface *objet=NULL;
	SDL_Rect positionobjet;
	objet=SDL_LoadBMP("Cercle.bmp");		//on charge l'objet cercle
	positionobjet.x=68;
	positionobjet.y=272;
	for(j=0;j<i+1;j++)
	{
		if(Verefier(Zone1[j]==1))
		{
			positionobjet.x+=75;
			SDL_BlitSurface(objet, NULL, ecran, &positionobjet);	//on charge une cercle dans la zone 2
			SDL_Flip(ecran);
		}
	}
	Robot=SDL_LoadBMP("Robot_bas.bmp");
	positionRobot.x=Position1[i];			//retour de robot vers la zone 1
    positionRobot.y=68;
    SDL_SetColorKey(Robot, SDL_SRCCOLORKEY, SDL_MapRGB(Robot->format, 255, 255, 255));
    SDL_SetAlpha(Robot, SDL_SRCALPHA, 255);
    SDL_BlitSurface(Robot, NULL, ecran, &positionRobot);
    SDL_Flip(ecran);
	return;
}	
	

void Deplacer(SDL_Surface *ecran,int i)
{
	int j;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    SDL_Flip(ecran);
    Initialiser(ecran);				//on initialise l'écran
	SDL_Surface *objet=NULL;
	SDL_Rect positionobjet;
	objet=SDL_LoadBMP("Cercle.bmp");
	positionobjet.x=68;
	positionobjet.y=272;
	for(j=0;j<i+1;j++)
	{
		if(Verefier(Zone1[j]==1))
		{
			positionobjet.x+=75;
			SDL_BlitSurface(objet, NULL, ecran, &positionobjet);	//on charge une cercle dans la zone 2
			SDL_Flip(ecran);
		}
	}
	Robot=SDL_LoadBMP("Robot_bas.bmp");
	positionRobot.x=Position1[i+1];		//deplacer le robot vers l'objet suivant
    positionRobot.y=68;
    SDL_SetColorKey(Robot, SDL_SRCCOLORKEY, SDL_MapRGB(Robot->format, 255, 255, 255));
    SDL_SetAlpha(Robot, SDL_SRCALPHA, 255);
    SDL_BlitSurface(Robot, NULL, ecran, &positionRobot);
    SDL_Flip(ecran);
	return;
	}
	
	
void Recule(SDL_Surface *ecran)
{
	int i;
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 162, 232));
    SDL_Flip(ecran);
	Initialiser(ecran);
	SDL_Surface *ob=NULL;
	SDL_Rect positionob;
	ob=SDL_LoadBMP("Cercle.bmp");
	positionob.x=68;
	positionob.y=272;
	for(i=0;i<6;i++)
	{
		if(Verefier(Zone1[i]==1))
		{
			positionob.x+=75;
			SDL_BlitSurface(ob, NULL, ecran, &positionob);
			SDL_Flip(ecran);
		}
	}
	Robot=SDL_LoadBMP("Robot_bas.bmp");
	positionRobot.x=68;			//reculer le robot vers sa position initiale
    positionRobot.y=150;
    SDL_SetColorKey(Robot, SDL_SRCCOLORKEY, SDL_MapRGB(Robot->format, 255, 255, 255));
    SDL_SetAlpha(Robot, SDL_SRCALPHA, 255);
    SDL_BlitSurface(Robot, NULL, ecran, &positionRobot);
    SDL_Flip(ecran);
	return;
}


//Utilisation de l'algorithme de Bresenham


void SDL_PutPixel32(SDL_Surface *ecran, int x, int y, Uint32 pixel)
{
    Uint8 *p = (Uint8*)ecran->pixels + y * ecran->pitch + x * 4;
    *(Uint32*)p = pixel;
	return;
}

Uint32 SDL_GetPixel32(SDL_Surface *ecran, int x, int y)
{
    Uint8 *p = (Uint8*)ecran->pixels + y * ecran->pitch + x * 4;
    return *(Uint32*)p;
}

void Line(SDL_Surface* ecran,int x1,int y1, int x2,int y2,Uint32 couleur)  
{
  int x,y;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;

  Dx = abs(x2-x1);
  Dy = abs(y2-y1);
  if(x1<x2)
    xincr = 1;
  else
    xincr = -1;
  if(y1<y2)
    yincr = 1;
  else
    yincr = -1;

  x = x1;
  y = y1;
  if(Dx>Dy)
    {
      erreur = Dx/2;
      for(i=0;i<Dx;i++)
        {
          x += xincr;
          erreur += Dy;
          if(erreur>Dx)
            {
              erreur -= Dx;
              y += yincr;
            }
        SDL_PutPixel32(ecran,x, y,couleur);
        }
    }
  else
    {
      erreur = Dy/2;
      for(i=0;i<Dy;i++)
        {
          y += yincr;
          erreur += Dx;
          if(erreur>Dy)
            {
              erreur -= Dy;
              x += xincr;
            }
        SDL_PutPixel32(ecran,x, y,couleur);
        }
    }
    SDL_PutPixel32(ecran,x1,y1,couleur);
    SDL_PutPixel32(ecran,x2,y2,couleur);
}


void Tracer_Chemin(SDL_Surface *ecran,int n,Uint32 couleur){
	int i;
	for(i=0;i<n;i++){
		Line(ecran,Position2[i][0],Position2[i][1],Position2[i+1][0],Position2[i+1][1],couleur);	//tracer une droite entre les deux position du tableau i et i+1
		SDL_Flip(ecran);
	}
	return;
}

void Commencer(SDL_Surface *ecran)
{
	int i,d;
	//les dimensions du robot est 34*68
	Position2[0][0]=68+17;					//position initial du robot
    Position2[0][1]=150+34;
	Avance(ecran);							//avancer le robot vers la zone 1
	Position2[1][0]=positionRobot.x+17;		//position du premier objet du zone 1
	Position2[1][1]=positionRobot.y+34;
	Tracer_Chemin(ecran,1,0xFF0000FF);		//tracer le chemin du robot 
	d=2;
	SDL_Delay(2000);						//bloquée l'exécution 2 seconde
	for(i=0;i<6;i++)
	{
		if(Verefier(Zone1[i]==1))
		{
			Zone2[i]=1;
			Gauche(ecran,i);						//transporter le robot vers la zone 2
			Position2[d][0]=positionRobot.x+17;
			Position2[d][1]=positionRobot.y+34;
			Tracer_Chemin(ecran,d,0xFF0000FF);		//tracer le chemin du robot 
			d++;
			SDL_Delay(2000);						//bloquée l'exécution 2 seconde
			Droite(ecran,i);						//transporter le robot vers la zone 1
			Position2[d][0]=positionRobot.x+17;
			Position2[d][1]=positionRobot.y+34;
			Tracer_Chemin(ecran,d,0xFF0000FF);		//tracer le chemin du robot 
			d++;
			SDL_Delay(2000);						//bloquée l'exécution 2 seconde
		}
		if(i!=5)
		{
		Deplacer(ecran,i);							//deplacer le robot vers l'objet suivant
		Position2[d][0]=positionRobot.x+17;
		Position2[d][1]=positionRobot.y+34;
		Tracer_Chemin(ecran,d,0xFF0000FF);			//tracer le chemin du robot 
		d++;
		SDL_Delay(2000);							//bloquée l'exécution 2 seconde
		}
	}
	Recule(ecran);									//reculer le robot vers sa positon initiale
	Position2[d][0]=positionRobot.x+17;
	Position2[d][1]=positionRobot.y+34;
	Tracer_Chemin(ecran,d,0xFF0000FF);				//tracer le chemin du robot 
	return;
}
#endif
