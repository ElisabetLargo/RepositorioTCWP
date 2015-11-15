
#include "Nivel.h"


USING_NS_CC;

Scene* Nivel::createScene(float tiempoMax, int puntosMax, int objetosMoviles[], int posicionesX[], int posicionesY[])
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Nivel::create();

	// add layer as a child to scene
	scene->addChild(layer);


	/*
	//cargar objetos del escenario
	tiempoDelNivel = tiempoMax;
	puntosDelNivel = puntosMax;

	try{
		if (sizeof(objetosMoviles) != sizeof(posicionesX) != sizeof(posicionesY)) throw 1;
	}
	catch (int e){
		printf( "Exception: Arrays con diferentes tamaños");
	}
	*/
	/*
		//colocar los objetos del escenario
	for (int i = 0; i < sizeof(objetosMoviles); i++){

		objetosMoviles[i]->visible = true;
		objetosMoviles[i]->position(Point(posicionesX[i], posicionesY[i]));
		addChild(objetosMoviles[i], 2);
	}*/


	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Nivel::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();


	//menu
	auto startBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",
		CC_CALLBACK_1(Nivel::returnToScene, this));
	auto menu = Menu::create(startBtn, NULL);
	menu->setPosition(Point(visibleSize.width - 20, visibleSize.height - 20));
	addChild(startBtn, 2);




	//Fondo
	auto background = Sprite::create("images/Nivel/fondo_Nivel.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(background, 0);

	return true;
}



void Nivel::returnToScene(Ref *pSender){

	Director::getInstance()->popScene();
}


/*
void Nivel::abrirTienda(){

}


void Nivel::abrirVestuario(){

}


void Nivel::cerrarTienda(){

}


void Nivel::cerrarVestuario(){

}

*/