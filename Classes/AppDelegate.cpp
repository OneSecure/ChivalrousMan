#include "AppDelegate.h"
#include"BeginScene.h"
#include"GameData.h"
#include"GameDynamicData.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{

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

    //FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object
	LoadResource();

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
	char filename[20] = { 0 };
	Player1Ani->setDelayPerUnit(FloatValue("PlayerFps"));
	for (int i = 1; i <= 8; ++i)
	{
		sprintf_s(filename, "player1/2_%d.png", i);
		Texture2D *texture = TextureCache::getInstance()->addImage(filename);
		Rect rect{ 0,0,texture->getContentSize().width,texture->getContentSize().height };
		Player1Ani->addSpriteFrameWithTexture(texture, rect);
	}
	AnimationCache::getInstance()->addAnimation(Player1Ani, "Player1");
}
