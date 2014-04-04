#pragma once


class CBlockBase : public cocos2d::Layer
{
	public:
		virtual bool init();  
		
		CREATE_FUNC(CBlockBase);


		void onEnter() override;
		void onExit() override;

		bool onTouchBegan( cocos2d::Touch *touch, cocos2d::Event *event) override;
		void onTouchMoved( cocos2d::Touch *touch, cocos2d::Event* event) override;
		void onTouchEnded( cocos2d::Touch *touch, cocos2d::Event* event) override;
};

