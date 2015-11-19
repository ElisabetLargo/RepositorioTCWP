
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
	
	ContadorArmas = 0;
	Global::getInstance()->juegoEnCurso = false;
	rectangulo->setScaleX(ancho/rectangulo->getContentSize().width);
	rectangulo->setScaleY(alto/rectangulo->getContentSize().height);
	rectangulo->setPosition(Point(ancho/2, alto/2));
	rectangulo->setVisible(false);
	addChild(rectangulo, 2);


	//Arma de prueba arriba
	Texture2D* t = Director::getInstance()->getTextureCache()->addImage("images/Armas/arma.png");
	Arma* a = Arma::create(t, 100, "voladora", "punzante");
	a->setColor(Color3B(5,50,83));
	addChild(a, 4);
	a->setPosition(Point(400,500));


	//FONDO Y BOTONES GENERALES

	auto pauseBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::goToPause, this));
	auto tiendaBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::goToTienda, this));
	tiendaBtn->setColor(Color3B(255, 0, 0));
	auto vestuarioBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png",CC_CALLBACK_1(Nivel::goToVestuario, this));
	vestuarioBtn->setColor(Color3B(0, 255, 0));

	auto menu1 = Menu::create(pauseBtn, tiendaBtn, vestuarioBtn, NULL);
	menu1->setPosition(Point(150, visibleSize.height - visibleSize.height / 40));
	menu1->alignItemsHorizontallyWithPadding(30);
	addChild(menu1, 1);

	auto arsenalBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png", CC_CALLBACK_1(Nivel::abrirArsenal, this));
	arsenalBtn->setColor(Color3B(100, 100, 100));
	auto simulacionBtn = MenuItemImage::create("images/Nivel/back_btn.png", "images/Nivel/back_btn.png", CC_CALLBACK_1(Nivel::simulacion, this));
	simulacionBtn->setColor(Color3B(150, 50, 150));

	auto menu2 = Menu::create(arsenalBtn,simulacionBtn, NULL);
	menu2->setPosition(Point(visibleSize.width / 2 + visibleSize.width / 3, visibleSize.height / 40));
	menu2->alignItemsHorizontallyWithPadding(30);
	addChild(menu2, 1);
	

	masBtn = MenuItemImage::create("images/LevelsMenuScene/Flecha.png", "images/LevelsMenuScene/Flecha.png",CC_CALLBACK_1(Nivel::muestraUnoMas, this));

	auto ancho1 = rectangulo->getContentSize().width;
	auto alto1 = Global::getInstance()->visibleSize.height / 16;

	masBtn->setScaleX(-ancho1/(masBtn->getContentSize().width*11));
	masBtn->setScaleY(alto1 / masBtn->getContentSize().height);
	masBtn->setPosition((-visibleSize.width / 2.0)+ancho-45, -visibleSize.height/2.0 +30);
	menosBtn = MenuItemImage::create("images/LevelsMenuScene/Flecha.png", "images/LevelsMenuScene/Flecha.png",CC_CALLBACK_1(Nivel::muestraUnoMenos, this,vueltasArsenal));

	menosBtn->setScaleX(ancho1 / (menosBtn->getContentSize().width*11));
	menosBtn->setScaleY(alto1 / menosBtn->getContentSize().height);
	menosBtn->setPosition((-visibleSize.width / 2.0)+40, -visibleSize.height / 2.0 + 30);

	menuArsenal = Menu::create(masBtn, menosBtn,NULL);
	addChild(menuArsenal, 3);
	menuArsenal->setVisible(false);

	for (int i = 0; i < Global::getInstance()->armasArsenal.size(); i++) {
		Arma* arma = Global::getInstance()->armasArsenal[i];
		arma->enNivel = false;
		addChild(arma, 3);
		arma->setVisible(false);
	}



	auto background = Sprite::create("images/Nivel/fondo_NivelScene.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(background, 0);

	/*____________________________________________________________________________________________________________*/

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

	auto ancho = ANCHOARSENAL;
	auto alto = ALTOARSENAL;

	auto iterador = 0;
	auto posicion = 0;

	if (Global::getInstance()->armasArsenal.size()>5) {		
		borraArsenal(-5);
		recorreArmas(iterador, posicion, ancho, alto,5);
	}
	else {
		recorreArmas(iterador, posicion, ancho, alto, Global::getInstance()->armasArsenal.size());
	}
	CCLOG("vueltasarsenal vale %d", vueltasArsenal);
}

void Nivel::muestraUnoMenos(Ref *pSender,int i)
{
	auto iterador = 0;
	auto posicion = 0;

	auto ancho = ANCHOARSENAL;
	auto alto = ALTOARSENAL;
	Global::getInstance()->armasArsenal.size() > 5 ? CCLOG("true") : CCLOG("false");
	if(Global::getInstance()->armasArsenal.size()>5){
		CCLOG("Si entro");

		int max = 0;
		Global::getInstance()->armasArsenal.size() >10 ?  max = 10: max =5;
		borraArsenal(5);

		((vueltasArsenal - max) <= 0) ? vueltasArsenal = Global::getInstance()->armasArsenal.size() - 5 : vueltasArsenal -= 10;
		(vueltasArsenal < 0) ? vueltasArsenal = Global::getInstance()->armasArsenal.size()- vueltasArsenal*(-1):vueltasArsenal;

		recorreArmas(iterador, posicion, ancho, alto,5);
		if (vueltasArsenal > Global::getInstance()->armasArsenal.size()) vueltasArsenal = 0;
		CCLOG("vueltasarsenal vale %d", vueltasArsenal);
	}
	else {

	}


}

void Nivel::borraArsenal(int superiorinferior)
{
	auto aux = 0;


		(vueltasArsenal ==0) ? aux = Global::getInstance()->armasArsenal.size()-1 : aux = vueltasArsenal-1;
		auto iterador = aux;
		auto armasborradas = 0;;

		while (armasborradas<5){
			if (iterador <0){
				iterador = Global::getInstance()->armasArsenal.size()-1;
			}
			Arma* arma = Global::getInstance()->armasArsenal[iterador];
			activaDesactivaArma(arma,false);
			CCLOG("borro la %d", iterador);
			iterador--;
			armasborradas++;

		}

}

void Nivel::goToTienda(Ref *pSender){
	if(rectangulo->isVisible())abrirArsenal(this);
	vueltasArsenal = 0;
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
	if (Global::getInstance()->armasArsenal.size() > 5) {
		activaDesactivaBoton(masBtn, true);
		activaDesactivaBoton(menosBtn, true);
	}
	else {
		activaDesactivaBoton(masBtn, false);
		activaDesactivaBoton(menosBtn, false);
	}

	if (rectangulo->isVisible()) {
		rectangulo->setVisible(false);
		auto aux = 0;

		for (int i = 0; i < Global::getInstance()->armasArsenal.size(); i++) {
			Arma* arma = Global::getInstance()->armasArsenal[i];
			if(arma->isVisible())arma->setVisible(false);
			arma->EnableListener(false);
		}
		vueltasArsenal = 0;
		menuArsenal->setVisible(false);
	}
	else {
		menuArsenal->setVisible(true);
		rectangulo->setVisible(true);
		muestraUnoMas(this);
	} 
}


void Nivel::simulacion(Ref *pSender){

	Global::getInstance()->juegoEnCurso = true;
	if (ContadorArmas >= 5){
		CCLOG("Empieza la simulacion");
	}
	else{
		CCLOG("Aun puedes usar más armas");
	}
	
}

void Nivel::displayArmasNivel(){

	for (int i = Global::getInstance()->ArmasNivel.size(); i >0 ; i--){
		if (Global::getInstance()->ArmasNivel[i] != nullptr){
			
		}
	}

}

void Nivel::activaDesactivaBoton(MenuItemImage* boton, bool estado)
{
	boton->setEnabled(estado);
	boton->setVisible(estado);
}

void Nivel::recorreArmas(int iterador,int posicion,int ancho,int alto,int iteraciones)
{

	while (iterador < iteraciones) {
		posicion++;
		if (vueltasArsenal == Global::getInstance()->armasArsenal.size()) vueltasArsenal = 0;
		Arma* arma = Global::getInstance()->armasArsenal[vueltasArsenal];
		arma->setPosition((((posicion + 1)*ancho) / 7) - arma->getContentSize().width, alto / 2 + 2 * vueltasArsenal);
		activaDesactivaArma(arma, true);
		CCLOG("muestro la %d", vueltasArsenal);

		iterador++;
		vueltasArsenal++;


	}
}

void Nivel::activaDesactivaArma(Arma * arma, bool estado)
{
	arma->setVisible(estado);
	arma->EnableListener(estado);
}

int Nivel::getEnCurso()
{
	return 1;
}
