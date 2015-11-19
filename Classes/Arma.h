#ifndef __ARMA_H__
#define __ARMA_H__
#include "cocos2d.h"



class Arma : public cocos2d::Sprite
{
public:
	Arma(int da�o, std::string nombre, std::string tipo);
	~Arma();
	static Arma* create(cocos2d::Texture2D* t, int da�o, std::string nombre, std::string tipo);

	//void initOptions(cocos2d::Rect area);

	void AddListener();
	void EnableListener(bool b);
	void TouchEvent(cocos2d::Touch* touch, cocos2d::Point _p);
	void arrastraArma(cocos2d::Vec2 vector);
	void CreateMenuCompra();
	void CloseMenuCompra();
	void HacerCompra();
	void setPointY(int y);
<<<<<<< HEAD
	Arma* ClonarArma(Arma*a);

=======
	void setDesdeTienda(bool estado);
>>>>>>> origin/Rama_Richi

	void setArma(Arma* arma);

	Arma* clon;
	Arma* getArma();
	Arma* ClonarArma(Arma*a);

	std::string getTipo();
	std::string getNombre();
	int getDa�o();
	bool getDesdeTienda();
<<<<<<< HEAD
	void setDesdeTienda(bool estado);
=======

>>>>>>> origin/Rama_Richi
	bool enNivel = false;

private:
	bool desdeTienda;
	int da�o;
	int toqueY;
	cocos2d::EventListenerTouchOneByOne* listener;
	//cocos2d::Rect areaArma;
	std::string tipo;
	std::string nombre;
<<<<<<< HEAD
	Arma* armaAComprar;
=======
	Arma* esteArma;

>>>>>>> origin/Rama_Richi
	void accionTouch();


};

#endif //ARMA

