#ifndef __NIVEL_SCENE_H__
#define __NIVEL_SCENE_H__
#include "cocos2d.h"
#include "Arma.h"

class Nivel : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
															// es int temporalmente debe ser de 
																		//objetos de la clase ObjetosEscenario   float tiempoMax, int puntosMax, int objetosMoviles[], int posicionesX[], int posicionesY[]
	virtual bool init();

	void returnToScene(Ref *pSender);

	int ContadorArmas;

	int vueltasArsenal;
	cocos2d::Sprite* rectangulo;
	void preparaNivel(int n, int u);
	// implement the "static create()" method manually
	CREATE_FUNC(Nivel);

private:
	static int tiempoDelNivel;
	static int puntosDelNivel;
	cocos2d::Menu* menuArsenal;
	void muestraUnoMas(Ref *pSender);
	void muestraUnoMenos(Ref *pSender,int i);
	void borraArsenal(int superiorinferior);
	void goToTienda(Ref *pSender);
	void goToVestuario(Ref *pSender);
	void goToPause(Ref *pSender);
	void abrirArsenal(Ref *pSender);
	void simulacion(Ref *pSender);
	void displayArmasNivel();
};

#endif  
