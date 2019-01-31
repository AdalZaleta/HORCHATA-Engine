#pragma once
#include "Horchata/Horchata.h"
#include <stdlib.h>
#include "Horchata/hoSpriteSheet.h"

class RenderGL
{
	public:
		RenderGL();
		~RenderGL();

		float clipAreaXLeft;
		float clipAreaYTop;
		float clipAreaXRightt;
		float clipAreaYBottom;
		int h;
		int w;
		float lPos;
		float rPos;
		//Funcion encarga de inicializar OpenGL
		//Regresa True si se inicio correctamente o false en caso cotrario
		void inicializar();
		//Se llama al momento de libarse
		void liberar();

		//Se llama desde main en los click down, las coordenas estan en version openGL
		void onClickDown(float _x, float _y);

		//Funcion que se actualiza cada frame
		void update();
		//Funcion encargado de dibujar
		void render();

		void Ball();


		hoBody* body;
		hoSprite sprite;
		hoText2 txt;


		const GLuint WIDTH = 1500, HEIGHT = 1000;


		cpShapeFilter testFilter;
};

extern RenderGL g_renderGL; //Singleton
