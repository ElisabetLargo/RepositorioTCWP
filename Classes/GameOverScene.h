#ifndef __GameOver_SCENE_H__
#define __GameOver_SCENE_H__
#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void retryLevel(Ref *pSender);
	void goToMenuStartScene(Ref * pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(GameOverScene);
};

#endif  
