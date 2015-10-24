#ifndef __NIVEL_SCENE_H__
#define __NIVEL_SCENE_H__
#include "cocos2d.h"

class Nivel : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(float tiempoMax, int puntosMax, int objetosMoviles[], int posicionesX[], int posicionesY[]);
																		// es int temporalmente debe ser de 
																		//objetos de la clase ObjetosEscenario
	virtual bool init();
	void returnToScene(Ref *pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(Nivel);

/*private:
	static int tiempoDelNivel;
	static int puntosDelNivel;

	void abrirTienda();
	void abrirVestuario();
	void cerrarTienda();
	void cerrarVestuario();*/

};

#endif  
