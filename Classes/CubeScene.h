#ifndef __CUBE_SCENE_H__
#define __CUBE_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"

#define BLOCK_COLOR_0 Color3B(255, 0, 0)
#define BLOCK_COLOR_1 Color3B(0, 255, 0)
#define BLOCK_COLOR_2 Color3B(0, 0, 255)
#define BLOCK_COLOR_3 Color3B(255, 0, 0)
#define BLOCK_COLOR_4 Color3B(255, 0, 0)
#define BLOCK_COLOR_5 Color3B(255, 0, 0)
#define BLOCK_COLOR_6 Color3B(255, 0, 0)
#define BLOCK_COLOR_7 Color3B(255, 0, 0)
#define BLOCK_COLOR_8 Color3B(255, 0, 0)

class CubeScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CubeScene);

private:
    void initCube(Layer *);
    void initPlain(Layer *, int, int, int , int);

    bool onTouchBegan(cocos2d::Touch *, cocos2d::Event *);

};

#endif // __CUBE_SCENE_H__
