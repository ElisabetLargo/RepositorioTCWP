#include "Arma.h"
#include "Nivel.h"
#include"Global.h"

USING_NS_CC;

Arma::Arma( int daño, std::string nombre, std::string tipo)
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

Arma * Arma::create(cocos2d::Texture2D* t, int daño, std::string nombre, std::string tipo)
{
	Arma* arma = new Arma(daño,nombre,tipo);
	//Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(fileName);
	arma->initWithTexture(t);
	return arma;

		
	
	/*CC_SAFE_DELETE(arma);
	return NULL;*/
}

void Arma::EnableListener(bool b){
	listener->setEnabled(b);
}
void Arma::AddListener()
{
	listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(false);

	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event) {
		cocos2d::Point p = touch->getLocation();
		cocos2d::Rect rect = this->getBoundingBox();

		if (rect.containsPoint(p))
		{
			setPointY(p.y);

			return true;
		}

		return false;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event) {
		if (Global::getInstance()->juegoEnCurso && this->getPosition().y >300) Arma::arrastraArma(touch->getLocation());
	};
	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		Arma::TouchEvent(touch, touch->getLocation());
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);

}

void Arma::TouchEvent(cocos2d::Touch * touch, cocos2d::Point _p)
{
	//CCLOG("Has tocado un arma");

	accionTouch();
}

<<<<<<< HEAD
void Arma::accionTouch(){
	Point p = this->getPosition();
	if (p.y <300){

=======
void Arma::arrastraArma(cocos2d::Vec2 vector)
{
	this->setPosition(vector);
}

void Arma::accionTouch(){
	Point p = this->getPosition();
	if (p.y <300){
	CCLOG("El arma con daño : %d", this->daño);
>>>>>>> origin/Rama_Richi
		//CCLOG("Es para añadir a la lista de armas que vamos a usar");
		if (((Nivel*)Global::getInstance()->nivel)->ContadorArmas <5 && !this->enNivel){
		
			//CCLOG("Se puede añadir");
<<<<<<< HEAD
			CCLOG("El arma con daño : %d", this->daño);
			((Nivel*)Global::getInstance()->nivel)->ContadorArmas += 1;
			//llamar a global
			Global::getInstance()->creaArmasNivel(this);
=======

			((Nivel*)Global::getInstance()->nivel)->ContadorArmas += 1;
			//llamar a global
			Global::getInstance()->añadeArmasANivel(this->ClonarArma(this));
>>>>>>> origin/Rama_Richi
			this->enNivel = true;
		}
		else if (this->enNivel) CCLOG("ya esta metida");

		else{
		
			CCLOG("No puedes usar más");
		}
	}


	else {
		CCLOG("es para colocar");
<<<<<<< HEAD
=======
		if (!Global::getInstance()->juegoEnCurso) {
			Global::getInstance()->quitaArmaDeNivel(this);
		}
>>>>>>> origin/Rama_Richi
	}




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
	this->toqueY = y;
}

void Arma::setArma(Arma* arma)
{
	esteArma = arma;
}

Arma* Arma::getArma()
{
	return esteArma;
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

Arma* Arma::ClonarArma(Arma* a){

	Arma* nueva = Arma::create(a->getTexture(),a->daño,a->getNombre(),a->tipo);
<<<<<<< HEAD
=======
	nueva->clon = a;
>>>>>>> origin/Rama_Richi
	return nueva;
}

