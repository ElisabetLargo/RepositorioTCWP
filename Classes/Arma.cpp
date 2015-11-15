#include "Arma.h"


USING_NS_CC;


Arma::Arma()
{
}


Arma::~Arma()
{
}

Arma * Arma::create(const std::string & fileName,int daño, std::string nombre, std::string tipo)
{
	Arma* arma = new Arma();
	arma->Daño = daño;
	arma->Nombre = nombre;
	arma->Tipo = tipo;

	arma->initWithFile(fileName);
		arma->autorelease();
		arma->addListener();

		return arma;
	
	/*CC_SAFE_DELETE(arma);
	return NULL;*/
}

void Arma::addListener()
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Point p = touch->getLocation();
		cocos2d::Rect rect = this->getBoundingBox();

		if (rect.containsPoint(p))
		{
			return true;
		}

		return false; 
	};
	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		Arma::touchEvent(touch,touch->getLocation());
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);

}

void Arma::touchEvent(cocos2d::Touch * touch, cocos2d::Point _p)
{
	createMenuCompra();
	CCLOG("Has tocado un arma");
}

void Arma::createMenuCompra()
{
	//crear menu de compra
}

void Arma::closeMenuCompra()
{
	//cerrar menu
}

void Arma::hacerCompra()
{
	//(WIP)
}



