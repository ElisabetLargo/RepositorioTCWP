#ifndef __LevelsMenu_SCENE_H__
#define __LevelsMenu_SCENE_H__
#include "cocos2d.h"

class LevelsMenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LevelsMenuScene);

	void goToMenuStart(Ref *pSender);
	void goToNivel(Ref *pSender);
	void addlistener();
	void touchEvent(cocos2d::Touch * touch, cocos2d::Point _p);


	
	int mundoSeleccionado; //Será la posicion del sprite del nivel en el array
	// sirve para identificar el nivel

	std::vector<cocos2d::Sprite*> imagenesMundos;
	void muestraUnoMas(Ref *pSender);
	void muestraUnoMenos(Ref *pSender); //funciones para la seleccion del nivel con dos botones fleacha

private:
	


};

#endif  
