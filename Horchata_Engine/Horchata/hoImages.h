#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>
#include <SDL_image.h>

class hoImages
{
public:
	hoImages();
	hoImages(const char* _dirImages);
	~hoImages();

	void DrawImage();
	static bool LoadImage(const char *_dirImages);

private:
	const char* dirImage;
	SDL_Surface* imageSurface = NULL;
};
