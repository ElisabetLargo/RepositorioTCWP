#ifndef __NIVEL_SCENE_H__
#define __NIVEL_SCENE_H__
#include "cocos2d.h"
#include "Arma.h"

class Nivel : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	// es int temporalmente debe ser de 
	virtual bool init();
	int ContadorArmas;
	//bool prueba = true;
	int vueltasArsenal;
	cocos2d::Sprite* rectangulo;
	void preparaNivel(int n, int u);
	// implement the "static create()" method manually
	CREATE_FUNC(Nivel);

private:
	static int tiempoDelNivel;
	static int puntosDelNivel;
	cocos2d::Menu* menuArsenal;
	//bool juegoEnCurso;

	void muestraUnoMas(Ref *pSender);
	void muestraUnoMenos(Ref *pSender,int i);
	void borraArsenal(int superiorinferior);
	void goToTienda(Ref *pSender);
	void goToVestuario(Ref *pSender);
	void goToPause(Ref *pSender);
	void abrirArsenal(Ref *pSender);
	void simulacion(Ref *pSender);
	void displayArmasNivel();
	void activaDesactivaBoton(cocos2d::MenuItemImage* boton, bool estado);
	void recorreArmas(int iterador, int posicion, int ancho, int alto, int iteraciones);
	void activaDesactivaArma(Arma* arma, bool estado);
	void quitaArmas();

	cocos2d::MenuItemImage* masBtn;
	cocos2d::MenuItemImage* menosBtn;
	cocos2d::MenuItemImage* tiendaBtn;
	cocos2d::MenuItemImage* pauseBtn;
	cocos2d::MenuItemImage* vestuarioBtn;
	cocos2d::MenuItemImage* arsenalBtn;
	cocos2d::MenuItemImage* simulacionBtn;



};

#endif  
