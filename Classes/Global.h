#ifndef __GLOBAL_H__
#define __GLOBAL_H__
#include "cocos2d.h"
#include "Arma.h"
#include "ObjetoEscenario.h"

//Singleton

class Global 
{
public:
	static Global* getInstance();
	cocos2d::Scene* nivel;
	cocos2d::Scene* levelsMenuScene;

	std::vector<Arma*> armasTotales;
	std::vector<Arma*> armasArsenal;
	std::vector<Arma*> ArmasNivel;

	std::vector<ObjetoEscenario*> ObjetosTotalesEscenarios;
	cocos2d::Size visibleSize;
<<<<<<< HEAD
	void creaArmasNivel(Arma* a);
	void vaciaArmasNivel();
	void quitaArmaDeNivel(Arma* a);
=======
	void añadeArmasANivel(Arma* a);
	void vaciaArmasNivel();
	void quitaArmaDeNivel(Arma* a);
	bool juegoEnCurso;
>>>>>>> origin/Rama_Richi

	//std::vector<Vec2*> ObjetosTotalesEscenarioPosiciones;
	


private:
	Global();
	~Global();
	void creaArmas();
	void creaObjetosEscenario();
	


};

#endif //ARMA

