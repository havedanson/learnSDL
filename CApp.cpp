#include "CApp.h"


CApp::CApp()
{
  _currentPlayer = 0;
  _running = true;
  _surfaceDisplay = NULL; 
  _surfaceX = NULL;
  _surfaceO = NULL;
  _surfaceGrid = NULL;
}

int CApp::OnExecute(){
  if(OnInit() == false)
    {
      return -1; 
    }
  
  SDL_Event Event;
  
  while(_running)
    {
      while(SDL_PollEvent(&Event))
	{
	  OnEvent(&Event);
	}

      OnLoop();
      OnRender();
    }
  
  OnCleanup();
  
  return 0;

}

int main(int argc, char* argv[])
{
  CApp theApp;
  return theApp.OnExecute();
}

bool CApp::OnInit()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
      return false; 
    }
  
  if((_surfaceDisplay = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))== NULL)
    {
      return false;
    }

  
  if((_surfaceGrid = CSurface::OnLoad("grid.bmp")) == NULL)
    {
      return false;
      }

  if((_surfaceO = CSurface::OnLoad("o.bmp")) == NULL)
    {
      return false;
      }

  if((_surfaceX = CSurface::OnLoad("x.bmp")) == NULL)
    {
      return false;
      }

  //set our transparencies our on images
  CSurface::Transparent(_surfaceX, 255, 0, 255);
  CSurface::Transparent(_surfaceO, 255, 0, 255);

  Reset();

  return true;
  /*
  retVal = retVal &&  LoadSurface(_surfaceX,"x.png");
  (retVal) ? return retVal;

  retVal = retVal && LoadSurface(_surfaceO,"o.png");
  (retVal) ? return retVal;

 return retVal;
  */
}

void CApp::OnEvent(SDL_Event* Event)
{
  CEvent::OnEvent(Event);
  
}

void CApp::OnLoop(){
  
}

void CApp::OnRender()
{
  for(int i = 0; i < 9; i++)
    {
      int x = (i % 3) * 200;
      int y = (i % 3) * 200;

      if (_grid[i] == GRID_TYPE_X)
	{
	  CSurface::OnDraw(_surfaceDisplay, _surfaceX, x, y);
	}
      if(_grid[i] == GRID_TYPE_O)
	{
	  CSurface::OnDraw(_surfaceDisplay, _surfaceO, x, y);
	}
    }

  CSurface::OnDraw(_surfaceDisplay,_surfaceGrid,0,0);
  SDL_Flip(_surfaceDisplay);
  
}


void CApp::OnCleanup()
{
  SDL_FreeSurface(_surfaceGrid);
  SDL_FreeSurface(_surfaceO);
  SDL_FreeSurface(_surfaceX);

  SDL_FreeSurface(_surfaceDisplay);
  SDL_Quit();
}

void CApp::OnExit()
{
  _running = false;
}

bool  CApp::LoadSurface(SDL_Surface * surface, char * surfaceName)
{
if((surface = CSurface::OnLoad(surfaceName)) == NULL)
    {
      return false;
    }
 return true;

}

void CApp::Reset()
{
  for(int i = 0; i < 9; i++)
    {
      _grid[i] = GRID_TYPE_NONE;
    }
}

void CApp::SetCell(int id, int type)
{
  if(id < 0 || id >= 9) return;
  if(type < 0 || type > GRID_TYPE_O) return;
  
  _grid[id] = type;
}


void CApp::OnLButtonDown(int mX, int mY)
{
  int id = mX / 200; 
  id = id + ((mY / 200) * 3);

  if(_grid[id] != GRID_TYPE_NONE)
    {
      return;
    }

  if(_currentPlayer == 0)
    {
      SetCell(id, GRID_TYPE_X);
      _currentPlayer = 1;
    }
  else
    {
      SetCell(id, GRID_TYPE_O);
      _currentPlayer = 0;
    }


}
