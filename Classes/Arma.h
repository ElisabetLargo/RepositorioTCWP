#ifndef __ARMA_H__
#define __ARMA_H__
#include "cocos2d.h"


 
class Arma: public cocos2d::Sprite
{
public:
	Arma();
	~Arma();
	static Arma* create(const std::string &fileName,int daño, std::string nombre,std::string tipo);

	//void initOptions();

	void addListener();
	void touchEvent(cocos2d::Touch* touch, cocos2d::Point _p);
	void createMenuCompra();
	void closeMenuCompra();
	void hacerCompra();
private:
	int Daño;
	std::string Tipo;
	std::string Nombre;
	Arma* armaAComprar;

};

#endif //ARMA

