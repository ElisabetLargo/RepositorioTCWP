#include "Global.h"
#include"proj.win32\Nivel.h"
#include"proj.win32\levelsMenuScene.h"



USING_NS_CC;


static Global* global = nullptr;

Global::Global(){
	//inicializar escenas a null
	 nivel = Nivel::createScene();
	 levelsMenuScene = LevelsMenuScene::createScene();

	 nivel->retain();
	 levelsMenuScene->retain();
	 creaArmas();
	 creaObjetosEscenario();
	 visibleSize = Director::getInstance()->getVisibleSize();
}

void Global::creaArmas()
{
	//provisional crea un array genérico, en un futuro hay que meter las armas 1 a una
	for (int i = 0; i < 10; i++){
		char* nombre = "espada Bastarda numero: ";
		nombre += i;
		Arma* armaaux = Arma::create("images/Armas/arma.png", 100, nombre, "punzante");
		armaaux->setColor(Color3B(i * 25, i * 25, i * 25));
		armasTotales.push_back(armaaux);
	}
	for (int i = 0; i < 20; i++) {
		char* nombre = "espada Bastarda numero: ";
		nombre += i;
		Arma* armaaux = Arma::create("images/Armas/arma.png", 100, nombre, "punzante");
		armaaux->setColor(Color3B(i * 11, i * 11, i * 11));
		armasArsenal.push_back(armaaux);
	}

}

void Global::creaObjetosEscenario()
{
	auto visiblesize = Director::getInstance()->getVisibleSize();
	//provisional crea un array genérico, en un futuro hay que meter los objetos 1 a 1
	for (int i = 0; i < 10; i++) {
		char* nombre = "Objeto Escenario numero: ";
		nombre += i;

		//ObjetosTotalesEscenarioPosiciones.push_back(&Vec2(((i + 1)*visiblesize.width) / 10, visiblesize.height / 2));
		ObjetoEscenario* objetoaux = ObjetoEscenario::create("images/ObjetosEscenario/Baul.png", 100, nombre);
		Vec2 punto = Vec2(((i + 1)*visiblesize.width) / 10 - objetoaux->getContentSize().width, visiblesize.height / 2);
		objetoaux->setPosition(punto);
		objetoaux->setColor(Color3B(i * 25, i * 25, i * 25));
		ObjetosTotalesEscenarios.push_back(objetoaux);
	}
}

Global* Global::getInstance(){

	if (!global){
		global = new Global();
	}

	return global;
}