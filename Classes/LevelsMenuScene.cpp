#include "LevelsMenuScene.h"
#include "Nivel.h"
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
	//meter imagenes mundos en array
	Sprite* mundo1 = Sprite::create("images/LevelsMenuScene/mundo1.png");
	imagenesMundos.push_back(mundo1);
	Sprite* mundo2 = Sprite::create("images/LevelsMenuScene/mundo2.png");
	imagenesMundos.push_back(mundo2);
	Sprite* mundo3 = Sprite::create("images/LevelsMenuScene/mundo3.png");
	imagenesMundos.push_back(mundo3);
	Sprite* mundo4 = Sprite::create("images/LevelsMenuScene/mundo1.png");
	imagenesMundos.push_back(mundo4);
	Sprite* mundo5 = Sprite::create("images/LevelsMenuScene/mundo2.png");
	imagenesMundos.push_back(mundo5);

	mundoSeleccionado = 0;


	for (int i = 0; i < 5; i++){

		imagenesMundos[i]->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
		addChild(imagenesMundos[i],2);
		if (i+1 != 1) imagenesMundos[i]->setVisible(false);
	}
	
	
	//menu
	
	auto backBtn = MenuItemImage::create("images/LevelsMenuScene/back_btn.png", "images/LevelsScene/back_btn.png",
		CC_CALLBACK_1(LevelsMenuScene::goToMenuStart, this));

	auto startNivelBtn = MenuItemImage::create("images/LevelsMenuScene/back_btn.png", "images/LevelsScene/back_btn.png",
		CC_CALLBACK_1(LevelsMenuScene::goToNivel, this));
	startNivelBtn->setColor(Color3B(1,1,1));

	auto menu1 = Menu::create(backBtn,startNivelBtn, NULL);
	menu1->alignItemsHorizontallyWithPadding(visibleSize.width / 2);
	menu1->setPositionY(10);
	addChild(menu1, 2);

	
	auto masBtn = MenuItemImage::create("images/LevelsMenuScene/Flecha.png", "images/LevelsMenuScene/Flecha.png", 
		CC_CALLBACK_1(LevelsMenuScene::muestraUnoMas,this));
	masBtn->setScaleX(-1);

	auto menosBtn = MenuItemImage::create("images/LevelsMenuScene/Flecha.png", "images/LevelsMenuScene/Flecha.png",
		CC_CALLBACK_1(LevelsMenuScene::muestraUnoMenos, this));

	auto menu2 = Menu::create( menosBtn,masBtn, NULL);
	menu2->alignItemsHorizontallyWithPadding(visibleSize.width / 2);
	menu2->setPositionY(visibleSize.height-50);
	addChild(menu2, 2);
	//Fondo
	auto background = Sprite::create("images/LevelsScene/fondo_LevelsScene.png");
	background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	addChild(background, 0);

	addlistener();
	return true;
}


void LevelsMenuScene::goToMenuStart(Ref *pSender){

	Director::getInstance()->popScene();
}

void LevelsMenuScene::goToNivel(Ref *pSender){
	CCLOG("voy a añadir un nivel");
	/*auto scene = Nivel::createScene();
	Director::getInstance()->pushScene(scene);*/
}

void LevelsMenuScene::addlistener()
{
	{

		auto listener = cocos2d::EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(true);
		listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
			cocos2d::Point p = touch->getLocation();
			cocos2d::Rect rect =Rect(115,80, 568, 444);

			if (rect.containsPoint(p))
			{
				return true;
			}

			return false;
		};
		listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
		{
			LevelsMenuScene::touchEvent(touch, touch->getLocation());
		};

		cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);

	}
}

void LevelsMenuScene::touchEvent(cocos2d::Touch * touch, cocos2d::Point _p)
{
	LevelsMenuScene::goToNivel(this);
		
}

void  LevelsMenuScene::muestraUnoMas(Ref *pSender){
	if (mundoSeleccionado < 4){
	
		imagenesMundos[mundoSeleccionado]->setVisible(false);
		mundoSeleccionado += 1;
		imagenesMundos[mundoSeleccionado]->setVisible(true);
	}
	else {
		imagenesMundos[mundoSeleccionado]->setVisible(false);
		mundoSeleccionado = 0;
		imagenesMundos[mundoSeleccionado]->setVisible(true);

	}
}


void  LevelsMenuScene::muestraUnoMenos(Ref *pSender){
	if (mundoSeleccionado > 0){

		imagenesMundos[mundoSeleccionado]->setVisible(false);
		mundoSeleccionado -= 1;
		imagenesMundos[mundoSeleccionado]->setVisible(true);
	}
	else {
		imagenesMundos[mundoSeleccionado]->setVisible(false);
		mundoSeleccionado = 4;
		imagenesMundos[mundoSeleccionado]->setVisible(true);

	}

}