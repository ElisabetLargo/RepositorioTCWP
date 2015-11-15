#include "Arma.h"

USING_NS_CC;

Arma::Arma(const std::string & fileName, int daño, std::string nombre, std::string tipo)
{

	this->daño = daño;
	this->nombre = nombre;
	this->tipo = tipo;
	this->setArma(this);
	this->AddListener();
	desdeTienda = false;
	this->retain();
}

Arma::~Arma()
{
}

Arma * Arma::create(const std::string & fileName, int daño, std::string nombre, std::string tipo)
{
	Arma* arma = new Arma(fileName,daño,nombre,tipo);
	Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(fileName);
	arma->initWithTexture(texture);
	return arma;

		
	
	/*CC_SAFE_DELETE(arma);
	return NULL;*/
}


void Arma::AddListener()
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Point p = touch->getLocation();

	
		cocos2d::Rect rect = this->getBoundingBox();

		if (rect.containsPoint(p))
		{
			setPointY(touch->getLocation().y);
			return true;
		}

		return false;
	};
	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		Arma::TouchEvent(touch, touch->getLocation());
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);

}

void Arma::TouchEvent(cocos2d::Touch * touch, cocos2d::Point _p)
{
	CreateMenuCompra();
	CCLOG("Has tocado un arma");
}

void Arma::CreateMenuCompra()
{
	//crear menu de compra
}

void Arma::CloseMenuCompra()
{
	//cerrar menu
}

void Arma::HacerCompra()
{
	//(WIP)
}

void Arma::setPointY(int y)
{

	CCLOG("MI DAÑO ES: %d", this->getDaño());
	this->toqueY = y;
}

void Arma::setArma(Arma* arma)
{
	armaAComprar = arma;
}

Arma* Arma::getArma()
{
	return armaAComprar;
}

std::string Arma::getTipo()
{
	return tipo;
}

std::string Arma::getNombre()
{
	return nombre;
}

int Arma::getDaño()
{
	return this->daño;
}

bool Arma::getDesdeTienda()
{
	return desdeTienda;
}

void Arma::setDesdeTienda(bool estado)
{
	desdeTienda = estado;
}



