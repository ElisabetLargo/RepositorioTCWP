#include "TiendaScene.h"
#include "Arma.h"
#include "Global.h"
#include "Nivel.h"
USING_NS_CC;

Scene* TiendaScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TiendaScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool TiendaScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//menu
	auto backBtn = MenuItemImage::create("images/TiendaScene/back_btn.png", "images/TiendaScene/back_btn.png",
		CC_CALLBACK_1(TiendaScene::returnToScene, this));

	auto menu = Menu::create(backBtn, NULL);
	menu->setPosition(Point(visibleSize.width - 20, visibleSize.height - 20));
	addChild(menu, 2);

	auto a�adeArmaBtn = MenuItemImage::create("images/Armas/arma.png", "images/Armas/arma.png",
		CC_CALLBACK_0(TiendaScene::compraArma, this));
	auto menu2 = Menu::create(a�adeArmaBtn, NULL);
	addChild(menu2, 2);



	//Fondo
	auto background = Sprite::create("images/TiendaScene/fondo_TiendaScene.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(background, 0);


	return true;
}

void TiendaScene::returnToScene(Ref *pSender){

	Director::getInstance()->popScene();
}

void TiendaScene::compraArma()
{
	int i = random(1, 9);
	Texture2D* t = Director::getInstance()->getTextureCache()->addImage("images/Armas/arma.png");
	Arma* armacomprada = Arma::create(t, 10000*i, "voladora", "punzante");
	armacomprada->setColor(Color3B(5, 50, 83));
	Global::getInstance()->armasArsenal.push_back(armacomprada);
	((Nivel*)(Global::getInstance()->nivel))->addChild(armacomprada,3);

}
