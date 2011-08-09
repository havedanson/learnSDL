#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>
#include "CSurface.h"

class CApp 
{
 private:
  bool _running;
  
  SDL_Surface * _surfaceDisplay;
  SDL_Surface * _surfaceTest; 
 public:
  CApp();
  int OnExecute(); 
  
  bool OnInit(); 
  void OnEvent(SDL_Event * Event);
  void OnLoop(); 
  void OnRender(); 
  void OnCleanup(); 

};


#endif
