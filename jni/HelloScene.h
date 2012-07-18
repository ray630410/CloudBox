/*
 *  HelloScene.h
 *  CloudBox Cross-Platform Framework Project
 *
 *  Created by Cloud on 2011/7/31.
 *  Copyright 2011 Cloud Hsu. All rights reserved.
 *
 */

#ifndef _HELLOSCENE_H_
#define _HELLOSCENE_H_

#include "CloudBox.h"

#define MAX_ANIMATION 50

class CBImage;

class HelloScene : public CBScene
{
private:
	//CBImage* bg1;
	//CBImage* bg2;
	CBLabel* label;
	CBButton* button;
	CBAnimation* animation[MAX_ANIMATION];
	CBSprite* sprite;
	CBImage* dart;
	CBImage* dart2;
	CBSwitch* m_switch;
protected:
	void update();
public:
	HelloScene();
	~HelloScene();
	
	void initialize();
	
	void OnOptionButtonClick(CBView* item,int index);
	void OnClick(CBView* item,CBEvent* e);
	
	void touchBegan(float x, float y);
	void touchMoved(float x, float y);
	void touchEnded(float x, float y);
};

#endif
