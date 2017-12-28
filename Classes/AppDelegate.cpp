#include "AppDelegate.h"
#include"BeginScene.h"
#include"GameData.h"
#include"GameDynamicData.h"
#include"MapInfo.h"
#include"CameraPlayer.h"
#include"Commen.h"
#include"AudioSystem.h"
#include"NpcBlue.h"
#include"NpcEquip.h"
#include"NpcManmom.h"
#include"NpcMonk.h"
#include"NpcPink.h"
#include"NpcSkill.h"
#include"NpcVallige.h"
#include"CMClient.h"

#define LoadPlayerAnimation(player)    \
{      \
	char name[40] = { 0 };    \
sprintf_s(name, "%sWaitLeft", player);    \
LoadAnimationFromFile(StringValue(name).c_str(), name, 1, FloatValue("PlayerFps"));  \
sprintf_s(name, "%sWaitRight", player);    \
LoadAnimationFromFile(StringValue(name).c_str(), name, 1, FloatValue("PlayerFps"));  \
sprintf_s(name, "%sWaitDown", player);    \
LoadAnimationFromFile(StringValue(name).c_str(), name, 1, FloatValue("PlayerFps")); \
sprintf_s(name, "%sWaitUp", player);   \
LoadAnimationFromFile(StringValue(name).c_str(), name, 1, FloatValue("PlayerFps"));  \
sprintf_s(name, "%sRunLeft",  player);   \
LoadAnimationFromFile(StringValue(name).c_str(), name, 12, FloatValue("PlayerFps"));  \
sprintf_s(name, "%sRunRight",  player);   \
LoadAnimationFromFile(StringValue(name).c_str(), name, 12, FloatValue("PlayerFps"));  \
sprintf_s(name, "%sRunDown",  player);   \
LoadAnimationFromFile(StringValue(name).c_str(), name, 12, FloatValue("PlayerFps"));  \
sprintf_s(name, "%sRunUp",  player);   \
LoadAnimationFromFile(StringValue(name).c_str(), name, 12, FloatValue("PlayerFps"));  \
}

AppDelegate::AppDelegate()
{
	
}

AppDelegate::~AppDelegate() 
{
	GameData::release();
	GameDynamicData::release();
	MapInfo::release();
	CameraPlayer::release();
	AudioSystem::releaseAudioSystem();
	ReflectNpc::release();
	CMClient::release();
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("ChivalrousMan", Rect(0, 0, 960, 640));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(960, 640, ResolutionPolicy::SHOW_ALL);

    // turn on display FPS
    //director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object
	CMClient::getInstance();
	registerReflectClass();
	LoadResource();
	AudioSystem::getInstance();

	auto scene = BeginScene::create();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::LoadResource()
{
	Animation *Player1Ani = Animation::create();
	char filename[40] = { 0 };
	Player1Ani->setDelayPerUnit(FloatValue("PlayerFps"));
	for (int i = 1; i <= 8; ++i)
	{
		sprintf_s(filename, "player1/2_%d.png", i);
		Texture2D *texture = TextureCache::getInstance()->addImage(filename);
		Rect rect{ 0,0,texture->getContentSize().width,texture->getContentSize().height };
		Player1Ani->addSpriteFrameWithTexture(texture, rect);
	}
	AnimationCache::getInstance()->addAnimation(Player1Ani, "Player1");

	LoadPlayerAnimation("Player1");
	LoadPlayerAnimation("Player2");
	LoadPlayerAnimation("Player3");

	Animation* doorAnimation;
	LoadAnimationFromMinFile("door/door", 11, 0.1, doorAnimation);
	AnimationCache::getInstance()->addAnimation(doorAnimation, "DoorAnimation");
}

void AppDelegate::LoadAnimationFromFile(const char* filename,char* key,int num,float delay) 
{
	auto outAni = Animation::create();
	Texture2D* texture = TextureCache::getInstance()->addImage(filename);
	float h = texture->getContentSize().height;
	float w = texture->getContentSize().width / num;
	outAni->setDelayPerUnit(delay);
	for (int i = 0; i < num; ++i)
	{
		SpriteFrame* frame = SpriteFrame::createWithTexture(texture, Rect{ i*w,0,w,h });
		outAni->addSpriteFrame(frame);
	}
	AnimationCache::getInstance()->addAnimation(outAni, key);
}

void AppDelegate::registerReflectClass()
{
	REG_REFLECT_CLASS(NpcBlue);
	REG_REFLECT_CLASS(NpcEquip);
	REG_REFLECT_CLASS(NpcMamom);
	REG_REFLECT_CLASS(NpcMonk);
	REG_REFLECT_CLASS(NpcPink);
	REG_REFLECT_CLASS(NpcSkill);
	REG_REFLECT_CLASS(NpcVallige);
}
