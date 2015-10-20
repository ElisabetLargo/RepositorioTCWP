#include "MainMenuScene.h"
#include "proj.win32/CreditosScene.h"
#include"proj.win32/AjustesScene.h"
#include "proj.win32/MenuStartScene.h"



USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    

	//Menu
	auto menuTitle = MenuItemImage::create("images/MainMenuScene/Title.png", "images/MainMenuScene/Title.png");
	auto creditosBtn = MenuItemImage::create("images/MainMenuScene/creditos_btn.png", "images/MainMenuScene/creditos_btn.png",
			CC_CALLBACK_1(MainMenuScene::goToCreditos,this));
	auto ajustesBtn = MenuItemImage::create("images/MainMenuScene/ajustes_btn.png", "images/MainMenuScene/ajustes_btn.png",
			CC_CALLBACK_1(MainMenuScene::goToAjustes,this));
	auto startBtn = MenuItemImage::create("images/MainMenuScene/start_btn.png", "images/MainMenuScene/start_btn.png",
			CC_CALLBACK_1(MainMenuScene::goToMenuStart,this));

	auto menu = Menu::create(menuTitle,creditosBtn,ajustesBtn,startBtn,NULL);
	menu->alignItemsVertically();
	addChild(menu,1);


	//Fondo
	auto background = Sprite::create("images/MainMenuScene/fondo_mainMenu.png");
	background->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
	addChild(background, 0);
    
    return true;
}
void MainMenuScene::goToCreditos(Ref *pSender){

	auto scene = CreditosScene::createScene();

	Director::getInstance()->pushScene(scene);
}


void MainMenuScene::goToAjustes(Ref *pSender){

	auto scene = AjustesScene::createScene();

	Director::getInstance()->pushScene(scene);

}

void MainMenuScene::goToMenuStart(Ref *pSender){

	auto scene = MenuStartScene::createScene();

	Director::getInstance()->pushScene(scene);
}

