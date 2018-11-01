#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>
#include "SDL_image.h"

class hoImages
{
public:
	hoImages();
	//Contructor of the class with the direction of the Image
	hoImages(const char* _dirImages);
	~hoImages();

	//This function Draw a pre-load Image
	void DrawImage(int _x, int _y, int _width, int _height);
	//This function Load a Image in the path
	//The path star in the folder 'Resources'
	bool LoadImage_(const char *_dirImages);
	GLuint textureID;
private:
	//This is the surface of the image will be loaded
	SDL_Surface* imageSurface = NULL;
};
