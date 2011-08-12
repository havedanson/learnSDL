#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>
#include "CEvent.h"
#include "CSurface.h"

class CApp : public CEvent
{
 private:
  bool _running;
  
  SDL_Surface * _surfaceDisplay;
  SDL_Surface * _surfaceGrid;
  SDL_Surface * _surfaceX;
  SDL_Surface * _surfaceO;
  bool LoadSurface(SDL_Surface * surface, char * surfaceName);

  int _grid[9];
  int _currentPlayer;
  enum { 
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X, 
    GRID_TYPE_O
  };


 public:
  CApp();
  int OnExecute(); 
  
  bool OnInit(); 
  void OnEvent(SDL_Event * Event);
  void OnLoop(); 
  void OnRender(); 
  void OnCleanup(); 
  void OnExit();
  void Reset();
  void SetCell(int id, int type);
  void OnLButtonDown(int mX, int mY);
};


#endif
