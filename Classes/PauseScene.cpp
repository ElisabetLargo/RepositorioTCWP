#include "PauseScene.h"
#include "proj.win32\LogrosScene.h"
#include"MainMenuScene.h"


USING_NS_CC;

Scene* PauseScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PauseScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PauseScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();


	return true;
}


void PauseScene::resumeGameScene(Ref *pSender){

	Director::getInstance()->popScene();
}


void PauseScene::goToMainMenuScene(Ref *pSender){

	auto scene = MainMenuScene::createScene();

	Director::getInstance()->popScene();
	Director::getInstance()->replaceScene(scene);
}


void PauseScene::goToLogrosScene(Ref *pSender){

	auto scene = LogrosScene::createScene();

	Director::getInstance()->replaceScene(scene);
}