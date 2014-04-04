#include "stdafx.h"
#include "MapLayer.h"

#include "BlockBase.h"

// on "init" you need to initialize your instance
bool MapLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor( Color4B( 255, 0, 0, 255 )))
    {
        return false;
    }

	
	Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();



	auto img = Sprite::create("image/map.png");
//	img->setPosition( getPosition());
//	img->setContentSize( Size( MAP_WIDTH, MAP_HEIGHT ));

	img->setPosition( MAP_WIDTH/2, MAP_HEIGHT/2);
	this->addChild( img, 0 );


	setContentSize( Size( MAP_WIDTH, MAP_HEIGHT ) );
	setPosition( ( visibleSize.width - MAP_WIDTH ) / 2, ( visibleSize.height - MAP_HEIGHT ) / 2 );

//	this->setContentSize( Size( 100, 100 ));

	////////////////////////////////
	
	this->setTouchEnabled( true );

	auto m_touchListener = EventListenerTouchOneByOne::create();
//	m_touchListener->setSwallowTouches(true);
    
	m_touchListener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
	m_touchListener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
	m_touchListener->onTouchEnded = CC_CALLBACK_2(MapLayer::onTouchEnded, this);

	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    
	dispatcher->addEventListenerWithFixedPriority( m_touchListener, 1 );

	////////////////////////////////
	
	auto keyboardListener = EventListenerKeyboard::create();
//	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    
	keyboardListener->onKeyPressed = CC_CALLBACK_2( MapLayer::onKeyPressed, this );
	keyboardListener->onKeyReleased = CC_CALLBACK_2( MapLayer::onKeyReleased, this );

	dispatcher->addEventListenerWithFixedPriority( keyboardListener, 1 );

//	setKeyboardEnabled( true );

	setKeyboardEnabled( true );

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	auto label = LabelTTF::create("test test.", "Arial", 30);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

	label->setColor( Color3B( 255, 0, 0 ));

    // add the label as a child to this layer
    this->addChild(label, 1);

	return true;
}

void MapLayer::onEnter()
{
	m_moveStartMousePos	= Point( 0.0f, 0.0f );
	m_moveStartLayerPos	= Point( 0.0f, 0.0f );

//	this->setColor( Color3B( 255, 0, 0 ));
	// 들어왔니?

	for ( int y=1;y<10;y++)
	{
		for ( int x=1;x<10;x++)
		{
			CreateBlock( Point( x * 50, y * 50 ));
		}	
	}
}

void MapLayer::onExit()
{
}

void MapLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch( keyCode )
	{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			{
				Point pos = this->getPosition();
				pos.x -= 100;
				this->setPosition( pos.x, pos.y );
			}
			break;

		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			{
				Point pos = this->getPosition();
				pos.x += 100;
				this->setPosition( pos.x, pos.y );
			}
			break;
			

	}
	
}

void MapLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
//	LOGN( "들어오죠?!" );
}


bool MapLayer::onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event)
{
//	m_moveStartMousePos = touch->getLocation();
//	m_moveStartLayerPos = getPosition();

//	LOGN( "터치시작!  %g %g", m_pressStartPos.x, m_pressStartPos.y );
	return true;
}


void MapLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event* event)
{
	/*
	Point mouseMove = touch->getLocation() - m_moveStartMousePos;
	
	Point curPos = this->getPosition();

	curPos.x += diff.x;
	curPos.x += diff.x;

	this->setPosition( curPos );

	*/
//	LOGN( "들어오죠?!" );

	Point delta = touch->getDelta();

	LOGN( "%g, %g", delta.x, delta.y );

	this->setPosition( this->getPosition() + delta );
}


void MapLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event* event)
{

}

void MapLayer::CreateBlock( const Point& rPos )
{
	CBlockBase* pBlock = CBlockBase::create();

	pBlock->setContentSize( Size( 50, 50 ));
	pBlock->setPosition( rPos.x, rPos.y );

	this->addChild( pBlock, 1 );
	m_blockList.push_back( pBlock );
}
