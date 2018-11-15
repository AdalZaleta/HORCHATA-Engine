#include "hoAudioManager.h"
#include <iostream>
#include <windows.h>



hoAudioManager::hoAudioManager()
{

}


hoAudioManager::~hoAudioManager()
{

}

void hoAudioManager::InitEngine()
{
	// Creamos el Engine
	try {
		engineSonido = createIrrKlangDevice();
	}

	catch (int e)
		{
			std::cout << "no hay bocina " + e << std::endl;
		}
	}

// Sonidos
ISound* hoAudioManager::Play(const char* _clip)
{
	// Variable para guardar el sonido a reproducir
	ISound* sonido;

	// Reproducimos el clip recibido y lo guardamos
	sonido = engineSonido->play2D(_clip, false, false, true);

	return sonido;
}

void hoAudioManager::Stop(ISound* _clip)
{
	// Detiene el sonido recibido
	_clip->stop();
}

void hoAudioManager::IsPause(ISound* _clip, bool _estado)
{
	// Pausa o reanuda el sonido recibido
	_clip->setIsPaused(_estado);
}

// Musica Background
void hoAudioManager::PlayBackgroundMusic(const char* _BackgroundMusic)
{
	// Si no hay musica de background
	if (background == NULL)
	{
		// Reproduciminos el nuevo
		background = engineSonido->play2D(_BackgroundMusic, true, false, true);
	}
	else
	{
		// Detenemos el anterior
		background->stop();
		// Reproducimos el nuevo sonido
		background = engineSonido->play2D(_BackgroundMusic, true,false,true);
	}
}

void hoAudioManager::StopBackgroundMusic()
{
	// Detiene la musica de BackGround
	if(background == NULL)
	{
		printf("No hay ningun background reproduciendose");
	}
	else
	{
		background->stop();
	}
}

void hoAudioManager::PauseBackgroundMusic(bool _estado)
{
	// Pausa o reanuda la musica de BackGround
	background->setIsPaused(_estado);
}

//Todos Los Sonidos

void hoAudioManager::StopAllSounds()
{
	// Detiene todos los sonidos que se esten reproduciendo
	engineSonido->stopAllSounds();
}

void hoAudioManager::PauseAllSounds(bool _estado)
{
	// Pausa o reanuda todos los sonidos que tenga el engine
	engineSonido->setAllSoundsPaused(_estado);
}

//Volumen
void hoAudioManager::SetVolume(float _volumen)
{
	// Guardamos el volumen de BackGround
	float volumenBackground;
	volumenBackground = background->getVolume();

	// Seteamos el volumen de todos los sonidos
	engineSonido->setSoundVolume(_volumen);
	
	// Mantenemos el volumen de BackGround
	background->setVolume(volumenBackground);
}

void hoAudioManager::SetBackGroundVolume(float _volumen)
{
	// Cambiamos el volumen de BackGround
	background->setVolume(_volumen);
}
