#include "LevelsMenuScene.h"
USING_NS_CC;

Scene* LevelsMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelsMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelsMenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//menu
	
	auto backBtn = MenuItemImage::create("images/LevelsScene/back_btn.png", "images/LevelsScene/back_btn.png",
		CC_CALLBACK_1(LevelsMenuScene::goToMenuStart, this));

	auto startNivelBtn = MenuItemImage::create("images/LevelsScene/back_btn.png", "images/LevelsScene/back_btn.png",
		CC_CALLBACK_1(LevelsMenuScene::goToNivel, this));


	auto menu = Menu::create(backBtn,startNivelBtn, NULL);
	menu->setPosition(Point(visibleSize.width - 20, visibleSize.height - 20));
	addChild(menu, 2);


	

	//Fondo
	auto background = Sprite::create("images/LevelsScene/fondo_LevelsScene.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(background, 0);

	return true;
}


void LevelsMenuScene::goToMenuStart(Ref *pSender){

	Director::getInstance()->popScene();
}

void LevelsMenuScene::goToNivel(Ref *pSender){

}