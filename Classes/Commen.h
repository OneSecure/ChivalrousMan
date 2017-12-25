#pragma once
#ifndef __COMMEN_H__
#define __COMMEN_H__

using namespace cocos2d;

#define PI 3.1415

#define SCREEN Director::getInstance()->getWinSize()

//转到开始界面
#define GO_BACK_START_MENU() \
auto startScene = StartMenu::create(); \
auto reScene = CCTransitionFadeDown::create(1,  startScene); \
Director::getInstance()->replaceScene(reScene)

#define GO_BACK_BEGIN()             \
 auto bs = BeginScene::create();           \
 auto reScene = CCTransitionFadeDown::create(1,bs);  \
 Director::getInstance()->replaceScene(reScene ) 

//是否包含该点
#define CONTAIN_POINT(WHO,POS,RES)                                           \
                     Size WHO##size = WHO->getContentSize();                      \
                     float WHO##x = WHO->getPositionX() - WHO##size.width / 2;    \
                     float WHO##y = WHO->getPositionY() - WHO##size.height / 2;    \
                     if (POS.x > WHO##x&&POS.x<WHO##x + WHO##size.width&&POS.y>WHO##y&&POS.y < WHO##y + WHO##size.height)   \
                     {                                                                                            \
	                     RES=true;                                                                                \
                     }                                                                                            \
                     else                                                                                         \
                     {                                                                                            \
	                     RES = false;                                                                           \
                     }                                 
//添加编辑框
#define ADD_EDIT(__NAME__,ECHONAME,POS,LABELNAME,BGNAME,IS_PASSWD,TARGET,DELEGATE)    \
               auto lb##__NAME__ = LabelTTF::create(StringValue(LABELNAME), "楷体", 45); \
               lb##__NAME__->setColor(ccc3(164, 23, 142));  \
               __NAME__ = CCTextFieldTTF::textFieldWithPlaceHolder(StringValue(ECHONAME), "楷体", 20);  \
               __NAME__->setColorSpaceHolder(ccc3(73, 214, 23));   \
               __NAME__->setWidth(200);        \
               __NAME__->setHeight(25);         \
               __NAME__->setAnchorPoint(Vec2{ 0,0.5 });   \
               __NAME__->setAlignment(TextHAlignment::LEFT);   \
               __NAME__->setTextColor(ccc4(131, 3, 92, 255));    \
               __NAME__->setContentSize(Size{ SCREEN.width*0.5f,45.0f });   \
               __NAME__->setSecureTextEntry(IS_PASSWD);        \
               __NAME__->setDelegate(DELEGATE);        \
               auto __NAME__##Bg = Sprite::create(StringValue(BGNAME));   \
               lb##__NAME__->setPosition(ccp(POS.x, POS.y));    \
               __NAME__##Bg->setPosition(ccp(POS.x + 90, POS.y));   \
               __NAME__->setPosition(ccp(POS.x + 120,POS.y-3));   \
               __NAME__##Bg->setAnchorPoint(Vec2{ 0,0.5 });  \
               TARGET->addChild(lb##__NAME__);    \
               TARGET->addChild(__NAME__##Bg);    \
               TARGET->addChild(__NAME__)

//装载或卸载
#define ATTACH_OR_DETACH(__NAME__,TOUCH_POS,__IS)     \
             CONTAIN_POINT(__NAME__, TOUCH_POS, __IS);   \
             if(__IS)                                 \
             {                                        \
	             __NAME__->attachWithIME();        \
             }                                      \
             else                                 \
             {                                     \
	             __NAME__->detachWithIME();        \
             }                                    

#define COMMEN_BTN(TARGET,CALL_BACK1,CALL_BACK2) \
        auto confirmBtn = MenuItemImage::create(StringValue("SureBtn"), StringValue("SureBtn1"),TARGET, menu_selector(CALL_BACK1)); \
        confirmBtn->setScaleY(1.2f);   \
        auto cancelBtn = MenuItemImage::create(StringValue("BackBtn"), StringValue("BackBtn1"),TARGET, menu_selector(CALL_BACK2)); \
        cancelBtn->setScaleY(1.2f);   \
        confirmBtn->setPosition(SCREEN.width*0.35, SCREEN.height*0.15);\
        cancelBtn->setPosition(SCREEN.width*0.65, SCREEN.height*0.15); \
        auto CBmenu= Menu::create(); \
        CBmenu->addChild(confirmBtn); \
        CBmenu->addChild(cancelBtn); \
        CBmenu->setPosition(0, 0); \
        TARGET->addChild(CBmenu)

#define STONE_STATION(X,Y,CALL_BACK,TARGET)  \
        auto SSmenu = Menu::create(); \
        for (int i = 1; i <= 3; ++i) \
        { \
	         auto station = MenuItemImage::create(StringValue("Stone"),  \
		       StringValue("Stone"), TARGET, menu_selector(CALL_BACK)); \
	         station->setTag(100 + i); \
	         station->setPosition(SCREEN.width*X*i, SCREEN.height*Y); \
	         SSmenu->addChild(station); \
        }  \
        SSmenu->setPosition(0, 0); \
        TARGET->addChild(SSmenu)

#define NEGATE(NUMBER) (NUMBER)=-(NUMBER);

#define LISTEN_TOUCH(__TYPE__)  \
         setTouchEnabled(true); \
         auto touchListener = EventListenerTouchOneByOne::create();   \
         touchListener->onTouchBegan = CC_CALLBACK_2(__TYPE__::onTouchBegan, this); \
         touchListener->onTouchMoved = CC_CALLBACK_2(__TYPE__::onTouchMoved, this);  \
         touchListener->onTouchEnded = CC_CALLBACK_2(__TYPE__::onTouchEnded, this);   \
         _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this)
  
#define RELEASE_NULL(p) \
 if((p)!=nullptr) \
 { \
    delete (p); \
    (p) = nullptr; \
  }

#define FOUR_LOSE_FIVE_ADD(number) \
  if((number)-(int)(number)>=0.5) \
  { \
	  (number) = (int)(number) + 1; \
  } \
  else \
  { \
	  (number) = (int)(number); \
  }

#define LoadAnimationFromMinFile(name,num,delay,animation) \
{ \
  animation = Animation::create(); \
  char filename[40] = { 0 }; \
  animation->setDelayPerUnit(delay); \
  for (int i = 1; i <=num; ++i) \
  { \
	  sprintf_s(filename, "%s%d.png", name, i); \
	  Texture2D *texture = TextureCache::getInstance()->addImage(filename); \
	  Rect rect{ 0,0,texture->getContentSize().width,texture->getContentSize().height }; \
	  animation->addSpriteFrameWithTexture(texture, rect); \
  } \
}

#define ToggleMusic()  \
{ \
auto toggle = (MenuItemToggle*)sender; \
if (toggle->getSelectedIndex() == 1) \
{ \
SetIntData("BgMusic", 1,true); \
} \
else \
{ \
SetIntData("BgMusic", 0,true); \
} \
}

#endif  // !__COMMEN_H__