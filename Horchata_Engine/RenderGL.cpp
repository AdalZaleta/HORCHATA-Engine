#include "RenderGL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include "hoImages.h"
#include <iostream>


RenderGL g_renderGL; //Singleton

RenderGL::RenderGL()
{
}
RenderGL::~RenderGL()
{

}

void RenderGL::inicializar()
{
	GLenum error = GL_NO_ERROR;
	//Para obtener error: error = glGetError();

	//Inicializamos Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Model view Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	float aspect =(float)w / (float)h;

	if (w >= h)
	{
		clipAreaXLeft=-10.0*aspect;
		clipAreaXRightt = 10.0*aspect;
		clipAreaYBottom = -10.0;
		clipAreaYTop = 10.0;
	}
	else
	{
		clipAreaXLeft = -10.0;
		clipAreaXRightt = 10.0;
		clipAreaYBottom = -10.0/aspect;
		clipAreaYTop = 10.0/aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRightt, clipAreaYBottom, clipAreaYTop);

	glEnable(GL_TEXTURE_2D);
	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);
	testImage.LoadImage_("GABO.jpg");
}

void RenderGL::liberar()
{
	//delete this
}

void RenderGL::update()
{
	
}

void RenderGL::render()
{

	testImage.DrawImage(1, 1, 50, 50);

	
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT);

}


