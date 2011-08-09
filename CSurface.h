#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL/SDL.h>

class CSurface { 
 public: 
  CSurface();
  
 public: 
  static SDL_Surface * OnLoad(char * File);
  static bool OnDraw(SDL_Surface* surfDest, SDL_Surface * surfSource, int x , int y);
  static bool OnDraw(SDL_Surface * surfDest, SDL_Surface * surfSource, int x, int y, int x2, int y2, int w, int h);


};
#endif
