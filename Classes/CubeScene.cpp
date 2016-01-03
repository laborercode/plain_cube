#include "CubeScene.h"

USING_NS_CC;

Scene* CubeScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CubeScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool CubeScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto cubeLayer = LayerColor::create(Color4B(192, 192, 192, 255));
    initCube(cubeLayer);
    
    this->addChild(cubeLayer);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(CubeScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

void CubeScene::initCube(Layer *layer)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    int size = visibleSize.width;
    int margin = 4;
    int plainStartY = visibleSize.height - size;

    int blockSize = (size - (7 * margin)) / 9;

    int midStartX = 3 * blockSize + 3 * margin;
    // upper plain
    initPlain(layer, midStartX, plainStartY, blockSize, margin / 2);

    // mid plain
    int midStartY = plainStartY + 3 * blockSize + 3 * margin;
    for(int plain = 0 ; plain < 3 ; plain++) {
        int x = margin + plain * (3 * blockSize + 2 * margin);
        initPlain(layer, x, midStartY, blockSize, margin / 2);
    }

    // bottom plain
    int botStartY = midStartY + 3 * blockSize + 2 * margin;
    initPlain(layer, midStartX, botStartY, blockSize, margin / 2);
}

void CubeScene::initPlain(Layer *layer, int plainX, int plainY, int blockSize, int margin)
{
    for(int i = 0 ; i < 9 ; i++) {
        int x = plainX + (blockSize + margin) * (i % 3);
        int y = plainY + (blockSize + margin) * (i / 3);

        auto block = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
        //block->setColor();
        block->setAnchorPoint(Point(0, 1));
        block->setContentSize(Size(blockSize, blockSize));
        block->setPosition(x, y);

        layer->addChild(block);
    }
}

bool CubeScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unsued_event) 
{
    printf("###onTouchBegan###\n");
    // find block if it cannot find valid block ignore this event
    return true;
}
