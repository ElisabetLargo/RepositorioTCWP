
#include "Nivel.h"
#include "proj.win32\TiendaScene.h"
#include "proj.win32\VestuarioScene.h"
#include "proj.win32\PauseScene.h"
#include "Global.h"

USING_NS_CC;

#define ANCHOARSENAL ((Global::getInstance()->visibleSize.width*4)/6);
#define ALTOARSENAL ((Global::getInstance()->visibleSize.height)/8);



Scene* Nivel::createScene()  //prueba. En realidad debe ser(float tiempoMax, int puntosMax, int objetosMoviles[], int posicionesX[], int posicionesY[])
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Nivel::create();

	// add layer as a child to scene
	scene->addChild(layer);

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
	/*	tiempoDelNivel = tiempoMax;
	puntosDelNivel = puntosMax;*/
	return true;
}


void Nivel::preparaNivel(int n, int u){  // nivel=numero nivel para colocar

	Size visibleSize = Director::getInstance()->getVisibleSize();
	vueltasArsenal = 0;
	rectangulo = Sprite::create("images/Nivel/rectangle.png");
	auto ancho = ANCHOARSENAL;
	auto alto = ALTOARSENAL;


	rectangulo->setScaleX(ancho/rectangulo->getContentSize().width);
	rectangulo->setScaleY(alto/rectangulo->getContentSize().height);
	rectangulo->setPosition(Point(ancho/2, alto/2));
	rectangulo->setVisible(false);
	addChild(rectangulo, 2);


	//FONDO Y BOTONES GENERALES

	auto pauseBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::goToPause, this));
	auto tiendaBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::goToTienda, this));
	tiendaBtn->setColor(Color3B(255, 0, 0));
	auto vestuarioBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::goToVestuario, this));
	vestuarioBtn->setColor(Color3B(0, 255, 0));

	auto menu1 = Menu::create(pauseBtn, tiendaBtn, vestuarioBtn, NULL);
	menu1->setPosition(Point(visibleSize.width / 2, visibleSize.height - visibleSize.height / 40));
	menu1->alignItemsHorizontallyWithPadding(visibleSize.height / 3);
	addChild(menu1, 1);

	auto arsenalBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::abrirArsenal, this));
	arsenalBtn->setColor(Color3B(100, 100, 100));

	auto menu2 = Menu::create(arsenalBtn, NULL);
	menu2->setPosition(Point(visibleSize.width / 2 + visibleSize.width / 3, visibleSize.height / 40));
	addChild(menu2, 1);
	

	auto masBtn = MenuItemImage::create("images/LevelsMenuScene/Flecha.png", "images/LevelsMenuScene/Flecha.png",CC_CALLBACK_1(Nivel::muestraUnoMas, this));

	auto ancho1 = rectangulo->getContentSize().width;
	auto alto1 = Global::getInstance()->visibleSize.height / 16;

	masBtn->setScaleX(-ancho1/(masBtn->getContentSize().width*11));
	masBtn->setScaleY(alto1 / masBtn->getContentSize().height);
	masBtn->setPosition((-visibleSize.width / 2.0)+ancho-45, -visibleSize.height/2.0 +30);
	auto menosBtn = MenuItemImage::create("images/LevelsMenuScene/Flecha.png", "images/LevelsMenuScene/Flecha.png",CC_CALLBACK_1(Nivel::muestraUnoMenos, this,vueltasArsenal));

	menosBtn->setScaleX(ancho1 / (menosBtn->getContentSize().width*11));
	menosBtn->setScaleY(alto1 / menosBtn->getContentSize().height);
	menosBtn->setPosition((-visibleSize.width / 2.0)+40, -visibleSize.height / 2.0 + 30);

	menuArsenal = Menu::create(masBtn, menosBtn,NULL);
	addChild(menuArsenal, 3);
	menuArsenal->setVisible(false);

	for (int i = 0; i < Global::getInstance()->armasArsenal.size(); i++) {
		Arma* arma = Global::getInstance()->armasArsenal[i];
		addChild(arma, 3);
		arma->setVisible(false);
	}



	auto background = Sprite::create("images/Nivel/fondo_NivelScene.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(background, 0);

	/*____________________________________________________________________________________________________________*/


	/*
	//OBJETOS DEL ESCENARIO


	try{
	if (sizeof(objetosMoviles) != sizeof(posicionesX) != sizeof(posicionesY)) throw 1;
	}
	catch (int e){
	printf( "Exception: Arrays con diferentes tamaños");
	}
	*/
	//       n= indice primer objeto del nivel    u=numero deobjetos a colocar en el nivel
	for (int i = n; i < u; i++){
		addChild(Global::getInstance()->ObjetosTotalesEscenarios[i]);
		Global::getInstance()->ObjetosTotalesEscenarios[i]->setVisible(true);
	//objetosMoviles[i]->position(Point(posicionesX[i], posicionesY[i]));
	//addChild(objetosMoviles[i], 2);
	}

}

void Nivel::muestraUnoMas(Ref *pSender)
{
	if (vueltasArsenal == Global::getInstance()->armasArsenal.size()) vueltasArsenal = 0;
	auto ancho = ANCHOARSENAL;
	auto alto = ALTOARSENAL;

	auto size = vueltasArsenal;
	auto iterador = 0;
	borraArsenal(-5);
	for (vueltasArsenal; vueltasArsenal < size + 5; vueltasArsenal++) {
		iterador++;
		Arma* arma = Global::getInstance()->armasArsenal[vueltasArsenal];
		arma->setPosition((((iterador + 1)*ancho) / 7) - arma->getContentSize().width, alto / 2);
		arma->setVisible(true);
		
	}

	if (vueltasArsenal+1 >= Global::getInstance()->armasArsenal.size()) vueltasArsenal = 0;

}

void Nivel::muestraUnoMenos(Ref *pSender,int i)
{

	((vueltasArsenal - 10) < 0)?vueltasArsenal = Global::getInstance()->armasArsenal.size() - 5: vueltasArsenal -= 10;
	
	auto ancho = ANCHOARSENAL;
	auto alto = ALTOARSENAL;
	auto size = vueltasArsenal;
	auto iterador = 0;
	borraArsenal(5);
	for (vueltasArsenal; vueltasArsenal < size + 5; vueltasArsenal++) {
		iterador++;

		Arma* arma = Global::getInstance()->armasArsenal[vueltasArsenal];
		arma->setPosition((((iterador + 1)*ancho) / 7)-arma->getContentSize().width, alto / 2);
		arma->setVisible(true);

	}

	if (vueltasArsenal > Global::getInstance()->armasArsenal.size()) vueltasArsenal = 0;

}

void Nivel::borraArsenal(int superiorinferior)
{
	auto aux = 0;
	if (superiorinferior < 0) {
		((vueltasArsenal + superiorinferior) <0) ? aux = Global::getInstance()->armasArsenal.size() - 5 : aux = vueltasArsenal - 5;
	}
	else
		((vueltasArsenal + superiorinferior)>=Global::getInstance()->armasArsenal.size()) ? aux = 0 : aux = vueltasArsenal + 5;

	auto aux2 = aux;
	for (aux; aux < aux2+5; aux++) {
		//CCLOG("borrador vale %d ", aux);
		Arma* arma = Global::getInstance()->armasArsenal[aux];
		arma->setVisible(false);
	}

}

void Nivel::goToTienda(Ref *pSender){
	auto scene = TiendaScene::createScene();
	Director::getInstance()->pushScene(scene);
}


void Nivel::goToVestuario(Ref *pSender){
	auto scene = VestuarioScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void Nivel::goToPause(Ref *pSender){

	auto scene = PauseScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void Nivel::abrirArsenal(Ref *pSender){
	if (rectangulo->isVisible()) {
		rectangulo->setVisible(false);
		auto aux = 0;

		for (int i = 0; i < Global::getInstance()->armasArsenal.size(); i++) {
			Arma* arma = Global::getInstance()->armasArsenal[i];
			if(arma->isVisible())arma->setVisible(false);
		}
		((vueltasArsenal - 5) < 0) ? vueltasArsenal = Global::getInstance()->armasArsenal.size() - 5 : vueltasArsenal -= 5;
		menuArsenal->setVisible(false);
	}
	else {
		menuArsenal->setVisible(true);
		rectangulo->setVisible(true);
		muestraUnoMas(this);
	} 

	
}