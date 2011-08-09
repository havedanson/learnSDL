#include "CApp.h"


CApp::CApp()
{
  _running = true;
  _surfaceDisplay = NULL; 
  _surfaceTest = NULL;
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
  
  if((_surfaceDisplay = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF))== NULL)
    {
      return false;
    }

  if((_surfaceTest = CSurface::OnLoad("Untitled.bmp")) == NULL)
    {
      return false;
    }

  return true;
}

void CApp::OnEvent(SDL_Event* Event)
{
  if(Event->type == SDL_QUIT)
    {
      _running = false;
    }
  
}

void CApp::OnLoop(){
  
}

void CApp::OnRender()
{
  CSurface::OnDraw(_surfaceDisplay, _surfaceTest, 0, 0);
  CSurface::OnDraw(_surfaceDisplay, _surfaceTest, 100, 100, 0, 0, 25, 25);
  SDL_Flip(_surfaceDisplay);

}


void CApp::OnCleanup()
{
  SDL_FreeSurface(_surfaceTest);
  SDL_FreeSurface(_surfaceDisplay);
  SDL_Quit();
}
