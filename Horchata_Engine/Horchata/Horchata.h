#pragma once
#include "hoText2.h"
#include "hoAudioManager.h"
#include "hoPrimitives.h"
#include "hoColor.h"
#include "hoBotones.h"

#include "hoSprite.h"


class Horchata {
public:
	Horchata();
	~Horchata();

	void Iniciar();

	hoPrimitives primitives;
	hoColor colorchata;
	hoAudioManager SonidosManager;
	Shader shader;
	hoBotones Boton;

private:

};

extern Horchata g_ho;