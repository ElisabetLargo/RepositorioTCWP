#ifndef __ARMA_H__
#define __ARMA_H__
#include "cocos2d.h"



class Arma : public cocos2d::Sprite
{
public:
	Arma(int daño, std::string nombre, std::string tipo);
	~Arma();
	static Arma* create(cocos2d::Texture2D* t, int daño, std::string nombre, std::string tipo);

	//void initOptions(cocos2d::Rect area);

	void AddListener();
	void EnableListener(bool b);
	void TouchEvent(cocos2d::Touch* touch, cocos2d::Point _p);
	void CreateMenuCompra();
	void CloseMenuCompra();
	void HacerCompra();
	void setPointY(int y);
	Arma* ClonarArma(Arma*a);


	void setArma(Arma* arma);

	Arma* punteroaClon();
	Arma* getArma();

	std::string getTipo();
	std::string getNombre();
	int getDaño();
	bool getDesdeTienda();
	void setDesdeTienda(bool estado);
	bool enNivel = false;
	Arma* clon;
private:
	bool desdeTienda;
	int daño;
	int toqueY;
	cocos2d::EventListenerTouchOneByOne* listener;
	//cocos2d::Rect areaArma;
	std::string tipo;
	std::string nombre;
	Arma* esteArma;

	void accionTouch();


};

#endif //ARMA

