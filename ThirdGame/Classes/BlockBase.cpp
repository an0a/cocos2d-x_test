#include "stdafx.h"
#include "BlockBase.h"



bool CBlockBase::init()
{
	if ( !Layer::init() )
    {
        return false;
    }

//	this->setContentSize( Size( 100, 100 ));

	////////////////////////////////
	
	/*
	this->setTouchEnabled( true );
	this->setContentSize( Size( 50.0f, 50.0f ));

	auto touchListener = EventListenerTouchOneByOne::create();
//	touchListener->setSwallowTouches(true);
    
	touchListener->onTouchBegan = CC_CALLBACK_2(CBlockBase::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(CBlockBase::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(CBlockBase::onTouchEnded, this);

	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
    
	dispatcher->addEventListenerWithFixedPriority( touchListener, 1 );
	*/

	DrawNode* node = DrawNode::create();
	node->drawDot( ccp( 0.0f, 0.0f ), 10, Color4F( 0.0f, 0.0f, 1.0f, 1.0f ));
	this->addChild(node,10);//Make sure your z-order is large enough


	return true;
}


void CBlockBase::onEnter()
{
}

void CBlockBase::onExit()
{
}

bool CBlockBase::onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event)
{
	Point pos = touch->getLocation();

	LOGN( " mouse(%f, %f)", pos.x, pos .y  );

	/*
	GetPositionX();
	getPosition
	Point pos = touch->getLocation();

	Point posInNode = m_ty->convertToNodeSpace( touch->getLocation());
	cocos2d::Rect rect = m_ty->getTextureRect();
    
	if ( !rect.containsPoint( posInNode ))
		return false;
	*/

	return true;
}

void CBlockBase::onTouchMoved( cocos2d::Touch *touch, cocos2d::Event* event)
{
}

void CBlockBase::onTouchEnded( cocos2d::Touch *touch, cocos2d::Event* event)
{
}

