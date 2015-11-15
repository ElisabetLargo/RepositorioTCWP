#ifndef __ARMA_H__
#define __ARMA_H__
#include "cocos2d.h"



class Arma : public cocos2d::Sprite
{
public:
	Arma(const std::string & fileName, int daño, std::string nombre, std::string tipo);
	~Arma();
	static Arma* create(const std::string &fileName, int daño, std::string nombre, std::string tipo);

	//void initOptions(cocos2d::Rect area);

	void AddListener();
	void TouchEvent(cocos2d::Touch* touch, cocos2d::Point _p);
	void CreateMenuCompra();
	void CloseMenuCompra();
	void HacerCompra();
	void setPointY(int y);


	void setArma(Arma* arma);
	Arma* getArma();

	std::string getTipo();
	std::string getNombre();
	int getDaño();
	bool getDesdeTienda();
	void setDesdeTienda(bool estado);

private:
	bool desdeTienda;
	int daño;
	int toqueY;
	//cocos2d::Rect areaArma;
	std::string tipo;
	std::string nombre;
	Arma* armaAComprar;


};

#endif //ARMA

