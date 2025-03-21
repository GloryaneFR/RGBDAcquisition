#include <stdio.h>
#include <stdlib.h>

#if defined ( _WIN32 )
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#else
#include <GL/glx.h>    /* this includes the necessary X headers */
#include <GL/gl.h>
#include <GL/glu.h>
#include <X11/X.h>    /* X11 constant (e.g. TrueColor) */
#include <X11/keysym.h>
#include "glx.h"
#include "glx2.h"
#include "glx3.h"
#endif


int start_glx_stuff(int WIDTH,int HEIGHT,int openGLVersion,int viewWindow,int argc,const char **argv)
{
  switch (openGLVersion)
  {
    case 1:
    case 2:
      return start_glx2_stuff(WIDTH,HEIGHT,viewWindow,argc,argv);
    break;

    case 3:
    case 4:
      return start_glx3_stuff(WIDTH,HEIGHT,viewWindow,argc,argv);
    break;
  };
  return 0;
}



int glx_endRedraw(int openGLVersion)
{
  switch (openGLVersion)
  {
    case 1:
    case 2:
      return glx2_endRedraw();
    break;

    case 3:
    case 4:
      return glx3_endRedraw();
    break;
  };
  return 1;
}


int glx_checkEvents(int openGLVersion)
{
   //fprintf(stderr,"glx_checkEvents version %u",openGLVersion);  
  switch (openGLVersion)
  {
    case 1:
    case 2:
      return glx2_checkEvents();
    break;

    case 3:
    case 4:
      return glx3_checkEvents();
    break;
  };
     return 0;
}

