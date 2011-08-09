#include "CEvent.h"

CEvent::CEvent(){

  
}

CEvent::~CEvent(){
  //we choose to do nothing
}

void CEvent::OnEvent(SDL_Event * event)
{
  switch(event->type){
  case SDL_ACTIVEEVENT:{
    switch(event-> active.state)
      {
      case SDL_APPMOUSEFOCUS:
	{
	  if(event->active.gain)
	    {
	      OnMouseFocus();
	    }
	  else
	    {
	      OnMouseBlur();
	    }
	  break;
	}
      case SDL_APPINPUTFOCUS:
	{
	if(event->active.gain)
	  OnInputFocus();
	else
	  OnMinimize();
	
	break;
	}
	
      case SDL_APPACTIVE:
      {
	if(event->active.gain)
	  {
	    OnRestore();
	  }
	else
	  {
	    OnMinimize();
	  }
	break;
      }
      break;
      }
    
    case SDL_KEYDOWN:
      {
	OnKeyDown(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
	break;
      }

  }
    break;
  }
}
    
    
    
}
