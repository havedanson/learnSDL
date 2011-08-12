#include "CSurface.h"

CSurface::CSurface(){
}

SDL_Surface * CSurface::OnLoad(char * File)
{
  SDL_Surface * surfTemp = NULL; 
  SDL_Surface * surfReturn = NULL; 

  if((surfTemp = SDL_LoadBMP(File)) == NULL)
    {
      return NULL;
    }

  surfReturn = SDL_DisplayFormat(surfTemp);
  SDL_FreeSurface(surfTemp);

  return surfReturn; 
}

bool CSurface::OnDraw(SDL_Surface * surfDest, SDL_Surface * surfSource, int x, int y)
{
  if(surfDest == NULL || surfSource == NULL)
    {
      return false;
    }
  
  SDL_Rect destR; 
  
  destR.x = x;
  destR.y = y;
  
  SDL_BlitSurface(surfSource, NULL, surfDest, &destR);
  return true;
}

bool CSurface::OnDraw(SDL_Surface * surfDest, SDL_Surface * surfSource, int x, int y, int x2, int y2, int w, int h)
{
  if(surfDest == NULL || surfSource == NULL){
    return false;
  }
  
  SDL_Rect destR; 
 
  destR.x = x;
  destR.y = y;
  
  SDL_Rect srcR;
  
  srcR.x = x2; 
  srcR.y = y2; 
  srcR.w = w;
  srcR.h = h;
  
  SDL_BlitSurface(surfSource, &srcR, surfDest, &destR);

  return true;
  
}


bool CSurface::Transparent(SDL_Surface * surfDest, int R, int G, int B)
{
  if(surfDest == NULL)
    {
      return false;
    }

  SDL_SetColorKey(surfDest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surfDest->format, R, G, B));
  
  return true;
}
