#ifndef __MAP_LAYER_H__
#define __MAP_LAYER_H__


class CBlockBase;

class MapLayer : public cocos2d::LayerColor
{
	public:
		enum
		{
			MAP_WIDTH	= 760,
			MAP_HEIGHT	= 1080
		};

	public:
		// there's no 'id' in cpp, so we recommend returning the class instance pointer
//		static cocos2d::Scene* createScene();

		// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
		virtual bool init();  
		
		// a selector callback

    
		// implement the "static create()" method manually
		CREATE_FUNC(MapLayer);

		/*
	    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) override;
		void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) override;
		
		cocos2d::Sprite* m_ty;
		cocos2d::EventListenerTouchOneByOne* m_touchListener;
		cocos2d::EventListenerKeyboard*	m_keyboardListener;
		*/

		
		void onEnter() override;
		void onExit() override;

		bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event) override;
		void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event* event) override;
		void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event* event) override;


	    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) override;
		void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) override;

	private:
		void CreateBlock( const Point& rPos );

	private:	
		typedef list< CBlockBase* >	TBlockList;

		TBlockList	m_blockList;

		Point		m_moveStartMousePos;
		Point		m_moveStartLayerPos;
};

#endif // __HELLOWORLD_SCENE_H__
