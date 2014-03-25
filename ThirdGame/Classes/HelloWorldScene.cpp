#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    if ( scene == NULL )
        return NULL;
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    if ( layer == NULL )
        return scene;
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    m_touchListener = EventListenerTouchOneByOne::create();
	m_touchListener->setSwallowTouches(true);
    
	m_touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	m_touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	m_touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    
	dispatcher->addEventListenerWithSceneGraphPriority( m_touchListener, this);

    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

	 // add "HelloWorld" splash screen"
    //    auto sprite = Sprite::create("HelloWorld.png");
	 m_ty = Sprite::create("image/ty01.jpg");
    
    if ( m_ty == NULL )
        return false;
    
    // position the sprite on the center of the screen
    m_ty->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    //	sprite->setPosition( Point( 10, 10 ));
    
    // add the sprite as a child to this layer
    this->addChild(m_ty, 0);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool HelloWorld::onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event)
{
	CCPoint posInNode = m_ty->convertToNodeSpace( touch->getLocation());
	cocos2d::Rect rect = m_ty->getTextureRect();
    
	if ( !rect.containsPoint( posInNode ))
		return false;
    
	/*
     cocos2d::Rect tmp( pos.x - rect.size.width/2, pos.y - rect.size.height / 2, rect.size.width, rect.size.height );
     
     cocos2d::Point cursor = touch->getLocation();
     
     if ( !tmp.containsPoint( cursor ))
     return false;
     */
    
	m_ty->setScale( 1.2f );
	onTouchMoved( touch, event );
	return true;
}

void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event* event)
{
	m_ty->setPosition( touch->getLocation() );
}

void HelloWorld::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event* event)
{
	m_ty->setScale( 1.0f );
}

