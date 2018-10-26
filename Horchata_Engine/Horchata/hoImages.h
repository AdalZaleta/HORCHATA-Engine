#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>
#include "SDL_image.h"

class hoImages
{
public:
	hoImages();
	hoImages(const char* _dirImages);
	~hoImages();

	void DrawImage(int _x, int _y, int _width, int _height);
	bool LoadImage_(const char *_dirImages);
	GLuint textureID;
private:
	const char* dirImage;
	SDL_Surface* imageSurface = NULL;
};
